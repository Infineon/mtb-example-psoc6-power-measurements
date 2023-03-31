/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for CM0+ in the PSoC6 power
*              measurements for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* Copyright 2023, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/
#include "cy_pdl.h"
#include "cycfg.h"
#include "cybsp.h"
#include "cyhal.h"
/* Include to provide app configurations */
#include "specs.h"
/* Include to provide dhrystone implementation */
#include "dhry.h"

/*******************************************************************************
* Macros
********************************************************************************/
/* Key to power off circuits */
#define PWR_OFF_CTL_KEY     0x05FA0000

/* Mask to disable cache */
#define CACHE_DISABLE_MASK  0x0000FFFF

/* RAM Page related constants */
#define RAM_PAGE_SIZE       0x8000U
#define NUM_RAM_PAGES      (CY_SRAM0_SIZE/RAM_PAGE_SIZE)

/*******************************************************************************
* Global Variables
********************************************************************************/
cyhal_clock_t system_clock;

int main(void)
{
    cy_rslt_t result;

    /* Enable global interrupts */
    __enable_irq();
    
    /* Initialize the device and board peripherals */
    result = cybsp_init();
    
      /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS) 
    {
        CY_ASSERT(0);
    }

/* Check if should disable the cache */
#ifdef RUN_FROM_FLASH
    FLASHC->CM4_CA_CTL0 = FLASHC->CM4_CA_CTL0 & CACHE_DISABLE_MASK;
    FLASHC->CM0_CA_CTL0 = FLASHC->CM0_CA_CTL0 & CACHE_DISABLE_MASK;

    /* Set the minimum Wait States */
    #ifdef SYSTEM_LP
        Cy_SysLib_SetWaitStates(false, FREQ_150_MHZ/FREQ_1_MHZ);
    #else
        Cy_SysLib_SetWaitStates(true, FREQ_50_MHZ/FREQ_1_MHZ);
    #endif
#else
    /* Set the minimum Wait States */
    #ifdef SYSTEM_LP
        Cy_SysLib_SetWaitStates(false, CM4_FREQ/FREQ_1_MHZ);
    #else
        Cy_SysLib_SetWaitStates(true, CM4_FREQ/FREQ_1_MHZ);
    #endif
#endif

/* Check if should switch from LDO (default) to BUCK VCCD supply */
#if (VCCD_SUPPLY == BUCK)
    result = Cy_SysPm_SwitchToSimoBuck();
    if (result != CY_RSLT_SUCCESS) 
    {
        CY_ASSERT(0);
    }

    /* Check if should set the VCCD supply to 1.1 V */
    #ifdef SYSTEM_LP
        result = Cy_SysPm_SimoBuckSetVoltage1(CY_SYSPM_SIMO_BUCK_OUT1_VOLTAGE_1_1V);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }
    #endif
#endif

/* Enter the specific System Mode */
#ifdef SYSTEM_LP
    result = cyhal_syspm_set_system_state(CYHAL_SYSPM_SYSTEM_NORMAL);
    if (result != CY_RSLT_SUCCESS) 
    {
        CY_ASSERT(0);
    }
#else
    result = cyhal_syspm_set_system_state(CYHAL_SYSPM_SYSTEM_LOW);
    if (result != CY_RSLT_SUCCESS) 
    {
        CY_ASSERT(0);
    }
#endif

/* Set Minimum Current */
#ifdef MIN_CURRENT
    result =  Cy_SysPm_SystemSetMinRegulatorCurrent();
    if (result != CY_RSLT_SUCCESS) 
    {
        CY_ASSERT(0);
    }
#endif

/* Change the source for High frequency clock */
#if (HF_CLK_SOURCE != IMO)
    /* Check whether CM4 and CM0P frequency is not equal and set the peri divider accordingly */
    #if (CM4_FREQ != CM0P_FREQ)
        result = cyhal_clock_reserve(&system_clock, &CYHAL_CLOCK_PERI);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }

        result = cyhal_clock_set_divider(&system_clock, CM4_FREQ/CM0P_FREQ);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }
    #endif

    #if(HF_CLK_SOURCE == FLL)
        /* Reserve the FLL to system clock */
        result = cyhal_clock_reserve(&system_clock, &CYHAL_CLOCK_FLL);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }
    #elif(HF_CLK_SOURCE == PLL)
        /* Reserve the high frequency clock to system clock*/
        result = cyhal_clock_reserve(&system_clock, &CYHAL_CLOCK_HF[0]);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }
    
        /* Set the PLL source for high frequency clock */
        result = cyhal_clock_set_source(&system_clock, &CYHAL_CLOCK_PLL);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }

        /* Reserve the PLL to system clock */
        result = cyhal_clock_reserve(&system_clock, &CYHAL_CLOCK_PLL);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }
    #endif

    /* Set the frequency for high frequency clock */
    result = cyhal_clock_set_frequency(&system_clock, CM4_FREQ, NULL);      
    if (result != CY_RSLT_SUCCESS) 
    {
        CY_ASSERT(0);
    }

    /* If the clock is not already enabled, enable it */
    if (!cyhal_clock_is_enabled(&system_clock))
    {
        result = cyhal_clock_set_enabled(&system_clock, true, true);
        if (result != CY_RSLT_SUCCESS) 
        {
            CY_ASSERT(0);
        }
    }
#endif

/* Check if CM4 should run */
#ifdef CM4_OFF
    /* Power off CM4 */
    CPUSS->CM4_PWR_CTL = PWR_OFF_CTL_KEY;
#else
    /* Run CM4 */
    Cy_SysEnableCM4(CY_CORTEX_M4_APPL_ADDR);
#endif

/* If in System Deep Sleep, check if SPEC ID requires to shutdown of SRAM */
/* Keep the first two pages (64kB) or eight pages (256kB) enabled */
#if ((SPEC_ID == SIDDS1) || (SPEC_ID == SIDDS2))
    for (uint32_t i = NO_OF_PAGES; i < NUM_RAM_PAGES; i++)
    {
        CPUSS->RAM0_PWR_MACRO_CTL[i] = PWR_OFF_CTL_KEY;
    }
        CPUSS->RAM1_PWR_CTL = PWR_OFF_CTL_KEY;
        CPUSS->RAM2_PWR_CTL = PWR_OFF_CTL_KEY;
        /* Turn-off UDB Block */
        CPUSS->UDB_PWR_CTL = PWR_OFF_CTL_KEY;
#endif

    for(;;) 
    {
        /* Check if CM0+ should enter CPU Sleep */
        #if defined(CM0P_SLEEP)
            cyhal_syspm_sleep();
        /* Check if CM0+ should enter CPU Deep Sleep */
        #elif defined(CM0P_DEEP_SLEEP)
            cyhal_syspm_deepsleep();
        /* Check if CM0+ should run a while loop */
        #elif defined(CM0P_WHILE_LOOP)
            while (1);
        /* Check if CM0+ should run dhrystone */
        #elif defined(CM0P_DHRYSTONE)
            dhrystone();
        /* Check if CM0+ should go to hibernate */
        #elif defined(CM0P_HIBERNATE)
            cyhal_syspm_hibernate(CYHAL_SYSPM_HIBERNATE_PINA_HIGH);
        #endif
    }
}

/* [] END OF FILE */
