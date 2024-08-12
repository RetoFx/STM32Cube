/**
  ******************************************************************************
  * @file    stm32l4xx_hal_gpio_ex.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO HAL Extended module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32L4xx_HAL_GPIO_EX_H
#define STM32L4xx_HAL_GPIO_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal_def.h"

/** @addtogroup STM32L4xx_HAL_Driver
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

#if defined(STM32L412xx) || defined(STM32L422xx)
/*--------------STM32L412xx/STM32L422xx---*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /* USART1 Alternate Function mapping */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping   */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping   */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_COMP1         ((uint8_t)0x06U)  /* COMP1 Alternate Function mapping   */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping     */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_USB_FS       ((uint8_t)0x0AU)  /* USB_FS Alternate Function mapping */
#define GPIO_AF10_QUADSPI      ((uint8_t)0x0AU)  /* QUADSPI Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */


/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L412xx || STM32L422xx */

#if defined(STM32L431xx) || defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx)
/*--------------STM32L431xx/STM32L432xx/STM32L433xx/STM32L442xx/STM32L443xx---*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#if defined(STM32L433xx) || defined(STM32L443xx)
#define GPIO_AF0_LCDBIAS       ((uint8_t)0x00U)  /* LCDBIAS Alternate Function mapping                          */
#endif /* STM32L433xx || STM32L443xx */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /* USART1 Alternate Function mapping */
#define GPIO_AF3_TIM1_COMP2    ((uint8_t)0x03U)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping   */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping   */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3 Alternate Function mapping   */
#define GPIO_AF6_COMP1         ((uint8_t)0x06U)  /* COMP1 Alternate Function mapping   */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping     */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  /* CAN1 Alternate Function mapping    */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#if defined(STM32L432xx) || defined(STM32L433xx) || defined(STM32L442xx) || defined(STM32L443xx)
#define GPIO_AF10_USB_FS       ((uint8_t)0x0AU)  /* USB_FS Alternate Function mapping */
#endif /* STM32L432xx || STM32L433xx || STM32L442xx || STM32L443xx */
#define GPIO_AF10_QUADSPI      ((uint8_t)0x0AU)  /* QUADSPI Alternate Function mapping */

#if defined(STM32L433xx) || defined(STM32L443xx)
/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_LCD          ((uint8_t)0x0BU)  /* LCD Alternate Function mapping */
#endif /* STM32L433xx || STM32L443xx */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_SWPMI1       ((uint8_t)0x0CU)  /* SWPMI1 Alternate Function mapping  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */
#define GPIO_AF12_COMP2        ((uint8_t)0x0CU)  /* COMP2 Alternate Function mapping   */
#define GPIO_AF12_SDMMC1       ((uint8_t)0x0CU)  /* SDMMC1 Alternate Function mapping  */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_SAI1         ((uint8_t)0x0DU)  /* SAI1 Alternate Function mapping */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L431xx || STM32L432xx || STM32L433xx || STM32L442xx || STM32L443xx */

#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx)
/*--------------STM32L451xx/STM32L452xx/STM32L462xx---------------------------*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_I2C4          ((uint8_t)0x02U)  /* I2C4 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_TIM1_COMP2    ((uint8_t)0x03U)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /* USART2 Alternate Function mapping     */
#define GPIO_AF3_CAN1          ((uint8_t)0x03U)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF3_I2C4          ((uint8_t)0x03U)  /* I2C4 Alternate Function mapping */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */
#define GPIO_AF4_I2C4          ((uint8_t)0x04U)  /* I2C4 Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping   */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping   */
#define GPIO_AF5_I2C4          ((uint8_t)0x05U)  /* I2C4 Alternate Function mapping   */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3 Alternate Function mapping   */
#define GPIO_AF6_DFSDM1        ((uint8_t)0x06U)  /* DFSDM1 Alternate Function mapping */
#define GPIO_AF6_COMP1         ((uint8_t)0x06U)  /* COMP1 Alternate Function mapping   */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping     */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  /* UART4 Alternate Function mapping   */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */
#define GPIO_AF8_CAN1          ((uint8_t)0x08U)  /* CAN1 Alternate Function mapping  */


