/**
  ******************************************************************************
  * @file    stm32l4xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32L4xx Device Peripheral Access Layer Header File.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The STM32L4xx device used in the target application
  *              - To use or not the peripheral's drivers in application code(i.e.
  *                code will be based on direct access to peripheral's registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_HAL_DRIVER"
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

/** @addtogroup stm32l4xx
  * @{
  */

#ifndef __STM32L4xx_H
#define __STM32L4xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief STM32 Family
  */
#if !defined (STM32L4)
#define STM32L4
#endif /* STM32L4 */

/* Uncomment the line below according to the target STM32L4 device used in your
   application
  */

#if !defined (STM32L412xx) && !defined (STM32L422xx) && \
    !defined (STM32L431xx) && !defined (STM32L432xx) && !defined (STM32L433xx) && !defined (STM32L442xx) && !defined (STM32L443xx) && \
    !defined (STM32L451xx) && !defined (STM32L452xx) && !defined (STM32L462xx) && \
    !defined (STM32L471xx) && !defined (STM32L475xx) && !defined (STM32L476xx) && !defined (STM32L485xx) && !defined (STM32L486xx) && \
    !defined (STM32L496xx) && !defined (STM32L4A6xx) && \
    !defined (STM32L4P5xx) && !defined (STM32L4Q5xx) && \
    !defined (STM32L4R5xx) && !defined (STM32L4R7xx) && !defined (STM32L4R9xx) && !defined (STM32L4S5xx) && !defined (STM32L4S7xx) && !defined (STM32L4S9xx)
  /* #define STM32L412xx */   /*!< STM32L412xx Devices */
  /* #define STM32L422xx */   /*!< STM32L422xx Devices */
  /* #define STM32L431xx */   /*!< STM32L431xx Devices */
  /* #define STM32L432xx */   /*!< STM32L432xx Devices */
  /* #define STM32L433xx */   /*!< STM32L433xx Devices */
  /* #define STM32L442xx */   /*!< STM32L442xx Devices */
  /* #define STM32L443xx */   /*!< STM32L443xx Devices */
  /* #define STM32L451xx */   /*!< STM32L451xx Devices */
  /* #define STM32L452xx */   /*!< STM32L452xx Devices */
  /* #define STM32L462xx */   /*!< STM32L462xx Devices */
  /* #define STM32L471xx */   /*!< STM32L471xx Devices */
  /* #define STM32L475xx */   /*!< STM32L475xx Devices */
  /* #define STM32L476xx */   /*!< STM32L476xx Devices */
  /* #define STM32L485xx */   /*!< STM32L485xx Devices */
  /* #define STM32L486xx */   /*!< STM32L486xx Devices */
  /* #define STM32L496xx */   /*!< STM32L496xx Devices */
  /* #define STM32L4A6xx */   /*!< STM32L4A6xx Devices */
  /* #define STM32L4P5xx */   /*!< STM32L4Q5xx Devices */
  /* #define STM32L4R5xx */   /*!< STM32L4R5xx Devices */
  /* #define STM32L4R7xx */   /*!< STM32L4R7xx Devices */
  /* #define STM32L4R9xx */   /*!< STM32L4R9xx Devices */
  /* #define STM32L4S5xx */   /*!< STM32L4S5xx Devices */
  /* #define STM32L4S7xx */   /*!< STM32L4S7xx Devices */
  /* #define STM32L4S9xx */   /*!< STM32L4S9xx Devices */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
  /*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @brief CMSIS Device version number
  */
