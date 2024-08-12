/**
  ******************************************************************************
  * @file    system_stm32f4xx.c
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer System Source File.
  *
  *   This file provides two functions and one global variable to be called from
  *   user application:
  *      - SystemInit(): This function is called at startup just after reset and
  *                      before branch to main program. This call is made inside
  *                      the "startup_stm32f4xx.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *
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

/** @addtogroup stm32f4xx_system
  * @{
  */

/** @addtogroup STM32F4xx_System_Private_Includes
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
#include "stm32f4xx.h"
*/
/*
#include "stm32f4xx_hal.h"
*/
/*lint -save -w1*/

#if !defined  (HSE_VALUE)
  #define HSE_VALUE               25000000UL /*!< Default value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE               16000000UL /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */


#if !defined  (RCC_CFGR_MCO2PRE_0)
  #define RCC_CFGR_MCO2PRE_Pos    (27U)
  #define RCC_CFGR_MCO2PRE_0      (0x1UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x08000000UL */
#endif /* RCC_CFGR_MCO2PRE_0 */

#if !defined  (RCC_CFGR_MCO2PRE_1)
  #define RCC_CFGR_MCO2PRE_1      (0x2UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x10000000UL */
#endif /* RCC_CFGR_MCO2PRE_1 */

#if !defined  (RCC_CFGR_MCO2PRE_2)
  #define RCC_CFGR_MCO2PRE_2      (0x4UL << RCC_CFGR_MCO2PRE_Pos)      /*!< 0x20000000UL */
#endif /* RCC_CFGR_MCO2PRE_2 */

#if !defined  (RCC_CFGR_MCO2_0)
  #define RCC_CFGR_MCO2_Pos       (30U)
  #define  RCC_CFGR_MCO2_0        (0x1UL << RCC_CFGR_MCO2_Pos)         /*!< 0x40000000UL */
#endif /* RCC_CFGR_MCO2_0 */

#if !defined  (RCC_CFGR_MCO2_1)
  #define  RCC_CFGR_MCO2_1        (0x2UL << RCC_CFGR_MCO2_Pos)         /*!< 0x80000000UL */
#endif /* RCC_CFGR_MCO2_1 */


/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Defines
  * @{
  */

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to use external SRAM or SDRAM as data memory  */
#if defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx) || defined(STM32F417xx) \
 || defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) \
 || defined(STM32F469xx) || defined(STM32F479xx) || defined(STM32F412Zx) || defined(STM32F412Vx)
/* #define DATA_IN_ExtSRAM */
#endif /* STM32F40xxx || STM32F41xxx || STM32F42xxx || STM32F43xxx || STM32F469xx || STM32F479xx || \
          STM32F412Zx || STM32F412Vx */

#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) \
 || defined(STM32F446xx) || defined(STM32F469xx) || defined(STM32F479xx)
/* #define DATA_IN_ExtSDRAM */
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx || STM32F446xx || STM32F469xx || \
          STM32F479xx */

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

/** @addtogroup STM32F4xx_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Variables
  * @{
  */
  /* This variable is updated in three ways:
      1) by calling CMSIS function SystemCoreClockUpdate()
      2) by calling HAL API function HAL_RCC_GetHCLKFreq()
      3) each time HAL_RCC_ClockConfig() is called to configure the system clock frequency
         Note: If you use this function to configure the system clock; then there
               is no need to call the 2 first functions listed above, since SystemCoreClock
               variable is updated automatically.
  */
