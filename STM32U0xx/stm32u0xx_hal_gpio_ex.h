/**
  ******************************************************************************
  * @file    stm32u0xx_hal_gpio_ex.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO HAL Extended module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U0xx_HAL_GPIO_EX_H
#define STM32U0xx_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u0xx_hal_def.h"

/** @addtogroup STM32U0xx_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
  * @brief GPIO Extended HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIOEx_Exported_Constants GPIOEx Exported Constants
  * @{
  */

/** @defgroup GPIOEx_Alternate_function_selection GPIOEx Alternate function selection
  * @{
  */

/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /*!< MCO (MCO1) Alternate Function mapping */
#define GPIO_AF0_OSC_EN        ((uint8_t)0x00U)  /*!< OSC (By pass and Enable) Alternate Function mapping */
#define GPIO_AF0_OSC32_EN      ((uint8_t)0x00U)  /*!< OSC32 (By pass and Enable) Alternate Function mapping */
#define GPIO_AF0_SWD           ((uint8_t)0x00U)  /*!< SWD (SWDIO/SWDCLK)  Alternate Function mapping */
#define GPIO_AF0_MCO2          ((uint8_t)0x00U)  /*!< MCO (MCO2) Alternate Function mapping */
#define GPIO_AF0_RTC           ((uint8_t)0x00U)  /*!< RTC (OUT2/REFIN) Alternate Function mapping */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /*!< IR Alternate Function mapping */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /*!< TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /*!< TIM2 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF1_OSC_EN        ((uint8_t)0x01U)  /*!< OSC (By pass and Enable) Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_LPTIM1        ((uint8_t)0x02U)  /*!< LPTIM1 Alternate Function mapping */
#if defined(LPTIM3)
#define GPIO_AF2_LPTIM3        ((uint8_t)0x02U)  /*!< LPTIM3 Alternate Function mapping */
#endif /* LPTIM3 */
#if defined(I2C4)
#define GPIO_AF2_I2C4          ((uint8_t)0x02U)  /*!< I2C4 Alternate Function mapping */
#endif /* I2C4 */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /*!< TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  /*!< TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /*!< TIM3 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_I2C2          ((uint8_t)0x03U)  /*!< I2C2 Alternate Function mapping */
#define GPIO_AF3_MCO2          ((uint8_t)0x03U)  /*!< MCO (MCO2) Alternate Function mapping */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /*!< USART2 Alternate Function mapping */
#if defined(I2C4)
#define GPIO_AF3_I2C4          ((uint8_t)0x03U)  /*!< I2C4 Alternate Function mapping */
#endif /* I2C4 */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /*!< I2C3 Alternate Function mapping */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /*!< I2C1 Alternate Function mapping */
#if defined(LPTIM3)
#define GPIO_AF4_LPTIM3        ((uint8_t)0x04U)  /*!< LPTIM3 Alternate Function mapping */
#endif /* LPTIM3 */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /*!< I2C2 Alternate Function mapping */
#if defined(I2C4)
#define GPIO_AF4_I2C4          ((uint8_t)0x04U)  /*!< I2C4 Alternate Function mapping */
#endif /* I2C4 */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /*!< SPI1 Alternate Function mapping */
#define GPIO_AF5_I2C2          ((uint8_t)0x05U)  /*!< I2C2 Alternate Function mapping */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /*!< SPI2 Alternate Function mapping */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_SPI2          ((uint8_t)0x06U)  /*!< SPI2 Alternate Function mapping */
#if defined (SPI3)
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /*!< SPI3 Alternate Function mapping */
#endif /* SPI3 */
#define GPIO_AF6_COMP1         ((uint8_t)0x06U)  /*!< COMP1 Alternate Function mapping */
#if defined(LPUART3)
#define GPIO_AF6_LPUART3       ((uint8_t)0x06U)  /*!< LPUART3 Alternate Function mapping */
#endif /* LPUART3 */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /*!< USART1 Alternate Function mapping */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /*!< USART2 Alternate Function mapping */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /*!< USART3 Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_USART4        ((uint8_t)0x08U)  /*!< USART4 Alternate Function mapping  */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /*!< LPUART1 Alternate Function mapping */
#define GPIO_AF8_LPUART2       ((uint8_t)0x08U)  /*!< LPUART2 Alternate Function mapping */
#if defined(LPUART3)
#define GPIO_AF8_LPUART3       ((uint8_t)0x08U)  /*!< LPUART3 Alternate Function mapping */
#endif /* LPUART3 */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /*!< TSC Alternate Function mapping */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_LPUART2      ((uint8_t)0x0AU)  /*!< LPUART2 Alternate Function mapping */
#if defined(USB_DRD_FS)
#define GPIO_AF10_USB          ((uint8_t)0x0AU)  /*!< USB Alternate Function mapping */
#endif /* USB_DRD_FS */
#if defined(CRS)
#define GPIO_AF10_CRS          ((uint8_t)0x0AU)  /*!< CRS Alternate Function mapping */
#endif /* CRS */

/**
  * @brief   AF 11 selection
  */
#if defined(LCD)
#define GPIO_AF11_LCD         ((uint8_t)0x0BU)  /*!< LCD Alternate Function mapping */
#endif /* LCD */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_COMP1       ((uint8_t)0x0CU)  /*!< COMP1 Alternate Function mapping */
#if defined(COMP2)
#define GPIO_AF12_COMP2       ((uint8_t)0x0CU)  /*!< COMP2 Alternate Function mapping */
#endif /* COMP2 */
#if defined(LCD)
#define GPIO_AF12_LCD         ((uint8_t)0x0CU)  /*!< LCD Alternate Function mapping */
#endif /* LCD */

/**
  * @brief   AF 13 selection
  */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_LPTIM1      ((uint8_t)0x0EU)  /*!< LPTIM1 Alternate Function mapping */
#define GPIO_AF14_LPTIM2      ((uint8_t)0x0EU)  /*!< LPTIM2 Alternate Function mapping */
#if defined(LPTIM3)
#define GPIO_AF14_LPTIM3      ((uint8_t)0x0EU)  /*!< LPTIM3 Alternate Function mapping */
#endif /* LPTIM3 */
#define GPIO_AF14_TIM2        ((uint8_t)0x0EU)  /*!< TIM2 Alternate Function mapping   */
#define GPIO_AF14_TIM15       ((uint8_t)0x0EU)  /*!< TIM15 Alternate Function mapping  */
#define GPIO_AF14_TIM16       ((uint8_t)0x0EU)  /*!< TIM16 Alternate Function mapping  */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT    ((uint8_t)0x0FU)  /*!< EVENTOUT Alternate Function mapping */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIOEx_Exported_Macros GPIOEx Exported Macros
  * @{
  */

/** @defgroup GPIOEx_Get_Port_Index GPIOEx Get Port Index
  * @{
  */
#if defined (GPIOE)
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOE)) ? 4UL : \
                                      ((__GPIOx__) == (GPIOF)) ? 5UL : 6UL)
#else
#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOF)) ? 5UL : 6UL)
#endif /* GPIOE */
/**
  * @}
  */

#define IS_GPIO_AF(AF)         ((AF) <= (uint8_t)0x0FU)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32U0xx_HAL_GPIO_EX_H */

