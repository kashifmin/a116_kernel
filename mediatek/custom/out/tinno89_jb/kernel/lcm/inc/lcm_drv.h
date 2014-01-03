#ifndef __LCM_DRV_H__
#define __LCM_DRV_H__


// ---------------------------------------------------------------------------

#ifndef ARY_SIZE
#define ARY_SIZE(x) (sizeof((x)) / sizeof((x[0])))
#endif

// ---------------------------------------------------------------------------

/* common enumerations */

typedef enum
{
    LCM_TYPE_DBI = 0,
    LCM_TYPE_DPI,
    LCM_TYPE_DSI
} LCM_TYPE;


typedef enum
{
    LCM_CTRL_NONE = 0,
    LCM_CTRL_SERIAL_DBI,
    LCM_CTRL_PARALLEL_DBI,
    LCM_CTRL_GPIO
} LCM_CTRL;


typedef enum
{
    LCM_POLARITY_RISING  = 0,
    LCM_POLARITY_FALLING = 1
} LCM_POLARITY;


typedef enum
{
    LCM_CLOCK_PHASE_0  = 0,
    LCM_CLOCK_PHASE_90 = 1
} LCM_CLOCK_PHASE;


typedef enum
{
    LCM_COLOR_ORDER_RGB = 0,
    LCM_COLOR_ORDER_BGR = 1
} LCM_COLOR_ORDER;


typedef enum
{    
   LCM_DRIVING_CURRENT_8MA       = (1 << 0),
   LCM_DRIVING_CURRENT_4MA       = (1 << 1),
   LCM_DRIVING_CURRENT_2MA       = (1 << 2),
   LCM_DRIVING_CURRENT_SLEW_CNTL = (1 << 3),
   LCM_DRIVING_CURRENT_6575_4MA  = (1 << 4),
   LCM_DRIVING_CURRENT_6575_8MA  = (3 << 4),
   LCM_DRIVING_CURRENT_6575_12MA  = (2 << 4),
   LCM_DRIVING_CURRENT_6575_16MA  = (4 << 4)
} LCM_DRIVING_CURRENT;


/* DBI related enumerations */

typedef enum
{
    LCM_DBI_CLOCK_FREQ_104M = 0,
    LCM_DBI_CLOCK_FREQ_52M,
    LCM_DBI_CLOCK_FREQ_26M,
    LCM_DBI_CLOCK_FREQ_13M,
    LCM_DBI_CLOCK_FREQ_7M
} LCM_DBI_CLOCK_FREQ;


typedef enum
{
    LCM_DBI_DATA_WIDTH_8BITS  = 0,
    LCM_DBI_DATA_WIDTH_9BITS  = 1,
    LCM_DBI_DATA_WIDTH_16BITS = 2,
    LCM_DBI_DATA_WIDTH_18BITS = 3,
    LCM_DBI_DATA_WIDTH_24BITS = 4,
	LCM_DBI_DATA_WIDTH_32BITS = 5
} LCM_DBI_DATA_WIDTH;


typedef enum
{
    LCM_DBI_CPU_WRITE_8_BITS  = 8,
    LCM_DBI_CPU_WRITE_16_BITS = 16,
    LCM_DBI_CPU_WRITE_32_BITS = 32,
} LCM_DBI_CPU_WRITE_BITS;


typedef enum
{
    LCM_DBI_FORMAT_RGB332 = 0,
    LCM_DBI_FORMAT_RGB444 = 1,
    LCM_DBI_FORMAT_RGB565 = 2,
    LCM_DBI_FORMAT_RGB666 = 3,
    LCM_DBI_FORMAT_RGB888 = 4
} LCM_DBI_FORMAT;


typedef enum
{
    LCM_DBI_TRANS_SEQ_MSB_FIRST = 0,
    LCM_DBI_TRANS_SEQ_LSB_FIRST = 1
} LCM_DBI_TRANS_SEQ;


typedef enum
{
    LCM_DBI_PADDING_ON_LSB = 0,
    LCM_DBI_PADDING_ON_MSB = 1
} LCM_DBI_PADDING;


typedef enum
{
    LCM_DBI_TE_MODE_DISABLED       = 0,
    LCM_DBI_TE_MODE_VSYNC_ONLY     = 1,
    LCM_DBI_TE_MODE_VSYNC_OR_HSYNC = 2,
} LCM_DBI_TE_MODE;


