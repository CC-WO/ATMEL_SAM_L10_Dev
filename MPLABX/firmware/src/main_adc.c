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

#define ADC_VREF                (3300)  // 3300 mV (3.3V)

uint16_t adc_count;
uint32_t input_voltage;

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );

    // SYSTICK Settings
    SYSTICK_TimerStart();

    // ADC Settings
    ADC_Enable();

    /* Start ADC conversion */
    ADC_ConversionStart();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );



        /* Wait till ADC conversion result is available */
        while(!ADC_ConversionStatusGet())
        {

        };

        /* Read the ADC result */
        adc_count = ADC_ConversionResultGet();
        input_voltage = adc_count * ADC_VREF / 4095U;

        printf("ADC Count = 0x%x, ADC Input Voltage = %d.%03d V \r", adc_count, (int)(input_voltage/1000), (int)(input_voltage%1000));

        SYSTICK_DelayMs(10);
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

