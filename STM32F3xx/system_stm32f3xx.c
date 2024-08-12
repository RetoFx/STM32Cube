/**
  ******************************************************************************
  * @file    system_stm32f3xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File.
  *
  * 1. This file provides two functions and one global variable to be called from
  *    user application:
  *      - SystemInit(): This function is called at startup just after reset and
  *                      before branch to main program. This call is made inside
  *                      the "startup_stm32f3xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  * 2. After each device reset the HSI (8 MHz) is used as system clock source.
  *    Then SystemInit() function is called, in "startup_stm32f3xx.s" file, to
  *    configure the system clock before to branch to main program.
  *
  * 3. This file configures the system clock as follows:
  *=============================================================================
  *                         Supported STM32F3xx device
  *-----------------------------------------------------------------------------
  *        System Clock source                    | HSI
  *-----------------------------------------------------------------------------
  *        SYSCLK(Hz)                             | 8000000UL
  *-----------------------------------------------------------------------------
  *        HCLK(Hz)                               | 8000000UL
  *-----------------------------------------------------------------------------
  *        AHB Prescaler                          | 1
  *-----------------------------------------------------------------------------
  *        APB2 Prescaler                         | 1
  *-----------------------------------------------------------------------------
  *        APB1 Prescaler                         | 1
  *-----------------------------------------------------------------------------
  *        USB Clock                              | DISABLE
  *-----------------------------------------------------------------------------
  *=============================================================================
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
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

/** @addtogroup stm32f3xx_system
  * @{
  */

/** @addtogroup STM32F3xx_System_Private_Includes
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
#include "stm32f3xx.h"
*/
/*
#include "stm32f3xx_hal.h"
*/
/*lint -save -w1*/

/**
  * @}
  */

/** @addtogroup STM32F3xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F3xx_System_Private_Defines
  * @{
  */
#if !defined  (HSE_VALUE)
  #define HSE_VALUE               8000000UL /*!< Default value of the External oscillator in Hz.
                                                This value can be provided and adapted by the user application. */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE               8000000UL /*!< Default value of the Internal oscillator in Hz.
                                                This value can be provided and adapted by the user application. */
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
#define VECT_TAB_BASE_ADDRESS   SRAM_BASE       /*!< Vector Table base address field.
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

/******************************************************************************/
/**
  * @}
  */

/** @addtogroup STM32F3xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F3xx_System_Private_Variables
  * @{
  */
  /* This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
         Note: If you use this function to configure the system clock there is no need to
               call the 2 first functions listed above, since SystemCoreClock variable is
               updated automatically.
  */
uint32_t SystemCoreClock = 8000000UL;

uint8_t const AHBPrescTable[16U] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
uint8_t const APBPrescTable[8U]  = { 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};

/**
  * @}
  */

/** @addtogroup STM32F3xx_System_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F3xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
/* FPU settings --------------------------------------------------------------*/
#if (__FPU_PRESENT == 1U) && (__FPU_USED == 1U)
  SCB->CPACR |= ((3UL << (10U * 2U))
				  |(3UL << (11U * 2U)));  /* set CP10 and CP11 Full Access */
#endif

  /* Reset the RCC clock configuration to the default reset state ------------*/
  /* Set HSION bit */
  /*
  RCC->CR |= 0x00000001UL;
  */
  RCC->CR |= RCC_CR_HSION;

  /* Reset CFGR register */
  /*
  RCC->CFGR &= 0xF87FC00CUL;
  */
#if !defined(RCC_CFGR_I2SSRC_Msk)
 /*!< I2S configuration */
 #define RCC_CFGR_I2SSRC_Pos                      (23U)
 #define RCC_CFGR_I2SSRC_Msk                      (0x1UL << RCC_CFGR_I2SSRC_Pos) /*!< 0x00800000UL */
#endif
#if !defined(RCC_CFGR_USBPRE_Msk)
 /*!< USB configuration */
 #define RCC_CFGR_USBPRE_Pos                      (22U)
 #define RCC_CFGR_USBPRE_Msk                      (0x1UL << RCC_CFGR_USBPRE_Pos) /*!< 0x00400000UL */