/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#if defined(STM32L452xx) || defined(STM32L462xx)
#define GPIO_AF10_USB_FS       ((uint8_t)0x0AU)  /* USB_FS Alternate Function mapping */
#endif /* STM32L452xx || STM32L462xx */
#define GPIO_AF10_QUADSPI      ((uint8_t)0x0AU)  /* QUADSPI Alternate Function mapping */
#define GPIO_AF10_CAN1         ((uint8_t)0x0AU)  /* CAN1 Alternate Function mapping  */

/**
  * @brief   AF 11 selection
  */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */
#define GPIO_AF12_COMP2        ((uint8_t)0x0CU)  /* COMP2 Alternate Function mapping   */
#define GPIO_AF12_SDMMC1       ((uint8_t)0x0CU)  /* SDMMC1 Alternate Function mapping  */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_SAI1         ((uint8_t)0x0DU)  /* SAI1 Alternate Function mapping */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping */
#define GPIO_AF14_TIM17        ((uint8_t)0x0EU)  /* TIM17 Alternate Function mapping */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L451xx || STM32L452xx || STM32L462xx */

#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx)
/*--------------STM32L471xx/STM32L475xx/STM32L476xx/STM32L485xx/STM32L486xx---*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#if defined(STM32L476xx) || defined(STM32L486xx)
#define GPIO_AF0_LCDBIAS       ((uint8_t)0x00U)  /* LCDBIAS Alternate Function mapping                        */
#endif /* STM32L476xx || STM32L486xx */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_TIM5          ((uint8_t)0x01U)  /* TIM5 Alternate Function mapping */
#define GPIO_AF1_TIM8          ((uint8_t)0x01U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          ((uint8_t)0x02U)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          ((uint8_t)0x02U)  /* TIM5 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  /* TIM8 Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP2    ((uint8_t)0x03U)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping   */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping   */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3 Alternate Function mapping   */
#define GPIO_AF6_DFSDM1        ((uint8_t)0x06U)  /* DFSDM1 Alternate Function mapping */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping     */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  /* UART4 Alternate Function mapping   */
#define GPIO_AF8_UART5         ((uint8_t)0x08U)  /* UART5 Alternate Function mapping   */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */


/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#if defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx)
#define GPIO_AF10_OTG_FS       ((uint8_t)0x0AU)  /* OTG_FS Alternate Function mapping */
#endif /* STM32L475xx || STM32L476xx || STM32L485xx || STM32L486xx */
#define GPIO_AF10_QUADSPI      ((uint8_t)0x0AU)  /* QUADSPI Alternate Function mapping */

#if defined(STM32L476xx) || defined(STM32L486xx)
/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_LCD          ((uint8_t)0x0BU)  /* LCD Alternate Function mapping */
#endif /* STM32L476xx || STM32L486xx */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_FMC          ((uint8_t)0x0CU)  /* FMC Alternate Function mapping     */
#define GPIO_AF12_SWPMI1       ((uint8_t)0x0CU)  /* SWPMI1 Alternate Function mapping  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */
#define GPIO_AF12_COMP2        ((uint8_t)0x0CU)  /* COMP2 Alternate Function mapping   */
#define GPIO_AF12_SDMMC1       ((uint8_t)0x0CU)  /* SDMMC1 Alternate Function mapping  */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_SAI1         ((uint8_t)0x0DU)  /* SAI1 Alternate Function mapping */
#define GPIO_AF13_SAI2         ((uint8_t)0x0DU)  /* SAI2 Alternate Function mapping */
#define GPIO_AF13_TIM8_COMP2   ((uint8_t)0x0DU)  /* TIM8/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF13_TIM8_COMP1   ((uint8_t)0x0DU)  /* TIM8/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping */
#define GPIO_AF14_TIM17        ((uint8_t)0x0EU)  /* TIM17 Alternate Function mapping */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */
#define GPIO_AF14_TIM8_COMP1   ((uint8_t)0x0EU)  /* TIM8/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L471xx || STM32L475xx || STM32L476xx || STM32L485xx || STM32L486xx */

