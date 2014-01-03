/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   sensor.c
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 *   Source code of Sensor driver
 *
 *
 * Author:
 * -------
 *   PC Huang (MTK02204)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 *
 * 10 13 2010 sean.cheng
 * [ALPS00021684] [Need Patch] [Volunteer Patch] CCT new feature
 * .
 *
 * 09 10 2010 jackie.su
 * [ALPS00002279] [Need Patch] [Volunteer Patch] ALPS.Wxx.xx Volunteer patch for
 * .10y dual sensor
 *
 * 09 02 2010 jackie.su
 * [ALPS00002279] [Need Patch] [Volunteer Patch] ALPS.Wxx.xx Volunteer patch for
 * .roll back dual sensor
 *
 * 07 27 2010 sean.cheng
 * [ALPS00003112] [Need Patch] [Volunteer Patch] ISP/Sensor driver modification for Customer support
 * .1. add master clock switcher 
 *  2. add master enable/disable 
 *  3. add dummy line/pixel for sensor 
 *  4. add sensor driving current setting
 *
 * 07 01 2010 sean.cheng
 * [ALPS00121215][Camera] Change color when switch low and high 
 * .Add video delay frame.
 *
 * 07 01 2010 sean.cheng
 * [ALPS00002805][Need Patch] [Volunteer Patch]10X Patch for DS269 Video Frame Rate 
 * .Change the sensor clock to let frame rate to be 30fps in vidoe mode
 *
 * 06 13 2010 sean.cheng
 * [ALPS00002514][Need Patch] [Volunteer Patch] ALPS.10X.W10.11 Volunteer patch for E1k Camera 
 * .
 * 1. Add set zoom factor and capdelay frame for YUV sensor 
 * 2. Modify e1k sensor setting
 *
 * 05 25 2010 sean.cheng
 * [ALPS00002250][Need Patch] [Volunteer Patch] ALPS.10X.W10.11 Volunteer patch for YUV video frame rate 
 * .
 * Add 15fps option for video mode
 *
 * 05 03 2010 sean.cheng
 * [ALPS00001357][Meta]CameraTool 
 * .
 * Fix OV2659 YUV sensor frame rate to 30fps in vidoe mode
 *
 * Mar 4 2010 mtk70508
 * [DUMA00154792] Sensor driver
 * 
 *
 * Mar 4 2010 mtk70508
 * [DUMA00154792] Sensor driver
 * 
 *
 * Mar 1 2010 mtk01118
 * [DUMA00025869] [Camera][YUV I/F & Query feature] check in camera code
 * 
 *
 * Feb 24 2010 mtk01118
 * [DUMA00025869] [Camera][YUV I/F & Query feature] check in camera code
 * 
 *
 * Nov 24 2009 mtk02204
 * [DUMA00015869] [Camera Driver] Modifiy camera related drivers for dual/backup sensor/lens drivers.
 * 
 *
 * Oct 29 2009 mtk02204
 * [DUMA00015869] [Camera Driver] Modifiy camera related drivers for dual/backup sensor/lens drivers.
 * 
 *
 * Oct 27 2009 mtk02204
 * [DUMA00015869] [Camera Driver] Modifiy camera related drivers for dual/backup sensor/lens drivers.
 * 
 *
 * Aug 13 2009 mtk01051
 * [DUMA00009217] [Camera Driver] CCAP First Check In
 * 
 *
 * Aug 5 2009 mtk01051
 * [DUMA00009217] [Camera Driver] CCAP First Check In
 * 
 *
 * Jul 17 2009 mtk01051
 * [DUMA00009217] [Camera Driver] CCAP First Check In
 * 
 *
 * Jul 7 2009 mtk01051
 * [DUMA00008051] [Camera Driver] Add drivers for camera high ISO binning mode.
 * Add ISO query info for Sensor
 *
 * May 18 2009 mtk01051
 * [DUMA00005921] [Camera] LED Flashlight first check in
 * 
 *
 * May 16 2009 mtk01051
 * [DUMA00005921] [Camera] LED Flashlight first check in
 * 
 *
 * May 16 2009 mtk01051
 * [DUMA00005921] [Camera] LED Flashlight first check in
 * 
 *
 * Apr 7 2009 mtk02204
 * [DUMA00004012] [Camera] Restructure and rename camera related custom folders and folder name of came
 * 
 *
 * Mar 27 2009 mtk02204
 * [DUMA00002977] [CCT] First check in of MT6516 CCT drivers
 *
 *
 * Mar 25 2009 mtk02204
 * [DUMA00111570] [Camera] The system crash after some operations
 *
 *
 * Mar 20 2009 mtk02204
 * [DUMA00002977] [CCT] First check in of MT6516 CCT drivers
 *
 *
 * Mar 2 2009 mtk02204
 * [DUMA00001084] First Check in of MT6516 multimedia drivers
 *
 *
 * Feb 24 2009 mtk02204
 * [DUMA00001084] First Check in of MT6516 multimedia drivers
 *
 *
 * Dec 27 2008 MTK01813
 * DUMA_MBJ CheckIn Files
 * created by clearfsimport
 *
 * Dec 10 2008 mtk02204
 * [DUMA00001084] First Check in of MT6516 multimedia drivers
 *
 *
 * Oct 27 2008 mtk01051
 * [DUMA00000851] Camera related drivers check in
 * Modify Copyright Header
 *
 * Oct 24 2008 mtk02204
 * [DUMA00000851] Camera related drivers check in
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>
#include <asm/io.h>
#include <asm/system.h>
	 
#include "kd_camera_hw.h"
#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_imgsensor_errcode.h"
#include "kd_camera_feature.h"
	 
#include "ov2659yuv_Sensor.h"
#include "ov2659yuv_Camera_Sensor_para.h"
#include "ov2659yuv_CameraCustomized.h" 


#define OV2659YUV_DEBUG
#ifdef OV2659YUV_DEBUG
#define OV2659SENSORDB printk
#else
#define OV2659SENSORDB(x,...)
#endif
static DEFINE_SPINLOCK(ov2659_drv_lock);

MSDK_SCENARIO_ID_ENUM OV2659CurrentScenarioId = MSDK_SCENARIO_ID_CAMERA_PREVIEW;

extern int iReadReg(u16 a_u2Addr , u8 * a_puBuff , u16 i2cId);
extern int iWriteReg(u16 a_u2Addr , u32 a_u4Data , u32 a_u4Bytes , u16 i2cId);

#define OV2659_write_cmos_sensor(addr, para) iWriteReg((u16) addr , (u32) para ,1,OV2659_WRITE_ID)
kal_uint16 OV2659_read_cmos_sensor(kal_uint32 addr)
{
	kal_uint16 get_byte=0;
    iReadReg((u16) addr ,(u8*)&get_byte,OV2659_WRITE_ID);
    
    return get_byte;
}

#define mDELAY(ms)  msleep(ms)

static struct
{
	kal_uint8   Banding;
	kal_bool	NightMode;
	kal_bool	VideoMode;
	kal_uint16  Fps;
	kal_uint16  ShutterStep;
	kal_uint8   IsPVmode;
	kal_uint32  PreviewDummyPixels;
	kal_uint32  PreviewDummyLines;
	kal_uint32  CaptureDummyPixels;
	kal_uint32  CaptureDummyLines;
	kal_uint32  PreviewPclk;
	kal_uint32  CapturePclk;
	kal_uint32  PreviewShutter;
	kal_uint32  PreviewExtraShutter;
	kal_uint32  SensorGain;
	kal_uint32  SensorShutter;	
	kal_uint32  WhiteBalance;
	OV2659_SENSOR_MODE SensorMode;
} OV2659Sensor;

/* Global Valuable */

static kal_uint32 zoom_factor = 0; 

static kal_int8 OV2659_DELAY_AFTER_PREVIEW = -1;

static kal_uint8 OV2659_Banding_setting = AE_FLICKER_MODE_50HZ;  //Wonder add

static kal_bool OV2659_AWB_ENABLE = KAL_TRUE; 
static kal_bool OV2659_AE_ENABLE = KAL_TRUE; 

//SENSOR_REG_STRUCT OV2659SensorCCT[FACTORY_END_ADDR]=CAMERA_SENSOR_CCT_DEFAULT_VALUE;
//SENSOR_REG_STRUCT OV2659SensorReg[ENGINEER_END]=CAMERA_SENSOR_REG_DEFAULT_VALUE;
//	camera_para.SENSOR.cct	SensorCCT	=> SensorCCT
//	camera_para.SENSOR.reg	SensorReg
MSDK_SENSOR_CONFIG_STRUCT OV2659SensorConfigData;

//BEGIN <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou
BOOL OV2659_set_param_banding(UINT16 para);//LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
BOOL OV2659_set_param_effect(UINT16 para);
BOOL OV2659_set_param_wb(UINT16 para);
void OV2659_night_mode(kal_bool enable);
BOOL OV2659_set_param_exposure(UINT16 para);

UINT16 effect_para = MEFFECT_OFF;
UINT16 banding_para = AE_FLICKER_MODE_50HZ;
UINT16 wb_para = AWB_MODE_AUTO;
UINT16 mode_para = KAL_FALSE;
UINT16 exposure_para = AE_EV_COMP_00;


void OV2659_set_param()
{
    OV2659_set_param_banding(banding_para);//LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
    OV2659_set_param_wb(wb_para);
    OV2659_night_mode(mode_para); 
    OV2659_set_param_exposure(exposure_para);
    OV2659_set_param_effect(effect_para);

}
//END <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou

/*************************************************************************
* FUNCTION
*	OV2659_set_dummy
*
* DESCRIPTION
*	This function set the dummy pixels(Horizontal Blanking) & dummy lines(Vertical Blanking), it can be
*	used to adjust the frame rate or gain more time for back-end process.
*	
*	IMPORTANT NOTICE: the base shutter need re-calculate for some sensor, or else flicker may occur.
*
* PARAMETERS
*	1. kal_uint32 : Dummy Pixels (Horizontal Blanking)
*	2. kal_uint32 : Dummy Lines (Vertical Blanking)
*
* RETURNS
*	None
*
*************************************************************************/
static void OV2659SetDummy(kal_uint32 dummy_pixels, kal_uint32 dummy_lines)
{
	if (OV2659Sensor.IsPVmode)  
	{
		dummy_pixels = dummy_pixels+0x0514; 
		OV2659_write_cmos_sensor(0x380D,( dummy_pixels&0xFF));         
		OV2659_write_cmos_sensor(0x380C,(( dummy_pixels&0xFF00)>>8)); 

		dummy_lines= dummy_lines+0x02de; //268
		OV2659_write_cmos_sensor(0x380F,(dummy_lines&0xFF));       
		OV2659_write_cmos_sensor(0x380E,((dummy_lines&0xFF00)>>8));  
	}
	else
	{
		dummy_pixels = dummy_pixels+0x079f; 
		OV2659_write_cmos_sensor(0x380D,( dummy_pixels&0xFF));         
		OV2659_write_cmos_sensor(0x380C,(( dummy_pixels&0xFF00)>>8)); 

		dummy_lines= dummy_lines*2+0x04d0; 
		OV2659_write_cmos_sensor(0x380F,(dummy_lines&0xFF));       
		OV2659_write_cmos_sensor(0x380E,((dummy_lines&0xFF00)>>8));  
	}	
}    /* OV2659_set_dummy */

/*************************************************************************
* FUNCTION
*	OV2659WriteShutter
*
* DESCRIPTION
*	This function used to write the shutter.
*
* PARAMETERS
*	1. kal_uint32 : The shutter want to apply to sensor.
*
* RETURNS
*	None
*
*************************************************************************/
static void OV2659WriteShutter(kal_uint32 shutter)
{
	kal_uint32 extra_exposure_lines = 0;
	if (shutter < 1)
	{
		shutter = 1;
	}

	if (OV2659Sensor.IsPVmode) 
	{
		if (shutter <= OV2659_PV_EXPOSURE_LIMITATION) 
		{
			extra_exposure_lines = 0;
		}
		else 
		{
			extra_exposure_lines=shutter - OV2659_PV_EXPOSURE_LIMITATION;
		}

	}
	else 
	{
		if (shutter <= OV2659_FULL_EXPOSURE_LIMITATION) 
		{
			extra_exposure_lines = 0;
		}
		else 
		{
			extra_exposure_lines = shutter - OV2659_FULL_EXPOSURE_LIMITATION;
		}

	}

	//AEC PK EXPOSURE
	shutter*=16;
	OV2659_write_cmos_sensor(0x3502, (shutter & 0x00FF));           //AEC[7:0]
	OV2659_write_cmos_sensor(0x3501, ((shutter & 0x0FF00) >>8));  //AEC[15:8]
	OV2659_write_cmos_sensor(0x3500, ((shutter & 0xFF0000) >> 16));	

	// set extra exposure line [aec add vts]
	OV2659_write_cmos_sensor(0x3507, extra_exposure_lines & 0xFF);          // EXVTS[b7~b0]
	OV2659_write_cmos_sensor(0x3506, (extra_exposure_lines & 0xFF00) >> 8); // EXVTS[b15~b8]
	
}    /* OV2659_write_shutter */