#define __STM32L4_CMSIS_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define __STM32L4_CMSIS_VERSION_SUB1   (0x07U) /*!< [23:16] sub1 version */
#define __STM32L4_CMSIS_VERSION_SUB2   (0x04U) /*!< [15:8]  sub2 version */
#define __STM32L4_CMSIS_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __STM32L4_CMSIS_VERSION        ((__STM32L4_CMSIS_VERSION_MAIN << 24U) \
                                       |(__STM32L4_CMSIS_VERSION_SUB1 << 16U) \
                                       |(__STM32L4_CMSIS_VERSION_SUB2 << 8U ) \
                                       |(__STM32L4_CMSIS_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#if defined(_MSC_VER)
 #pragma warning(push)
 #pragma warning(disable: 4100)		//Unreferenzierter formaler Parameter
 #pragma warning(disable: 4244)		//Konvertierung, möglicher Datenverlust
 #pragma warning( disable: 4510 )	//Standardkonstruktor konnte nicht generiert werden
 #pragma warning( disable: 4610 )	//kann niemals instantiiert werden - benutzerdefinierter Konstruktor erforderlich
#endif

#if defined(MASK)
 /*lint -save -e9021 -e9159*/ //use of '#undef' is discouraged
 #undef MASK
 /*lint -restore*/
#endif

#if defined(STM32L412xx)
  #include "stm32l412xx.h"
#elif defined(STM32L422xx)
  #include "stm32l422xx.h"
#elif defined(STM32L431xx)
  #include "stm32l431xx.h"
#elif defined(STM32L432xx)
  #include "stm32l432xx.h"
#elif defined(STM32L433xx)
  #include "stm32l433xx.h"
#elif defined(STM32L442xx)
  #include "stm32l442xx.h"
#elif defined(STM32L443xx)
  #include "stm32l443xx.h"
#elif defined(STM32L451xx)
  #include "stm32l451xx.h"
#elif defined(STM32L452xx)
  #include "stm32l452xx.h"
#elif defined(STM32L462xx)
  #include "stm32l462xx.h"
#elif defined(STM32L471xx)
  #include "stm32l471xx.h"
#elif defined(STM32L475xx)
  #include "stm32l475xx.h"
#elif defined(STM32L476xx)
  #include "stm32l476xx.h"
#elif defined(STM32L485xx)
  #include "stm32l485xx.h"
#elif defined(STM32L486xx)
  #include "stm32l486xx.h"
#elif defined(STM32L496xx)
  #include "stm32l496xx.h"
#elif defined(STM32L4A6xx)
  #include "stm32l4a6xx.h"
#elif defined(STM32L4P5xx)
  #include "stm32l4p5xx.h"
#elif defined(STM32L4Q5xx)
  #include "stm32l4q5xx.h"
#elif defined(STM32L4R5xx)
  #include "stm32l4r5xx.h"
#elif defined(STM32L4R7xx)
  #include "stm32l4r7xx.h"
#elif defined(STM32L4R9xx)
  #include "stm32l4r9xx.h"
#elif defined(STM32L4S5xx)
  #include "stm32l4s5xx.h"
#elif defined(STM32L4S7xx)
  #include "stm32l4s7xx.h"
#elif defined(STM32L4S9xx)
  #include "stm32l4s9xx.h"
#else
 #error "Please select first the target STM32L4xx device used in your application (in stm32l4xx.h file)"
#endif

#include "stm32l4xx_ex.h"

#if defined(__PERIPHERIE_STRUCT)
#include "../Windows/stm32_peripherie.h"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0U,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0U,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

#if defined(ERROR)
 #undef ERROR			/* defined in WinGDI */
#endif

typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0U))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/* Use of CMSIS compiler intrinsics for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                             \
  do {                                                       \
    uint32_t val;                                            \
    do {                                                     \
      val = __LDREXW((__IO uint32_t *)&(REG)) | (BIT);       \
    } while ((__STREXW(val,(__IO uint32_t *)&(REG))) != 0U); \
  } while(0U)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                           \
  do {                                                       \
    uint32_t val;                                            \
    do {                                                     \
      val = __LDREXW((__IO uint32_t *)&(REG)) & ~(BIT);      \
    } while ((__STREXW(val,(__IO uint32_t *)&(REG))) != 0U); \
  } while(0U)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)                          \
  do {                                                                     \
    uint32_t val;                                                          \
    do {                                                                   \
      val = (__LDREXW((__IO uint32_t *)&(REG)) & ~(CLEARMSK)) | (SETMASK); \
    } while ((__STREXW(val,(__IO uint32_t *)&(REG))) != 0U);               \
  } while(0U)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT)                            \
  do {                                                       \
    uint16_t val;                                            \
    do {                                                     \
      val = __LDREXH((__IO uint16_t *)&(REG)) | (BIT);       \
    } while ((__STREXH(val,(__IO uint16_t *)&(REG))) != 0U); \
  } while(0U)

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT)                          \
  do {                                                       \
    uint16_t val;                                            \
    do {                                                     \
      val = __LDREXH((__IO uint16_t *)&(REG)) & ~(BIT);      \
    } while ((__STREXH(val,(__IO uint16_t *)&(REG))) != 0U); \
  } while(0U)

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK)                         \
  do {                                                                     \
    uint16_t val;                                                          \
    do {                                                                   \
      val = (__LDREXH((__IO uint16_t *)&(REG)) & ~(CLEARMSK)) | (SETMASK); \
    } while ((__STREXH(val,(__IO uint16_t *)&(REG))) != 0U);               \
  } while(0U)

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

/**
  * @}
  */