#if defined(STM32L496xx) || defined(STM32L4A6xx)
/*--------------------------------STM32L496xx/STM32L4A6xx---------------------*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_TIM5          ((uint8_t)0x01U)  /* TIM5 Alternate Function mapping */
#define GPIO_AF1_TIM8          ((uint8_t)0x01U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          ((uint8_t)0x02U)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          ((uint8_t)0x02U)  /* TIM5 Alternate Function mapping */
#define GPIO_AF2_I2C4          ((uint8_t)0x02U)  /* I2C4 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  /* TIM8 Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP2    ((uint8_t)0x03U)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF3_CAN2          ((uint8_t)0x03U)  /* CAN2 Alternate Function mapping    */
#define GPIO_AF3_I2C4          ((uint8_t)0x03U)  /* I2C4 Alternate Function mapping */
#define GPIO_AF3_QUADSPI       ((uint8_t)0x03U)  /* QUADSPI Alternate Function mapping */
#define GPIO_AF3_SPI2          ((uint8_t)0x03U)  /* SPI2 Alternate Function mapping */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /* USART2 Alternate Function mapping */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */
#define GPIO_AF4_I2C4          ((uint8_t)0x04U)  /* I2C4 Alternate Function mapping   */
#define GPIO_AF4_DCMI          ((uint8_t)0x04U)  /* DCMI Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping   */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping   */
#define GPIO_AF5_DCMI          ((uint8_t)0x05U)  /* DCMI Alternate Function mapping   */
#define GPIO_AF5_I2C4          ((uint8_t)0x05U)  /* I2C4 Alternate Function mapping */
#define GPIO_AF5_QUADSPI       ((uint8_t)0x05U)  /* QUADSPI Alternate Function mapping */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3 Alternate Function mapping   */
#define GPIO_AF6_DFSDM1        ((uint8_t)0x06U)  /* DFSDM1 Alternate Function mapping */
#define GPIO_AF6_I2C3          ((uint8_t)0x06U)  /* I2C3 Alternate Function mapping */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping     */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping     */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping     */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  /* UART4 Alternate Function mapping   */
#define GPIO_AF8_UART5         ((uint8_t)0x08U)  /* UART5 Alternate Function mapping   */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */
#define GPIO_AF8_CAN2          ((uint8_t)0x08U)  /* CAN2 Alternate Function mapping    */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_OTG_FS       ((uint8_t)0x0AU)  /* OTG_FS Alternate Function mapping */
#define GPIO_AF10_QUADSPI      ((uint8_t)0x0AU)  /* QUADSPI Alternate Function mapping */
#define GPIO_AF10_CAN2         ((uint8_t)0x0AU)  /* CAN2 Alternate Function mapping */
#define GPIO_AF10_DCMI         ((uint8_t)0x0AU)  /* DCMI Alternate Function mapping */