/*************************************************************************
* FUNCTION
*	OV2659WriteWensorGain
*
* DESCRIPTION
*	This function used to write the sensor gain.
*
* PARAMETERS
*	1. kal_uint32 : The sensor gain want to apply to sensor.
*
* RETURNS
*	None
*
*************************************************************************/
static void OV2659WriteSensorGain(kal_uint32 gain)
{
	kal_uint16 temp_reg = 0;

	if(gain > 1024)  ASSERT(0);
	temp_reg = 0;

	temp_reg=gain&0x0FF;	
	OV2659_write_cmos_sensor(0x350B,temp_reg);
}  /* OV2659_write_sensor_gain */

/*************************************************************************
* FUNCTION
*	OV2659ReadShutter
*
* DESCRIPTION
*	This function read current shutter for calculate the exposure.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint16 : The current shutter value.
*
*************************************************************************/
static kal_uint32 OV2659ReadShutter(void)
{
	kal_uint16 temp_reg1, temp_reg2 ,temp_reg3;
	temp_reg1 = OV2659_read_cmos_sensor(0x3500);    // AEC[b19~b16]
	temp_reg2 = OV2659_read_cmos_sensor(0x3501);    // AEC[b15~b8]
	temp_reg3 = OV2659_read_cmos_sensor(0x3502);    // AEC[b7~b0]
	//read out register value and divide 16;
	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.PreviewShutter  = (temp_reg1 <<12)| (temp_reg2<<4)|(temp_reg3>>4);
	spin_unlock(&ov2659_drv_lock);

	temp_reg1 = OV2659_read_cmos_sensor(0x3506);    // EXVTS[b15~b8]
	temp_reg2 = OV2659_read_cmos_sensor(0x3507);    // EXVTS[b7~b0]
	/* Backup the preview mode last shutter & sensor gain. */
	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.PreviewExtraShutter = (temp_reg2 & 0xFF) | (temp_reg1 << 8);
	spin_unlock(&ov2659_drv_lock);

	return OV2659Sensor.PreviewShutter;
}    /* OV2659_read_shutter */

/*************************************************************************
* FUNCTION
*	OV2659ReadSensorGain
*
* DESCRIPTION
*	This function read current sensor gain for calculate the exposure.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint16 : The current sensor gain value.
*
*************************************************************************/
static kal_uint32 OV2659ReadSensorGain(void)
{
	kal_uint16 temp_reg = 0;
	kal_uint32 sensor_gain = 0;
	sensor_gain=(OV2659_read_cmos_sensor(0x350B)&0xFF);//+((OV2659_read_cmos_sensor(0x350A)&0xFF<<8)&0xFF00);  

	return sensor_gain;

}  /* OV2659ReadSensorGain */


static void OV2659_set_AE_mode(kal_bool AE_enable)
{
	kal_uint8 AeTemp;
	AeTemp = OV2659_read_cmos_sensor(0x3503);

	if (AE_enable == KAL_TRUE)
	{
		// turn on AEC/AGC
		OV2659_write_cmos_sensor(0x3503, (AeTemp&(~0x07)));
	}
	else
	{
		// turn off AEC/AGC
		OV2659_write_cmos_sensor(0x3503, (AeTemp| 0x07));
	}
}

static void OV2659_set_AWB_mode(kal_bool AWB_enable)
{
	OV2659SENSORDB("MINGJI test func calling OV2659_set_AWB_mode()\n");
	kal_uint8 AwbTemp;
	AwbTemp = OV2659_read_cmos_sensor(0x3406);

	//return ;

	if (AWB_enable == KAL_TRUE)
	{
		//enable Auto WB
		OV2659_write_cmos_sensor(0x3406 , AwbTemp&0xFE ); 
	}
	else
	{
		//turn off AWB
		OV2659_write_cmos_sensor(0x3406 , AwbTemp|0x01 ); 
	}
}

/*************************************************************************
* FUNCTION
*	OV2659_night_mode
*
* DESCRIPTION
*	This function night mode of OV2659.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void OV2659_night_mode(kal_bool enable)
{
	OV2659SENSORDB("MINGJI test func calling OV2659_night_mode()\n");
	kal_uint16 night = OV2659_read_cmos_sensor(0x3A00); 
	
	printk("[OV2659_night_mode0]flip :%x   \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659_night_mode0]mirror :%x   \n",OV2659_read_cmos_sensor(0x3821));
	
	if (enable)
	{ 
		/* camera night mode */
		OV2659_write_cmos_sensor(0x3A00,night|0x04); // 1/8
		OV2659_write_cmos_sensor(0x3a02,0x0b);//13 
		OV2659_write_cmos_sensor(0x3a03,0x78);//40                         
		OV2659_write_cmos_sensor(0x3a14,0x0b);//13 
		OV2659_write_cmos_sensor(0x3a15,0x78);//40   
	
/*		//gamma to improve nightmode noise
		OV2659_write_cmos_sensor(0x5025,0x12);
		OV2659_write_cmos_sensor(0x5026,0x1a);
		OV2659_write_cmos_sensor(0x5027,0x2e);
		OV2659_write_cmos_sensor(0x5028,0x42);
		OV2659_write_cmos_sensor(0x5029,0x52);
		OV2659_write_cmos_sensor(0x502a,0x60);	
		OV2659_write_cmos_sensor(0x502b,0x70);
		OV2659_write_cmos_sensor(0x502c,0x7c);
		OV2659_write_cmos_sensor(0x502d,0x8a);
		OV2659_write_cmos_sensor(0x502e,0xa8);
		OV2659_write_cmos_sensor(0x502f,0xb8);
		OV2659_write_cmos_sensor(0x5030,0xc7);
		OV2659_write_cmos_sensor(0x5031,0xdd);
		OV2659_write_cmos_sensor(0x5032,0xee);
		OV2659_write_cmos_sensor(0x5033,0xf6);
		OV2659_write_cmos_sensor(0x5034,0x0d);
*/      
	}
	else
	{   /* camera normal mode */
		OV2659_write_cmos_sensor(0x3A00,night|0x04); // 1/3               
		OV2659_write_cmos_sensor(0x3a02,0x02); //07 09 0x05
		OV2659_write_cmos_sensor(0x3a03,0xde); //38 a0 0xbc
		OV2659_write_cmos_sensor(0x3a14,0x02); //07 09 0x05
		OV2659_write_cmos_sensor(0x3a15,0xde); //38 a0 0xbc
	}
	
	printk("[OV2659_night_mode1]flip :%x   \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659_night_mode1]mirror :%x   \n",OV2659_read_cmos_sensor(0x3821));
}	/* OV2659_night_mode */

/*************************************************************************
* FUNCTION
*	OV2659_GetSensorID
*
* DESCRIPTION
*	This function get the sensor ID
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 OV2659_GetSensorID(kal_uint32 *sensorID)
{
	volatile signed char i;
	kal_uint32 sensor_id=0;
	kal_uint8 temp_sccb_addr = 0;
	//s_move to here from CISModulePowerOn()

	OV2659_write_cmos_sensor(0x0103,0x01);// Reset sensor
	mDELAY(10);


	//  Read sensor ID to adjust I2C is OK?
	for(i=0;i<3;i++)
	{
		sensor_id = (OV2659_read_cmos_sensor(0x300A) << 8) | OV2659_read_cmos_sensor(0x300B);
		OV2659SENSORDB("OV2659 READ ID: %x",sensor_id);
		if(sensor_id != OV2659_SENSOR_ID)
		{	
			*sensorID =0xffffffff;
			return ERROR_SENSOR_CONNECT_FAIL;
		}
	}
	
    return ERROR_NONE;    
}   

/*************************************************************************
* FUNCTION
*    OV2659InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659InitialSetting(void)
{
	OV2659SENSORDB("MINGJI test func calling OV2659InitialSetting()\n");

	OV2659_write_cmos_sensor(0x3000,0x0f); 
	OV2659_write_cmos_sensor(0x3001,0xff); 
	OV2659_write_cmos_sensor(0x3002,0xff); 
	OV2659_write_cmos_sensor(0x0100,0x01); 
	OV2659_write_cmos_sensor(0x3633,0x3d); 
	OV2659_write_cmos_sensor(0x3620,0x02); 
	OV2659_write_cmos_sensor(0x3631,0x11); 
	OV2659_write_cmos_sensor(0x3612,0x04); 
	OV2659_write_cmos_sensor(0x3630,0x20); 
	OV2659_write_cmos_sensor(0x4702,0x02); 
	OV2659_write_cmos_sensor(0x370c,0x34); 

	OV2659_write_cmos_sensor(0x4003,0x88); 

	//window setup                         
	OV2659_write_cmos_sensor(0x3800,0x00); 
	OV2659_write_cmos_sensor(0x3801,0x00); 
	OV2659_write_cmos_sensor(0x3802,0x00); 
	OV2659_write_cmos_sensor(0x3803,0x00); 
	OV2659_write_cmos_sensor(0x3804,0x06); 
	OV2659_write_cmos_sensor(0x3805,0x5f); 
	OV2659_write_cmos_sensor(0x3806,0x04); 
	OV2659_write_cmos_sensor(0x3807,0xb7); 
	OV2659_write_cmos_sensor(0x3808,0x03); 
	OV2659_write_cmos_sensor(0x3809,0x20); 
	OV2659_write_cmos_sensor(0x380a,0x02); 
	OV2659_write_cmos_sensor(0x380b,0x58); 
	OV2659_write_cmos_sensor(0x3811,0x08); 
	OV2659_write_cmos_sensor(0x3813,0x02); 
	OV2659_write_cmos_sensor(0x3814,0x31); 
	OV2659_write_cmos_sensor(0x3815,0x31);

	OV2659_write_cmos_sensor(0x3820,0x81); 
	OV2659_write_cmos_sensor(0x3821,0x01); 
	OV2659_write_cmos_sensor(0x5002,0x10);
	OV2659_write_cmos_sensor(0x4608,0x00); 
	OV2659_write_cmos_sensor(0x4609,0xa0);  

	OV2659_write_cmos_sensor(0x3623,0x00); 
	OV2659_write_cmos_sensor(0x3634,0x76); 
	OV2659_write_cmos_sensor(0x3701,0x44); 

	//define group 1 for preview 
	OV2659_write_cmos_sensor(0x3208,0x01);//enable group 1 
	OV2659_write_cmos_sensor(0x3702,0x18); 
	OV2659_write_cmos_sensor(0x3703,0x24); 
	OV2659_write_cmos_sensor(0x3704,0x24); 
	OV2659_write_cmos_sensor(0x3208,0x11);//end group 1 

	//define group 2 for capture 
	OV2659_write_cmos_sensor(0x3208,0x02);//enable group 2 
	OV2659_write_cmos_sensor(0x3702,0x30); 
	OV2659_write_cmos_sensor(0x3703,0x48); 
	OV2659_write_cmos_sensor(0x3704,0x48); 
	OV2659_write_cmos_sensor(0x3208,0x12);//end group 2 

	OV2659_write_cmos_sensor(0x3705,0x0c); 
	OV2659_write_cmos_sensor(0x370a,0x52); 

	//pclk setting 
	OV2659_write_cmos_sensor(0x3003,0x80);//30fps 26mclk 
	OV2659_write_cmos_sensor(0x3004,0x10); 
	OV2659_write_cmos_sensor(0x3005,0x16); 
	OV2659_write_cmos_sensor(0x3006,0x0d); 
	//dummy lines&dummy pixels 
	OV2659_write_cmos_sensor(0x380c,0x05); 
	OV2659_write_cmos_sensor(0x380d,0x14); 
	OV2659_write_cmos_sensor(0x380e,0x02); 
	OV2659_write_cmos_sensor(0x380f,0xde); //68
	//banding                           
	OV2659_write_cmos_sensor(0x3a05,0x30);//bit[7]='0',50hz;bit[7]='1',60hz                     
	OV2659_write_cmos_sensor(0x3a08,0x00); 
	OV2659_write_cmos_sensor(0x3a09,0xb9); 
	OV2659_write_cmos_sensor(0x3a0e,0x03); 
	OV2659_write_cmos_sensor(0x3a0a,0x00); 
	OV2659_write_cmos_sensor(0x3a0b,0x9a); 
	OV2659_write_cmos_sensor(0x3a0d,0x04);          

	OV2659_write_cmos_sensor(0x3a00,0x38); 
	OV2659_write_cmos_sensor(0x3a02,0x02); 
	OV2659_write_cmos_sensor(0x3a03,0x28); 
	OV2659_write_cmos_sensor(0x3a14,0x02); 
	OV2659_write_cmos_sensor(0x3a15,0x68);    

	OV2659_write_cmos_sensor(0x350c,0x00); 
	OV2659_write_cmos_sensor(0x350d,0x00); 
	OV2659_write_cmos_sensor(0x4300,0x30); //YUYV
	OV2659_write_cmos_sensor(0x5086,0x02); 

	OV2659_write_cmos_sensor(0x5000,0xff); 
	OV2659_write_cmos_sensor(0x5001,0x1f); 
	OV2659_write_cmos_sensor(0x507e,0x32);//saturation 
	OV2659_write_cmos_sensor(0x507f,0x10); 
	OV2659_write_cmos_sensor(0x507c,0x80); 
	OV2659_write_cmos_sensor(0x507d,0x00);         
	OV2659_write_cmos_sensor(0x507b,0x06);          
	//gamma-Ken
	#if 1
    OV2659_write_cmos_sensor(0x5025,0x0d); 
	OV2659_write_cmos_sensor(0x5026,0x1c); 
	OV2659_write_cmos_sensor(0x5027,0x32); 
	OV2659_write_cmos_sensor(0x5028,0x46); 
	OV2659_write_cmos_sensor(0x5029,0x57); 
	OV2659_write_cmos_sensor(0x502a,0x69);         
	OV2659_write_cmos_sensor(0x502b,0x78); 
	OV2659_write_cmos_sensor(0x502c,0x84); 
	OV2659_write_cmos_sensor(0x502d,0x90); 
	OV2659_write_cmos_sensor(0x502e,0xa6); 
	OV2659_write_cmos_sensor(0x502f,0xb8); 
	OV2659_write_cmos_sensor(0x5030,0xc7); 
	OV2659_write_cmos_sensor(0x5031,0xdd); 
	OV2659_write_cmos_sensor(0x5032,0xee); 
	OV2659_write_cmos_sensor(0x5033,0xf6); 
	OV2659_write_cmos_sensor(0x5034,0x0d); 
    #else
    OV2659_write_cmos_sensor(0x5025,0x08); 
	OV2659_write_cmos_sensor(0x5026,0x13); 
	OV2659_write_cmos_sensor(0x5027,0x24); 
	OV2659_write_cmos_sensor(0x5028,0x37); 
	OV2659_write_cmos_sensor(0x5029,0x4a); 
	OV2659_write_cmos_sensor(0x502a,0x60);         
	OV2659_write_cmos_sensor(0x502b,0x72); 
	OV2659_write_cmos_sensor(0x502c,0x80); 
	OV2659_write_cmos_sensor(0x502d,0x90); 
	OV2659_write_cmos_sensor(0x502e,0xa6); 
	OV2659_write_cmos_sensor(0x502f,0xb5); 
	OV2659_write_cmos_sensor(0x5030,0xc4); 
	OV2659_write_cmos_sensor(0x5031,0xda); 
	OV2659_write_cmos_sensor(0x5032,0xe4); 
	OV2659_write_cmos_sensor(0x5033,0xed); 
	OV2659_write_cmos_sensor(0x5034,0x0d); 
    #endif
	//color matrix  

#if 1                       
/*	OV2659_write_cmos_sensor(0x5070,0x28); 
	OV2659_write_cmos_sensor(0x5071,0x48); 
	OV2659_write_cmos_sensor(0x5072,0x10); 
	OV2659_write_cmos_sensor(0x5073,0x1b); 
	OV2659_write_cmos_sensor(0x5074,0xd0); 
	OV2659_write_cmos_sensor(0x5075,0xeb); 
	OV2659_write_cmos_sensor(0x5076,0xeb); 
	OV2659_write_cmos_sensor(0x5077,0xe0); 
	OV2659_write_cmos_sensor(0x5078,0x0b); 
	OV2659_write_cmos_sensor(0x5079,0x98); 
	OV2659_write_cmos_sensor(0x507a,0x01);*/

	OV2659_write_cmos_sensor(0x5070,0x30); 
	OV2659_write_cmos_sensor(0x5071,0x27); 
	OV2659_write_cmos_sensor(0x5072,0x26); 
	OV2659_write_cmos_sensor(0x5073,0x1f); 
	OV2659_write_cmos_sensor(0x5074,0xbd); 
	OV2659_write_cmos_sensor(0x5075,0xdd); 
	OV2659_write_cmos_sensor(0x5076,0xcd); 
	OV2659_write_cmos_sensor(0x5077,0xba); //0xbe 2012-11-14 0xdb 
	OV2659_write_cmos_sensor(0x5078,0x10); 
	OV2659_write_cmos_sensor(0x5079,0x98); 
	OV2659_write_cmos_sensor(0x507a,0x01);
