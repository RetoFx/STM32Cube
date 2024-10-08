/**
  ******************************************************************************
  * @file    stm32l1xx_hal_gpio_ex.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO HAL Extension module.
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
#ifndef __STM32L1xx_HAL_GPIO_EX_H
#define __STM32L1xx_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_hal_def.h"

/** @addtogroup STM32L1xx_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
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

/* AF 0 selection */
#define GPIO_AF0_MCO           ((uint8_t)0x00U)  /*!< MCO Alternate Function mapping                 */
#define GPIO_AF0_TAMPER        ((uint8_t)0x00U)  /*!< TAMPER  Alternate Function mapping             */
#define GPIO_AF0_SWJ           ((uint8_t)0x00U)  /*!< SWJ (SWD and JTAG) Alternate Function mapping  */
#define GPIO_AF0_TRACE         ((uint8_t)0x00U)  /*!< TRACE Alternate Function mapping               */
#define GPIO_AF0_RTC_50Hz      ((uint8_t)0x00U)  /*!< RTC_OUT Alternate Function mapping             */

/* AF 1 selection */
#define GPIO_AF1_TIM2           ((uint8_t)0x01U)  /*!< TIM2 Alternate Function mapping */

/* AF 2 selection */
#define GPIO_AF2_TIM3           ((uint8_t)0x02U)  /*!< TIM3 Alternate Function mapping */
#define GPIO_AF2_TIM4           ((uint8_t)0x02U)  /*!< TIM4 Alternate Function mapping */
#if defined (STM32L151xCA) || defined (STM32L151xD) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L151xE) || defined (STM32L151xDX) || defined (STM32L152xE) || defined (STM32L152xDX) || defined (STM32L162xE) || defined (STM32L162xDX) || defined (STM32L162xC) || defined (STM32L152xC) || defined (STM32L151xC)
#define GPIO_AF2_TIM5           ((uint8_t)0x02U)  /*!< TIM5 Alternate Function mapping */

#endif /*  STM32L151xCA || STM32L151xD || STM32L152xCA || STM32L152xD || STM32L162xCA || STM32L162xD ...STM32L151xC */

/* AF 3 selection */
#define GPIO_AF3_TIM9            ((uint8_t)0x03U)  /*!< TIM9 Alternate Function mapping */
#define GPIO_AF3_TIM10           ((uint8_t)0x03U)  /*!< TIM10 Alternate Function mapping */
#define GPIO_AF3_TIM11           ((uint8_t)0x03U)  /*!< TIM11 Alternate Function mapping */


/* AF 4 selection */
#define GPIO_AF4_I2C1          ((uint8_t)0x04U)  /*!< I2C1 Alternate Function mapping */
#define GPIO_AF4_I2C2          ((uint8_t)0x04U)  /*!< I2C2 Alternate Function mapping */

/* AF 5 selection */
#define GPIO_AF5_SPI1          ((uint8_t)0x05U)  /*!< SPI1/I2S1 Alternate Function mapping      */
#define GPIO_AF5_SPI2          ((uint8_t)0x05U)  /*!< SPI2/I2S2 Alternate Function mapping */

/* AF 6 selection */
#if defined (STM32L100xC) || defined (STM32L151xC) || defined (STM32L151xCA) || defined (STM32L151xD) || defined (STM32L151xE) || defined (STM32L151xDX) || \
    defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xE) || defined (STM32L152xDX) || \
    defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L162xE) || defined (STM32L162xDX)

#define GPIO_AF6_SPI3          ((uint8_t)0x06U)  /*!< SPI3/I2S3 Alternate Function mapping */

#endif /* STM32L100xC || STM32L151xC || (...) || STM32L162xD || STM32L162xE || STM32L162xDX */


/* AF 7 selection */
#define GPIO_AF7_USART1        ((uint8_t)0x07U)  /*!< USART1 Alternate Function mapping  */
#define GPIO_AF7_USART2        ((uint8_t)0x07U)  /*!< USART2 Alternate Function mapping  */
#define GPIO_AF7_USART3        ((uint8_t)0x07U)  /*!< USART3 Alternate Function mapping  */

/* AF 8 selection */
#if defined (STM32L151xD) || defined (STM32L151xE) || defined (STM32L151xDX) || \
    defined (STM32L152xD) || defined (STM32L152xE) || defined (STM32L152xDX) || \
    defined (STM32L162xD) || defined (STM32L162xE) || defined (STM32L162xDX)

