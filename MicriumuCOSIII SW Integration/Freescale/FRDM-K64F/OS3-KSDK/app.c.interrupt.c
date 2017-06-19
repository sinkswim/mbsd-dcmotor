/*
*********************************************************************************************************
*                                            EXAMPLE CODE
*
*               This file is provided as an example on how to use Micrium products.
*
*               Please feel free to use any application code labeled as 'EXAMPLE CODE' in
*               your application products.  Example code may be used as is, in whole or in
*               part, or may be used as a reference only. This file can be modified as
*               required to meet the end-product requirements.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*
*               You can find our product's user manual, API reference, release notes and
*               more information at https://doc.micrium.com.
*               You can contact us at www.micrium.com.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                            EXAMPLE CODE
*
*                                        Freescale Kinetis K64
*                                               on the
*
*                                         Freescale FRDM-K64F
*                                          Evaluation Board
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : FF
*********************************************************************************************************
*/

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


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/
#define		INTERRUPT_ENABLED

#ifdef INTERRUPT_ENABLED
	#include "fsl_interrupt_manager.h"
	#include "fsl_gpio_common.h"
#endif

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB       AppStartupTaskTCB;
static  CPU_STK      AppStartupTaskStk[APP_CFG_TASK_START_STK_SIZE];

static  OS_TCB       AppTaskTCB;
static  CPU_STK      AppTaskStk[APP_CFG_TASK_START_STK_SIZE];



/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  AppStartupTask (void  *p_arg);
static  void  AppTask (void  *p_arg);

#ifdef INTERRUPT_ENABLED
	static  void BSP_SW1_int_hdlr( void );
#endif

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


#if (CPU_CFG_NAME_EN == DEF_ENABLED)
    CPU_NameSet((CPU_CHAR *)"MK64FN1M0VMD12",
                (CPU_ERR  *)&cpu_err);
#endif

#ifdef INTERRUPT_ENABLED
    INT_SYS_InstallHandler(PORTC_IRQn, BSP_SW1_int_hdlr);
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

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&os_err);                            /* Compute CPU capacity with no task running            */
#endif

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

    OSTaskCreate(&AppTaskTCB,                              /* Create the start task                                */
                     "App Task",
                      AppTask,
                      0u,
                      APP_CFG_TASK_START_PRIO,
                     &AppTaskStk[0u],
                     (APP_CFG_TASK_START_STK_SIZE / 10u),
                      APP_CFG_TASK_START_STK_SIZE,
                      0u,
                      0u,
                      0u,
                     (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR | OS_OPT_TASK_SAVE_FP),
                     &os_err);

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    }
}

static  void  AppTask (void *p_arg)
{
    (void)p_arg;                                                /* See Note #1                                          */

    GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_RED);
    GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_GREEN);
    GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_BLUE);

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */

#ifndef INTERRUPT_ENABLED
    	if( GPIO_DRV_ReadPinInput(kGpioSW1) == 1 )				/* Switches are active low: pressed=0, not pressed=1    */
    		GPIO_DRV_SetPinOutput(BOARD_GPIO_LED_BLUE);			/* LED are active low: set = off, clear = on            */
    	else
    		GPIO_DRV_ClearPinOutput(BOARD_GPIO_LED_BLUE);
#endif
    }
}

volatile uint32_t lock = 0;

#ifdef INTERRUPT_ENABLED
/*
 * Interrupt handler for switch 1
 */
void BSP_SW1_int_hdlr( void )
{
  static uint8_t flag = 0;
  uint32_t ifsr;         /* interrupt flag status register */
  uint32_t portBaseAddr = g_portBaseAddr[GPIO_EXTRACT_PORT(kGpioSW1)];

  CPU_CRITICAL_ENTER();											/* Disable interrupts									*/
  OSIntEnter();                                               	/* Tell the OS that we are starting an ISR              */

  ifsr = PORT_HAL_GetPortIntFlag(portBaseAddr);

  if( (ifsr & (1 << GPIO_EXTRACT_PIN(kGpioSW1))) )              /* Check if the pending interrupt is for kGpioSW1       */
  {																/* If yes, do your mission                              */
    if( flag )
    {
          GPIO_DRV_SetPinOutput( BOARD_GPIO_LED_RED );
          flag = 0;
          lock=0;
    }
    else
    {
        if(lock==0)
        {
            GPIO_DRV_ClearPinOutput( BOARD_GPIO_LED_RED );
            flag = 1;
            lock=1;
        }
    }

    GPIO_DRV_ClearPinIntFlag( kGpioSW1 );
  }

  CPU_CRITICAL_EXIT();											/* Re-enable interrupts									*/

  OSIntExit();													/* Tell the OS we are exiting from an ISR				*/
}
#endif