uint32_t SystemCoreClock = 16000000UL;
uint8_t const AHBPrescTable[16U] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
uint8_t const APBPrescTable[8U]  = { 0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_FunctionPrototypes
  * @{
  */

#if defined (DATA_IN_ExtSRAM) || defined (DATA_IN_ExtSDRAM)
  static void SystemInit_ExtMemCtl(void);
#endif /* DATA_IN_ExtSRAM || DATA_IN_ExtSDRAM */

/**
  * @}
  */

/** @addtogroup STM32F4xx_System_Private_Functions
  * @{
  */

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting, vector table location and External memory
  *         configuration.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
  /* FPU settings ------------------------------------------------------------*/
  #if (__FPU_PRESENT == 1U) && (__FPU_USED == 1U)
    SCB->CPACR |= ((3UL << (10U * 2U))
				  |(3UL << (11U * 2U)));  /* set CP10 and CP11 Full Access */
  #endif

	/* Reset CFGR register */
	/*
	RCC->CFGR = 0x00000000UL;
	*/
	RCC->CFGR = (0UL * RCC_CFGR_MCO2_1)
			  | (0UL * RCC_CFGR_MCO2_0)
			  | (0UL * RCC_CFGR_MCO2PRE_2)
			  | (0UL * RCC_CFGR_MCO2PRE_1)
			  | (0UL * RCC_CFGR_MCO2PRE_0)
			  | (0UL * RCC_CFGR_MCO1PRE_2)
			  | (0UL * RCC_CFGR_MCO1PRE_1)
			  | (0UL * RCC_CFGR_MCO1PRE_0)
			  | (0UL * RCC_CFGR_MCO1_1)
			  | (0UL * RCC_CFGR_MCO1_0)
			  | (0UL * RCC_CFGR_RTCPRE_4)
			  | (0UL * RCC_CFGR_RTCPRE_3)
			  | (0UL * RCC_CFGR_RTCPRE_2)
			  | (0UL * RCC_CFGR_RTCPRE_1)
			  | (0UL * RCC_CFGR_RTCPRE_0)
			  | RCC_CFGR_PPRE2_DIV1         /*!< HCLK not divided */
			  | RCC_CFGR_PPRE1_DIV1         /*!< HCLK not divided */
			  | RCC_CFGR_HPRE_DIV1          /*!< SYSCLK not divided */
			  | RCC_CFGR_SWS_HSI            /*!< HSI oscillator used as system clock */
			  | RCC_CFGR_SW_HSI;		    /*!< HSI selected as system clock */

	/* Reset HSEON, CSSON and PLLON bits */
	/*
	RCC->CR &= (uint32_t)0xFEF6FFFFUL;
	*/
	RCC->CR &= ~( RCC_CR_HSEON
			  | RCC_CR_CSSON
			  | RCC_CR_PLLON );

	/* Reset PLLCFGR register */
	/*
	RCC->PLLCFGR = 0x24003010UL;
	*/
#define  RCC_PLLCFGR_RESET	( 0x20000000UL \
							| (0U * RCC_PLLCFGR_PLLM_0) \
							| (0U * RCC_PLLCFGR_PLLM_1) \
							| (0U * RCC_PLLCFGR_PLLM_2) \
							| (0U * RCC_PLLCFGR_PLLM_3) \
							| (1U * RCC_PLLCFGR_PLLM_4) \
							| (0U * RCC_PLLCFGR_PLLM_5) \
			                                            \
							| (0U * RCC_PLLCFGR_PLLN_0) \
							| (0U * RCC_PLLCFGR_PLLN_1) \
							| (0U * RCC_PLLCFGR_PLLN_2) \
							| (0U * RCC_PLLCFGR_PLLN_3) \
							| (0U * RCC_PLLCFGR_PLLN_4) \
							| (0U * RCC_PLLCFGR_PLLN_5) \
							| (1U * RCC_PLLCFGR_PLLN_6) \
							| (1U * RCC_PLLCFGR_PLLN_7) \
							| (0U * RCC_PLLCFGR_PLLN_8) \
			                                            \
							| (0U * RCC_PLLCFGR_PLLP_0) \
							| (0U * RCC_PLLCFGR_PLLP_1) \
			                                            \
							| RCC_PLLCFGR_PLLSRC_HSI    \
			                                            \
							| (0U * RCC_PLLCFGR_PLLQ_0) \
							| (0U * RCC_PLLCFGR_PLLQ_1) \
							| (1U * RCC_PLLCFGR_PLLQ_2) \
							| (0U * RCC_PLLCFGR_PLLQ_3) )

	RCC->PLLCFGR = RCC_PLLCFGR_RESET;

	/* Reset HSEBYP bit */
	/*
	RCC->CR &= (uint32_t)0xFFFBFFFFUL;
	*/
	RCC->CR &= ~(RCC_CR_HSEBYP);

	/* Disable all interrupts */
	RCC->CIR = 0x00000000UL;

#if defined (DATA_IN_ExtSRAM) || defined (DATA_IN_ExtSDRAM)
  SystemInit_ExtMemCtl();
#endif /* DATA_IN_ExtSRAM || DATA_IN_ExtSDRAM */

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
  *         (*) HSI_VALUE is a constant defined in stm32f4xx_hal_conf.h file (default value
  *             16 MHz) but the real value may vary depending on the variations
  *             in voltage and temperature.
  *
  *         (**) HSE_VALUE is a constant defined in stm32f4xx_hal_conf.h file (its value
  *              depends on the application requirements), user has to ensure that HSE_VALUE
  *              is same as the real frequency of the crystal used. Otherwise, this function
  *              may have wrong result.
  *
  *         - The result of this function could be not correct when using fractional
  *           value for HSE crystal.
  *
  * @param  None
  * @retval None
  */
void SystemCoreClockUpdate(void)
{
	uint32_t tmp = 0U;
	uint32_t pllvco = 0U;
	uint32_t pllp = 2U;
	uint32_t pllsource = 0U;
	uint32_t pllm = 2U;

  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
	case RCC_CFGR_SWS_HSI:  /* HSI used as system clock source */
      SystemCoreClock = HSI_VALUE;
      break;
	case RCC_CFGR_SWS_HSE:  /* HSE used as system clock source */
      SystemCoreClock = HSE_VALUE;
      break;
	case RCC_CFGR_SWS_PLL:  /* PLL used as system clock source */

      /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N
         SYSCLK = PLL_VCO / PLL_P
         */
      pllsource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC) >> 22U;
      pllm = RCC->PLLCFGR & RCC_PLLCFGR_PLLM;

      if (pllsource != 0U)
      {
        /* HSE used as PLL clock source */
        pllvco = (HSE_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6U);
      }
      else
      {
        /* HSI used as PLL clock source */
        pllvco = (HSI_VALUE / pllm) * ((RCC->PLLCFGR & RCC_PLLCFGR_PLLN) >> 6U);
      }

      pllp = (((RCC->PLLCFGR & RCC_PLLCFGR_PLLP) >> 16U) + 1U ) * 2U;
      SystemCoreClock = pllvco/pllp;
      break;
    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK frequency --------------------------------------------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4U)];
  /* HCLK frequency */
  SystemCoreClock >>= tmp;
}