#else
	OV2659_write_cmos_sensor(0x5070,0x27); 
	OV2659_write_cmos_sensor(0x5071,0x3a); 
	OV2659_write_cmos_sensor(0x5072,0x1d); 
	OV2659_write_cmos_sensor(0x5073,0x1b); 
	OV2659_write_cmos_sensor(0x5074,0xc8); 
	OV2659_write_cmos_sensor(0x5075,0xe3); 
	OV2659_write_cmos_sensor(0x5076,0xd5); 
	OV2659_write_cmos_sensor(0x5077,0xcb); 
	OV2659_write_cmos_sensor(0x5078,0x04); 
	OV2659_write_cmos_sensor(0x5079,0x98); 
	OV2659_write_cmos_sensor(0x507a,0x01); 
#endif

#if 0   
         //awb  --largan lens
	/*OV2659_write_cmos_sensor(0x5035,0x6A); 
	OV2659_write_cmos_sensor(0x5036,0x11); 
	OV2659_write_cmos_sensor(0x5037,0x92); 
	OV2659_write_cmos_sensor(0x5038,0x25); 
	OV2659_write_cmos_sensor(0x5039,0xe1); 
	OV2659_write_cmos_sensor(0x503a,0x01); 
	OV2659_write_cmos_sensor(0x503c,0x0b); 
	OV2659_write_cmos_sensor(0x503d,0x0d); 
	OV2659_write_cmos_sensor(0x503e,0x0f); 
	OV2659_write_cmos_sensor(0x503f,0x73);//54   green-blue
	OV2659_write_cmos_sensor(0x5040,0x51);//51
	OV2659_write_cmos_sensor(0x5041,0x45); 
	OV2659_write_cmos_sensor(0x5042,0x9a); 
	OV2659_write_cmos_sensor(0x5043,0x39); 
	OV2659_write_cmos_sensor(0x5044,0x27);//50
	OV2659_write_cmos_sensor(0x5045,0x52); 
	OV2659_write_cmos_sensor(0x5046,0x46);//40
	OV2659_write_cmos_sensor(0x5047,0xf8); 
	OV2659_write_cmos_sensor(0x5048,0x08); 
	OV2659_write_cmos_sensor(0x5049,0x70); 
	OV2659_write_cmos_sensor(0x504a,0xf0); 
	OV2659_write_cmos_sensor(0x504b,0xf0);*/

	OV2659_write_cmos_sensor(0x5035,0x6A); 
	OV2659_write_cmos_sensor(0x5036,0x11); 
	OV2659_write_cmos_sensor(0x5037,0x92); 
	OV2659_write_cmos_sensor(0x5038,0x21); 
	OV2659_write_cmos_sensor(0x5039,0xe1); 
	OV2659_write_cmos_sensor(0x503a,0x01); 
	OV2659_write_cmos_sensor(0x503c,0x10); 
	OV2659_write_cmos_sensor(0x503d,0x16); 
	OV2659_write_cmos_sensor(0x503e,0x08); 
	OV2659_write_cmos_sensor(0x503f,0x58);
	OV2659_write_cmos_sensor(0x5040,0x62); 
	OV2659_write_cmos_sensor(0x5041,0x0e); 
	OV2659_write_cmos_sensor(0x5042,0x9c); 
	OV2659_write_cmos_sensor(0x5043,0x20); 
	OV2659_write_cmos_sensor(0x5044,0x30); 
	OV2659_write_cmos_sensor(0x5045,0x22); 
	OV2659_write_cmos_sensor(0x5046,0x32); 
	OV2659_write_cmos_sensor(0x5047,0xf8); 
	OV2659_write_cmos_sensor(0x5048,0x08); 
	OV2659_write_cmos_sensor(0x5049,0x70); 
	OV2659_write_cmos_sensor(0x504a,0xf0); 
	OV2659_write_cmos_sensor(0x504b,0xf0);  
#else
	//awb  --normal                         
	OV2659_write_cmos_sensor(0x5035,0x6A); 
	OV2659_write_cmos_sensor(0x5036,0x11); 
	OV2659_write_cmos_sensor(0x5037,0x92); 
	OV2659_write_cmos_sensor(0x5038,0x25); 
	OV2659_write_cmos_sensor(0x5039,0xe1); 
	OV2659_write_cmos_sensor(0x503a,0x01); 
	OV2659_write_cmos_sensor(0x503c,0x11); 
	OV2659_write_cmos_sensor(0x503d,0x10); //0x20
	OV2659_write_cmos_sensor(0x503e,0x10); //0x10
	OV2659_write_cmos_sensor(0x503f,0x63);//54   green-blue 0x63 //0x5a 2012-11-08 63
	OV2659_write_cmos_sensor(0x5040,0x51);//51 54
	OV2659_write_cmos_sensor(0x5041,0x0e);//0x0e 
	OV2659_write_cmos_sensor(0x5042,0xa0);//0x9c 
	OV2659_write_cmos_sensor(0x5043,0x49);//0x20 0x39
	OV2659_write_cmos_sensor(0x5044,0x34);//50
	OV2659_write_cmos_sensor(0x5045,0x22); 
	OV2659_write_cmos_sensor(0x5046,0x3f);//40
	OV2659_write_cmos_sensor(0x5047,0xf8); 
	OV2659_write_cmos_sensor(0x5048,0x08); 
	OV2659_write_cmos_sensor(0x5049,0x70); 
	OV2659_write_cmos_sensor(0x504a,0xf0); 
	OV2659_write_cmos_sensor(0x504b,0xf0);
#endif      
   
#if 0
        //lens shading  --largan lens                       
	OV2659_write_cmos_sensor(0x500c,0x03); 
	OV2659_write_cmos_sensor(0x500d,0x20); 
	OV2659_write_cmos_sensor(0x500e,0x02); 
	OV2659_write_cmos_sensor(0x500f,0x5c);         
	OV2659_write_cmos_sensor(0x5010,0x5e); 
	OV2659_write_cmos_sensor(0x5011,0x18); 
	OV2659_write_cmos_sensor(0x5012,0x66); 
	OV2659_write_cmos_sensor(0x5013,0x03); 
	OV2659_write_cmos_sensor(0x5014,0x24); 
	OV2659_write_cmos_sensor(0x5015,0x02); 
	OV2659_write_cmos_sensor(0x5016,0x60); 
	OV2659_write_cmos_sensor(0x5017,0x55); 
	OV2659_write_cmos_sensor(0x5018,0x10); 
	OV2659_write_cmos_sensor(0x5019,0x66); 
	OV2659_write_cmos_sensor(0x501a,0x03); 
	OV2659_write_cmos_sensor(0x501b,0x1c); 
	OV2659_write_cmos_sensor(0x501c,0x02); 
	OV2659_write_cmos_sensor(0x501d,0x70); 
	OV2659_write_cmos_sensor(0x501e,0x50); 
	OV2659_write_cmos_sensor(0x501f,0x10); 
	OV2659_write_cmos_sensor(0x5020,0x66); 
#else
	//lens shading  --normal lens
	OV2659_write_cmos_sensor(0x500c,0x03); 
	OV2659_write_cmos_sensor(0x500d,0x32); 
	OV2659_write_cmos_sensor(0x500e,0x02); 
	OV2659_write_cmos_sensor(0x500f,0x64);         
	OV2659_write_cmos_sensor(0x5010,0x47); //5a 56 7-30 0x49
	OV2659_write_cmos_sensor(0x5011,0x18); 
	OV2659_write_cmos_sensor(0x5012,0x66); 
	OV2659_write_cmos_sensor(0x5013,0x03); 
	OV2659_write_cmos_sensor(0x5014,0x24); 
	OV2659_write_cmos_sensor(0x5015,0x02); 
	OV2659_write_cmos_sensor(0x5016,0x60); 
	OV2659_write_cmos_sensor(0x5017,0x41); //58 4c 7-30
	OV2659_write_cmos_sensor(0x5018,0x10); 
	OV2659_write_cmos_sensor(0x5019,0x66); 
	OV2659_write_cmos_sensor(0x501a,0x03); 
	OV2659_write_cmos_sensor(0x501b,0x16); //18
	OV2659_write_cmos_sensor(0x501c,0x02); 
	OV2659_write_cmos_sensor(0x501d,0x68); //50
	OV2659_write_cmos_sensor(0x501e,0x3f); //52 43 7-30
	OV2659_write_cmos_sensor(0x501f,0x10); 
	OV2659_write_cmos_sensor(0x5020,0x66);