typedef enum
{
    LCM_DBI_TE_VS_WIDTH_CNT_DIV_8  = 0,
    LCM_DBI_TE_VS_WIDTH_CNT_DIV_16 = 1,
    LCM_DBI_TE_VS_WIDTH_CNT_DIV_32 = 2,
    LCM_DBI_TE_VS_WIDTH_CNT_DIV_64 = 3,
} LCM_DBI_TE_VS_WIDTH_CNT_DIV;


/* DPI related enumerations */

typedef enum
{
    LCM_DPI_FORMAT_RGB565 = 0,
    LCM_DPI_FORMAT_RGB666 = 1,
    LCM_DPI_FORMAT_RGB888 = 2
} LCM_DPI_FORMAT;

typedef enum
{
    LCM_SERIAL_CLOCK_FREQ_104M = 0,
    LCM_SERIAL_CLOCK_FREQ_26M,
	LCM_SERIAL_CLOCK_FREQ_52M
} LCM_SERIAL_CLOCK_FREQ;

typedef enum
{
    LCM_SERIAL_CLOCK_DIV_2 = 0,
    LCM_SERIAL_CLOCK_DIV_4 = 1,
    LCM_SERIAL_CLOCK_DIV_8 = 2,
    LCM_SERIAL_CLOCK_DIV_16 = 3,
} LCM_SERIAL_CLOCK_DIV;


/* DSI related enumerations */

typedef enum
{
	CMD_MODE = 0,
	SYNC_PULSE_VDO_MODE = 1,
	SYNC_EVENT_VDO_MODE = 2,
	BURST_VDO_MODE = 3
} LCM_DSI_MODE_CON;


typedef enum
{
	LCM_ONE_LANE = 1,
	LCM_TWO_LANE = 2,
	LCM_THREE_LANE = 3,
	LCM_FOUR_LANE = 4,
} LCM_LANE_NUM;


typedef enum
{
    LCM_DSI_FORMAT_RGB565 = 0,
    LCM_DSI_FORMAT_RGB666 = 1,
    LCM_DSI_FORMAT_RGB888 = 2
} LCM_DSI_FORMAT;


typedef enum
{
    LCM_DSI_TRANS_SEQ_MSB_FIRST = 0,
    LCM_DSI_TRANS_SEQ_LSB_FIRST = 1
} LCM_DSI_TRANS_SEQ;


typedef enum
{
    LCM_DSI_PADDING_ON_LSB = 0,
    LCM_DSI_PADDING_ON_MSB = 1
} LCM_DSI_PADDING;


typedef enum
{
	LCM_PACKED_PS_16BIT_RGB565=0,
	LCM_LOOSELY_PS_18BIT_RGB666=1,	
	LCM_PACKED_PS_24BIT_RGB888=2,
	LCM_PACKED_PS_18BIT_RGB666=3		
} LCM_PS_TYPE;


// ---------------------------------------------------------------------------

typedef struct 
{
    LCM_COLOR_ORDER color_order;
    LCM_DBI_TRANS_SEQ trans_seq;
    LCM_DBI_PADDING padding;
    LCM_DBI_FORMAT format;
    LCM_DBI_DATA_WIDTH width;
} LCM_DBI_DATA_FORMAT;


typedef struct
{
    LCM_POLARITY cs_polarity;
    LCM_POLARITY clk_polarity;
    LCM_CLOCK_PHASE clk_phase;
    unsigned int is_non_dbi_mode;

	LCM_SERIAL_CLOCK_FREQ clock_base;
	LCM_SERIAL_CLOCK_DIV  clock_div;
////////////////////////////////////MT6575 added params, and if lcm driver is for 6575, only care these below params
	unsigned int css;
	unsigned int csh;	
	unsigned int rd_1st;
	unsigned int rd_2nd;
	unsigned int wr_1st;
	unsigned int wr_2nd;

	unsigned int sif_3wire;
	unsigned int sif_sdi;
	LCM_POLARITY sif_1st_pol;
	LCM_POLARITY sif_sck_def;
	unsigned int sif_div2;
	unsigned int sif_hw_cs;
////////////////////////////////////	
} LCM_DBI_SERIAL_PARAMS;


typedef struct
{
    /* timing parameters */
    unsigned int write_setup;
    unsigned int write_hold;
    unsigned int write_wait;
    unsigned int read_setup;
	unsigned int read_hold;
    unsigned int read_latency;
    unsigned int wait_period;
	/*only for 6575*/
	unsigned int cs_high_width;
} LCM_DBI_PARALLEL_PARAMS;