#if defined (DATA_IN_ExtSRAM) && defined (DATA_IN_ExtSDRAM)
#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) \
 || defined(STM32F469xx) || defined(STM32F479xx)
/**
  * @brief  Setup the external memory controller.
  *         Called in startup_stm32f4xx.s before jump to main.
  *         This function configures the external memories (SRAM/SDRAM)
  *         This SRAM/SDRAM will be used as program data memory (including heap and stack).
  * @param  None
  * @retval None
  */
void SystemInit_ExtMemCtl(void)
{
  __IO uint32_t tmp = 0x00U;

  uint32_t tmpreg = 0, timeout = 0xFFFFU;
  __IO uint32_t index;

  /* Enable GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH and GPIOI interface clock */
  RCC->AHB1ENR |= 0x000001F8UL;

  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);

  /* Connect PDx pins to FMC Alternate function */
  GPIOD->AFR[0U]  = 0x00CCC0CCUL;
  GPIOD->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PDx pins in Alternate function mode */
  GPIOD->MODER   = 0xAAAA0A8AUL;
  /* Configure PDx pins speed to 100 MHz */
  GPIOD->OSPEEDR = 0xFFFF0FCFUL;
  /* Configure PDx pins Output type to push-pull */
  GPIOD->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PDx pins */
  GPIOD->PUPDR   = 0x00000000UL;

  /* Connect PEx pins to FMC Alternate function */
  GPIOE->AFR[0U]  = 0xC00CC0CCUL;
  GPIOE->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PEx pins in Alternate function mode */
  GPIOE->MODER   = 0xAAAA828AUL;
  /* Configure PEx pins speed to 100 MHz */
  GPIOE->OSPEEDR = 0xFFFFC3CFUL;
  /* Configure PEx pins Output type to push-pull */
  GPIOE->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PEx pins */
  GPIOE->PUPDR   = 0x00000000UL;

  /* Connect PFx pins to FMC Alternate function */
  GPIOF->AFR[0U]  = 0xCCCCCCCCUL;
  GPIOF->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PFx pins in Alternate function mode */
  GPIOF->MODER   = 0xAA800AAAUL;
  /* Configure PFx pins speed to 50 MHz */
  GPIOF->OSPEEDR = 0xAA800AAAUL;
  /* Configure PFx pins Output type to push-pull */
  GPIOF->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PFx pins */
  GPIOF->PUPDR   = 0x00000000UL;

  /* Connect PGx pins to FMC Alternate function */
  GPIOG->AFR[0U]  = 0xCCCCCCCCUL;
  GPIOG->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER   = 0xAAAAAAAAUL;
  /* Configure PGx pins speed to 50 MHz */
  GPIOG->OSPEEDR = 0xAAAAAAAAUL;
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PGx pins */
  GPIOG->PUPDR   = 0x00000000UL;

  /* Connect PHx pins to FMC Alternate function */
  GPIOH->AFR[0U]  = 0x00C0CC00UL;
  GPIOH->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PHx pins in Alternate function mode */
  GPIOH->MODER   = 0xAAAA08A0UL;
  /* Configure PHx pins speed to 50 MHz */
  GPIOH->OSPEEDR = 0xAAAA08A0UL;
  /* Configure PHx pins Output type to push-pull */
  GPIOH->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PHx pins */
  GPIOH->PUPDR   = 0x00000000UL;

  /* Connect PIx pins to FMC Alternate function */
  GPIOI->AFR[0U]  = 0xCCCCCCCCUL;
  GPIOI->AFR[1U]  = 0x00000CC0UL;
  /* Configure PIx pins in Alternate function mode */
  GPIOI->MODER   = 0x0028AAAAUL;
  /* Configure PIx pins speed to 50 MHz */
  GPIOI->OSPEEDR = 0x0028AAAAUL;
  /* Configure PIx pins Output type to push-pull */
  GPIOI->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PIx pins */
  GPIOI->PUPDR   = 0x00000000UL;

