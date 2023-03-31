/******************************************************************************
* File Name:   specs.h
*
* Description: This is the application specification header file
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
#ifndef SPECS_H
#define SPECS_H

/* Consult the datasheet and pick one of the SPEC IDs from the CPU current 
 * measurents table. All specs are also listed in this file. Set the 
 * #define SPEC_ID below to the desired value. You can also set to CUSTOM
 * and define your own settings.
 */
#define SPEC_ID     SIDF1
   
/* Set the VCCD Supply source. Two values are accepted: BUCK or LDO */
#define VCCD_SUPPLY BUCK
      
/*********************************************************************
 * LP Range Power Specifications (for Vccd = 1.1V with Buck and LDO)
 *********************************************************************/   
/* Cortex M4. Active Mode 
 *********************************************************************/
/* Execute with Cache Disabled (Flash)
 *********************************************************************/
/* SIDF1    | Execute from Flash; CM4 Active 50 MHz, CM0+ Sleep 25 MHz.
 *          | With IMO & FLL. While (1)
 * SIDF2    | Execute from Flash; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. While (1)
 *********************************************************************/   
/* Execute with Cache Enabled
 *********************************************************************/
/* SIDC1    | Execute from Cache; CM4 Active 150 MHz, CM0+ Sleep 75 MHz.
 *          | IMO & PLL. Dhrystone.
 * SIDC2    | Execute from Cache; CM4 Active 100 MHz, CM0+ Sleep 100 MHz.
 *          | IMO & FLL. Dhrystone.
 * SIDC3    | Execute from Cache; CM4 Active 50 MHz, CM0+ Sleep 25 MHz.
 *          | IMO & FLL. Dhrystone.
 * SIDC4    | Execute from Cache; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. Dhrystone.
 *********************************************************************/
/* Cortex M0+. Active Mode 
 *********************************************************************/
/* Execute with Cache Disabled (Flash)
 *********************************************************************/
/* SIDF3    | Execute from Flash; CM4 Off, CM0+ Active 50 MHz.
 *          | With IMO & FLL. While (1)
 * SIDF4    | Execute from Flash; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. While (1)
 *********************************************************************/  
/* Execute with Cache Enabled
 *********************************************************************/
/* SIDC5    | Execute from Cache; CM4 Off, CM0+ Active 100 MHz.
 *          | With IMO & FLL. Dhrystone.
 * SIDC6    | Execute from Cache; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. Dhrystone.
 *********************************************************************/    
/* Cortex M4. Sleep Mode
 *********************************************************************/    
/* SIDS1    | CM4 Sleep 100 MHz; CM0+ Sleep 25 MHz. With IMO & FLL.
 * SIDS2    | CM4 Sleep 50 MHz; CM0+ Sleep 25 MHz. With IMO & FLL.
 * SIDS3    | CM4 Sleep 8 MHz; CM0+ Sleep 8 MHz. With IMO.
 *********************************************************************/    
/* Cortex M0+. Sleep Mode
 *********************************************************************/  
/* SIDS4    | CM4 Off; CM0+ Sleep 50 MHz. With IMO & FLL.    
 * SIDS5    | CM4 Off; CM0+ Sleep 8 MHz. With IMO.
 *********************************************************************/    
/* Cortex M4. Minimum Regulator Current Mode
 *********************************************************************/   
/* SIDLPA1  | Execute from Flash; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. While (1)
 * SIDLPA2  | Execute from Cache; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. Dhrystone.
 *********************************************************************/    
/* Cortex M0+. Minimum Regulator Current Mode
 *********************************************************************/   
/* SIDLPA3  | Execute from Flash; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. While (1)
 * SIDLPA4  | Execute from Cache; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. Dhrystone .  
 *********************************************************************/    
/* Cortex M4. Minimum Regulator Current Mode
 *********************************************************************/    
/* SIDLPS1  | CM4 Sleep 8 MHz, CM0+ Sleep 8 MHz. With IMO.
 *********************************************************************/    