typedef struct 
{
    LCM_COLOR_ORDER color_order;
    LCM_DSI_TRANS_SEQ trans_seq;
    LCM_DSI_PADDING padding;
    LCM_DSI_FORMAT format;
} LCM_DSI_DATA_FORMAT;


// ---------------------------------------------------------------------------

typedef struct
{
    /* common parameters for serial & parallel interface */
    unsigned int port;
    LCM_DBI_CLOCK_FREQ     clock_freq;
    LCM_DBI_DATA_WIDTH     data_width; 
    LCM_DBI_DATA_FORMAT    data_format;
    LCM_DBI_CPU_WRITE_BITS cpu_write_bits;
    LCM_DRIVING_CURRENT    io_driving_current;
    
    /* tearing control */
    LCM_DBI_TE_MODE              te_mode;
    LCM_POLARITY                 te_edge_polarity;
    unsigned int                 te_hs_delay_cnt;
    unsigned int                 te_vs_width_cnt;
    LCM_DBI_TE_VS_WIDTH_CNT_DIV  te_vs_width_cnt_div;
    
    /* particular parameters for serial & parallel interface */
    union {
        LCM_DBI_SERIAL_PARAMS serial;
        LCM_DBI_PARALLEL_PARAMS parallel;
    };
} LCM_DBI_PARAMS;


typedef struct
{
    /* 
        Pixel Clock Frequency = 26MHz * mipi_pll_clk_div1
                                      / (mipi_pll_clk_ref + 1) 
                                      / (2 * mipi_pll_clk_div2)
                                      / dpi_clk_div
    */
    unsigned int mipi_pll_clk_ref;   // 0..1
    unsigned int mipi_pll_clk_div1;  // 0..63
    unsigned int mipi_pll_clk_div2;  // 0..15
    unsigned int dpi_clk_div;        // 2..32

    unsigned int dpi_clk_duty;       // (dpi_clk_div - 1) .. 31

    /* polarity parameters */
    LCM_POLARITY clk_pol;
    LCM_POLARITY de_pol;
    LCM_POLARITY vsync_pol;
    LCM_POLARITY hsync_pol;

    /* timing parameters */
    unsigned int hsync_pulse_width;
    unsigned int hsync_back_porch;
    unsigned int hsync_front_porch;
    unsigned int vsync_pulse_width;
    unsigned int vsync_back_porch;
    unsigned int vsync_front_porch;
    
    /* output format parameters */
    LCM_DPI_FORMAT format;
    LCM_COLOR_ORDER rgb_order;
    unsigned int is_serial_output;
	unsigned int i2x_en;
	unsigned int i2x_edge;
	unsigned int embsync;
    /* intermediate buffers parameters */
    unsigned int intermediat_buffer_num; // 2..3

    /* iopad parameters */
    LCM_DRIVING_CURRENT io_driving_current;
    
} LCM_DPI_PARAMS;


// ---------------------------------------------------------------------------

typedef struct
{
	LCM_DSI_MODE_CON 	mode;
	unsigned int		DSI_WMEM_CONTI;
	unsigned int		DSI_RMEM_CONTI;	
	unsigned int		VC_NUM;

	LCM_LANE_NUM		LANE_NUM;
	LCM_DSI_DATA_FORMAT	data_format;

    /* intermediate buffers parameters */
    unsigned int 		intermediat_buffer_num; // 2..3
	
	LCM_PS_TYPE			PS;	
	unsigned int		word_count;
	
	unsigned int		packet_size;

	unsigned int		vertical_sync_active;
	unsigned int		vertical_backporch;
	unsigned int		vertical_frontporch;
	unsigned int		vertical_active_line;

	unsigned int		horizontal_sync_active;
	unsigned int		horizontal_backporch;
	unsigned int		horizontal_frontporch;
	unsigned int		horizontal_active_pixel;

	unsigned int		line_byte;
	unsigned int		horizontal_sync_active_byte;
	unsigned int		horizontal_backporch_byte;
	unsigned int		horizontal_frontporch_byte; 
	unsigned int		rgb_byte; 

	unsigned int		horizontal_sync_active_word_count;	
	unsigned int		horizontal_backporch_word_count;
	unsigned int		horizontal_frontporch_word_count;

	unsigned char		HS_TRAIL;
	unsigned char		HS_ZERO;
	unsigned char		HS_PRPR;
	unsigned char		LPX;

	unsigned char		TA_SACK;
	unsigned char		TA_GET;
	unsigned char		TA_SURE;	
	unsigned char		TA_GO;

	unsigned char		CLK_TRAIL;
	unsigned char		CLK_ZERO;	
	unsigned char		LPX_WAIT;
	unsigned char		CONT_DET;

	unsigned char		CLK_HS_PRPR;
	unsigned char		CLK_HS_POST;
	unsigned char       DA_HS_EXIT;
	unsigned char       CLK_HS_EXIT;
	
	unsigned int		pll_div1;
	unsigned int		pll_div2;	
	unsigned int        fbk_div;
	unsigned int		fbk_sel;
	unsigned int		rg_bir;
	unsigned int		rg_bic;
	unsigned int		rg_bp;
	
	unsigned int		lcm_int_te_monitor;
	unsigned int		lcm_int_te_period;
	
	unsigned int		lcm_ext_te_monitor;
	
	unsigned int		noncont_clock;
	unsigned int		noncont_clock_period;
	
} LCM_DSI_PARAMS;