/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_LCD          ((uint8_t)0x0BU)  /* LCD Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_FMC          ((uint8_t)0x0CU)  /* FMC Alternate Function mapping     */
#define GPIO_AF12_SWPMI1       ((uint8_t)0x0CU)  /* SWPMI1 Alternate Function mapping  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */
#define GPIO_AF12_COMP2        ((uint8_t)0x0CU)  /* COMP2 Alternate Function mapping   */
#define GPIO_AF12_SDMMC1       ((uint8_t)0x0CU)  /* SDMMC1 Alternate Function mapping  */
#define GPIO_AF12_TIM1_COMP2   ((uint8_t)0x0CU)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF12_TIM1_COMP1   ((uint8_t)0x0CU)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF12_TIM8_COMP2   ((uint8_t)0x0CU)  /* TIM8/COMP2 Break in Alternate Function mapping  */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_SAI1         ((uint8_t)0x0DU)  /* SAI1 Alternate Function mapping */
#define GPIO_AF13_SAI2         ((uint8_t)0x0DU)  /* SAI2 Alternate Function mapping */
#define GPIO_AF13_TIM8_COMP2   ((uint8_t)0x0DU)  /* TIM8/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF13_TIM8_COMP1   ((uint8_t)0x0DU)  /* TIM8/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping */
#define GPIO_AF14_TIM17        ((uint8_t)0x0EU)  /* TIM17 Alternate Function mapping */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */
#define GPIO_AF14_TIM8_COMP1   ((uint8_t)0x0EU)  /* TIM8/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L496xx || STM32L4A6xx */

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
/*---STM32L4P5xx/STM32L4Q5xx--*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_TIM5          ((uint8_t)0x01U)  /* TIM5 Alternate Function mapping */
#define GPIO_AF1_TIM8          ((uint8_t)0x01U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping   */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          ((uint8_t)0x02U)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          ((uint8_t)0x02U)  /* TIM5 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_I2C4          ((uint8_t)0x03U)  /* I2C4 Alternate Function mapping   */
#define GPIO_AF3_OCTOSPIM_P1   ((uint8_t)0x03U)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF3_SAI1          ((uint8_t)0x03U)  /* SAI1 Alternate Function mapping */
#define GPIO_AF3_SPI2          ((uint8_t)0x03U)  /* SPI2 Alternate Function mapping   */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP2    ((uint8_t)0x03U)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  /* TIM8 Alternate Function mapping   */
#define GPIO_AF3_TIM8_COMP1    ((uint8_t)0x03U)  /* TIM8/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM8_COMP2    ((uint8_t)0x03U)  /* TIM8/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /* USART2 Alternate Function mapping   */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */
#define GPIO_AF4_I2C4          ((uint8_t)0x04U)  /* I2C4 Alternate Function mapping   */
#define GPIO_AF4_DCMI          ((uint8_t)0x04U)  /* DCMI Alternate Function mapping   */
#define GPIO_AF4_PSSI          ((uint8_t)0x04U)  /* PSSI Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_DCMI          ((uint8_t)0x05U)  /* DCMI Alternate Function mapping     */
#define GPIO_AF5_PSSI          ((uint8_t)0x05U)  /* PSSI Alternate Function mapping     */
#define GPIO_AF5_DFSDM1        ((uint8_t)0x05U)  /* DFSDM1 Alternate Function mapping   */
#define GPIO_AF5_I2C4          ((uint8_t)0x05U)  /* I2C4 Alternate Function mapping     */
#define GPIO_AF5_OCTOSPIM_P1   ((uint8_t)0x05U)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF5_OCTOSPIM_P2   ((uint8_t)0x05U)  /* OctoSPI Manager Port 2 Alternate Function mapping */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping     */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping     */
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping     */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_DFSDM1        ((uint8_t)0x06U)  /* DFSDM1 Alternate Function mapping */
#define GPIO_AF6_I2C3          ((uint8_t)0x06U)  /* I2C3 Alternate Function mapping   */
#define GPIO_AF6_OCTOSPIM_P1   ((uint8_t)0x06U)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF6_OCTOSPIM_P2   ((uint8_t)0x06U)  /* OctoSPI Manager Port 2 Alternate Function mapping */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3 Alternate Function mapping   */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping */
#define GPIO_AF7_SDMMC2        ((uint8_t)0x07U)  /* SDMMC2 Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */
#define GPIO_AF8_SDMMC1        ((uint8_t)0x08U)  /* SDMMC1 Alternate Function mapping  */
#define GPIO_AF8_SDMMC2        ((uint8_t)0x08U)  /* SDMMC1 Alternate Function mapping  */
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  /* UART4 Alternate Function mapping   */
#define GPIO_AF8_UART5         ((uint8_t)0x08U)  /* UART5 Alternate Function mapping   */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_LTDC          ((uint8_t)0x09U)  /* LTDC Alternate Function mapping  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_DCMI         ((uint8_t)0x0AU)  /* DCMI Alternate Function mapping     */
#define GPIO_AF10_PSSI         ((uint8_t)0x0AU)  /* PSSI Alternate Function mapping     */
#define GPIO_AF10_OCTOSPIM_P1  ((uint8_t)0x0AU)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF10_OCTOSPIM_P2  ((uint8_t)0x0AU)  /* OctoSPI Manager Port 2 Alternate Function mapping */
#define GPIO_AF10_OTG_FS       ((uint8_t)0x0AU)  /* OTG_FS Alternate Function mapping   */

