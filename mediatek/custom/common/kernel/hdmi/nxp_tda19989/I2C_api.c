/*===========================================================================*
*                                                                            *
*  main.c:  Master Transmitter/Receiver I�C Driver for LPC2138               *
*  Author:  V. Latapie                                                       *
*  Date  :  14/06/07                                                         *
*                                                                            *
============================================================================*/


/*===========================================================================*
*                           Include Files                                    *
*============================================================================*/

#include <linux/autoconf.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/init.h>
#include <linux/fb.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/dma-mapping.h>
#include <linux/earlysuspend.h>
#include <linux/kthread.h>
#include <linux/rtpm_prio.h>

#include "I2C.h"
#include "tmNxCompId.h"
#include "tmdlHdmiTx_IW.h"
#include <linux/string.h>
#ifdef BUILD_UBOOT
#include <asm/arch/mt_gpio.h>
#else
#include <mach/mt_gpio.h>
#include "mach/eint.h"
#include "mach/irqs.h"
#endif
#include "hdmi_drv.h"

static size_t hdmi_i2c_log_on = false;
#define HDMI_I2C_LOG(fmt, arg...) \
    do { \
        if (hdmi_i2c_log_on) \
        { \
            printk("[hdmi_i2c log], %s, #%d", __func__, __LINE__); \
            printk(fmt, ##arg); \
        } \
    }while (0)

#define HDMI_I2C_FUNC()	\
	do { \
		if(hdmi_i2c_log_on) printk("[hdmi_i2c func] %s\n", __func__); \
	}while (0)

void hdmi_i2c_log_enable(int enable)
{
	printk("hdmi_i2c log %s\n", enable?"enabled":"disabled");
	hdmi_i2c_log_on = enable;
}

extern void I2C_ISR(void);

unsigned char nb_byte[3];
unsigned char slave[3];
unsigned char *pt_mtd[3], *pt_mrd[3];
volatile unsigned char transmission ;
unsigned char rep_start_cntr;
unsigned char  ptr[255];

/* Semaphore for I�C access */
tmdlHdmiTxIWSemHandle_t gI2CSemaphore;

/*===========================================================================*
*                                                                            *
*    FUNCTION NAME:    I2C_Init                                              *
*    DESCRIPTION  :    I�C initialisation                                    *
*                                                                            *
*    INPUT   :         none                                                  *
*    OUTPUT  :         none                                                  *
*                                                                            *
*    RETURN  :         none                                                  *
*                                                                            *
*    CONTEXT :         SYNCHRONOUS                                           *
*============================================================================*/

#if defined GPIO_HDMI_I2C_SDA
	#define GPIO_SDA 	GPIO_HDMI_I2C_SDA
#else
	#define GPIO_SDA 	255		//xuecheng, 255 is larger than MAX_GPIO_PIN, so this will cause runtime error and will not affect other modules.
#endif

#if defined GPIO_HDMI_I2C_SCL
	#define GPIO_SCL	GPIO_HDMI_I2C_SCL
#else
	#define GPIO_SCL		255		//xuecheng, 255 is larger than MAX_GPIO_PIN, so this will cause runtime error and will not affect other modules.
#endif

#define SET_SCCB_CLK_OUTPUT						mt_set_gpio_dir(GPIO_SCL, GPIO_DIR_OUT)
#define SET_SCCB_CLK_INPUT						mt_set_gpio_dir(GPIO_SCL, GPIO_DIR_IN)
#define SET_SCCB_DATA_OUTPUT					mt_set_gpio_dir(GPIO_SDA, GPIO_DIR_OUT)
#define SET_SCCB_DATA_INPUT						mt_set_gpio_dir(GPIO_SDA, GPIO_DIR_IN)

#define SET_SCCB_CLK_HIGH						mt_set_gpio_out(GPIO_SCL, GPIO_OUT_ONE)
#define SET_SCCB_CLK_LOW						mt_set_gpio_out(GPIO_SCL, GPIO_OUT_ZERO)
#define SET_SCCB_DATA_HIGH						mt_set_gpio_out(GPIO_SDA, GPIO_OUT_ONE)
#define SET_SCCB_DATA_LOW						mt_set_gpio_out(GPIO_SDA, GPIO_OUT_ZERO)

#define GET_SCCB_DATA_BIT						mt_get_gpio_in(GPIO_SDA)

#define I2C_DELAY								2

static int i2c_delay(unsigned int n)
{
#if 1
    udelay(n);
#else
	unsigned int count = 1024*n;
	asm volatile(
			"1:                                 \n\t"
			"subs   %[count], %[count], #1      \n\t"
			"bge    1b                          \n\t"
			:[count] "+r" (count)
			:
			:"memory"
			);
#endif
	return 0;
}


#define I2C_START_TRANSMISSION \
{ \
	/*volatile unsigned char j;*/ \
	SET_SCCB_CLK_OUTPUT; \
	SET_SCCB_DATA_OUTPUT; \
	SET_SCCB_CLK_HIGH; \
	SET_SCCB_DATA_HIGH; \
	/*for(j=0;j<I2C_DELAY;j++);*/\
	i2c_delay(I2C_DELAY); 	\
	SET_SCCB_DATA_LOW; \
	/*for(j=0;j<I2C_DELAY;j++);*/\
	i2c_delay(I2C_DELAY);	\
	SET_SCCB_CLK_LOW; \
}

#define I2C_STOP_TRANSMISSION \
{ \
	/*volatile unsigned char j;*/ \
	SET_SCCB_CLK_OUTPUT; \
	SET_SCCB_DATA_OUTPUT; \
	SET_SCCB_CLK_LOW; \
	SET_SCCB_DATA_LOW; \
	/*for(j=0;j<I2C_DELAY;j++);*/\
	i2c_delay(I2C_DELAY);	\
	SET_SCCB_CLK_HIGH; \
	/*for(j=0;j<I2C_DELAY;j++);*/\
	i2c_delay(I2C_DELAY);	\
	SET_SCCB_DATA_HIGH; \
}					

static void SCCB_send_byte(unsigned char send_byte)
{
	volatile signed char i;
	//volatile unsigned int j;

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		if (send_byte & (1<<i))
		{
			SET_SCCB_DATA_HIGH;
		}
		else
		{
			SET_SCCB_DATA_LOW;
		}
		i2c_delay(I2C_DELAY);
		SET_SCCB_CLK_HIGH;
		i2c_delay(I2C_DELAY);
		SET_SCCB_CLK_LOW;
		i2c_delay(I2C_DELAY);
	}
	/* don't care bit, 9th bit */
	SET_SCCB_DATA_LOW;
	SET_SCCB_DATA_INPUT;
	SET_SCCB_CLK_HIGH;
	i2c_delay(I2C_DELAY);
	SET_SCCB_CLK_LOW;
	SET_SCCB_DATA_OUTPUT;
}	/* SCCB_send_byte() */