#if defined (USE_HAL_DRIVER)
 #include "stm32l4xx_hal.h"
#endif /* USE_HAL_DRIVER */


#if defined(USE_ADC_LL_DRIVER)
 #include "stm32l4xx_ll_adc.h"
#endif
#if defined(USE_BUS_LL_DRIVER)
 #include "stm32l4xx_ll_bus.h"
#endif
#if defined(USE_COMP_LL_DRIVER)
 #include "stm32l4xx_ll_comp.h"
#endif
#if defined(USE_CORTEX_LL_DRIVER)
 #include "stm32l4xx_ll_cortex.h"
#endif
#if defined(USE_CRC_LL_DRIVER)
 #include "stm32l4xx_ll_crc.h"
#endif
#if defined(USE_CRS_LL_DRIVER)
 #include "stm32l4xx_ll_crs.h"
#endif
#if defined(USE_DAC_LL_DRIVER)
 #include "stm32l4xx_ll_dac.h"
#endif
#if defined(USE_DMA_LL_DRIVER)
 #include "stm32l4xx_ll_dma.h"
#endif
#if defined(USE_DMA2D_LL_DRIVER)
 #include "stm32l4xx_ll_dma2d.h"
#endif
#if defined(USE_DMAMUX_LL_DRIVER)
 #include "stm32l4xx_ll_dmamux.h"
#endif
#if defined(USE_EXTI_LL_DRIVER)
 #include "stm32l4xx_ll_exti.h"
#endif
#if defined(USE_FMC_LL_DRIVER)
 #include "stm32l4xx_ll_fmc.h"
#endif
#if defined(USE_GPIO_LL_DRIVER)
 #include "stm32l4xx_ll_gpio.h"
#endif
#if defined(USE_I2C_LL_DRIVER)
 #include "stm32l4xx_ll_i2c.h"
#endif
#if defined(USE_IWDG_LL_DRIVER)
 #include "stm32l4xx_ll_iwdg.h"
#endif
#if defined(USE_LPTIM_LL_DRIVER)
 #include "stm32l4xx_ll_lptim.h"
#endif
#if defined(USE_LPUART_LL_DRIVER)
 #include "stm32l4xx_ll_lpuart.h"
#endif
#if defined(USE_OPAMP_LL_DRIVER)
 #include "stm32l4xx_ll_opamp.h"
#endif
#if defined(USE_PWR_LL_DRIVER)
 #include "stm32l4xx_ll_pwr.h"
#endif
#if defined(USE_RCC_LL_DRIVER)
 #include "stm32l4xx_ll_rcc.h"
#endif
#if defined(USE_RNG_LL_DRIVER)
 #include "stm32l4xx_ll_rng.h"
#endif
#if defined(USE_RTC_LL_DRIVER)
 #include "stm32l4xx_ll_rtc.h"
#endif
#if defined(USE_SDMMC_LL_DRIVER)
 #include "stm32l4xx_ll_sdmmc.h"
#endif
#if defined(USE_SPI_LL_DRIVER)
 #include "stm32l4xx_ll_spi.h"
#endif
#if defined(USE_SWPMI_LL_DRIVER)
 #include "stm32l4xx_ll_swpmi.h"
#endif
#if defined(USE_SYSTEM_LL_DRIVER)
 #include "stm32l4xx_ll_system.h"
#endif
#if defined(USE_TIM_LL_DRIVER)
 #include "stm32l4xx_ll_tim.h"
#endif
#if defined(USE_USART_LL_DRIVER)
 #include "stm32l4xx_ll_usart.h"
#endif
#if defined(USE_USB_LL_DRIVER)
 #include "stm32l4xx_ll_usb.h"
#endif
#if defined(USE_UTILS_LL_DRIVER)
 #include "stm32l4xx_ll_utils.h"
#endif
#if defined(USE_WWDG_LL_DRIVER)
 #include "stm32l4xx_ll_wwdg.h"
#endif

#if defined(_MSC_VER)
 #pragma warning(pop)
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32L4xx_H */
/**
  * @}
  */

/**
  * @}
  */