/* Cortex M0+. Minimum Regulator Current Mode
 *********************************************************************/   
/* SIDLPS3  | CM4 Off, CM0+ Sleep 8 MHz. With IMO.
 *********************************************************************/
/*********************************************************************
 * ULP Range Power Specifications (for Vccd = 0.9V using the Buck)
 *********************************************************************/   
/* Cortex M4. Active Mode 
 *********************************************************************/
/* Execute with Cache Disabled (Flash)
 *********************************************************************/ 
/* SIDF5    | Execute from Flash; CM4 Active 50 MHz, CM0+ Sleep 25 MHz.
 *          | with IMO & FLL. While (1)
 * SIDF6    | Execute from Flash; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. While (1)    
 *********************************************************************/   
/* Execute with Cache Enabled
 *********************************************************************/
/* SIDC8    | Execute from Cache; CM4 Active 50 MHz, CM0+ Sleep 25 MHz.
 *          | IMO & FLL. Dhrystone.
 * SIDC9    | Execute from Cache; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. Dhrystone.    
 *********************************************************************/
/* Cortex M0+. Active Mode 
 *********************************************************************/
/* Execute with Cache Disabled (Flash)
 *********************************************************************/
/* SIDF7    | Execute from Flash; CM4 Off, CM0+ Active 25 MHz.
 *          | With IMO & FLL. While (1)
 * SIDF8    | Execute from Flash; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. While (1)    
 *********************************************************************/  
/* Execute with Cache Enabled
 *********************************************************************/
/* SIDC10   | Execute from Cache; CM4 Off, CM0+ Active 25 MHz.
 *          | With IMO & FLL. Dhrystone.
 * SIDC11   | Execute from Cache; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. Dhrystone.
 *********************************************************************/    
/* Cortex M4. Sleep Mode
 *********************************************************************/    
/* SIDS7    | CM4 Sleep 50 MHz; CM0+ Sleep 25 MHz. With IMO & FLL.
 * SIDS8    | CM4 Sleep 8 MHz; CM0+ Sleep 8 MHz. With IMO.    
 *********************************************************************/    
/* Cortex M0+. Sleep Mode
 *********************************************************************/  
/* SIDS9    | CM4 Off; CM0+ Sleep 25 MHz. With IMO & FLL.    
 * SIDS10   | CM4 Off; CM0+ Sleep 8 MHz. With IMO.    
 *********************************************************************/    
/* Cortex M4. Minimum Regulator Current Mode
 *********************************************************************/   
/* SIDLPA5  | Execute from Flash; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. While (1)
 * SIDLPA6  | Execute from Cache; CM4 Active 8 MHz, CM0+ Sleep 8 MHz.
 *          | With IMO. Dhrystone.
 *********************************************************************/    
/* Cortex M0+. Minimum Regulator Current Mode
 *********************************************************************/   
/* SIDLPA7  | Execute from Flash; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. While (1)
 * SIDLPA8  | Execute from Cache; CM4 Off, CM0+ Active 8 MHz.
 *          | With IMO. Dhrystone .     
 *********************************************************************/    
/* Cortex M4. Minimum Regulator Current Mode
 *********************************************************************/    
/* SIDLPS5  | CM4 Sleep 8 MHz, CM0+ Sleep 8 MHz. With IMO.
 *********************************************************************/    
/* Cortex M0+. Minimum Regulator Current Mode
 *********************************************************************/   
/* SIDLPS7  | CM4 Off, CM0+ Sleep 8 MHz. With IMO.
 *********************************************************************/    
/* Deep Sleep Mode
 *********************************************************************/       
/* SIDDS1   | With internal Buck enabled and 64 KB SRAM retention
 * SIDDS2   | With internal Buck enabled and 256 KB SRAM retention
 *********************************************************************/       
/* Hibernate Mode
 *********************************************************************/ 