static unsigned char SCCB_get_byte(void)
{
	volatile signed char i;
	//volatile unsigned char j;
	unsigned char get_byte=0;

	SET_SCCB_DATA_INPUT;

	for (i=7;i>=0;i--)
	{	/* data bit 7~0 */
		SET_SCCB_CLK_HIGH;
		//for(j=0;j<I2C_DELAY;j++);
		i2c_delay(I2C_DELAY);
		if (GET_SCCB_DATA_BIT)
			get_byte |= (1<<i);
		//for(j=0;j<I2C_DELAY;j++);
		i2c_delay(I2C_DELAY);
		SET_SCCB_CLK_LOW;
		//for(j=0;j<I2C_DELAY;j++);
		i2c_delay(I2C_DELAY);
	}
	/* don't care bit, 9th bit */
	SET_SCCB_DATA_OUTPUT;
	SET_SCCB_DATA_HIGH;
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SET_SCCB_CLK_HIGH;
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SET_SCCB_CLK_LOW;

	return get_byte;
}	/* SCCB_send_byte() */

static void sccb_write(unsigned char slave_addr, unsigned char addr, unsigned char para)
{
	//volatile unsigned int i,j;

	I2C_START_TRANSMISSION;
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(slave_addr);

	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(addr);

	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(para);

	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	i2c_delay(I2C_DELAY);
	i2c_delay(I2C_DELAY);
	I2C_STOP_TRANSMISSION;
}

