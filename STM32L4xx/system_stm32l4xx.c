/**
  ******************************************************************************
  * @file    system_stm32l4xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File
  *
  *   This file provides two functions and one global variable to be called from
  *   user application:
  *      - SystemInit(): This function is called at startup just after reset and
  *                      before branch to main program. This call is made inside
  *                      the "startup_stm32l4xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *   After each device reset the MSI (4 MHz) is used as system clock source.
  *   Then SystemInit() function is called, in "startup_stm32l4xx.s" file, to
  *   configure the system clock before to branch to main program.
  *
  *   This file configures the system clock as follows:
  *=============================================================================
  *-----------------------------------------------------------------------------
  *        System Clock source                    | MSI
  *-----------------------------------------------------------------------------
  *        SYSCLK(Hz)                             | 4000000UL
  *-----------------------------------------------------------------------------
  *        HCLK(Hz)                               | 4000000UL
  *-----------------------------------------------------------------------------
  *        AHB Prescaler                          | 1
  *-----------------------------------------------------------------------------
  *        APB1 Prescaler                         | 1
  *-----------------------------------------------------------------------------
  *        APB2 Prescaler                         | 1
  *-----------------------------------------------------------------------------
  *        PLL_M                                  | 1
  *-----------------------------------------------------------------------------
  *        PLL_N                                  | 8
  *-----------------------------------------------------------------------------
  *        PLL_P                                  | 7
  *-----------------------------------------------------------------------------
  *        PLL_Q                                  | 2
  *-----------------------------------------------------------------------------
  *        PLL_R                                  | 2
  *-----------------------------------------------------------------------------
  *        PLLSAI1_P                              | NA
  *-----------------------------------------------------------------------------
  *        PLLSAI1_Q                              | NA
  *-----------------------------------------------------------------------------
  *        PLLSAI1_R                              | NA
  *-----------------------------------------------------------------------------
  *        PLLSAI2_P                              | NA
  *-----------------------------------------------------------------------------
  *        PLLSAI2_Q                              | NA
  *-----------------------------------------------------------------------------
  *        PLLSAI2_R                              | NA
  *-----------------------------------------------------------------------------
  *        Require 48MHz for USB OTG FS,          | Disabled
  *        SDIO and RNG clock                     |
  *-----------------------------------------------------------------------------
  *=============================================================================
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32l4xx_system
  * @{
  */

/** @addtogroup STM32L4xx_System_Private_Includes
  * @{
  */

#define  Uses_HAL_CPU_CORE
#define  USE_HAL_DRIVER
#define  HAL_CORTEX_MODULE_ENABLED
#define  Uses_DbgCpuInit	/* Debugger initialisation */
#define  Uses_HAL_Reset		/* for HAL_ResetCheck() */
#define  Uses_HAL_CpuSettings
#include "../../../AppInclude.h"