/* SIDHIB1  | Vddd = 1.8 V
 * SIDHIB2  | Vddd = 3.3 V
 *********************************************************************/ 
    
/* VCCD Supply source constants */
#define BUCK    0U
#define LDO     1U

/* Source for High frequency clock */
#define IMO    0U
#define FLL    1U
#define PLL    2U

/* SPEC IDs constants */
#define CUSTOM  0
#define SIDF1   1
#define SIDF2   2
#define SIDC1   3
#define SIDC2   4
#define SIDC3   5
#define SIDC4   6
#define SIDF3   7
#define SIDF4   8
#define SIDC5   9
#define SIDC6   10
#define SIDS1   11
#define SIDS2   12
#define SIDS3   13
#define SIDS4   14
#define SIDS5   15 
#define SIDLPA1 16
#define SIDLPA2 17
#define SIDLPA3 18
#define SIDLPA4 19
#define SIDLPS1 20
#define SIDLPS3 22
#define SIDF5   103
#define SIDF6   104
#define SIDC8   110
#define SIDC9   111
#define SIDF7   116
#define SIDF8   117
#define SIDC10  118
#define SIDC11  119
#define SIDS7   121
#define SIDS8   122
#define SIDS9   123
#define SIDS10  124
#define SIDLPA5 125
#define SIDLPA6 126
#define SIDLPA7 127
#define SIDLPA8 128
#define SIDLPS5 129
#define SIDLPS7 131
#define SIDDS1  1330
#define SIDDS2  1331
#define SIDHIB1 1340
#define SIDHIB2 1341
    
/* Frequency constants */
#define FREQ_1_MHZ      1000000UL
#define FREQ_8_MHZ      8000000UL
#define FREQ_25_MHZ     25000000UL
#define FREQ_50_MHZ     50000000UL
#define FREQ_75_MHZ     75000000UL
#define FREQ_100_MHZ    100000000UL
#define FREQ_150_MHZ    150000000UL  
    
/*********************************************************************
 * Configuration Options
 *********************************************************************/   
/* System Mode         | SYSTEM_LP  : Enter System Low Power Mode 
 *                     | SYSTEM_ULP : Enter System Ultra-Low Power Mode
 * Cache Support       | RUN_FROM_FLASH : Disable Cache
 *                     | RUN_FROM_CACHE : Enable cache
 * CM4 CPU Mode        | CM4_WHILE_LOOP : Runs a forever while loop
 *                     | CM4_DHRYSTONE  : Runs the Dhrystone instructions
 *                     | CM4_SLEEP      : Go to Sleep
 *                     | CM4_DEEP_SLEEP : Go to Deep Sleep
 * CM4 CPU Frequency   | FREQ_8_MHZ   : Set to 8 MHz
 * [CM4_FREQ]      | FREQ_25_MHZ  : Set to 25 MHz
 *                     | FREQ_50_MHZ  : Set to 50 MHz
 *                     | FREQ_100_MHZ : Set to 100 MHz
 * CM0+ CPU Mode       | CM0P_WHILE_LOOP : Runs a forever while loop
 *                     | CM0P_DHRYSTONE  : Runs the Dhrystone instructions
 *                     | CM0P_SLEEP      : Go to Sleep
 *                     | CM0P_DEEP_SLEEP : Go to Deep Sleep
 *                     | CM0P_HIBERNATE  : Go to Hibernate
 * CM0+ CPU Frequency  | FREQ_8_MHZ   : Set to 8 MHz
 * [CM0P_FREQ]     | FREQ_25_MHZ  : Set to 25 MHz
 *                     | FREQ_50_MHZ  : Set to 50 MHz
 *                     | FREQ_100_MHZ : Set to 100 MHz
 * HF Clock Source     | IMO : Use IMO only
 * [HF_CLK_SOURCE]     | FLL : Use FLL sourced from IMO
 *                     | PLL : Use PLL sourced from IMO
 * SRAM retention      | NO_OF_PAGES : Number of pages should be keep
 * [NO_OF_PAGES]       | if NO_OF_PAGES = 2, 64KB SRAM retention
 *                     | if NO_OF_PAGES = 8, 256KB SRAM retention
 * Minimum Regulator   | MIN_CURRENT : Set minimum regulator current mode
 *********************************************************************/
    