/*-- FMC Configuration -------------------------------------------------------*/
  /* Enable the FMC interface clock */
  RCC->AHB3ENR |= 0x00000001UL;
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);

  FMC_Bank5_6->SDCR[0U] = 0x000019E4UL;
  FMC_Bank5_6->SDTR[0U] = 0x01115351UL;

  /* SDRAM initialization sequence */
  /* Clock enable command */
  FMC_Bank5_6->SDCMR = 0x00000011UL;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* Delay */
  for (index = 0; index<1000; index++);

  /* PALL command */
  FMC_Bank5_6->SDCMR = 0x00000012UL;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  timeout = 0xFFFFU;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* Auto refresh command */
  FMC_Bank5_6->SDCMR = 0x00000073UL;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  timeout = 0xFFFFU;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* MRD register program */
  FMC_Bank5_6->SDCMR = 0x00046014UL;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  timeout = 0xFFFFU;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* Set refresh count */
  tmpreg = FMC_Bank5_6->SDRTR;
  FMC_Bank5_6->SDRTR = (tmpreg | (0x0000027CUL<< 1U));

  /* Disable write protection */
  tmpreg = FMC_Bank5_6->SDCR[0U];
  FMC_Bank5_6->SDCR[0U] = (tmpreg & 0xFFFFFDFFUL);

#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx)
  /* Configure and enable Bank1_SRAM2 */
  FMC_Bank1->BTCR[2U]  = 0x00001011UL;
  FMC_Bank1->BTCR[3U]  = 0x00000201UL;
  FMC_Bank1E->BWTR[2U] = 0x0fffffffUL;
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx */
#if defined(STM32F469xx) || defined(STM32F479xx)
  /* Configure and enable Bank1_SRAM2 */
  FMC_Bank1->BTCR[2U]  = 0x00001091UL;
  FMC_Bank1->BTCR[3U]  = 0x00110212UL;
  FMC_Bank1E->BWTR[2U] = 0x0fffffffUL;
#endif /* STM32F469xx || STM32F479xx */

  (void)(tmp);
}
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx || STM32F469xx || STM32F479xx */
#elif defined (DATA_IN_ExtSRAM) || defined (DATA_IN_ExtSDRAM)
/**
  * @brief  Setup the external memory controller.
  *         Called in startup_stm32f4xx.s before jump to main.
  *         This function configures the external memories (SRAM/SDRAM)
  *         This SRAM/SDRAM will be used as program data memory (including heap and stack).
  * @param  None
  * @retval None
  */