/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_LTDC         ((uint8_t)0x0BU)  /* LTDC Alternate Function mapping */
#define GPIO_AF11_SDMMC2       ((uint8_t)0x0BU)  /* SDMMC2 Alternate Function mapping  */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */
#define GPIO_AF12_COMP2        ((uint8_t)0x0CU)  /* COMP2 Alternate Function mapping   */
#define GPIO_AF12_FMC          ((uint8_t)0x0CU)  /* FMC Alternate Function mapping     */
#define GPIO_AF12_SDMMC1       ((uint8_t)0x0CU)  /* SDMMC1 Alternate Function mapping  */
#define GPIO_AF12_SDMMC2       ((uint8_t)0x0CU)  /* SDMMC2 Alternate Function mapping  */
#define GPIO_AF12_TIM1_COMP1   ((uint8_t)0x0CU)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF12_TIM1_COMP2   ((uint8_t)0x0CU)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF12_TIM8_COMP2   ((uint8_t)0x0CU)  /* TIM8/COMP2 Break in Alternate Function mapping  */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_SAI1         ((uint8_t)0x0DU)  /* SAI1 Alternate Function mapping */
#define GPIO_AF13_SAI2         ((uint8_t)0x0DU)  /* SAI2 Alternate Function mapping */
#define GPIO_AF13_TIM8_COMP1   ((uint8_t)0x0DU)  /* TIM8/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping   */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping  */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping  */
#define GPIO_AF14_TIM17        ((uint8_t)0x0EU)  /* TIM17 Alternate Function mapping  */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */
#define GPIO_AF14_TIM8_COMP2   ((uint8_t)0x0EU)  /* TIM8/COMP2 Break in Alternate Function mapping   */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L4P5xx || STM32L4Q5xx */

#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
/*---STM32L4R5xx/STM32L4R7xx/STM32L4R9xx/STM32L4S5xx/STM32L4S7xx/STM32L4S9xx--*/
/**
  * @brief   AF 0 selection
  */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /* RTC_50Hz Alternate Function mapping                       */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /* MCO (MCO1 and MCO2) Alternate Function mapping            */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /* SWJ (SWD and JTAG) Alternate Function mapping             */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /* TRACE Alternate Function mapping                          */

/**
  * @brief   AF 1 selection
  */
#define GPIO_AF1_TIM1          ((uint8_t)0x01U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF1_TIM2          ((uint8_t)0x01U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF1_TIM5          ((uint8_t)0x01U)  /* TIM5 Alternate Function mapping */
#define GPIO_AF1_TIM8          ((uint8_t)0x01U)  /* TIM8 Alternate Function mapping */
#define GPIO_AF1_LPTIM1        ((uint8_t)0x01U)  /* LPTIM1 Alternate Function mapping */
#define GPIO_AF1_IR            ((uint8_t)0x01U)  /* IR Alternate Function mapping   */

/**
  * @brief   AF 2 selection
  */
#define GPIO_AF2_TIM1          ((uint8_t)0x02U)  /* TIM1 Alternate Function mapping */
#define GPIO_AF2_TIM2          ((uint8_t)0x02U)  /* TIM2 Alternate Function mapping */
#define GPIO_AF2_TIM3          ((uint8_t)0x02U)  /* TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4          ((uint8_t)0x02U)  /* TIM4 Alternate Function mapping */
#define GPIO_AF2_TIM5          ((uint8_t)0x02U)  /* TIM5 Alternate Function mapping */

/**
  * @brief   AF 3 selection
  */
#define GPIO_AF3_I2C4          ((uint8_t)0x03U)  /* I2C4 Alternate Function mapping   */
#define GPIO_AF3_OCTOSPIM_P1   ((uint8_t)0x03U)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF3_SAI1          ((uint8_t)0x03U)  /* SAI1 Alternate Function mapping */
#define GPIO_AF3_SPI2          ((uint8_t)0x03U)  /* SPI2 Alternate Function mapping   */
#define GPIO_AF3_TIM1_COMP1    ((uint8_t)0x03U)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM1_COMP2    ((uint8_t)0x03U)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM8          ((uint8_t)0x03U)  /* TIM8 Alternate Function mapping   */
#define GPIO_AF3_TIM8_COMP1    ((uint8_t)0x03U)  /* TIM8/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF3_TIM8_COMP2    ((uint8_t)0x03U)  /* TIM8/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF3_USART2        ((uint8_t)0x03U)  /* USART2 Alternate Function mapping   */

/**
  * @brief   AF 4 selection
  */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /* I2C1 Alternate Function mapping   */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /* I2C2 Alternate Function mapping   */
#define GPIO_AF4_I2C3          ((uint8_t)0x04U)  /* I2C3 Alternate Function mapping   */
#define GPIO_AF4_I2C4          ((uint8_t)0x04U)  /* I2C4 Alternate Function mapping   */
#define GPIO_AF4_DCMI          ((uint8_t)0x04U)  /* DCMI Alternate Function mapping   */