static void sccb_write_multi(unsigned char slave_addr, unsigned char *addr, unsigned int nb_char)
{
	volatile unsigned int i;

	I2C_START_TRANSMISSION;
	
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(slave_addr);

	for(i=0;i<nb_char;i++)
	{
		i2c_delay(I2C_DELAY);
		SCCB_send_byte(addr[i]);
	}

	I2C_STOP_TRANSMISSION;
}


static unsigned int sccb_read(unsigned char slave_addr, unsigned char addr)
{
	unsigned int get_byte;
	//volatile unsigned int i, j;

	I2C_START_TRANSMISSION;
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(slave_addr);
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(addr);
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	I2C_STOP_TRANSMISSION;
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	I2C_START_TRANSMISSION;
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	SCCB_send_byte(slave_addr|0x1);
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	get_byte=SCCB_get_byte();
	//for(j=0;j<I2C_DELAY;j++);
	i2c_delay(I2C_DELAY);
	I2C_STOP_TRANSMISSION;

	return get_byte;
}

tmErrorCode_t suspend_i2c(void)
{
    mt_set_gpio_pull_enable(GPIO_SDA, true);
    mt_set_gpio_pull_select(GPIO_SDA, GPIO_PULL_UP);
    //mt_set_gpio_out(GPIO187, 0);
    //mt_set_gpio_pull_enable(GPIO187, true);
    //mt_set_gpio_pull_select(GPIO187, GPIO_PULL_UP);


    mt_set_gpio_pull_enable(GPIO_SCL, true);    
    mt_set_gpio_pull_select(GPIO_SCL, GPIO_PULL_UP);    
    return TM_OK;
}

tmErrorCode_t resume_i2c(void)
{
    mt_set_gpio_pull_enable(GPIO_SDA, false);

    mt_set_gpio_pull_enable(GPIO_SCL, false);    
    return TM_OK;
}

#include <linux/semaphore.h>
DEFINE_SEMAPHORE(i2c_mutex);

tmErrorCode_t Init_i2c(void)
{
  tmErrorCode_t errCode;
  #if 0
  HDMI_I2C_LOG("hdmi, %s\n", __func__);
	mt_set_gpio_mode(GPIO_SDA, GPIO_MODE_00);
	mt_set_gpio_mode(GPIO_SCL, GPIO_MODE_00);

	mt_set_gpio_dir(GPIO_SDA, GPIO_DIR_OUT);
	mt_set_gpio_dir(GPIO_SCL, GPIO_DIR_OUT);
	#endif

#if 0
 /* Initialize I�C */
  I2CONCLR = 0x6C;  /* Clear Control Set Register */
  I2CONSET = 0x40;  /* Enable I�C */   
  
  /* Maximum speed for TDA9984 is 400 Khz */
  /* 60 Khz = pclk / (I�CSCLH + I�CSCLL) with pclk = peripheral clock*/
  /* according to VBPDIV Fpclk = Fcclk/4 = 60/4 = 15 Mhz  */
  /* so I�CSCLH + I�CSCLL = 37 */
  I2SCLH = 0x7D;
  I2SCLL = 0x7D;
 
  /* Initialize VIC for I�C use */
  VICIntEnable |= 0x200;  /* Enable I�C interruption */
  VICVectCntl0 = 0x29;   /* Enable I�C canal in IRQ Mode */
  VICVectAddr0 = (unsigned long) I2C_ISR;

  #endif
  /* Create the semaphore to protect I�C access */
  //errCode = tmdlHdmiTxIWSemaphoreCreate(&gI2CSemaphore);
  
  gI2CSemaphore = (unsigned long)(&i2c_mutex);
  errCode = TM_OK;   

  return errCode;
}