#endif
	//sharpness&denoise                         
	OV2659_write_cmos_sensor(0x506e,0x44);
	OV2659_write_cmos_sensor(0x5064,0x08);         
	OV2659_write_cmos_sensor(0x5065,0x10); 
	OV2659_write_cmos_sensor(0x5066,0x16); //0x38        
	OV2659_write_cmos_sensor(0x5067,0x10); //0x28
	OV2659_write_cmos_sensor(0x506c,0x08); 
	OV2659_write_cmos_sensor(0x506d,0x10);         
	OV2659_write_cmos_sensor(0x506f,0xa6);         
	OV2659_write_cmos_sensor(0x5068,0x08); 
	OV2659_write_cmos_sensor(0x5069,0x10);         
	OV2659_write_cmos_sensor(0x506a,0x18); //0x0d
	OV2659_write_cmos_sensor(0x506b,0x28); //0x16

	//uv                         
	OV2659_write_cmos_sensor(0x5084,0x0c);//10 
	OV2659_write_cmos_sensor(0x5085,0x1f);//3         
	OV2659_write_cmos_sensor(0x5005,0x80); 
	//LCD adjust                   
	OV2659_write_cmos_sensor(0x5051,0x40); //40 red 
	OV2659_write_cmos_sensor(0x5052,0x40); 
	OV2659_write_cmos_sensor(0x5053,0x40);  
	//ev 
	OV2659_write_cmos_sensor(0x3a0f,0x34); //40 34
	OV2659_write_cmos_sensor(0x3a10,0x2c); //38 2c
	OV2659_write_cmos_sensor(0x3a11,0x70);
	OV2659_write_cmos_sensor(0x3a1b,0x34); //40 34 
	OV2659_write_cmos_sensor(0x3a1e,0x2c); //38 2c       
	OV2659_write_cmos_sensor(0x3a1f,0x20); 

	OV2659_write_cmos_sensor(0x5060,0x69); 
	OV2659_write_cmos_sensor(0x5061,0xbe); 
	OV2659_write_cmos_sensor(0x5062,0xbe); 
	OV2659_write_cmos_sensor(0x5063,0x69);         
	//gain ceiling 
	OV2659_write_cmos_sensor(0x3a18,0x00); 
	OV2659_write_cmos_sensor(0x3a19,0x38);
	OV2659_write_cmos_sensor(0x4009,0x02);  

	OV2659_write_cmos_sensor(0x3503,0x00);                 

	OV2659_write_cmos_sensor(0x3011,0x82);
	
	printk("[OV2659init]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659init]mirror :%x \n",OV2659_read_cmos_sensor(0x3821));    

	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.IsPVmode= 1;
	OV2659Sensor.PreviewDummyPixels= 0;
	OV2659Sensor.PreviewDummyLines= 0;
	OV2659Sensor.PreviewPclk= 480;
	OV2659Sensor.CapturePclk= 480;
	OV2659Sensor.PreviewShutter=0x0000; //0265
	OV2659Sensor.SensorGain=0x10;
	spin_unlock(&ov2659_drv_lock);
}                                  

/*************************************************************************
* FUNCTION
*    OV2659PreviewSetting
*
* DESCRIPTION
*    This function config Preview setting related registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659PreviewSetting(void)
{
	OV2659SENSORDB("MINGJI test func calling OV2659PreviewSetting()\n");
	OV2659_write_cmos_sensor(0x0103,0x01);
	mDELAY(10); 
	OV2659InitialSetting();
#ifdef OVT_SIM
	OV2659_write_cmos_sensor(0x3004,0x20);
#else
	OV2659_write_cmos_sensor(0x3004,0x10);
#endif
	OV2659_write_cmos_sensor(0x3005,0x16);
	OV2659_write_cmos_sensor(0x3006,0x0f); //0x0d 7-24

	OV2659_write_cmos_sensor(0x3500,((OV2659Sensor.PreviewShutter*16)>>16) & 0XFF);
	OV2659_write_cmos_sensor(0x3501,((OV2659Sensor.PreviewShutter*16)>>8) & 0XFF);
	OV2659_write_cmos_sensor(0x3502,(OV2659Sensor.PreviewShutter*16) & 0XFF);
	OV2659_write_cmos_sensor(0x350B, OV2659Sensor.SensorGain);	

	OV2659_write_cmos_sensor(0x5066,0x28); //26 30 //2012-10-25 0x26
	OV2659_write_cmos_sensor(0x5067,0x20); //20 28 //2012-10-25 0x20
	OV2659_write_cmos_sensor(0x506a,0x18); //18 28
	OV2659_write_cmos_sensor(0x506b,0x28); //28 38
	OV2659_write_cmos_sensor(0x3807, 0xb7);

	//data outputsize(DVP)
	//800x600
	OV2659_write_cmos_sensor(0x3808, 0x03);
	OV2659_write_cmos_sensor(0x3809, 0x20);
	OV2659_write_cmos_sensor(0x380a, 0x02);
	OV2659_write_cmos_sensor(0x380b, 0x58);

	//TIMING HTS and VTS/////?
	//HTS 1300 
	OV2659_write_cmos_sensor(0x380c, 0x05);
	OV2659_write_cmos_sensor(0x380d, 0x14);
	//VTS 616
	OV2659_write_cmos_sensor(0x380e, 0x02);
	OV2659_write_cmos_sensor(0x380f, 0xde);//68

	//Prescaling size
	//H OFFSET 8
	OV2659_write_cmos_sensor(0x3811, 0x08);
	//V OFFSET 2
	OV2659_write_cmos_sensor(0x3813, 0x02);

	//bit[7:4] h/v odd increase number
	//bit[3:0] h/v even increase number
	//TIMING XINC : h odd inc 3;h even inc 1
	OV2659_write_cmos_sensor(0x3814, 0x31);
	//TIMING YINC : v odd inc 3;v even inc 1
	OV2659_write_cmos_sensor(0x3815, 0x31);

	if(1) 
	{ 
		OV2659_write_cmos_sensor(0x3820,0x81);           
		OV2659_write_cmos_sensor(0x3821, 0x01);
	} 
	else 
	{         
		OV2659_write_cmos_sensor(0x3820,0x87);           
		OV2659_write_cmos_sensor(0x3821,0x07); 
	}         

	OV2659_write_cmos_sensor(0x3A00, OV2659_read_cmos_sensor(0x3A00)| 0x04);///sofia 20110113

	////////////////50HZ//////////////////
	//OV2659_write_cmos_sensor(0x3a14,0x02);
	//OV2659_write_cmos_sensor(0x3a15,0x28);

	OV2659_write_cmos_sensor(0x3a08,0x00);
	OV2659_write_cmos_sensor(0x3a09,0xb8);

	OV2659_write_cmos_sensor(0x3a0e,0x03);
	////////////////60HZ//////////////////
	//OV2659_write_cmos_sensor(0x3a02,0x02);
	//OV2659_write_cmos_sensor(0x3a03,0x68);//616

	OV2659_write_cmos_sensor(0x3a0a,0x00);
	OV2659_write_cmos_sensor(0x3a0b,0x9A);//99

	OV2659_write_cmos_sensor(0x3a0d,0x04);
	/////////////////////////////////////////////

	///////////////////////////
	//OV2659_write_cmos_sensor(0x3623, 0x00);
	OV2659_write_cmos_sensor(0x3634, 0x76);
	//OV2659_write_cmos_sensor(0x3701, 0x44);
	//OV2659_write_cmos_sensor(0x3802, 0xa1);
	OV2659_write_cmos_sensor(0x3702, 0x18);
	OV2659_write_cmos_sensor(0x3703, 0x24);
	OV2659_write_cmos_sensor(0x3704, 0x24);
	OV2659_write_cmos_sensor(0x3705, 0x0c);
	///////////////////////////
	OV2659_write_cmos_sensor(0x370a, 0x52);

	//OV2659_write_cmos_sensor(0x4708, 0x02);//5-29

#if 0
	if(!(OV2659_read_cmos_sensor(0x507B)&0xf0))
	{
		OV2659_write_cmos_sensor(0x5084,0x0c);
		OV2659_write_cmos_sensor(0x5085,0x1f);
		OV2659_write_cmos_sensor(0x507e,0x32);
		OV2659_write_cmos_sensor(0x507f,0x10);
		OV2659_write_cmos_sensor(0x507a, OV2659_read_cmos_sensor(0x507a)&~0x10);//Auto UV
	}
#endif

	//OV2659_write_cmos_sensor(0X301d, 0X08);
	//mDELAY(67); 
	//OV2659_write_cmos_sensor(0X301d, 0X00);


	OV2659_write_cmos_sensor(0X0100, 0X01);
	mDELAY(50); 
	
	printk("[OV2659previewsetting 1]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659previewsetting 1]mirror :%x \n",OV2659_read_cmos_sensor(0x3821)); 

	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.IsPVmode = KAL_TRUE;
	OV2659Sensor.PreviewPclk= 480;
	OV2659Sensor.SensorMode= SENSOR_MODE_PREVIEW;
	spin_unlock(&ov2659_drv_lock);
	
}

/*************************************************************************
* FUNCTION
*     OV2659FullSizeCaptureSetting
*
* DESCRIPTION
*    This function config full size capture setting related registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659FullSizeCaptureSetting(void)
{
	//OV2659_write_cmos_sensor(0X0100, 0X00);	//test
	OV2659_write_cmos_sensor(0x3a00,OV2659_read_cmos_sensor(0x3a00)&0xfb); 
	OV2659_write_cmos_sensor(0x3503,OV2659_read_cmos_sensor(0x3503)|0x07); 
	//OV2659_write_cmos_sensor(0x3406,OV2659_read_cmos_sensor(0x3406)|0x01);                

	OV2659_write_cmos_sensor(0x5066, 0x28); //28 0x38 //2012-10-25  0x1e     
	OV2659_write_cmos_sensor(0x5067, 0x20); //18 0x28 mingji 0x18 //2012-10-25  0x06 
	OV2659_write_cmos_sensor(0x506a, 0x06); //0x0d   
	OV2659_write_cmos_sensor(0x506b, 0x40); //0x16 mingji 0x28 0x38 
	//(0,0)
	OV2659_write_cmos_sensor(0x3800, 0x00);
	OV2659_write_cmos_sensor(0x3801, 0x00);
	OV2659_write_cmos_sensor(0x3802, 0x00);
	OV2659_write_cmos_sensor(0x3803, 0x00);
	//(1631,1211)
	OV2659_write_cmos_sensor(0x3804, 0x06);
	OV2659_write_cmos_sensor(0x3805, 0x5f);
	OV2659_write_cmos_sensor(0x3806, 0x04);
	OV2659_write_cmos_sensor(0x3807, 0xbb);

	//1600x1200
	OV2659_write_cmos_sensor(0x3808, 0x06);
	OV2659_write_cmos_sensor(0x3809, 0x40);
	OV2659_write_cmos_sensor(0x380a, 0x04);
	OV2659_write_cmos_sensor(0x380b, 0xb0);

	//HTS 1951 
	//OV2659_write_cmos_sensor(0x380c, 0x07);
	//OV2659_write_cmos_sensor(0x380d, 0x9f);
	//VTS 1232
	//OV2659_write_cmos_sensor(0x380e, 0x04);
	//OV2659_write_cmos_sensor(0x380f, 0xd0);

	//(16,6)
	//h offset 16
	OV2659_write_cmos_sensor(0x3811, 0x10);
	//v offset 6
	OV2659_write_cmos_sensor(0x3813, 0x06);

	////////////////???????////////////////////
	//bit[7:4] h/v odd increase number
	//bit[3:0] h/v even increase number
	//TIMING XINC : h odd inc 1;h even inc 1
	OV2659_write_cmos_sensor(0x3814, 0x11);
	//TIMING YINC : V odd inc 1;h even inc 1
	OV2659_write_cmos_sensor(0x3815, 0x11);

	//maximum exposure for 60hz: 1232
	//OV2659_write_cmos_sensor(0x3a02, 0x04);
	//OV2659_write_cmos_sensor(0x3a03, 0xd0);

	//band step for 50/60 HZ light
	//CAM_BANDING_50HZ light:184
	//OV2659_write_cmos_sensor(0x3a08, 0x00);
	//OV2659_write_cmos_sensor(0x3a09, 0xb8);
	//CAM_BANDING_60HZ light:154
	//OV2659_write_cmos_sensor(0x3a0a, 0x00);
	//OV2659_write_cmos_sensor(0x3a0b, 0x9a);

	//maximum band number in one frame for 60 Hz light source:8
	//OV2659_write_cmos_sensor(0x3a0d, 0x08);
	//maximum band number in one frame for 50 Hz light source:6
	//OV2659_write_cmos_sensor(0x3a0e, 0x06);

	//maximum exposure number for 50Hz :1104
	//OV2659_write_cmos_sensor(0x3a14, 0x04);
	//OV2659_write_cmos_sensor(0x3a15, 0x50);

	OV2659_write_cmos_sensor(0x3623, 0x00);
	OV2659_write_cmos_sensor(0x3634, 0x44);
	OV2659_write_cmos_sensor(0x3701, 0x44);
	OV2659_write_cmos_sensor(0x3208, 0xa2); 
	OV2659_write_cmos_sensor(0x3705, 0x18);      
	OV2659_write_cmos_sensor(0x3820, OV2659_read_cmos_sensor(0x3820)&0xfe); 
	OV2659_write_cmos_sensor(0x3821, OV2659_read_cmos_sensor(0x3821)&0xfe); 
	OV2659_write_cmos_sensor(0x370a, 0x12);

	//VFIFO Read Strat:128
	OV2659_write_cmos_sensor(0x4608, 0x00);
	OV2659_write_cmos_sensor(0x4609, 0x80);

	//ISP CTRL Bit[4]:Scale Enable(1:en;0,dis)
	OV2659_write_cmos_sensor(0x5002, 0x00);
	//frame rate
	OV2659_write_cmos_sensor(0x3003, 0x80);//10fps 
	OV2659_write_cmos_sensor(0x3004, 0x10);
	OV2659_write_cmos_sensor(0x3005, 0x16); 
	OV2659_write_cmos_sensor(0x3006, 0x0d); 

	OV2659_write_cmos_sensor(0x380c, 0x07); 
	OV2659_write_cmos_sensor(0x380d, 0x9f); 
	OV2659_write_cmos_sensor(0x380e, 0x04); 
	OV2659_write_cmos_sensor(0x380f, 0xd0); 

	OV2659_write_cmos_sensor(0x3a08, 0x00); 
	OV2659_write_cmos_sensor(0x3a09, 0x7b);
	OV2659_write_cmos_sensor(0x3a0e, 0x09); 

	OV2659_write_cmos_sensor(0x3a0a, 0x00); 
	OV2659_write_cmos_sensor(0x3a0b, 0x67);                 
	OV2659_write_cmos_sensor(0x3a0d, 0x0f);         
	OV2659_write_cmos_sensor(0x4003, 0x88);
	//OV2659_write_cmos_sensor(0X0100, 0X01);	//test

    //OV2659_set_param_banding(AE_FLICKER_MODE_50HZ);//LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
    OV2659_set_param();//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou

		printk("[OV2659capturesetting]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659capturesetting]mirror :%x \n",OV2659_read_cmos_sensor(0x3821)); 

	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.IsPVmode = KAL_FALSE;
	OV2659Sensor.CapturePclk= 480;//585
	OV2659Sensor.SensorMode= SENSOR_MODE_CAPTURE;
	spin_unlock(&ov2659_drv_lock);

}


/*************************************************************************
* FUNCTION
*    OV2659SetHVMirror
*
* DESCRIPTION
*    This function set sensor Mirror
*
* PARAMETERS
*    Mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659SetHVMirror(kal_uint8 Mirror)
{
	kal_uint8 mirror= 0, flip=0;
	
	OV2659SENSORDB("[OV2659]OV2659SetHVMirror Mirror:%d\n",Mirror);    
  	flip = OV2659_read_cmos_sensor(0x3820);
	mirror=OV2659_read_cmos_sensor(0x3821);

  	printk("[OV2659SetHVMirror0]flip :%x   \n",flip);
	printk("[OV2659SetHVMirror0]mirror :%x \n",mirror);
	switch (Mirror)
	{
	case IMAGE_NORMAL:
		printk("[OV2659SetHVMirror]IMAGE_NORMAL\n");
		OV2659_write_cmos_sensor(0x3820, flip&0xf9);     
		OV2659_write_cmos_sensor(0x3821, mirror&0xf9);
		break;
	case IMAGE_H_MIRROR:
		printk("[OV2659SetHVMirror]IMAGE_H_MIRROR\n");
		OV2659_write_cmos_sensor(0x3820, flip&0xf9);     
		OV2659_write_cmos_sensor(0x3821, mirror|0x06);
		break;
	case IMAGE_V_MIRROR: 
		printk("[OV2659SetHVMirror]IMAGE_V_MIRROR\n");
		OV2659_write_cmos_sensor(0x3820, flip|0x06);     
		OV2659_write_cmos_sensor(0x3821, mirror&0xf9);
		break;
		
	case IMAGE_HV_MIRROR:
		printk("[OV2659SetHVMirror]IMAGE_HV_MIRROR\n");
		OV2659_write_cmos_sensor(0x3820, flip|0x06);     
		OV2659_write_cmos_sensor(0x3821, mirror|0x06);
		break;
		
	default:
		ASSERT(0);
	}
	  	flip = OV2659_read_cmos_sensor(0x3820);
	mirror=OV2659_read_cmos_sensor(0x3821);

    	printk("[OV2659SetHVMirror1]flip :%x   \n",flip);
	printk("[OV2659SetHVMirror1]mirror :%x   \n",mirror);
}

/*************************************************************************
* FUNCTION
*	OV2659Open
*
* DESCRIPTION
*	This function initialize the registers of CMOS sensor
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
UINT32 OV2659Open(void)
{
	OV2659SENSORDB("MINGJI test func calling OV2659Open()\n");
	volatile signed int i;
	kal_uint16 sensor_id = 0;

	OV2659SENSORDB("[OV2659]OV2659Open enter :\n ");
	OV2659_write_cmos_sensor(0x0103,0x01);// Reset sensor
	mDELAY(10);


	//  Read sensor ID to adjust I2C is OK?
	for(i=0;i<3;i++)
	{
		sensor_id = (OV2659_read_cmos_sensor(0x300A) << 8) | OV2659_read_cmos_sensor(0x300B);
		OV2659SENSORDB("OV2659 READ ID :%x",sensor_id);
		if(sensor_id != OV2659_SENSOR_ID)
		{
			return ERROR_SENSOR_CONNECT_FAIL;
		}
	}
	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.VideoMode = KAL_FALSE;
	OV2659Sensor.NightMode = KAL_FALSE;
	OV2659Sensor.Fps = 100;
	OV2659Sensor.ShutterStep= 0xb8;
	OV2659Sensor.CaptureDummyPixels = 0;
	OV2659Sensor.CaptureDummyLines = 0;
	OV2659Sensor.PreviewDummyPixels = 0;
	OV2659Sensor.PreviewDummyLines = 0;
	OV2659Sensor.WhiteBalance = 0;
	OV2659Sensor.SensorMode= SENSOR_MODE_INIT;
	spin_unlock(&ov2659_drv_lock);

	OV2659InitialSetting();
	OV2659Sensor.SensorMode = SENSOR_MODE_INIT;//mingji add 120207

	OV2659SENSORDB("[OV2659]OV2659Open exit :\n ");

	return ERROR_NONE;
}	/* OV2659Open() */