void SystemInit_ExtMemCtl(void)
{
  __IO uint32_t tmp = 0x00U;
#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) \
 || defined(STM32F446xx) || defined(STM32F469xx) || defined(STM32F479xx)
#if defined (DATA_IN_ExtSDRAM)
  uint32_t tmpreg = 0, timeout = 0xFFFFU;
  __IO uint32_t index;

#if defined(STM32F446xx)
  /* Enable GPIOA, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG interface
      clock */
  RCC->AHB1ENR |= 0x0000007DUL;
#else
  /* Enable GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH and GPIOI interface
      clock */
  RCC->AHB1ENR |= 0x000001F8UL;
#endif /* STM32F446xx */
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);

#if defined(STM32F446xx)
  /* Connect PAx pins to FMC Alternate function */
  GPIOA->AFR[0U]  |= 0xC0000000UL;
  GPIOA->AFR[1U]  |= 0x00000000UL;
  /* Configure PDx pins in Alternate function mode */
  GPIOA->MODER   |= 0x00008000UL;
  /* Configure PDx pins speed to 50 MHz */
  GPIOA->OSPEEDR |= 0x00008000UL;
  /* Configure PDx pins Output type to push-pull */
  GPIOA->OTYPER  |= 0x00000000UL;
  /* No pull-up, pull-down for PDx pins */
  GPIOA->PUPDR   |= 0x00000000UL;

  /* Connect PCx pins to FMC Alternate function */
  GPIOC->AFR[0U]  |= 0x00CC0000UL;
  GPIOC->AFR[1U]  |= 0x00000000UL;
  /* Configure PDx pins in Alternate function mode */
  GPIOC->MODER   |= 0x00000A00UL;
  /* Configure PDx pins speed to 50 MHz */
  GPIOC->OSPEEDR |= 0x00000A00UL;
  /* Configure PDx pins Output type to push-pull */
  GPIOC->OTYPER  |= 0x00000000UL;
  /* No pull-up, pull-down for PDx pins */
  GPIOC->PUPDR   |= 0x00000000UL;
#endif /* STM32F446xx */

  /* Connect PDx pins to FMC Alternate function */
  GPIOD->AFR[0U]  = 0x000000CCUL;
  GPIOD->AFR[1U]  = 0xCC000CCCUL;
  /* Configure PDx pins in Alternate function mode */
  GPIOD->MODER   = 0xA02A000AUL;
  /* Configure PDx pins speed to 50 MHz */
  GPIOD->OSPEEDR = 0xA02A000AUL;
  /* Configure PDx pins Output type to push-pull */
  GPIOD->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PDx pins */
  GPIOD->PUPDR   = 0x00000000UL;

  /* Connect PEx pins to FMC Alternate function */
  GPIOE->AFR[0U]  = 0xC00000CCUL;
  GPIOE->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PEx pins in Alternate function mode */
  GPIOE->MODER   = 0xAAAA800AUL;
  /* Configure PEx pins speed to 50 MHz */
  GPIOE->OSPEEDR = 0xAAAA800AUL;
  /* Configure PEx pins Output type to push-pull */
  GPIOE->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PEx pins */
  GPIOE->PUPDR   = 0x00000000UL;

  /* Connect PFx pins to FMC Alternate function */
  GPIOF->AFR[0U]  = 0xCCCCCCCCUL;
  GPIOF->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PFx pins in Alternate function mode */
  GPIOF->MODER   = 0xAA800AAAUL;
  /* Configure PFx pins speed to 50 MHz */
  GPIOF->OSPEEDR = 0xAA800AAAUL;
  /* Configure PFx pins Output type to push-pull */
  GPIOF->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PFx pins */
  GPIOF->PUPDR   = 0x00000000UL;

  /* Connect PGx pins to FMC Alternate function */
  GPIOG->AFR[0U]  = 0xCCCCCCCCUL;
  GPIOG->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER   = 0xAAAAAAAAUL;
  /* Configure PGx pins speed to 50 MHz */
  GPIOG->OSPEEDR = 0xAAAAAAAAUL;
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PGx pins */
  GPIOG->PUPDR   = 0x00000000UL;