// ---------------------------------------------------------------------------

typedef struct
{
    LCM_TYPE type;
    LCM_CTRL ctrl;  //! how to control LCM registers

    /* common parameters */
    unsigned int width;
    unsigned int height;
	unsigned int io_select_mode; //DBI or DPI should select IO mode according to chip spec
    /* particular parameters */
    LCM_DBI_PARAMS dbi;
    LCM_DPI_PARAMS dpi;
    LCM_DSI_PARAMS dsi;
} LCM_PARAMS;


// ---------------------------------------------------------------------------

#define REGFLAG_ESCAPE_ID		(0x00)
#define REGFLAG_DELAY_MS_V3		(0xFF)

typedef struct {
    unsigned char id;    
    unsigned char cmd;
    unsigned char count;
    unsigned char para_list[128];
} LCM_setting_table_V3;

typedef struct
{
    void (*set_reset_pin)(unsigned int value);
    int  (*set_gpio_out)(unsigned int gpio, unsigned int value);

    void (*udelay)(unsigned int us);
    void (*mdelay)(unsigned int ms);

    void (*send_cmd)(unsigned int cmd);
    void (*send_data)(unsigned int data);
    unsigned int (*read_data)(void);

	void (*dsi_set_cmdq_V3)(LCM_setting_table_V3 *para_list, unsigned int size, unsigned char force_update);
	void (*dsi_set_cmdq_V2)(unsigned cmd, unsigned char count, unsigned char *para_list, unsigned char force_update);
	void (*dsi_set_cmdq)(unsigned int *pdata, unsigned int queue_size, unsigned char force_update);
	void (*dsi_write_cmd)(unsigned int cmd);
	void (*dsi_write_regs)(unsigned int addr, unsigned int *para, unsigned int nums);
	unsigned int (*dsi_read_reg)(void);
	unsigned int (*dsi_dcs_read_lcm_reg)(unsigned char cmd);
	unsigned int (*dsi_dcs_read_lcm_reg_v2)(unsigned char cmd, unsigned char *buffer, unsigned char buffer_size);
    void (*wait_transfer_done)(void);

    /** FIXME: GPIO mode should not be configured in lcm driver
               REMOVE ME after GPIO customization is done    
    */
    int (*set_gpio_mode)(unsigned int pin, unsigned int mode);
    int (*set_gpio_dir)(unsigned int pin, unsigned int dir);
    int (*set_gpio_pull_enable)(unsigned int pin, unsigned char pull_en);
    
} LCM_UTIL_FUNCS;


typedef struct
{
    const char* name;
    void (*set_util_funcs)(const LCM_UTIL_FUNCS *util);
    void (*get_params)(LCM_PARAMS *params);

    void (*init)(void);
    void (*suspend)(void);
    void (*resume)(void);

    void (*update)(unsigned int x, unsigned int y,
                   unsigned int width, unsigned int height);
	unsigned int (*compare_id)(void);
///////////////////////////CABC backlight related function
	void (*set_backlight)(unsigned int level);
	void (*set_pwm)(unsigned int divider);
	unsigned int (*get_pwm)(unsigned int divider);
	void (*set_backlight_mode)(unsigned int mode);
///////////////////////////

/////////////ESD_RECOVERY//////////////////////
    unsigned int (*esd_check)(void);
    unsigned int  (*esd_recover)(void);
	unsigned int (*check_status)(void);
/////////////////////////////////////////////////

} LCM_DRIVER;


// ---------------------------------------------------------------------------
//  LCM Driver Functions
// ---------------------------------------------------------------------------

const LCM_DRIVER* LCM_GetDriver(void);

#endif // __LCM_DRV_H__