/*===========================================================================*
*                                                                            *
*    FUNCTION NAME:    I2C_write                                             *
*    DESCRIPTION  :    Write a series of bytes out the I2C bus to the given  *
*                      slave address                                         *
*                                                                            *
*    INPUT   :         unsigned char Address    -- Address of slave          *
*                      unsigned char nb_char    -- Nb of data bytes to write *
*                      unsigned char *ptr       -- Pointer to data to send   *
*    OUTPUT  :         unsigned char            -- Status of I2C bus at     *
*                                                   start of write.          *
*                                                                            *
*    RETURN  :         none                                                  *
*                                                                            *
*    CONTEXT :         SYNCHRONOUS                                           *
*============================================================================*/

unsigned char Write_i2c(unsigned char address,  unsigned char *ptr, unsigned char nb_char)
{
   //unsigned char i;
   int  hConnection;

  HDMI_I2C_LOG("hdmi, %s, 0x%08x, 0x%08x, 0x%08x\n", __func__, address, ptr[0], ptr[1]);
  
  switch(address)
	 {
	  case reg_TDA997X :
		  hConnection = (2*slaveAddressTDA9975A);
		  break;
	  case reg_TDA998X :
		  hConnection = (2*slaveAddressTDA9984);
		  break;
	  case reg_TDA8778 :
		  hConnection = (2*slaveAddressTDA8778);
		  break;
	  case reg_UDA1355H :
		  hConnection = (2*slaveAddressUDA1355H);
		  break;
	  case reg_MAX4562 :
		  hConnection = (2*slaveAddressMAX4562);
		  break;
	  case reg_TDA9989_CEC :
	  case reg_TDA9950 :
		  hConnection = (2*slaveAddressDriverHdmiCEC);
		  break;
	  case reg_PCA9536 :
		  hConnection = (2*slaveAddressPCA9536);
		  break;
  
	  default :
		  return (unsigned char) ~TM_OK;//TMBSL_ERR_INTEG_PARAMETER1;
	 }
  
	if(nb_char > 2)
	{
		HDMI_I2C_LOG("hdmi, !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%s, nb_char=%d\n", __func__, nb_char);
		sccb_write_multi((hConnection), ptr, nb_char);
	}
	else
	{
		sccb_write((hConnection), ptr[0], ptr[1]);
	}
#if 0 
   
   pt_mtd[0] = ptr;
   nb_byte[0] = nb_char;
   slave[0] = hConnection & 0xFE;         /* SLA + W */
   rep_start_cntr = 0;                      /* No repeated starts - hence using element 0 in the arrays */

   transmission = INIT;               /* Start transmission */
   I2CONSET = 0x20;

   while (transmission == INIT) i++;   /* Wait free bus */
   while (transmission == START) i++;  /* Wait end of transmission */
   #endif
   return 0;
}





/*===========================================================================*
*                                                                            *
*    FUNCTION NAME:    I2C_read                                              *
*    DESCRIPTION  :    Read a series of bytes out the I2C bus from the given *
*                      slave address                                         *
*                                                                            *
*    INPUT   :         unsigned char address    -- Address of slave          *
*                      unsigned char pos        -- offset in device          *
*                      unsigned char nb_char    -- Nb of data bytes to read  *
*                      unsigned char *ptr       -- Pointer to data to receive*
*    OUTPUT  :         unsigned char            -- Status of I2C bus at      *
*                                                   start of write.          *
*                                                                            *
*    RETURN  :         none                                                  *
*                                                                            *
*    CONTEXT :         SYNCHRONOUS                                           *
*============================================================================*/
                                                                              