/*************************************************************************
* FUNCTION
*	OV2659Close
*
* DESCRIPTION
*	This function is to turn off sensor module power.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
UINT32 OV2659Close(void)
{
	//	CISModulePowerOn(FALSE);
	return ERROR_NONE;
}	/* OV2659Close() */
/*************************************************************************
* FUNCTION
*	OV2659Preview
*
* DESCRIPTION
*	This function start the sensor preview.
*
* PARAMETERS
*	*image_window : address pointer of pixel numbers in one period of HSYNC
*  *sensor_config_data : address pointer of line numbers in one period of VSYNC
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
UINT32 OV2659Preview(MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *image_window,
					  MSDK_SENSOR_CONFIG_STRUCT *sensor_config_data)
{
	OV2659SENSORDB("MINGJI test func calling OV2659Preview()\n");
	kal_uint8 iTemp, temp_AE_reg, temp_AWB_reg;
	kal_uint16 iDummyPixels = 0, iDummyLines = 0, iStartX = 1, iStartY = 1;

	OV2659SENSORDB("[OV2659]OV2659Preview enter :\n ");
	OV2659Sensor.SensorMode = SENSOR_MODE_PREVIEW;//mingji add 120207
	printk("[OV2659Preview 0]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659Preview 0]mirror :%x \n",OV2659_read_cmos_sensor(0x3821));
	OV2659_set_AE_mode(KAL_TRUE);
	OV2659_set_AWB_mode(KAL_TRUE);
#if defined(MT6575)
	switch(OV2659CurrentScenarioId)
	{
		case MSDK_SCENARIO_ID_CAMERA_ZSD:
			OV2659SENSORDB("[OV2659][OV2659Preview]MSDK_SCENARIO_ID_CAMERA_ZSD :\n ");
			OV2659FullSizeCaptureSetting();			
			break;
		default:
			OV2659PreviewSetting();
			break;
	}
#else
	OV2659PreviewSetting();
#endif
#if 0
	OV2659_write_cmos_sensor(0x301a,0x01);
	mDELAY(67);
	OV2659_write_cmos_sensor(0x301a,0x00);
#endif
	
	//OV2659SetHVMirror(sensor_config_data->SensorImageMirror);
        OV2659SetHVMirror(IMAGE_HV_MIRROR);
	//OV2659_night_mode(1);

    //OV2659_set_param_banding(AE_FLICKER_MODE_50HZ);//LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
    OV2659_set_param();//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou

	mDELAY(200);//50

	OV2659SENSORDB("[OV2659]OV2659Preview exit :\n ");

	printk("test12432141241241234124 \n  ");
	printk("[OV2659Preview 1]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659Preview 1]mirror :%x \n",OV2659_read_cmos_sensor(0x3821));
	return TRUE ;//ERROR_NONE;
}	/* OV2659Preview() */

UINT32 OV2659Capture(MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *image_window,
					  MSDK_SENSOR_CONFIG_STRUCT *sensor_config_data)
{
	OV2659SENSORDB("MINGJI test func calling OV2659Capture()\n");
	OV2659SENSORDB("[OV2659]OV2659Capture enter :\n ");
	printk("[OV2659Capture 0]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659Capture 0]mirror :%x \n",OV2659_read_cmos_sensor(0x3821));
	kal_uint32 shutter = 0, gain=0,temp_reg = 0;
	kal_uint32 prev_line_len = 0;
	kal_uint32 cap_line_len = 0;

	if(OV2659Sensor.SensorMode == SENSOR_MODE_PREVIEW)
	{
		OV2659SENSORDB("[OV2659]NormalShot\n\n ");
		shutter=OV2659ReadShutter();
		OV2659Sensor.SensorShutter=shutter;
		gain=OV2659ReadSensorGain();
		spin_lock(&ov2659_drv_lock);
		OV2659Sensor.SensorGain=gain;
		spin_unlock(&ov2659_drv_lock);
	}
	else
	{
		OV2659SENSORDB("[OV2659]BurstShot\n\n ");
		shutter=OV2659Sensor.SensorShutter;
		gain=OV2659Sensor.SensorGain;
	}

	OV2659Sensor.SensorMode = SENSOR_MODE_CAPTURE;
	OV2659_set_AE_mode(KAL_FALSE);
	OV2659_set_AWB_mode(KAL_FALSE);

	OV2659FullSizeCaptureSetting();
	spin_lock(&ov2659_drv_lock);
	OV2659Sensor.CaptureDummyPixels = 0;
	OV2659Sensor.CaptureDummyLines = 0;
	spin_unlock(&ov2659_drv_lock);
	OV2659SetDummy(OV2659Sensor.CaptureDummyPixels, OV2659Sensor.CaptureDummyLines);

	prev_line_len = OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.PreviewDummyPixels;
	cap_line_len = OV2659_FULL_PERIOD_PIXEL_NUMS + OV2659Sensor.CaptureDummyPixels;
	shutter = (shutter * OV2659Sensor.CapturePclk) / OV2659Sensor.PreviewPclk;
	shutter = (shutter * prev_line_len) / cap_line_len;
	shutter*=2;
	shutter*=2; //7-20
#ifdef BINNING_EN/* By sensor design */
	shutter*=2;
#endif

	OV2659WriteShutter(shutter);

	OV2659WriteSensorGain(gain);
        OV2659SetHVMirror(IMAGE_HV_MIRROR);

    //OV2659_set_param_banding(AE_FLICKER_MODE_50HZ);//LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
    OV2659_set_param();//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou

	printk("[OV2659Capture 1]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659Capture 1]mirror :%x \n",OV2659_read_cmos_sensor(0x3821));
	OV2659SENSORDB("[OV2659]OV2659Capture exit :\n ");
	return ERROR_NONE; 
}/* OV2659Capture() */

UINT32 OV2659GetResolution(MSDK_SENSOR_RESOLUTION_INFO_STRUCT *pSensorResolution)
{
	OV2659SENSORDB("MINGJI test func calling OV2659GetResolution()\n");
	OV2659SENSORDB("[OV2659][OV2659GetResolution enter] :\n ");
	pSensorResolution->SensorPreviewWidth= OV2659_IMAGE_SENSOR_SVGA_WIDTH - 2 * OV2659_PV_GRAB_START_X;
	pSensorResolution->SensorPreviewHeight= OV2659_IMAGE_SENSOR_SVGA_HEIGHT - 2 * OV2659_PV_GRAB_START_Y;

	pSensorResolution->SensorFullWidth= OV2659_IMAGE_SENSOR_UVGA_WITDH - 2 * OV2659_FULL_GRAB_START_X;  
	pSensorResolution->SensorFullHeight= OV2659_IMAGE_SENSOR_UVGA_HEIGHT - 2 * OV2659_FULL_GRAB_START_X;

	pSensorResolution->SensorVideoWidth=OV2659_IMAGE_SENSOR_SVGA_WIDTH - 2 * OV2659_PV_GRAB_START_X;//LINE <> <DATE20121230> <fix video rec hung up> wupingzhou
	pSensorResolution->SensorVideoHeight=OV2659_IMAGE_SENSOR_SVGA_HEIGHT - 2 * OV2659_PV_GRAB_START_Y;//LINE <> <DATE20121230> <fix video rec hung up> wupingzhou
  
	OV2659SENSORDB("[OV2659][OV2659GetInfo exit] :\n ");
	return ERROR_NONE;
}	/* OV2659GetResolution() */