#if (SPEC_ID == CUSTOM)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_100_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_100_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDF1)
    #define SYSTEM_LP
    #define RUN_FROM_FLASH
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDF2)    
    #define SYSTEM_LP
    #define RUN_FROM_FLASH
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDC1)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_150_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_75_MHZ
    #define HF_CLK_SOURCE   PLL
#elif (SPEC_ID == SIDC2)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_100_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_100_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDC3)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDC4)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDF3)
    #define SYSTEM_LP
    #define RUN_FROM_FLASH
    #define CM4_OFF
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_50_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDF4)
    #define SYSTEM_LP
    #define RUN_FROM_FLASH
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDC5)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_100_MHZ
    #define CM0P_DHRYSTONE
    #define CM0P_FREQ   FREQ_100_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDC6)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_DHRYSTONE
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDS1)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_100_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDS2)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDS3)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDS4)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_50_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDS5)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDLPA1)
    #define SYSTEM_LP
    #define RUN_FROM_FLASH
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT
#elif (SPEC_ID == SIDLPA2)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT
#elif (SPEC_ID == SIDLPA3)
    #define SYSTEM_LP
    #define RUN_FROM_FLASH
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT    
#elif (SPEC_ID == SIDLPA4)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_DHRYSTONE
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT   
#elif (SPEC_ID == SIDLPS1)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT  
#elif (SPEC_ID == SIDLPS3)
    #define SYSTEM_LP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDF5)
    #define SYSTEM_ULP
    #define RUN_FROM_FLASH
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDF6)
    #define SYSTEM_ULP
    #define RUN_FROM_FLASH
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDC8)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDC9)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDF7)
    #define SYSTEM_ULP
    #define RUN_FROM_FLASH
    #define CM4_OFF
    #define CM4_FREQ    FREQ_25_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDF8)
    #define SYSTEM_ULP
    #define RUN_FROM_FLASH
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDC10)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_25_MHZ
    #define CM0P_DHRYSTONE
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDC11)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_DHRYSTONE
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDS7)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_50_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDS8)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDS9)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_25_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_25_MHZ
    #define HF_CLK_SOURCE   FLL
#elif (SPEC_ID == SIDS10)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
#elif (SPEC_ID == SIDLPA5)
    #define SYSTEM_ULP
    #define RUN_FROM_FLASH
    #define CM4_WHILE_LOOP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDLPA6)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_DHRYSTONE
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDLPA7)
    #define SYSTEM_ULP
    #define RUN_FROM_FLASH
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_WHILE_LOOP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDLPA8)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_DHRYSTONE
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDLPS5)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_SLEEP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDLPS7)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
#elif (SPEC_ID == SIDDS1)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_DEEP_SLEEP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_DEEP_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
    #define NO_OF_PAGES     2U         
#elif (SPEC_ID == SIDDS2)
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_DEEP_SLEEP
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_DEEP_SLEEP
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT 
    #define NO_OF_PAGES     8U
#elif ((SPEC_ID == SIDHIB1) || (SPEC_ID == SIDHIB2))
    #define SYSTEM_ULP
    #define RUN_FROM_CACHE
    #define CM4_OFF
    #define CM4_FREQ    FREQ_8_MHZ
    #define CM0P_HIBERNATE
    #define CM0P_FREQ   FREQ_8_MHZ
    #define HF_CLK_SOURCE   IMO
    #define MIN_CURRENT
#else
    #error Invalid or not supported SPEC ID
#endif
    
#endif /* SPECS_H */

/* [] END OF FILE */
