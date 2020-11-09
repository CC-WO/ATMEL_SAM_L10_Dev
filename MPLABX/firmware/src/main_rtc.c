/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

void RTC_Timeout_Handler(RTC_TIMER32_INT_MASK intCause, uintptr_t context)
{

    static uint32_t timer = 0;

    if(RTC_TIMER32_INT_MASK_CMP0  == (RTC_TIMER32_INT_MASK_CMP0 & intCause ))
    {
        LED_Toggle();
        // printf("RTC:%"PRIu32"\r\n", timer);
    }

    timer++;
}

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    // RTC Settings
    RTC_Timer32CallbackRegister(RTC_Timeout_Handler, (uintptr_t) NULL);
    RTC_Timer32InterruptEnable(RTC_TIMER32_INT_MASK_CMP0);
    RTC_Timer32Start();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