UINT32 OV2659GetInfo(MSDK_SCENARIO_ID_ENUM ScenarioId,
					  MSDK_SENSOR_INFO_STRUCT *pSensorInfo,
					  MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData)
{
	OV2659SENSORDB("MINGJI test func calling OV2659GetInfo()\n");
	OV2659SENSORDB("[OV2659]OV2659GetInfo enter :\n ");
#if defined(MT6575)
	switch (ScenarioId)
	{
		case MSDK_SCENARIO_ID_CAMERA_ZSD:
			pSensorInfo->SensorPreviewResolutionX=OV2659_IMAGE_SENSOR_UVGA_WITDH - 2*OV2659_PV_GRAB_START_X;
			pSensorInfo->SensorPreviewResolutionY=OV2659_IMAGE_SENSOR_UVGA_HEIGHT - 2*OV2659_PV_GRAB_START_Y;	
			break;
		default:
			pSensorInfo->SensorPreviewResolutionX=OV2659_IMAGE_SENSOR_SVGA_WIDTH - 2 * OV2659_PV_GRAB_START_X;
			pSensorInfo->SensorPreviewResolutionY=OV2659_IMAGE_SENSOR_SVGA_HEIGHT - 2 * OV2659_PV_GRAB_START_Y;	
			break;
	}
#else
	pSensorInfo->SensorPreviewResolutionX= OV2659_IMAGE_SENSOR_SVGA_WIDTH - 2 * OV2659_PV_GRAB_START_X;
	pSensorInfo->SensorPreviewResolutionY= OV2659_IMAGE_SENSOR_SVGA_HEIGHT - 2 * OV2659_PV_GRAB_START_Y;
#endif
	pSensorInfo->SensorFullResolutionX= OV2659_IMAGE_SENSOR_UVGA_WITDH - 2 * OV2659_FULL_GRAB_START_X;
	pSensorInfo->SensorFullResolutionY= OV2659_IMAGE_SENSOR_UVGA_HEIGHT - 2 * OV2659_FULL_GRAB_START_X;

	pSensorInfo->SensorCameraPreviewFrameRate=30;
	pSensorInfo->SensorVideoFrameRate=30;
	pSensorInfo->SensorStillCaptureFrameRate=10;
	pSensorInfo->SensorWebCamCaptureFrameRate=15;
	pSensorInfo->SensorResetActiveHigh=FALSE;
	pSensorInfo->SensorResetDelayCount=1;
	pSensorInfo->SensorOutputDataFormat=SENSOR_OUTPUT_FORMAT_YUYV;
	pSensorInfo->SensorClockPolarity=SENSOR_CLOCK_POLARITY_LOW;	/*??? */
	pSensorInfo->SensorClockFallingPolarity=SENSOR_CLOCK_POLARITY_LOW;
	pSensorInfo->SensorHsyncPolarity = SENSOR_CLOCK_POLARITY_LOW;
	pSensorInfo->SensorVsyncPolarity = SENSOR_CLOCK_POLARITY_LOW;
	pSensorInfo->SensorInterruptDelayLines = 1;
	pSensorInfo->SensroInterfaceType=SENSOR_INTERFACE_TYPE_PARALLEL;

	pSensorInfo->CaptureDelayFrame = 2;//1
	pSensorInfo->PreviewDelayFrame = 4; 
	pSensorInfo->VideoDelayFrame = 4; 		
	pSensorInfo->SensorMasterClockSwitch = 0; 
	pSensorInfo->SensorDrivingCurrent = ISP_DRIVING_8MA;   		

	switch (ScenarioId)
	{
		case MSDK_SCENARIO_ID_CAMERA_PREVIEW:
		case MSDK_SCENARIO_ID_VIDEO_PREVIEW:
		//case MSDK_SCENARIO_ID_VIDEO_CAPTURE_MPEG4:
			pSensorInfo->SensorClockFreq=26;
			pSensorInfo->SensorClockDividCount=	3;
			pSensorInfo->SensorClockRisingCount= 0;
			pSensorInfo->SensorClockFallingCount= 2;
			pSensorInfo->SensorPixelClockCount= 3;
			pSensorInfo->SensorDataLatchCount= 2;
			pSensorInfo->SensorGrabStartX = OV2659_PV_GRAB_START_X; 
			pSensorInfo->SensorGrabStartY = OV2659_PV_GRAB_START_Y;             
			break;
		case MSDK_SCENARIO_ID_CAMERA_CAPTURE_JPEG:
		//case MSDK_SCENARIO_ID_CAMERA_CAPTURE_MEM:
#if defined(MT6575)
		case MSDK_SCENARIO_ID_CAMERA_ZSD:
#endif
			pSensorInfo->SensorClockFreq=26;
			pSensorInfo->SensorClockDividCount=	3;
			pSensorInfo->SensorClockRisingCount= 0;
			pSensorInfo->SensorClockFallingCount= 2;
			pSensorInfo->SensorPixelClockCount= 3;
			pSensorInfo->SensorDataLatchCount= 2;
			pSensorInfo->SensorGrabStartX = OV2659_FULL_GRAB_START_X; 
			pSensorInfo->SensorGrabStartY = OV2659_FULL_GRAB_START_Y;             
			break;
		default:
			pSensorInfo->SensorClockFreq=26;
			pSensorInfo->SensorClockDividCount=3;
			pSensorInfo->SensorClockRisingCount=0;
			pSensorInfo->SensorClockFallingCount=2;
			pSensorInfo->SensorPixelClockCount=3;
			pSensorInfo->SensorDataLatchCount=2;
			pSensorInfo->SensorGrabStartX = OV2659_PV_GRAB_START_X; 
			pSensorInfo->SensorGrabStartY = OV2659_PV_GRAB_START_Y;             
			break;
	}

	memcpy(pSensorConfigData, &OV2659SensorConfigData, sizeof(MSDK_SENSOR_CONFIG_STRUCT));
	OV2659SENSORDB("[OV2659]OV2659GetInfo exit :\n ");
	return ERROR_NONE;
}	/* OV2659GetInfo() */

UINT32 OV2659Control(MSDK_SCENARIO_ID_ENUM ScenarioId, MSDK_SENSOR_EXPOSURE_WINDOW_STRUCT *pImageWindow,
					  MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData)
{
	OV2659SENSORDB("MINGJI test func calling OV2659Control()\n");
	OV2659SENSORDB("[OV2659]OV2659Control enter :\n ");
	OV2659CurrentScenarioId = ScenarioId;
	switch (ScenarioId)
	{
		case MSDK_SCENARIO_ID_CAMERA_PREVIEW:
		case MSDK_SCENARIO_ID_VIDEO_PREVIEW:
		//case MSDK_SCENARIO_ID_VIDEO_CAPTURE_MPEG4:
#if defined(MT6575)
		case MSDK_SCENARIO_ID_CAMERA_ZSD:
			OV2659SENSORDB("[OV2659][OV2659Control]MSDK_SCENARIO_ID_CAMERA_ZSD :\n ");
#endif
			OV2659Preview(pImageWindow, pSensorConfigData);
			break;
		case MSDK_SCENARIO_ID_CAMERA_CAPTURE_JPEG:
		//case MSDK_SCENARIO_ID_CAMERA_CAPTURE_MEM:				
			OV2659Capture(pImageWindow, pSensorConfigData);
			break;
		default:
			break; 
	}
	OV2659SENSORDB("[OV2659]OV2659Control exit :\n ");
	return TRUE;
}	/* OV2659Control() */

/* [TC] YUV sensor */	

BOOL OV2659_set_param_wb(UINT16 para)
{
	OV2659SENSORDB("MINGJI test func calling OV2659_set_param_wb()\n");
	OV2659SENSORDB("OV2659_set_param_wb iPara=%d, %d \n",para);
	OV2659Sensor.WhiteBalance = para;

	switch (para)
	{
		case AWB_MODE_OFF:
			spin_lock(&ov2659_drv_lock);
			OV2659_AWB_ENABLE = KAL_FALSE; 
			spin_unlock(&ov2659_drv_lock);
			OV2659_set_AWB_mode(OV2659_AWB_ENABLE);
			break;                    
		case AWB_MODE_AUTO:
			spin_lock(&ov2659_drv_lock);
			OV2659_AWB_ENABLE = KAL_TRUE;  //
            spin_unlock(&ov2659_drv_lock);
			OV2659_set_AWB_mode(KAL_TRUE);
			break;
		case AWB_MODE_CLOUDY_DAYLIGHT: //cloudy
			//OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0323
			OV2659_set_AWB_mode(KAL_FALSE);
			//OV2659_write_cmos_sensor(0x3406 ,temp_reg|0x1 );
			OV2659_write_cmos_sensor(0x3400 ,0x6 );
			OV2659_write_cmos_sensor(0x3401 ,0x30 );
			OV2659_write_cmos_sensor(0x3402 ,0x4 );
			OV2659_write_cmos_sensor(0x3403 ,0x0 );
			OV2659_write_cmos_sensor(0x3404 ,0x4 );
			OV2659_write_cmos_sensor(0x3405 ,0x30 );
			//OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0323
			//OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0323
			break;	
		case AWB_MODE_DAYLIGHT: //sunny
			//OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0323
			OV2659_set_AWB_mode(KAL_FALSE);
			//OV2659_write_cmos_sensor(0x3406 ,temp_reg|0x1 );
			OV2659_write_cmos_sensor(0x3400 ,0x6 );
			OV2659_write_cmos_sensor(0x3401 ,0x10 );
			OV2659_write_cmos_sensor(0x3402 ,0x4 );
			OV2659_write_cmos_sensor(0x3403 ,0x0 );
			OV2659_write_cmos_sensor(0x3404 ,0x4 );
			OV2659_write_cmos_sensor(0x3405 ,0x48 );
			//OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0323
			//OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0323
			break;
		case AWB_MODE_INCANDESCENT: //office
			//OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0323
			OV2659_set_AWB_mode(KAL_FALSE);
			//OV2659_write_cmos_sensor(0x3406 ,temp_reg|0x1 );
			OV2659_write_cmos_sensor(0x3400 ,0x4 );
			OV2659_write_cmos_sensor(0x3401 ,0xe0 );
			OV2659_write_cmos_sensor(0x3402 ,0x4 );
			OV2659_write_cmos_sensor(0x3403 ,0x0 );
			OV2659_write_cmos_sensor(0x3404 ,0x5 );
			OV2659_write_cmos_sensor(0x3405 ,0xa0 );
			//OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0323
			//OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0323
			break;
		case AWB_MODE_TUNGSTEN:
			//OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0323
			OV2659_set_AWB_mode(KAL_FALSE);
			//OV2659_write_cmos_sensor(0x3406 ,temp_reg|0x1 );
			OV2659_write_cmos_sensor(0x3400 ,0x4 );
			OV2659_write_cmos_sensor(0x3401 ,0x0 );
			OV2659_write_cmos_sensor(0x3402 ,0x4 );
			OV2659_write_cmos_sensor(0x3403 ,0x0 );
			OV2659_write_cmos_sensor(0x3404 ,0x6 );
			OV2659_write_cmos_sensor(0x3405 ,0x50 );
			//OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0323
			//OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0323
			break;
		case AWB_MODE_FLUORESCENT:
			//OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0323
			OV2659_set_AWB_mode(KAL_FALSE);
			//OV2659_write_cmos_sensor(0x3406 ,temp_reg|0x1 );
			OV2659_write_cmos_sensor(0x3400 ,0x5 );
			OV2659_write_cmos_sensor(0x3401 ,0x48 );
			OV2659_write_cmos_sensor(0x3402 ,0x4 );
			OV2659_write_cmos_sensor(0x3403 ,0x0 );
			OV2659_write_cmos_sensor(0x3404 ,0x5 );
			OV2659_write_cmos_sensor(0x3405 ,0xe0 );
			//OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0323
			//OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0323
			break;

		default:
			return FALSE;
	}

	return TRUE;
} /* OV2659_set_param_wb */