unsigned char Read_at_i2c(unsigned char address, unsigned char pos, unsigned char nb_char, unsigned char *ptr)
{
    //unsigned char i;
    int hConnection;
	switch(address)
   {
    case reg_TDA997X :
        hConnection = (2*slaveAddressTDA9975A);
        break;
    case reg_TDA998X :
        hConnection = (2*slaveAddressTDA9984);
        break;
    case reg_TDA8778 :
        hConnection = (2*slaveAddressTDA8778);
        break;
    case reg_UDA1355H :
        hConnection = (2*slaveAddressUDA1355H);
        break;
    case reg_MAX4562 :
        hConnection = (2*slaveAddressMAX4562);
        break;
    case reg_TDA9989_CEC :
    case reg_TDA9950 :
        hConnection = (2*slaveAddressDriverHdmiCEC);
        break;
    case reg_PCA9536 :
        hConnection = (2*slaveAddressPCA9536);
        break;
    default :
        return (unsigned char) ~TM_OK;//TMBSL_ERR_INTEG_PARAMETER1;
   }
  *ptr=sccb_read((hConnection), pos);
  HDMI_I2C_LOG("hdmi, %s, address=0x%08x, pos=0x%08x, nb_char=0x%08x, value=0x%08x\n", __func__, address, pos, nb_char, *ptr);

  return 0;
	#if 0

   

   pt_mtd[1] = &pos ;
   pt_mrd[0] = ptr ;
   nb_byte[1] = 1;
   nb_byte[0] = nb_char ;
   slave[1] =  hConnection & 0xFE;                     /* SLA + W */
   slave[0] =  hConnection | 0x01;            /* SLA + R */
   rep_start_cntr = 1;                          /* One repeated start  - element 1s in arrays for Write, element 0s for Read */

   transmission = INIT;
   I2CONSET = 0x20;                                 /* Start transmission */
   while (transmission == INIT) i++;        /* Wait free bus */
   while (transmission == START) i++;       /* Wait end of transmission */
   return (transmission);
   #endif
}


/*===========================================================================*
*                                                                              *
*    FUNCTION NAME:    Read_edid                                               *
*    DESCRIPTION  :    Read a series of bytes out the I2C bus from the given   *
*                      slave address                                           *
*                                                                              *
*    INPUT   :         unsigned char seg_addr   -- Address of slave            *
*                      unsigned char seg_ptr    -- offset in device            *
*                      unsigned char data_addr  -- Nb of data bytes to read    *
*                      unsigned char word_offset -- Pointer to data to receive *
*                      unsigned char nb_char  -- Pointer to data to receive    *
*                      unsigned char *ptr  -- Pointer to data to receive       *
*    OUTPUT  :         none                                                    *
*                                                                              *
*    RETURN  :         unsigned char            -- Status of I2C bus 
*                                                                              *
*    CONTEXT :         SYNCHRONOUS                                             *
*============================================================================*/
/********************************************/
/*          R E A D _ E D I D               */
/*                                          */
/* Write segment pointer, repeated start,   */
/* write word offset, repeated start,       */
/* read no. bytes requested, stop.          */
/********************************************/
unsigned char Read_edid(unsigned char seg_addr, unsigned char seg_ptr, unsigned char data_addr, unsigned char word_offset,
                                unsigned char nb_char, unsigned char *ptr)
{
   //unsigned char i;
   HDMI_I2C_LOG("hdmi, %s\n", __func__);
	#if 0

   pt_mtd[2] = &seg_ptr;
   pt_mtd[1] = &word_offset;
   pt_mrd[0] = ptr;
   nb_byte[2] = 1;                              /* Single byte for Segment pointer */
   nb_byte[1] = 1;                              /* Single byte for Word offset */
   nb_byte[0] = nb_char;                        /* Number of EDID bytes to read */
   slave[2] = seg_addr  & 0xFE;             /* SLA + W, segment pointer */
   slave[1] = data_addr & 0xFE;             /* SLA + W, data pointer */
   slave[0] = data_addr | 0x01;                 /* SLA + R, data pointer */
   if(seg_addr == 0)                               /* If segptr address invalid, skip the segptr write - allows for quick block 0/1 reads */
   {
        rep_start_cntr = 1;                     /* One repeated start. 1=Write word offset, 0=Read data */
   }
   else
   {
    rep_start_cntr = 2;                     /* Two repeated starts. 2=Write segptr, 1=Write word offset, 0=Read data */
   }


   transmission = INIT;
   I2CONSET = 0x20;                                 /* Start transmission */
   while (transmission == INIT) i++;        /* Wait free bus */
   while (transmission == START) i++;       /* Wait end of transmission */
   #endif
   return (transmission);
}



