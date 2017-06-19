/* A. Floridia, R. Margelli - MBSD A.Y. 2016/17 DC Motor Assignment*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  <math.h>
#include  <lib_math.h>
#include  <cpu_core.h>

#include  <app_cfg.h>
#include  <os.h>

#include  <fsl_os_abstraction.h>
#include  <system_MK64F12.h>
#include  <board.h>

#include  <bsp_ser.h>

#include <feedback_control.h>	/* MV */
#include <rtwtypes.h>			/* MV */

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#include "fsl_interrupt_manager.h"
#include "fsl_gpio_common.h"

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB       AppStartupTaskTCB;
static  CPU_STK      AppStartupTaskStk[APP_CFG_TASK_START_STK_SIZE];

static  OS_TMR		BaseRateTMR;

/* MV */

/*
 * Model state, input and output
 */
static RT_MODEL_feedback_control feedback_control_M_;
static RT_MODEL_feedback_control *const feedback_control_M = &feedback_control_M_;                /* Real-time model */

/* '<Root>/Error[Deg]' */
static real_T feedback_control_U_control_input;

/* '<Root>/Command[V]' */
static real_T feedback_control_Y_CommandV;

/* This index is used to step through the input stimuli at each invokation of the step function */
static uint16_t index = 0;
/* Input stimuli array */
static real_T inputs[6] = { 83.333333333333333, 82, 84, -83.333333333333333, -82, -84};

/* End of MV */

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppStartupTask (void  *p_arg);
static  void  AppTask (void  *p_arg);

static	void  		setup_adc0( void );
static	uint16_t	ADC_read16b( void );

/*
*********************************************************************************************************
*                                      STEP FUNCTION
*********************************************************************************************************
*/
void	StepFunction( OS_TMR *p_tmr, void *p_arg )
{
		(void)p_arg;
		/* MV */

         /*
		 * Step the controller
		 */
		feedback_control_U_control_input = inputs[index];
		index = (index+1)%6;
	    /* Turn Red and Blue LEDs on/off for debugging */
		feedback_control_step(feedback_control_M, feedback_control_U_control_input, &feedback_control_Y_CommandV);

		/* End of MV */
}
/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : This the main standard entry point.
*
* Note(s)     : none.
*********************************************************************************************************
*/

int  main (void)
{
    OS_ERR   err;

#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_ERR  cpu_err;
#endif

    hardware_init();

    GPIO_DRV_Init(switchPins, ledPins);

    setup_adc0();

#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_NameSet((CPU_CHAR *)"MK64FN1M0VMD12",
                (CPU_ERR  *)&cpu_err);
#endif

    BSP_Ser_Init(115200u);
    OSA_Init();                                                 /* Init uC/OS-III.                                      */

    OSTaskCreate(&AppStartupTaskTCB,                              /* Create the start task                                */
                 "App Startup Task",
                  AppStartupTask,
                  0u,
                  APP_CFG_TASK_START_PRIO,
                 &AppStartupTaskStk[0u],
                 (APP_CFG_TASK_START_STK_SIZE / 10u),
                  APP_CFG_TASK_START_STK_SIZE,
                  0u,
                  0u,
                  0u,
                 (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR | OS_OPT_TASK_SAVE_FP),
                 &err);

    /* MV */
    /* Turn Green LED on/off. Just to have a quick visual feedback of operation starting. */
	GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_GREEN);
	GPIO_DRV_TogglePinOutput(BOARD_GPIO_LED_GREEN);
	/* End of MV */

    OSA_Start();                                                /* Start multitasking (i.e. give control to uC/OS-III). */

    while (DEF_ON) {                                            /* Should Never Get Here                                */
        ;
    }
}


/*
*********************************************************************************************************
*                                          TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  AppStartupTask (void *p_arg)
{
    OS_ERR    os_err;

    (void)p_arg;                                                /* See Note #1                                          */

    CPU_Init();                                                 /* Initialize the uC/CPU Services.                      */
    Mem_Init();                                                 /* Initialize the Memory Management Module              */
    Math_Init();                                                /* Initialize the Mathematical Module                   */

    GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_RED);
    GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_GREEN);
    GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_BLUE);

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&os_err);                            /* Compute CPU capacity with no task running            */
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

    /* Initialize model */
    feedback_control_initialize(feedback_control_M);

    OSTmrCreate(&BaseRateTMR,
    			"Base Rate Timer",
				0,
				1,					/* MV 1 = 1 msec after having set OS_CFG_TMR_TASK_RATE_HZ to 1000u. See https://doc.micrium.com/display/osiiidoc30600/OSTmrCreate */
				OS_OPT_TMR_PERIODIC,
				(OS_TMR_CALLBACK_PTR)StepFunction,
				NULL,
				&os_err);
    OSTmrStart( &BaseRateTMR, &os_err );

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    	OSTimeDlyHMSM(0, 0, 0, 100, OS_OPT_TIME_HMSM_STRICT, &os_err);
    }
}

static	void  setup_adc0( void )
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	ADC0_CFG1 |= ADC_CFG1_MODE(3);			/* 16bits ADC*/
	ADC0_SC1A |= ADC_SC1_ADCH(31);			/* Disable the module, ADCH = 1111 */

}

static uint16_t ADC_read16b(void)
{
	ADC0_SC1A = 12 & ADC_SC1_ADCH_MASK; 					//Write to SC1B to start conversion
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK)
		;  												//Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK))
		;												//Until conversion complete
	return ADC0_RA;
}