#endif
  RCC->CFGR &= ~( 0U
//				| (0U * RCC_CFGR_PLLNODIV_Msk)	/*	0x80000000UL */
//				| (0U * RCC_CFGR_MCOF_Msk)		/*	0x10000000UL */
// 				| (0U * RCC_CFGR_MCOPRE_Msk)	/*	0x38000000UL */
//				| (0U * RCC_CFGR_SDADCPRE_Msk)	/*	0x08000000UL */
  				| (1U * RCC_CFGR_MCO_Msk)		/*	0x07000000UL */
				| (1U * RCC_CFGR_I2SSRC_Msk)	/*	0x00800000UL */
//				| (0U * RCC_CFGR_USBPRE_Msk)	/*	0x00400000UL */
//				| (0U * RCC_CFGR_PLLMUL_Msk)	/*	0x003C0000UL */
//				| (0U * RCC_CFGR_PLLXTPRE_Msk)	/*	0x00020000UL */
//				| (0U * RCC_CFGR_PLLSRC_Msk)	/*	0x00010000UL */
//				| (0U * RCC_CFGR_ADCPRE_Msk)	/*	0x0000C000UL */
				| (1U * RCC_CFGR_PPRE2_Msk)		/*	0x00003800UL */
				| (1U * RCC_CFGR_PPRE1_Msk)		/*	0x00000700UL */
				| (1U * RCC_CFGR_HPRE_Msk)		/*	0x000000F0UL */
//				| (0U * RCC_CFGR_SWS_Msk)		/*	0x0000000CUL */
				| (1U * RCC_CFGR_SW_Msk) 		/*	0x00000003UL */
				);

  /* Reset HSEON, CSSON and PLLON bits */
  /*
  RCC->CR &= 0xFEF6FFFFUL;
  */
  RCC->CR &= ~( RCC_CR_HSEON
              | RCC_CR_CSSON
              | RCC_CR_PLLON );

  /* Reset HSEBYP bit */
  /*
  RCC->CR &= 0xFFFBFFFFUL;
  */
  RCC->CR &= ~(RCC_CR_HSEBYP);

  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE bits */
  /*
  RCC->CFGR &= 0xFF80FFFFUL;
  */
  RCC->CFGR &= ~( 0U
//				| (0U * RCC_CFGR_PLLNODIV_Msk)	/*	0x80000000UL */
//				| (0U * RCC_CFGR_MCOF_Msk)		/*	0x10000000UL */
// 				| (0U * RCC_CFGR_MCOPRE_Msk)	/*	0x38000000UL */
//				| (0U * RCC_CFGR_SDADCPRE_Msk)	/*	0x08000000UL */
// 				| (0U * RCC_CFGR_MCO_Msk)		/*	0x07000000UL */
//				| (0U * RCC_CFGR_I2SSRC_Msk)	/*	0x00800000UL */
				| (1U * RCC_CFGR_USBPRE_Msk)	/*	0x00400000UL */
				| (1U * RCC_CFGR_PLLMUL_Msk)	/*	0x003C0000UL */
				| (1U * RCC_CFGR_PLLXTPRE_Msk)	/*	0x00020000UL */
				| (1U * RCC_CFGR_PLLSRC_Msk)	/*	0x00010000UL */
//				| (0U * RCC_CFGR_ADCPRE_Msk)	/*	0x0000C000UL */
//				| (0U * RCC_CFGR_PPRE2_Msk)		/*	0x00003800UL */
//				| (0U * RCC_CFGR_PPRE1_Msk)		/*	0x00000700UL */
//				| (0U * RCC_CFGR_HPRE_Msk)		/*	0x000000F0UL */
//				| (0U * RCC_CFGR_SWS_Msk)		/*	0x0000000CUL */
//				| (0U * RCC_CFGR_SW_Msk) 		/*	0x00000003UL */
				);

  /* Reset PREDIV1[3:0] bits */
  /*
  RCC->CFGR2 &= 0xFFFFFFF0UL;
  */
  RCC->CFGR2 &= ~RCC_CFGR2_PREDIV_DIV16;

  /* Reset USARTSW[1:0], I2CSW and TIMs bits */
  RCC->CFGR3 &= 0xFF00FCCCUL;

  /* Disable all interrupts */
  RCC->CIR = 0x00000000UL;

  /* Configure the Vector Table location -------------------------------------*/
#if defined(USER_VECT_TAB_ADDRESS)
  SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#endif /* USER_VECT_TAB_ADDRESS */

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
  *           - If SYSCLK source is HSI, SystemCoreClock will contain the HSI_VALUE(*)
  *
  *           - If SYSCLK source is HSE, SystemCoreClock will contain the HSE_VALUE(**)
  *
  *           - If SYSCLK source is PLL, SystemCoreClock will contain the HSE_VALUE(**)
  *             or HSI_VALUE(*) multiplied/divided by the PLL factors.
  *
  *         (*) HSI_VALUE is a constant defined in stm32f3xx_hal.h file (default value
  *             8 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *
  *         (**) HSE_VALUE is a constant defined in stm32f3xx_hal.h file (default value
  *              8 MHz), user has to ensure that HSE_VALUE is same as the real
  *              frequency of the crystal used. Otherwise, this function may
  *              have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate (void)
{
  uint32_t tmp = 0U;
  uint32_t pllmull = 0U;
  uint32_t pllsource = 0U;
  uint32_t predivfactor = 0U;

  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case RCC_CFGR_SWS_HSI:  /* HSI used as system clock */
      SystemCoreClock = HSI_VALUE;
      break;
    case RCC_CFGR_SWS_HSE:  /* HSE used as system clock */
      SystemCoreClock = HSE_VALUE;
      break;
    case RCC_CFGR_SWS_PLL:  /* PLL used as system clock */
      /* Get PLL clock source and multiplication factor ----------------------*/
      pllmull = RCC->CFGR & RCC_CFGR_PLLMUL;
      pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
      pllmull = ( pllmull >> 18U) + 2U;

#if defined (STM32F302xE) || defined (STM32F303xE) || defined (STM32F398xx)
        predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1U;
      if (pllsource == RCC_CFGR_PLLSRC_HSE_PREDIV)
      {
        /* HSE oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSE_VALUE / predivfactor) * pllmull;
      }
      else
      {
        /* HSI oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSI_VALUE / predivfactor) * pllmull;
      }
#else
      if (pllsource == RCC_CFGR_PLLSRC_HSI_DIV2)
      {
        /* HSI oscillator clock divided by 2 selected as PLL clock entry */
        SystemCoreClock = (HSI_VALUE >> 1U) * pllmull;
      }
      else
      {
        predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1U;
        /* HSE oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSE_VALUE / predivfactor) * pllmull;
      }
#endif /* STM32F302xE || STM32F303xE || STM32F398xx */
      break;
    default: /* HSI used as system clock */
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK clock frequency ----------------*/
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