tmErrorCode_t  i2cWrite(i2cRegisterType_t type_register,tmbslHdmiSysArgs_t *pSysArgs)
{
  
  tmErrorCode_t errCode;
  int           i;
 
  /* Take the semaphore for I�C */
  errCode = tmdlHdmiTxIWSemaphoreP(gI2CSemaphore);
  if(errCode)
  {
    return errCode;
  }
  
  ptr[0] = pSysArgs->firstRegister;

  for (i=1; i<=pSysArgs->lenData; i++)
  {
   ptr[i] = (*pSysArgs->pData);
   (pSysArgs->pData)++;
  }
  pSysArgs->lenData++;

  errCode = Write_i2c(type_register, ptr, pSysArgs->lenData); 
  if(errCode)
  {
    /* Release the semaphore if an error is detected */
    tmdlHdmiTxIWSemaphoreV(gI2CSemaphore);
    return errCode;
  }

  /* Release the semaphore for I�C */
  errCode = tmdlHdmiTxIWSemaphoreV(gI2CSemaphore);
  if(errCode)
  {
    return errCode;
  }

  return errCode;     
}





tmErrorCode_t  i2cRead(i2cRegisterType_t type_register,tmbslHdmiSysArgs_t *pSysArgs)
{
  tmErrorCode_t errCode;

  /* Take the semaphore for I�C */
  errCode = tmdlHdmiTxIWSemaphoreP(gI2CSemaphore);
  if(errCode)
  {
    return errCode;
  }

  errCode = Read_at_i2c(type_register, pSysArgs->firstRegister, pSysArgs->lenData, pSysArgs->pData);
  if(errCode)
  {
    /* Release the semaphore if an error is detected */
    tmdlHdmiTxIWSemaphoreV(gI2CSemaphore);
    return errCode;
  }

  /* Release the semaphore for I�C */
  errCode = tmdlHdmiTxIWSemaphoreV(gI2CSemaphore);
  if(errCode)
  {
    return errCode;
  }
  
  return errCode;
}



/********************************************/
/*          i2cReadEdid                     */
/*                                          */
/*  For TDA 9983 only !!!!                  */
/*                                          */
/* Write segment pointer, repeated start,   */
/* write word offset, repeated start,       */
/* read no. bytes requested, stop.          */
/********************************************/
unsigned char i2cReadEdid(unsigned char seg_addr, unsigned char seg_ptr, unsigned char data_addr, unsigned char word_offset,
                                unsigned char nb_char, unsigned char *ptr)
{
   //unsigned char i;
   //tmErrorCode_t errCode;

   HDMI_I2C_LOG("hdmi, %s\n", __func__);
#if 0
   /* Take the semaphore for I�C */
   errCode = tmdlHdmiTxIWSemaphoreP(gI2CSemaphore);
   if(errCode)
   {
     return errCode;
   }

   pt_mtd[2] = &seg_ptr;
   pt_mtd[1] = &word_offset;
   pt_mrd[0] = ptr;
   nb_byte[2] = 1;                  /* Single byte for Segment pointer */
   nb_byte[1] = 1;                  /* Single byte for Word offset */
   nb_byte[0] = nb_char;                /* Number of EDID bytes to read */
   slave[2] = seg_addr  & 0xFE;             /* SLA + W, segment pointer */
   slave[1] = data_addr & 0xFE;             /* SLA + W, data pointer */
   slave[0] = data_addr | 0x01;             /* SLA + R, data pointer */
   if(seg_addr == 0)                    /* If segptr address invalid, skip the segptr write - allows for quick block 0/1 reads */
   {
        rep_start_cntr = 1;         /* One repeated start. 1=Write word offset, 0=Read data */
   }
   else
   {
    rep_start_cntr = 2;             /* Two repeated starts. 2=Write segptr, 1=Write word offset, 0=Read data */
   }


   transmission = INIT;
   I2CONSET = 0x20;                         /* Start transmission */
   while (transmission == INIT) i++;        /* Wait free bus */
   while (transmission == START) i++;       /* Wait end of transmission */

   /* Release the semaphore for I�C */
   errCode = tmdlHdmiTxIWSemaphoreV(gI2CSemaphore);
   if(errCode)
   {
     return errCode;
   }
   #endif

   return (transmission);
}