BOOL OV2659_set_param_effect(UINT16 para)
{
	OV2659SENSORDB("MINGJI test func calling OV2659_set_param_effect()\n");
	OV2659SENSORDB("OV2659_set_param_effect iPara=%d, %d \n",para);
	switch (para)
	{
		case MEFFECT_OFF:
			//OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0321
			OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x507B,0x06); 
			OV2659_write_cmos_sensor(0x507e,0x33); //0x32
			OV2659_write_cmos_sensor(0x507f,0x22); //0x10 7-31 20 2c 18 20

			OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0321
			OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0321
			//mDELAY(250);
			break;

		case MEFFECT_SEPIA:
			//OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0321
			OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x507B,0x1e); 
			OV2659_write_cmos_sensor(0x507e,0x40); 
			OV2659_write_cmos_sensor(0x507f,0xa0); 
			OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0321
			OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0321
			//mDELAY(300);
			break;
		case MEFFECT_NEGATIVE:
			//OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0321
			OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x507B,0x46); 
			//OV2659_write_cmos_sensor(0x507e,0x32); 
			//OV2659_write_cmos_sensor(0x507f,0x10); 
			OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0321
			OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0321
			//mDELAY(300);
			break;

		case MEFFECT_SEPIAGREEN:
			//OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0321
			OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x507B,0x1e); 
			OV2659_write_cmos_sensor(0x507e,0x60); 
			OV2659_write_cmos_sensor(0x507f,0x60); 
			OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0321
			OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0321
			//mDELAY(300);
			break;

		case MEFFECT_SEPIABLUE:
			//OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0321
			OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x507B,0x1e); 
			OV2659_write_cmos_sensor(0x507e,0xa0); 
			OV2659_write_cmos_sensor(0x507f,0x40); 
			OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0321
			OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0321
			//mDELAY(300);
			break;
		case MEFFECT_MONO: //B&W
			//OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x3208, 0x00); //mingji add 0321
			OV2659_write_cmos_sensor(0x5001,0x1f);
			OV2659_write_cmos_sensor(0x507B,0x26); 
			//OV2659_write_cmos_sensor(0x507B, (0x4 | 0x60));
			OV2659_write_cmos_sensor(0x3208, 0x10); //mingji add 0321
			OV2659_write_cmos_sensor(0x3208, 0xa0); //mingji add 0321			 
			//mDELAY(300);
			break;
		default:
			return KAL_FALSE;
	}

	return KAL_FALSE;

} /* OV2659_set_param_effect */

BOOL OV2659_set_param_banding(UINT16 para)
{
	OV2659SENSORDB("MINGJI test func calling OV2659_set_param_banding()\n");

	kal_uint8 banding;
	kal_uint16 temp_reg = 0;
	kal_uint32 base_shutter = 0, max_shutter_step = 0, exposure_limitation = 0;
	kal_uint32 line_length = 0, sensor_pixel_clock = 0;

	if (OV2659Sensor.IsPVmode == KAL_TRUE)
	{
		OV2659SENSORDB("MINGJI test func calling OV2659Sensor.IsPVmode == KAL_TRUE\n");

		line_length = OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.PreviewDummyPixels;
		exposure_limitation = OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines;
		sensor_pixel_clock = OV2659Sensor.PreviewPclk * 100 * 1000;
	}
	else
	{
		OV2659SENSORDB("MINGJI test func calling OV2659Sensor.IsPVmode == KAL_FALSE\n");

		line_length = OV2659_FULL_PERIOD_PIXEL_NUMS + OV2659Sensor.CaptureDummyPixels;
		exposure_limitation = OV2659_FULL_PERIOD_LINE_NUMS + OV2659Sensor.CaptureDummyLines;
		sensor_pixel_clock = OV2659Sensor.CapturePclk * 100 * 1000;
	}

	line_length = line_length * 2;		/* Multiple 2 is because one YUV422 pixels need two clock. */

	banding = OV2659_read_cmos_sensor(0x3A05);
	switch (para)
	{
		case AE_FLICKER_MODE_50HZ:
	//	case AE_FLICKER_MODE_60HZ://LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
			OV2659SENSORDB("MINGJI test func calling AE_FLICKER_MODE_50HZ\n");
			spin_lock(&ov2659_drv_lock);
			OV2659_Banding_setting = AE_FLICKER_MODE_50HZ;
			 spin_unlock(&ov2659_drv_lock);
			/* + (line_length/2) is used fot base_shutter + 0.5 */
			//base_shutter=framerate*max exposure line/100=(plck/2/(line_len*frame_len))*max exposure line/100
			//base_shutter = ((sensor_pixel_clock/100) + (line_length/2)) / line_length;
			//max_shutter_step = (exposure_limitation / base_shutter);// - 1;
			//OV2659_write_cmos_sensor(0x3a0e, max_shutter_step); 
			//OV2659_write_cmos_sensor(0x3a09, base_shutter); 
			OV2659_write_cmos_sensor(0x3a09, 0x5c);
			OV2659_write_cmos_sensor(0x3a05, banding&0x7f);
			break;

		case AE_FLICKER_MODE_60HZ:
	//	case AE_FLICKER_MODE_50HZ://LINE <> <DATE20121230> <camera OV2659 anti-flicker> wupingzhou
			OV2659SENSORDB("MINGJI test func calling AE_FLICKER_MODE_60HZ\n");
			spin_lock(&ov2659_drv_lock);
			OV2659_Banding_setting = AE_FLICKER_MODE_60HZ;
			 spin_unlock(&ov2659_drv_lock);
			/* + (line_length/2) is used fot base_shutter + 0.5 */
			//base_shutter = ((sensor_pixel_clock/120) + (line_length/2)) / line_length;
			//max_shutter_step = (exposure_limitation / base_shutter);// - 1;
			//OV2659_write_cmos_sensor(0x3a0d, max_shutter_step); 
			//OV2659_write_cmos_sensor(0x3a0b, base_shutter);
			OV2659_write_cmos_sensor(0x3a09, 0x4d);
			OV2659_write_cmos_sensor(0x3a05, banding|0x80);
			break;

		default:
			return FALSE;
	}
	return TRUE;
} /* OV2659_set_param_banding */

BOOL OV2659_set_param_exposure(UINT16 para)
{
	OV2659SENSORDB("MINGJI test func calling OV2659_set_param_exposure()\n");

	kal_uint8 EvTemp0 = 0x00, EvTemp1 = 0x00, temp_reg= 0x00;

	temp_reg=OV2659_read_cmos_sensor(0x5083);//[3] sign
	OV2659_write_cmos_sensor(0x507b,OV2659_read_cmos_sensor(0x507b)|0x04);

	switch (para)
	{	
		case AE_EV_COMP_20:
			EvTemp0= 0x20;
			EvTemp1= temp_reg&0xf7;
			break;
		/*case AE_EV_COMP_15:
			EvTemp0= 0x30;
			EvTemp1= temp_reg&0xf7;
			break;*/
		case AE_EV_COMP_10:
			EvTemp0= 0x10;
			EvTemp1= temp_reg&0xf7;
			break;
		/*case AE_EV_COMP_03:
			EvTemp0= 0x10;
			EvTemp1= temp_reg&0xf7;
			break;*/
		case AE_EV_COMP_00:
			EvTemp0= 0x00;
			EvTemp1= temp_reg&0xf7;
			break;
		/*case AE_EV_COMP_n03:
			EvTemp0= 0x10;
			EvTemp1= temp_reg|0x08;		
			break;*/
		case AE_EV_COMP_n10:
			EvTemp0= 0x10;
			EvTemp1= temp_reg|0x08;	
			break;
		/*case AE_EV_COMP_n15:
			EvTemp0= 0x30;
			EvTemp1= temp_reg|0x08;	
			break;*/
		case AE_EV_COMP_n20:
			EvTemp0= 0x20;
			EvTemp1= temp_reg|0x08;	
			break;		
		default:
			return FALSE;
	}
	OV2659_write_cmos_sensor(0x3208, 0x00); 
	OV2659_write_cmos_sensor(0x5082, EvTemp0);
	OV2659_write_cmos_sensor(0x5083, EvTemp1);	
	OV2659_write_cmos_sensor(0x3208, 0x10); 
	OV2659_write_cmos_sensor(0x3208, 0xa0); 
	return TRUE;
} /* OV2659_set_param_exposure */



UINT32 OV2659YUVSensorSetting(FEATURE_ID iCmd, UINT32 iPara)
{
	OV2659SENSORDB("MINGJI test func calling OV2659YUVSensorSetting()\n");

	OV2659SENSORDB("OV2659YUVSensorSetting:iCmd=%d,iPara=%d, %d \n",iCmd, iPara);

	switch (iCmd) {
		case FID_SCENE_MODE:
			OV2659SENSORDB("Night Mode:%d\n", iPara); 
            mode_para = (iPara== SCENE_MODE_NIGHTSCENE?KAL_TRUE:KAL_FALSE);//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou
            
			if (iPara == SCENE_MODE_OFF)
			{
				OV2659_night_mode(KAL_FALSE); 
			}
			else if (iPara == SCENE_MODE_NIGHTSCENE)
			{
				OV2659_night_mode(KAL_TRUE); 
			}	    
			break; 	    
		case FID_AWB_MODE:
			OV2659SENSORDB("Set AWB Mode:%d\n", iPara); 
            wb_para = iPara;//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou
			OV2659_set_param_wb(iPara);
			break;
		case FID_COLOR_EFFECT:
			OV2659SENSORDB("Set Color Effect:%d\n", iPara); 	
            effect_para = iPara;//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou
			OV2659_set_param_effect(iPara);
			break;
		case FID_AE_EV:
			OV2659SENSORDB("Set EV:%d\n", iPara); 	    	    
            exposure_para = iPara;//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou
			OV2659_set_param_exposure(iPara);
			break;
		case FID_AE_FLICKER:
			OV2659SENSORDB("Set Flicker:%d\n", iPara); 	
            banding_para = iPara;//LINE <PZOI-368> <DATE20120121> <camera OV2659 setting> wupingzhou
			OV2659_set_param_banding(iPara);
			break;
		case FID_AE_SCENE_MODE: 
			OV2659SENSORDB("Set AE Mode:%d\n", iPara);
         	if (iPara == AE_MODE_OFF) 
			{
				spin_lock(&ov2659_drv_lock);
				OV2659_AE_ENABLE = KAL_FALSE; 
				spin_unlock(&ov2659_drv_lock);
			}
         	else 
			{
				spin_lock(&ov2659_drv_lock);
				OV2659_AE_ENABLE = KAL_TRUE; 
				spin_unlock(&ov2659_drv_lock);
			}
			OV2659_set_AE_mode(OV2659_AE_ENABLE);
			break; 
		case FID_ZOOM_FACTOR:
			OV2659SENSORDB("FID_ZOOM_FACTOR:%d\n", iPara); 	    
			spin_lock(&ov2659_drv_lock);
			zoom_factor = iPara; 
			spin_unlock(&ov2659_drv_lock);
			break; 
		default:
			break;
	}
	return TRUE;
}   /* OV2659YUVSensorSetting */