#define GPIO_AF8_UART4        ((uint8_t)0x08U)  /*!< UART4 Alternate Function mapping  */
#define GPIO_AF8_UART5        ((uint8_t)0x08U)  /*!< UART5 Alternate Function mapping  */

#endif /* STM32L151xD || STM32L151xE || STM32L151xDX || STM32L152xD || STM32L 152xE || STM32L162xD || STM32L162xE || STM32L162xDX */


/* AF 9 selection */

/* AF 10 selection */

/* AF 11 selection */
#if defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC) || \
    defined (STM32L152xB) || defined (STM32L152xBA) || defined (STM32L152xC) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L152xE) || defined (STM32L152xDX) || \
    defined (STM32L162xC) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L162xE) || defined (STM32L162xDX)

#define GPIO_AF11_LCD            ((uint8_t)0x0BU)  /*!< LCD Alternate Function mapping */

#endif /* STM32L100xB || STM32L100xBA || STM32L100xC || (...) || STM32L162xCA || STM32L162xD || STM32L162xE || STM32L162xDX */

/* AF 12 selection */
#if defined (STM32L151xD) || defined (STM32L152xD) || defined (STM32L162xD)

#define GPIO_AF12_FSMC            ((uint8_t)0x0CU)  /*!< FSMC Alternate Function mapping */
#define GPIO_AF12_SDIO            ((uint8_t)0x0CU)  /*!< SDIO Alternate Function mapping */

#endif /* STM32L151xD || STM32L152xD || STM32L162xD */
/* AF 13 selection */

/* AF 14 selection */
#define GPIO_AF14_TIM_IC1         ((uint8_t)0x0EU)  /*!< TIMER INPUT CAPTURE Alternate Function mapping */
#define GPIO_AF14_TIM_IC2         ((uint8_t)0x0EU)  /*!< TIMER INPUT CAPTURE Alternate Function mapping */
#define GPIO_AF14_TIM_IC3         ((uint8_t)0x0EU)  /*!< TIMER INPUT CAPTURE Alternate Function mapping */
#define GPIO_AF14_TIM_IC4         ((uint8_t)0x0EU)  /*!< TIMER INPUT CAPTURE Alternate Function mapping */

/* AF 15 selection */
#define GPIO_AF15_EVENTOUT      ((uint8_t)0x0FU)  /*!< EVENTOUT Alternate Function mapping */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIOEx_Private_Macros GPIOEx Private Macros
  * @{
  */


#define IS_GPIO_AF(AF)   ((AF) <= (uint8_t)0x0FU)


#if defined (STM32L151xCA) || defined (STM32L151xD) || defined (STM32L152xCA) || defined (STM32L152xD) || defined (STM32L162xCA) || defined (STM32L162xD) || defined (STM32L151xE) || defined (STM32L151xDX) || defined (STM32L152xE) || defined (STM32L152xDX) || defined (STM32L162xE) || defined (STM32L162xDX)
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA)) ? 0U : \
                                   ((__GPIOx__) == (GPIOB)) ? 1U : \
                                   ((__GPIOx__) == (GPIOC)) ? 2U : \
                                   ((__GPIOx__) == (GPIOD)) ? 3U : \
                                   ((__GPIOx__) == (GPIOE)) ? 4U : \
                                   ((__GPIOx__) == (GPIOH)) ? 5U : \
                                   ((__GPIOx__) == (GPIOF)) ? 6U : 7U)
#endif

#if defined (STM32L151xB) || defined (STM32L151xBA) || defined (STM32L151xC) || defined (STM32L152xB) || defined (STM32L152xBA) || defined (STM32L152xC) || defined (STM32L162xC)
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA)) ? 0U : \
                                   ((__GPIOx__) == (GPIOB)) ? 1U : \
                                   ((__GPIOx__) == (GPIOC)) ? 2U : \
                                   ((__GPIOx__) == (GPIOD)) ? 3U : \
                                   ((__GPIOx__) == (GPIOE)) ? 4U : 5U)
#endif

#if defined (STM32L100xB) || defined (STM32L100xBA) || defined (STM32L100xC)
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA)) ? 0U : \
                                   ((__GPIOx__) == (GPIOB)) ? 1U : \
                                   ((__GPIOx__) == (GPIOC)) ? 2U : \
                                   ((__GPIOx__) == (GPIOD)) ? 3U : 5U)
#endif



/**
  * @}
  */



/* Exported macro ------------------------------------------------------------*/
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

#endif /* __STM32L1xx_HAL_GPIO_EX_H */