#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) \
 || defined(STM32F469xx) || defined(STM32F479xx)
  /* Connect PHx pins to FMC Alternate function */
  GPIOH->AFR[0U]  = 0x00C0CC00UL;
  GPIOH->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PHx pins in Alternate function mode */
  GPIOH->MODER   = 0xAAAA08A0UL;
  /* Configure PHx pins speed to 50 MHz */
  GPIOH->OSPEEDR = 0xAAAA08A0UL;
  /* Configure PHx pins Output type to push-pull */
  GPIOH->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PHx pins */
  GPIOH->PUPDR   = 0x00000000UL;

  /* Connect PIx pins to FMC Alternate function */
  GPIOI->AFR[0U]  = 0xCCCCCCCCUL;
  GPIOI->AFR[1U]  = 0x00000CC0UL;
  /* Configure PIx pins in Alternate function mode */
  GPIOI->MODER   = 0x0028AAAAUL;
  /* Configure PIx pins speed to 50 MHz */
  GPIOI->OSPEEDR = 0x0028AAAAUL;
  /* Configure PIx pins Output type to push-pull */
  GPIOI->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PIx pins */
  GPIOI->PUPDR   = 0x00000000UL;
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx || STM32F469xx || STM32F479xx */

/*-- FMC Configuration -------------------------------------------------------*/
  /* Enable the FMC interface clock */
  RCC->AHB3ENR |= 0x00000001UL;
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);

  /* Configure and enable SDRAM bank1 */
#if defined(STM32F446xx)
  FMC_Bank5_6->SDCR[0U] = 0x00001954UL;
#else
  FMC_Bank5_6->SDCR[0U] = 0x000019E4UL;
#endif /* STM32F446xx */
  FMC_Bank5_6->SDTR[0U] = 0x01115351UL;

  /* SDRAM initialization sequence */
  /* Clock enable command */
  FMC_Bank5_6->SDCMR = 0x00000011UL;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* Delay */
  for (index = 0; index<1000; index++);

  /* PALL command */
  FMC_Bank5_6->SDCMR = 0x00000012UL;
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  timeout = 0xFFFFU;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* Auto refresh command */
#if defined(STM32F446xx)
  FMC_Bank5_6->SDCMR = 0x000000F3UL;
#else
  FMC_Bank5_6->SDCMR = 0x00000073UL;
#endif /* STM32F446xx */
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  timeout = 0xFFFFU;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* MRD register program */
#if defined(STM32F446xx)
  FMC_Bank5_6->SDCMR = 0x00044014UL;
#else
  FMC_Bank5_6->SDCMR = 0x00046014UL;
#endif /* STM32F446xx */
  tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  timeout = 0xFFFFU;
  while((tmpreg != 0) && (timeout-- > 0))
  {
    tmpreg = FMC_Bank5_6->SDSR & 0x00000020UL;
  }

  /* Set refresh count */
  tmpreg = FMC_Bank5_6->SDRTR;
#if defined(STM32F446xx)
  FMC_Bank5_6->SDRTR = (tmpreg | (0x0000050CUL<< 1U));
#else
  FMC_Bank5_6->SDRTR = (tmpreg | (0x0000027CUL<< 1U));
#endif /* STM32F446xx */

  /* Disable write protection */
  tmpreg = FMC_Bank5_6->SDCR[0U];
  FMC_Bank5_6->SDCR[0U] = (tmpreg & 0xFFFFFDFFUL);
#endif /* DATA_IN_ExtSDRAM */
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx || STM32F446xx || STM32F469xx || STM32F479xx */

#if defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx) || defined(STM32F417xx) \
 || defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx) \
 || defined(STM32F469xx) || defined(STM32F479xx) || defined(STM32F412Zx) || defined(STM32F412Vx)