/**
  * @brief   AF 5 selection
  */
#define GPIO_AF5_DCMI          ((uint8_t)0x05U)  /* DCMI Alternate Function mapping     */
#define GPIO_AF5_DFSDM1        ((uint8_t)0x05U)  /* DFSDM1 Alternate Function mapping   */
#define GPIO_AF5_I2C4          ((uint8_t)0x05U)  /* I2C4 Alternate Function mapping     */
#define GPIO_AF5_OCTOSPIM_P1   ((uint8_t)0x05U)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF5_OCTOSPIM_P2   ((uint8_t)0x05U)  /* OctoSPI Manager Port 2 Alternate Function mapping */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /* SPI1 Alternate Function mapping     */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping     */
#define GPIO_AF5_SPI3          ((uint8_t)0x05U)  /* SPI2 Alternate Function mapping     */

/**
  * @brief   AF 6 selection
  */
#define GPIO_AF6_DFSDM1        ((uint8_t)0x06U)  /* DFSDM1 Alternate Function mapping */
#define GPIO_AF6_I2C3          ((uint8_t)0x06U)  /* I2C3 Alternate Function mapping   */
#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /* SPI3 Alternate Function mapping   */

/**
  * @brief   AF 7 selection
  */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /* USART1 Alternate Function mapping */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /* USART2 Alternate Function mapping */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /* USART3 Alternate Function mapping */

/**
  * @brief   AF 8 selection
  */
#define GPIO_AF8_LPUART1       ((uint8_t)0x08U)  /* LPUART1 Alternate Function mapping */
#define GPIO_AF8_SDMMC1        ((uint8_t)0x08U)  /* SDMMC1 Alternate Function mapping  */
#define GPIO_AF8_UART4         ((uint8_t)0x08U)  /* UART4 Alternate Function mapping   */
#define GPIO_AF8_UART5         ((uint8_t)0x08U)  /* UART5 Alternate Function mapping   */

/**
  * @brief   AF 9 selection
  */
#define GPIO_AF9_CAN1          ((uint8_t)0x09U)  /* CAN1 Alternate Function mapping  */
#define GPIO_AF9_LTDC          ((uint8_t)0x09U)  /* LTDC Alternate Function mapping  */
#define GPIO_AF9_TSC           ((uint8_t)0x09U)  /* TSC Alternate Function mapping   */

/**
  * @brief   AF 10 selection
  */
#define GPIO_AF10_DCMI         ((uint8_t)0x0AU)  /* DCMI Alternate Function mapping     */
#define GPIO_AF10_OCTOSPIM_P1  ((uint8_t)0x0AU)  /* OctoSPI Manager Port 1 Alternate Function mapping */
#define GPIO_AF10_OCTOSPIM_P2  ((uint8_t)0x0AU)  /* OctoSPI Manager Port 2 Alternate Function mapping */
#define GPIO_AF10_OTG_FS       ((uint8_t)0x0AU)  /* OTG_FS Alternate Function mapping   */

/**
  * @brief   AF 11 selection
  */
#define GPIO_AF11_DSI          ((uint8_t)0x0BU)  /* DSI Alternate Function mapping  */
#define GPIO_AF11_LTDC         ((uint8_t)0x0BU)  /* LTDC Alternate Function mapping */

/**
  * @brief   AF 12 selection
  */
#define GPIO_AF12_COMP1        ((uint8_t)0x0CU)  /* COMP1 Alternate Function mapping   */
#define GPIO_AF12_COMP2        ((uint8_t)0x0CU)  /* COMP2 Alternate Function mapping   */
#define GPIO_AF12_DSI          ((uint8_t)0x0CU)  /* DSI Alternate Function mapping     */
#define GPIO_AF12_FMC          ((uint8_t)0x0CU)  /* FMC Alternate Function mapping     */
#define GPIO_AF12_SDMMC1       ((uint8_t)0x0CU)  /* SDMMC1 Alternate Function mapping  */
#define GPIO_AF12_TIM1_COMP1   ((uint8_t)0x0CU)  /* TIM1/COMP1 Break in Alternate Function mapping  */
#define GPIO_AF12_TIM1_COMP2   ((uint8_t)0x0CU)  /* TIM1/COMP2 Break in Alternate Function mapping  */
#define GPIO_AF12_TIM8_COMP2   ((uint8_t)0x0CU)  /* TIM8/COMP2 Break in Alternate Function mapping  */