/*
#include "stm32l4xx.h"
*/
/*
#include "stm32l4xx_hal.h"
*/
/*lint -save -w1*/

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Private_Defines
  * @{
  */

#if !defined  (HSE_VALUE)
  #define HSE_VALUE    8000000UL  /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (MSI_VALUE)
  #define MSI_VALUE    4000000UL  /*!< Value of the Internal oscillator in Hz*/
#endif /* MSI_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    16000000UL /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/* Note: Following vector table addresses must be defined in line with linker
         configuration. */
/*!< Uncomment the following line if you need to relocate the vector table
     anywhere in Flash or Sram, else the vector table is kept at the automatic
     remap of boot address selected */
/* #define USER_VECT_TAB_ADDRESS */

#if defined(USER_VECT_TAB_ADDRESS)
/*!< Uncomment the following line if you need to relocate your vector Table
     in Sram else user remap will be done in Flash. */
/* #define VECT_TAB_SRAM */

#if defined(VECT_TAB_SRAM)
#define VECT_TAB_BASE_ADDRESS   SRAM1_BASE      /*!< Vector Table base address field.
                                                     This value must be a multiple of 0x200U. */
#define VECT_TAB_OFFSET         0x00000000UL     /*!< Vector Table base offset field.
                                                     This value must be a multiple of 0x200U. */
#else
#define VECT_TAB_BASE_ADDRESS   CPU_FLASH_BASE   /*!< Vector Table base address field.
                                                     This value must be a multiple of 0x200U. */
#define VECT_TAB_OFFSET         0x00000000UL     /*!< Vector Table base offset field.
                                                     This value must be a multiple of 0x200U. */
#endif /* VECT_TAB_SRAM */
#endif /* USER_VECT_TAB_ADDRESS */

#if !defined(RCC_CR_PLLSAI1ON)
 #define RCC_CR_PLLSAI1ON_Pos				  (26U)
 #define RCC_CR_PLLSAI1ON_Msk				  (0x1UL << RCC_CR_PLLSAI1ON_Pos)   /*!< 0x04000000UL */
 #define RCC_CR_PLLSAI1ON					  RCC_CR_PLLSAI1ON_Msk             /*!< SAI1 PLL enable */
#endif

#if !defined(RCC_CR_PLLSAI1RDY)
 #define RCC_CR_PLLSAI1RDY_Pos                (27U)
 #define RCC_CR_PLLSAI1RDY_Msk                (0x1UL << RCC_CR_PLLSAI1RDY_Pos)   /*!< 0x08000000UL */
 #define RCC_CR_PLLSAI1RDY                    RCC_CR_PLLSAI1RDY_Msk             /*!< SAI1 PLL ready */
#endif

#if !defined(RCC_CR_PLLSAI2ON)
 #define RCC_CR_PLLSAI2ON_Pos                 (28U)
 #define RCC_CR_PLLSAI2ON_Msk                 (0x1UL << RCC_CR_PLLSAI2ON_Pos)    /*!< 0x10000000UL */
 #define RCC_CR_PLLSAI2ON                     RCC_CR_PLLSAI2ON_Msk              /*!< SAI2 PLL enable */
#endif

#if !defined(RCC_CR_PLLSAI2RDY)
 #define RCC_CR_PLLSAI2RDY_Pos                (29U)
 #define RCC_CR_PLLSAI2RDY_Msk                (0x1UL << RCC_CR_PLLSAI2RDY_Pos)   /*!< 0x20000000UL */
 #define RCC_CR_PLLSAI2RDY                    RCC_CR_PLLSAI2RDY_Msk             /*!< SAI2 PLL ready */
#endif

#if !defined(RCC_PLLCFGR_PLLPEN)
 #define RCC_PLLCFGR_PLLPEN_Pos                (16U)
 #define RCC_PLLCFGR_PLLPEN_Msk                (0x1UL << RCC_PLLCFGR_PLLPEN_Pos) /*!< 0x00010000UL */
 #define RCC_PLLCFGR_PLLPEN                    RCC_PLLCFGR_PLLPEN_Msk           /*!< PLLP enable */
#endif

#if !defined(RCC_PLLCFGR_PLLP)
 #define RCC_PLLCFGR_PLLP_Pos                  (17U)
 #define RCC_PLLCFGR_PLLP_Msk                  (0x1UL << RCC_PLLCFGR_PLLP_Pos)   /*!< 0x00020000UL */
 #define RCC_PLLCFGR_PLLP                      RCC_PLLCFGR_PLLP_Msk               /*!< PLLP division factor */
#endif

/******************************************************************************/
/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Private_Variables
  * @{
  */
  /* The SystemCoreClock variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
         Note: If you use this function to configure the system clock; then there
               is no need to call the 2 first functions listed above, since SystemCoreClock
               variable is updated automatically.
  */
  uint32_t SystemCoreClock = 4000000UL;

  uint8_t const  AHBPrescTable[16U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
  uint8_t const  APBPrescTable[8U] =  {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
  uint32_t const MSIRangeTable[12U] = {100000UL,   200000UL,   400000UL,   800000UL,  1000000UL,  2000000UL,
                                      4000000UL, 8000000UL, 16000000UL, 24000000UL, 32000000UL, 48000000UL};
/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system.
  * @retval None
  */

void SystemInit(void)
{
#if defined(USER_VECT_TAB_ADDRESS)
  /* Configure the Vector Table location -------------------------------------*/
  SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET;
#endif

  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1U) && (__FPU_USED == 1U)
    SCB->CPACR |= ((3UL << (10U * 2U))
                  |(3UL << (11U * 2U)));  /* set CP10 and CP11 Full Access */
  #endif
  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set MSION bit */
  RCC->CR |= RCC_CR_MSION;

  /* Reset CFGR register */
  RCC->CFGR = 0x00000000UL;

  /* Reset HSEON, CSSON , HSION, and PLLON bits */
  /*
  RCC->CR &= 0xEAF6FFFFUL;
  */
  RCC->CR &= ~( (0U * RCC_CR_MSION)
  			  | (0U * RCC_CR_MSIRDY)
  			  | (0U * RCC_CR_MSIPLLEN)
  			  | (0U * RCC_CR_MSIRGSEL)
  			  | (0U * RCC_CR_MSIRANGE)
  			  | (0U * RCC_CR_HSION)
  			  | (0U * RCC_CR_HSIKERON)
  			  | (0U * RCC_CR_HSIRDY)
  			  | (0U * RCC_CR_HSIASFS)
  			  | (1U * RCC_CR_HSEON)
  			  | (0U * RCC_CR_HSERDY)
  			  | (0U * RCC_CR_HSEBYP)
  			  | (1U * RCC_CR_CSSON)
  			  | (1U * RCC_CR_PLLON)
  			  | (0U * RCC_CR_PLLRDY)
  			  | (1U * RCC_CR_PLLSAI1ON)
  			  | (0U * RCC_CR_PLLSAI1RDY)
  			  | (1U * RCC_CR_PLLSAI2ON)
  			  | (0U * RCC_CR_PLLSAI2RDY) );

  /* Reset PLLCFGR register */
  /*
  RCC->PLLCFGR = 0x00001000UL;
  */
  RCC->PLLCFGR = (0U * RCC_PLLCFGR_PLLSRC)
  			   | (0U * RCC_PLLCFGR_PLLM_0)
  			   | (0U * RCC_PLLCFGR_PLLM_1)
  			   | (0U * RCC_PLLCFGR_PLLM_2)
  			   | (0U * RCC_PLLCFGR_PLLN_0)
  			   | (0U * RCC_PLLCFGR_PLLN_1)
  			   | (0U * RCC_PLLCFGR_PLLN_2)
  			   | (0U * RCC_PLLCFGR_PLLN_3)
  			   | (1U * RCC_PLLCFGR_PLLN_4)
  			   | (0U * RCC_PLLCFGR_PLLN_5)
  			   | (0U * RCC_PLLCFGR_PLLN_6)
  			   | (0U * RCC_PLLCFGR_PLLPEN)
  			   | (0U * RCC_PLLCFGR_PLLP)
  			   | (0U * RCC_PLLCFGR_PLLQEN)
  			   | (0U * RCC_PLLCFGR_PLLQ_0)
  			   | (0U * RCC_PLLCFGR_PLLQ_1)
  			   | (0U * RCC_PLLCFGR_PLLREN)
  			   | (0U * RCC_PLLCFGR_PLLR_0)
  			   | (0U * RCC_PLLCFGR_PLLR_1);
//  			   | (0U * RCC_PLLCFGR_PLLPDIV_0)
//  			   | (0U * RCC_PLLCFGR_PLLPDIV_1)
//  			   | (0U * RCC_PLLCFGR_PLLPDIV_2)
//  			   | (0U * RCC_PLLCFGR_PLLPDIV_3)
//  			   | (0U * RCC_PLLCFGR_PLLPDIV_4);

  /* Reset HSEBYP bit */
  /*
  RCC->CR &= 0xFFFBFFFFUL;
  */
  RCC->CR &= ~RCC_CR_HSEBYP;

  /* Disable all interrupts */
  RCC->CIER = 0x00000000UL;

  /* Configure the Debug Feature of the CPU ----------------------------------*/
#if defined(DBG_CpuInit)
	DBG_CpuInit();
#endif

#if defined(_HAL_RESET_H)
	HAL_ResetCheck();
#endif
}

/**
  * @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  *
  * @note   Each time the core clock (HCLK) changes, this function must be called
  *         to update SystemCoreClock variable value. Otherwise, any configuration
  *         based on this variable will be incorrect.
  *
  * @note   - The system frequency computed by this function is not the real
  *           frequency in the chip. It is calculated based on the predefined
  *           constant and the selected clock source:
  *
  *           - If SYSCLK source is MSI, SystemCoreClock will contain the MSI_VALUE(*)
  *
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(**)
  *
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(***)
  *
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(***)
  *             or HSI_VALUE(*) or MSI_VALUE(*) multiplied/divided by the PLL factors.
  *
  *         (*) MSI_VALUE is a constant defined in stm32l4xx_hal.h file (default value
  *             4 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *
  *         (**) HSI_VALUE is a constant defined in stm32l4xx_hal.h file (default value
  *              16 MHz) but the real value may vary depending on the variations
  *              in voltage and temperature.
  *
  *         (***) HSE_VALUE is a constant defined in stm32l4xx_hal.h file (default value
  *              8 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
  uint32_t tmp = 0U;
  uint32_t msirange = 0U;
  uint32_t pllvco = 0U;
  uint32_t pllr = 2U;
  uint32_t pllsource = 0U;
  uint32_t pllm = 2U;

  /* Get MSI Range frequency--------------------------------------------------*/
  if ((RCC->CR & RCC_CR_MSIRGSEL) == 0U)
  { /* MSISRANGE from RCC_CSR applies */
    msirange = (RCC->CSR & RCC_CSR_MSISRANGE) >> 8U;
  }
  else
  { /* MSIRANGE from RCC_CR applies */
    msirange = (RCC->CR & RCC_CR_MSIRANGE) >> 4U;
  }
  /*MSI frequency range in HZ*/
  msirange = MSIRangeTable[msirange];

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (RCC->CFGR & RCC_CFGR_SWS)
  {
    case RCC_CFGR_SWS_MSI:  /* MSI used as system clock source */
      SystemCoreClock = msirange;
      break;

    case RCC_CFGR_SWS_HSI:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;

    case RCC_CFGR_SWS_HSE:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;

    case RCC_CFGR_SWS_PLL:  /* PLL used as system clock  source */
      /* PLL_VCO = (HSE_VALUE or HSI_VALUE or MSI_VALUE/ PLLM) * PLLN
         SYSCLK = PLL_VCO / PLLR
         */
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
      pllm = ((RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> 4U) + 1U ;

      switch (pllsource)
      {
        case RCC_PLLCFGR_PLLSRC_HSI:  /* HSI used as PLL clock source */
          pllvco = (HSI_VALUE / pllm);
          break;

        case RCC_PLLCFGR_PLLSRC_HSE:  /* HSE used as PLL clock source */
          pllvco = (HSE_VALUE / pllm);
          break;

        default:    /* MSI used as PLL clock source */
          pllvco = (msirange / pllm);
          break;
      }
      pllvco = pllvco * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 8U);
      pllr = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLR) >> 25U) + 1U) * 2U;
      SystemCoreClock = pllvco/pllr;
      break;

    default:
      SystemCoreClock = msirange;
      break;
  }
  /* Compute HCLK clock frequency --------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4U)];
  /* HCLK clock frequency */
  SystemCoreClock >>= tmp;
}


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/*lint -restore*/