#if defined(DATA_IN_ExtSRAM)
/*-- GPIOs Configuration -----------------------------------------------------*/
   /* Enable GPIOD, GPIOE, GPIOF and GPIOG interface clock */
  RCC->AHB1ENR   |= 0x00000078UL;
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);

  /* Connect PDx pins to FMC Alternate function */
  GPIOD->AFR[0U]  = 0x00CCC0CCUL;
  GPIOD->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PDx pins in Alternate function mode */
  GPIOD->MODER   = 0xAAAA0A8AUL;
  /* Configure PDx pins speed to 100 MHz */
  GPIOD->OSPEEDR = 0xFFFF0FCFUL;
  /* Configure PDx pins Output type to push-pull */
  GPIOD->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PDx pins */
  GPIOD->PUPDR   = 0x00000000UL;

  /* Connect PEx pins to FMC Alternate function */
  GPIOE->AFR[0U]  = 0xC00CC0CCUL;
  GPIOE->AFR[1U]  = 0xCCCCCCCCUL;
  /* Configure PEx pins in Alternate function mode */
  GPIOE->MODER   = 0xAAAA828AUL;
  /* Configure PEx pins speed to 100 MHz */
  GPIOE->OSPEEDR = 0xFFFFC3CFUL;
  /* Configure PEx pins Output type to push-pull */
  GPIOE->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PEx pins */
  GPIOE->PUPDR   = 0x00000000UL;

  /* Connect PFx pins to FMC Alternate function */
  GPIOF->AFR[0U]  = 0x00CCCCCCUL;
  GPIOF->AFR[1U]  = 0xCCCC0000UL;
  /* Configure PFx pins in Alternate function mode */
  GPIOF->MODER   = 0xAA000AAAUL;
  /* Configure PFx pins speed to 100 MHz */
  GPIOF->OSPEEDR = 0xFF000FFFUL;
  /* Configure PFx pins Output type to push-pull */
  GPIOF->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PFx pins */
  GPIOF->PUPDR   = 0x00000000UL;

  /* Connect PGx pins to FMC Alternate function */
  GPIOG->AFR[0U]  = 0x00CCCCCCUL;
  GPIOG->AFR[1U]  = 0x000000C0UL;
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER   = 0x00085AAAUL;
  /* Configure PGx pins speed to 100 MHz */
  GPIOG->OSPEEDR = 0x000CAFFFUL;
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER  = 0x00000000UL;
  /* No pull-up, pull-down for PGx pins */
  GPIOG->PUPDR   = 0x00000000UL;

/*-- FMC/FSMC Configuration --------------------------------------------------*/
  /* Enable the FMC/FSMC interface clock */
  RCC->AHB3ENR         |= 0x00000001UL;

#if defined(STM32F427xx) || defined(STM32F437xx) || defined(STM32F429xx) || defined(STM32F439xx)
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);
  /* Configure and enable Bank1_SRAM2 */
  FMC_Bank1->BTCR[2U]  = 0x00001011UL;
  FMC_Bank1->BTCR[3U]  = 0x00000201UL;
  FMC_Bank1E->BWTR[2U] = 0x0fffffffUL;
#endif /* STM32F427xx || STM32F437xx || STM32F429xx || STM32F439xx */
#if defined(STM32F469xx) || defined(STM32F479xx)
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);
  /* Configure and enable Bank1_SRAM2 */
  FMC_Bank1->BTCR[2U]  = 0x00001091UL;
  FMC_Bank1->BTCR[3U]  = 0x00110212UL;
  FMC_Bank1E->BWTR[2U] = 0x0fffffffUL;
#endif /* STM32F469xx || STM32F479xx */
#if defined(STM32F405xx) || defined(STM32F415xx) || defined(STM32F407xx)|| defined(STM32F417xx) \
   || defined(STM32F412Zx) || defined(STM32F412Vx)
  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FSMCEN);
  /* Configure and enable Bank1_SRAM2 */
  FSMC_Bank1->BTCR[2U]  = 0x00001011UL;
  FSMC_Bank1->BTCR[3U]  = 0x00000201UL;
  FSMC_Bank1E->BWTR[2U] = 0x0FFFFFFFUL;
#endif /* STM32F405xx || STM32F415xx || STM32F407xx || STM32F417xx || STM32F412Zx || STM32F412Vx */

#endif /* DATA_IN_ExtSRAM */
#endif /* STM32F405xx || STM32F415xx || STM32F407xx || STM32F417xx || STM32F427xx || STM32F437xx || \
          STM32F429xx || STM32F439xx || STM32F469xx || STM32F479xx || STM32F412Zx || STM32F412Vx  */
  (void)(tmp);
}
#endif /* DATA_IN_ExtSRAM && DATA_IN_ExtSDRAM */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