UINT32 OV2659YUVSetVideoMode(UINT16 u2FrameRate)
{
	if (u2FrameRate == 30)
	{
		OV2659_write_cmos_sensor(0x3003,0x80);//30fps 26mclk 
		OV2659_write_cmos_sensor(0x3004,0x10); 
		OV2659_write_cmos_sensor(0x3005,0x16); 
		OV2659_write_cmos_sensor(0x3006,0x0f); //d
		//dummy lines&dummy pixels 
		OV2659_write_cmos_sensor(0x380c,0x05); 
		OV2659_write_cmos_sensor(0x380d,0x14); 
		OV2659_write_cmos_sensor(0x380e,0x02); 
		OV2659_write_cmos_sensor(0x380f,0xde); //68
		//banding                    
		OV2659_write_cmos_sensor(0x3a08,0x00); 
		OV2659_write_cmos_sensor(0x3a09,0xb9); 
		OV2659_write_cmos_sensor(0x3a0e,0x03); 
		OV2659_write_cmos_sensor(0x3a0a,0x00); 
		OV2659_write_cmos_sensor(0x3a0b,0x9a); 
		OV2659_write_cmos_sensor(0x3a0d,0x04);          

		//OV2659_write_cmos_sensor(0x3a00,0x38); 
		//OV2659_write_cmos_sensor(0x3a02,0x02); 
		//OV2659_write_cmos_sensor(0x3a03,0x28); 
		//OV2659_write_cmos_sensor(0x3a14,0x02); 
		//OV2659_write_cmos_sensor(0x3a15,0x68); 

		OV2659_write_cmos_sensor(0x3a00,0x38); 
		OV2659_write_cmos_sensor(0x3a02,0x02); 
		OV2659_write_cmos_sensor(0x3a03,0xde); 
		OV2659_write_cmos_sensor(0x3a14,0x02); 
		OV2659_write_cmos_sensor(0x3a15,0xde);   
	}
	else if (u2FrameRate == 15)   
	{
		OV2659_write_cmos_sensor(0x3003,0x80);//15fps 26mclk 
		/////26X22/4/2/3=24M
		OV2659_write_cmos_sensor(0x3004,0x20);////////4X
		OV2659_write_cmos_sensor(0x3005,0x16);////PLUS 22
		OV2659_write_cmos_sensor(0x3006,0x0f);/////01 101  2X 3X   d
		//dummy lines&dummy pixels 
		OV2659_write_cmos_sensor(0x380c,0x05); 
		OV2659_write_cmos_sensor(0x380d,0x14); 
		OV2659_write_cmos_sensor(0x380e,0x02); 
		OV2659_write_cmos_sensor(0x380f,0xde); //68
		//banding                   
		OV2659_write_cmos_sensor(0x3a08,0x00); 
		OV2659_write_cmos_sensor(0x3a09,0x5c); 
		OV2659_write_cmos_sensor(0x3a0e,0x06); 
		OV2659_write_cmos_sensor(0x3a0a,0x00); 
		OV2659_write_cmos_sensor(0x3a0b,0x4d); 
		OV2659_write_cmos_sensor(0x3a0d,0x08);          

		//OV2659_write_cmos_sensor(0x3a00,0x38); 
		//OV2659_write_cmos_sensor(0x3a02,0x02); 
		//OV2659_write_cmos_sensor(0x3a03,0x28); 
		//OV2659_write_cmos_sensor(0x3a14,0x02); 
		//OV2659_write_cmos_sensor(0x3a15,0x68); 

		OV2659_write_cmos_sensor(0x3a00,0x38); 
		OV2659_write_cmos_sensor(0x3a02,0x02); 
		OV2659_write_cmos_sensor(0x3a03,0xde); 
		OV2659_write_cmos_sensor(0x3a14,0x02); 
		OV2659_write_cmos_sensor(0x3a15,0xde);   
	}   
	else 
	{
		printk("Wrong frame rate setting \n");
	}


			printk("[OV2659YUVSetVideoMode 1]flip :%x  \n",OV2659_read_cmos_sensor(0x3820));
	printk("[OV2659YUVSetVideoMode 1]mirror :%x \n",OV2659_read_cmos_sensor(0x3821)); 
	return TRUE;
}
#if defined(MT6575)
static void OV2659GetEvAwbRef(UINT32 pSensorAEAWBRefStruct)
{
	PSENSOR_AE_AWB_REF_STRUCT Ref = (PSENSOR_AE_AWB_REF_STRUCT)pSensorAEAWBRefStruct;
	Ref->SensorAERef.AeRefLV05Shutter=1503;
	Ref->SensorAERef.AeRefLV05Gain=496*2;
	Ref->SensorAERef.AeRefLV13Shutter=49;
	Ref->SensorAERef.AeRefLV13Gain=64*2;
	Ref->SensorAwbGainRef.AwbRefD65Rgain=188;
	Ref->SensorAwbGainRef.AwbRefD65Bgain=128;
	Ref->SensorAwbGainRef.AwbRefCWFRgain=160;
	Ref->SensorAwbGainRef.AwbRefCWFBgain=164;
}

static void OV2659GetCurAeAwbInfo(UINT32 pSensorAEAWBCurStruct)
{
	PSENSOR_AE_AWB_CUR_STRUCT Info = (PSENSOR_AE_AWB_CUR_STRUCT)pSensorAEAWBCurStruct;
	Info->SensorAECur.AeCurShutter=OV2659ReadShutter();
	Info->SensorAECur.AeCurGain=OV2659ReadSensorGain() * 2;
	Info->SensorAwbGainCur.AwbCurRgain=OV2659_read_cmos_sensor(0x504c);
	Info->SensorAwbGainCur.AwbCurBgain=OV2659_read_cmos_sensor(0x504e);
}
#endif

void OV2659GetExifInfo(UINT32 exifAddr)
{
	SENSOR_EXIF_INFO_STRUCT* pExifInfo = (SENSOR_EXIF_INFO_STRUCT*)exifAddr;
	pExifInfo->FNumber = 28;
	pExifInfo->AEISOSpeed = AE_ISO_100;
	pExifInfo->AWBMode = OV2659Sensor.WhiteBalance;
	pExifInfo->CapExposureTime = 0;
	pExifInfo->FlashLightTimeus = 0;
	pExifInfo->RealISOValue = AE_ISO_100;
}

UINT32 OV2659FeatureControl(MSDK_SENSOR_FEATURE_ENUM FeatureId,
							 UINT8 *pFeaturePara,UINT32 *pFeatureParaLen)
{
	UINT16 *pFeatureReturnPara16=(UINT16 *) pFeaturePara;
	UINT16 *pFeatureData16=(UINT16 *) pFeaturePara;
	UINT32 *pFeatureReturnPara32=(UINT32 *) pFeaturePara;
	UINT32 *pFeatureData32=(UINT32 *) pFeaturePara;
	MSDK_SENSOR_CONFIG_STRUCT *pSensorConfigData=(MSDK_SENSOR_CONFIG_STRUCT *) pFeaturePara;
	MSDK_SENSOR_REG_INFO_STRUCT *pSensorRegData=(MSDK_SENSOR_REG_INFO_STRUCT *) pFeaturePara;
	UINT32 Tony_Temp1 = 0;
	UINT32 Tony_Temp2 = 0;
	Tony_Temp1 = pFeaturePara[0];
	Tony_Temp2 = pFeaturePara[1];

	//OV2659SENSORDB("[OV2659]OV2659FeatureControl enter :\n ");
	OV2659SENSORDB("[OV2659][OV2659FeatureControl]feature id=%d \n",FeatureId);

	switch (FeatureId)
	{
		case SENSOR_FEATURE_GET_RESOLUTION:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_RESOLUTION \n");
			*pFeatureReturnPara16++=OV2659_IMAGE_SENSOR_UVGA_WITDH;
			*pFeatureReturnPara16=OV2659_IMAGE_SENSOR_UVGA_HEIGHT;
			*pFeatureParaLen=4;
			break;
		case SENSOR_FEATURE_GET_PERIOD:
		#if defined(MT6575)
			switch(OV2659CurrentScenarioId)
			{
				case MSDK_SCENARIO_ID_CAMERA_ZSD:
					OV2659SENSORDB("[OV2659][SENSOR_FEATURE_GET_PERIOD]MSDK_SCENARIO_ID_CAMERA_ZSD :\n ");
					//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_PERIOD \n");
					*pFeatureReturnPara16++=OV2659_FULL_PERIOD_PIXEL_NUMS + OV2659Sensor.CaptureDummyPixels;
					*pFeatureReturnPara16=OV2659_FULL_PERIOD_LINE_NUMS + OV2659Sensor.CaptureDummyLines;
					*pFeatureParaLen=4;
					break;
				default:
					//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_PERIOD \n");
					*pFeatureReturnPara16++=OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.PreviewDummyPixels;
					*pFeatureReturnPara16=OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines;
					*pFeatureParaLen=4;
					break;
				}
		#else
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_PERIOD \n");
			*pFeatureReturnPara16++=OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.PreviewDummyPixels;
			*pFeatureReturnPara16=OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines;
			*pFeatureParaLen=4;
		#endif
		break;
		case SENSOR_FEATURE_GET_PIXEL_CLOCK_FREQ:
	#if defined(MT6575)
	    switch(OV2659CurrentScenarioId)
		{
			case MSDK_SCENARIO_ID_CAMERA_ZSD:
				OV2659SENSORDB("[OV2659][SENSOR_FEATURE_GET_PIXEL_CLOCK_FREQ]MSDK_SCENARIO_ID_CAMERA_ZSD :\n ");
				//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_PIXEL_CLOCK_FREQ \n");
				*pFeatureReturnPara32 = OV2659Sensor.CapturePclk/10;
				*pFeatureParaLen=4;
				break;
			default:
				//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_PIXEL_CLOCK_FREQ \n");
				*pFeatureReturnPara32 = OV2659Sensor.PreviewPclk * 1000 *100;	 //unit: Hz
				*pFeatureParaLen=4;
				break;
		}
	#else
		//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_PIXEL_CLOCK_FREQ \n");
		*pFeatureReturnPara32 = OV2659Sensor.PreviewPclk * 1000 *100;	 //unit: Hz
		*pFeatureParaLen=4;
	#endif
		break;
		case SENSOR_FEATURE_SET_ESHUTTER:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_ESHUTTER \n");
			break;
		case SENSOR_FEATURE_SET_NIGHTMODE:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_NIGHTMODE \n");
			OV2659_night_mode((BOOL) *pFeatureData16);
			break;
		case SENSOR_FEATURE_SET_GAIN:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_GAIN \n");
			break;
		case SENSOR_FEATURE_SET_FLASHLIGHT:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_FLASHLIGHT \n");
			break;
		case SENSOR_FEATURE_SET_ISP_MASTER_CLOCK_FREQ:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_ISP_MASTER_CLOCK_FREQ \n");
			break;
		case SENSOR_FEATURE_SET_REGISTER:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_REGISTER \n");
			OV2659_write_cmos_sensor(pSensorRegData->RegAddr, pSensorRegData->RegData);
			break;
		case SENSOR_FEATURE_GET_REGISTER:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_REGISTER \n");
			pSensorRegData->RegData = OV2659_read_cmos_sensor(pSensorRegData->RegAddr);
			break;
		case SENSOR_FEATURE_GET_CONFIG_PARA:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_CONFIG_PARA \n");
			memcpy(pSensorConfigData, &OV2659SensorConfigData, sizeof(MSDK_SENSOR_CONFIG_STRUCT));
			*pFeatureParaLen=sizeof(MSDK_SENSOR_CONFIG_STRUCT);
			break;
		case SENSOR_FEATURE_SET_CCT_REGISTER:
		case SENSOR_FEATURE_GET_CCT_REGISTER:
		case SENSOR_FEATURE_SET_ENG_REGISTER:
		case SENSOR_FEATURE_GET_ENG_REGISTER:
		case SENSOR_FEATURE_GET_REGISTER_DEFAULT:

		case SENSOR_FEATURE_CAMERA_PARA_TO_SENSOR:
		case SENSOR_FEATURE_SENSOR_TO_CAMERA_PARA:
		case SENSOR_FEATURE_GET_GROUP_INFO:
		case SENSOR_FEATURE_GET_ITEM_INFO:
		case SENSOR_FEATURE_SET_ITEM_INFO:
		case SENSOR_FEATURE_GET_ENG_INFO:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET/get_CCT_xxxx ect \n");
			break;
		case SENSOR_FEATURE_GET_GROUP_COUNT:
			*pFeatureReturnPara32++=0;
			*pFeatureParaLen=4;	   
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_GROUP_COUNT \n");
			break; 
		case SENSOR_FEATURE_GET_LENS_DRIVER_ID:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_GET_LENS_DRIVER_ID \n");
			// get the lens driver ID from EEPROM or just return LENS_DRIVER_ID_DO_NOT_CARE
			// if EEPROM does not exist in camera module.
			*pFeatureReturnPara32=LENS_DRIVER_ID_DO_NOT_CARE;
			*pFeatureParaLen=4;
			break;
		case SENSOR_FEATURE_CHECK_SENSOR_ID:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_CHECK_SENSOR_ID \n");
			OV2659_GetSensorID(pFeatureData32);
			break;
		case SENSOR_FEATURE_SET_YUV_CMD:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_YUV_CMD \n");
			OV2659YUVSensorSetting((FEATURE_ID)*pFeatureData32, *(pFeatureData32+1));
			break;
		case SENSOR_FEATURE_SET_VIDEO_MODE:
			//OV2659SENSORDB("OV2659FeatureControl:SENSOR_FEATURE_SET_VIDEO_MODE \n");
			OV2659YUVSetVideoMode(*pFeatureData16);
			break; 
	#if defined(MT6575)
		case SENSOR_FEATURE_GET_EV_AWB_REF:
			OV2659GetEvAwbRef(*pFeatureData32);
			break;
		case SENSOR_FEATURE_GET_SHUTTER_GAIN_AWB_GAIN:
			OV2659GetCurAeAwbInfo(*pFeatureData32);			
			break;
	#endif
		case SENSOR_FEATURE_GET_EXIF_INFO:
			OV2659SENSORDB("SENSOR_FEATURE_GET_EXIF_INFO\n");
			OV2659SENSORDB("EXIF addr = 0x%x\n",*pFeatureData32);          
			OV2659GetExifInfo(*pFeatureData32);
			break;
		default:
			OV2659SENSORDB("OV2659FeatureControl:default \n");
			break;			
	}
	//OV2659SENSORDB("[OV2659]OV2659FeatureControl exit :\n ");
	return ERROR_NONE;
}	/* OV2659FeatureControl() */


SENSOR_FUNCTION_STRUCT	SensorFuncOV2659=
{
	OV2659Open,
	OV2659GetInfo,
	OV2659GetResolution,
	OV2659FeatureControl,
	OV2659Control,
	OV2659Close
};

UINT32 OV2659_YUV_SensorInit(PSENSOR_FUNCTION_STRUCT *pfFunc)
{
	/* To Do : Check Sensor status here */
	if (pfFunc!=NULL)
	    *pfFunc=&SensorFuncOV2659;

	return ERROR_NONE;
}	/* SensorInit() */