/**
  * @brief   AF 13 selection
  */
#define GPIO_AF13_SAI1         ((uint8_t)0x0DU)  /* SAI1 Alternate Function mapping */
#define GPIO_AF13_SAI2         ((uint8_t)0x0DU)  /* SAI2 Alternate Function mapping */
#define GPIO_AF13_TIM8_COMP1   ((uint8_t)0x0DU)  /* TIM8/COMP1 Break in Alternate Function mapping  */

/**
  * @brief   AF 14 selection
  */
#define GPIO_AF14_TIM2         ((uint8_t)0x0EU)  /* TIM2 Alternate Function mapping   */
#define GPIO_AF14_TIM15        ((uint8_t)0x0EU)  /* TIM15 Alternate Function mapping  */
#define GPIO_AF14_TIM16        ((uint8_t)0x0EU)  /* TIM16 Alternate Function mapping  */
#define GPIO_AF14_TIM17        ((uint8_t)0x0EU)  /* TIM17 Alternate Function mapping  */
#define GPIO_AF14_LPTIM2       ((uint8_t)0x0EU)  /* LPTIM2 Alternate Function mapping */
#define GPIO_AF14_TIM8_COMP2   ((uint8_t)0x0EU)  /* TIM8/COMP2 Break in Alternate Function mapping   */

/**
  * @brief   AF 15 selection
  */
#define GPIO_AF15_EVENTOUT     ((uint8_t)0x0FU)  /* EVENTOUT Alternate Function mapping */

#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)

#endif /* STM32L4R5xx || STM32L4R7xx || STM32L4R9xx || STM32L4S5xx || STM32L4S7xx || STM32L4S9xx */

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

/** @defgroup GPIOEx_Get_Port_Index GPIOEx_Get Port Index
* @{
  */
#if defined(STM32L412xx) || defined(STM32L422xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : 7UL)

#endif /* STM32L412xx || STM32L422xx */

#if defined(STM32L431xx) || defined(STM32L433xx) || defined(STM32L443xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOE)) ? 4UL : 7UL)

#endif /* STM32L431xx || STM32L433xx || STM32L443xx */

#if defined(STM32L432xx) || defined(STM32L442xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : 7UL)

#endif /* STM32L432xx || STM32L442xx */

#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOE)) ? 4UL : 7UL)

#endif /* STM32L451xx || STM32L452xx || STM32L462xx */

#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOE)) ? 4UL : \
                                      ((__GPIOx__) == (GPIOF)) ? 5UL : \
                                      ((__GPIOx__) == (GPIOG)) ? 6UL : 7UL)

#endif /* STM32L471xx || STM32L475xx || STM32L476xx || STM32L485xx || STM32L486xx */

#if defined(STM32L496xx) || defined(STM32L4A6xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOE)) ? 4UL : \
                                      ((__GPIOx__) == (GPIOF)) ? 5UL : \
                                      ((__GPIOx__) == (GPIOG)) ? 6UL : \
                                      ((__GPIOx__) == (GPIOH)) ? 7UL : 8UL)

#endif /* STM32L496xx || STM32L4A6xx */

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)

#define GPIO_GET_INDEX(__GPIOx__)    (((__GPIOx__) == (GPIOA)) ? 0UL : \
                                      ((__GPIOx__) == (GPIOB)) ? 1UL : \
                                      ((__GPIOx__) == (GPIOC)) ? 2UL : \
                                      ((__GPIOx__) == (GPIOD)) ? 3UL : \
                                      ((__GPIOx__) == (GPIOE)) ? 4UL : \
                                      ((__GPIOx__) == (GPIOF)) ? 5UL : \
                                      ((__GPIOx__) == (GPIOG)) ? 6UL : \
                                      ((__GPIOx__) == (GPIOH)) ? 7UL : 8UL)

#endif /* STM32L4P5xx || STM32L4Q5xx || STM32L4R5xx || STM32L4R7xx || STM32L4R9xx || STM32L4S5xx || STM32L4S7xx || STM32L4S9xx */

/**
  * @}
  */

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

#endif /* STM32L4xx_HAL_GPIO_EX_H */

