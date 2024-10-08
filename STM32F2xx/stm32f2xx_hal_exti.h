/**
  ******************************************************************************
  * @file    stm32f2xx_hal_exti.h
  * @author  MCD Application Team
  * @brief   Header file of EXTI HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32F2xx_HAL_EXTI_H
#define STM32F2xx_HAL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal_def.h"

/** @addtogroup STM32F2xx_HAL_Driver
  * @{
  */

/** @defgroup EXTI EXTI
  * @brief EXTI HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup EXTI_Exported_Types EXTI Exported Types
  * @{
  */

/**
  * @brief  HAL EXTI common Callback ID enumeration definition
  */
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U
} EXTI_CallbackIDTypeDef;

/**
  * @brief  EXTI Handle structure definition
  */
typedef struct
{
  uint32_t Line;                    /*!<  Exti line number */
  void (* PendingCallback)(void);   /*!<  Exti pending callback */
} EXTI_HandleTypeDef;

/**
  * @brief  EXTI Configuration structure definition
  */
typedef struct
{
  uint32_t Line;      /*!< The Exti line to be configured. This parameter
                           can be a value of @ref EXTI_Line */
  uint32_t Mode;      /*!< The Exit Mode to be configured for a core.
                           This parameter can be a combination of @ref EXTI_Mode */
  uint32_t Trigger;   /*!< The Exti Trigger to be configured. This parameter
                           can be a value of @ref EXTI_Trigger */
  uint32_t GPIOSel;   /*!< The Exti GPIO multiplexer selection to be configured.
                           This parameter is only possible for line 0 to 15. It
                           can be a value of @ref EXTI_GPIOSel */
} EXTI_ConfigTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup EXTI_Exported_Constants EXTI Exported Constants
  * @{
  */

/** @defgroup EXTI_Line  EXTI Line
  * @{
  */
#define EXTI_LINE_0                        (EXTI_GPIO     | 0x00U)    /*!< External interrupt line 0 */
#define EXTI_LINE_1                        (EXTI_GPIO     | 0x01U)    /*!< External interrupt line 1 */
#define EXTI_LINE_2                        (EXTI_GPIO     | 0x02U)    /*!< External interrupt line 2 */
#define EXTI_LINE_3                        (EXTI_GPIO     | 0x03U)    /*!< External interrupt line 3 */
#define EXTI_LINE_4                        (EXTI_GPIO     | 0x04U)    /*!< External interrupt line 4 */
#define EXTI_LINE_5                        (EXTI_GPIO     | 0x05U)    /*!< External interrupt line 5 */
#define EXTI_LINE_6                        (EXTI_GPIO     | 0x06U)    /*!< External interrupt line 6 */
#define EXTI_LINE_7                        (EXTI_GPIO     | 0x07U)    /*!< External interrupt line 7 */
#define EXTI_LINE_8                        (EXTI_GPIO     | 0x08U)    /*!< External interrupt line 8 */
#define EXTI_LINE_9                        (EXTI_GPIO     | 0x09U)    /*!< External interrupt line 9 */
#define EXTI_LINE_10                       (EXTI_GPIO     | 0x0AU)    /*!< External interrupt line 10 */
#define EXTI_LINE_11                       (EXTI_GPIO     | 0x0BU)    /*!< External interrupt line 11 */
#define EXTI_LINE_12                       (EXTI_GPIO     | 0x0CU)    /*!< External interrupt line 12 */
#define EXTI_LINE_13                       (EXTI_GPIO     | 0x0DU)    /*!< External interrupt line 13 */
#define EXTI_LINE_14                       (EXTI_GPIO     | 0x0EU)    /*!< External interrupt line 14 */
#define EXTI_LINE_15                       (EXTI_GPIO     | 0x0FU)    /*!< External interrupt line 15 */
#define EXTI_LINE_16                       (EXTI_CONFIG   | 0x10U)    /*!< External interrupt line 16 Connected to the PVD Output */
#define EXTI_LINE_17                       (EXTI_CONFIG   | 0x11U)    /*!< External interrupt line 17 Connected to the RTC Alarm event */
#define EXTI_LINE_18                       (EXTI_CONFIG   | 0x12U)    /*!< External interrupt line 18 Connected to the USB OTG FS Wakeup from suspend event */
#define EXTI_LINE_19                       (EXTI_CONFIG   | 0x13U)    /*!< External interrupt line 19 Connected to the Ethernet Wakeup event */
#define EXTI_LINE_20                       (EXTI_CONFIG   | 0x14U)    /*!< External interrupt line 20 Connected to the USB OTG HS (configured in FS) Wakeup event  */
#define EXTI_LINE_21                       (EXTI_CONFIG   | 0x15U)    /*!< External interrupt line 21 Connected to the RTC Tamper and Time Stamp events */
#define EXTI_LINE_22                       (EXTI_CONFIG   | 0x16U)    /*!< External interrupt line 22 Connected to the RTC Wakeup event */

/**
  * @}
  */

/** @defgroup EXTI_Mode  EXTI Mode
  * @{
  */
#define EXTI_MODE_NONE                      0x00000000UL
#define EXTI_MODE_INTERRUPT                 0x00000001UL
#define EXTI_MODE_EVENT                     0x00000002UL
/**
  * @}
  */

/** @defgroup EXTI_Trigger  EXTI Trigger
  * @{
  */
#define EXTI_TRIGGER_NONE                   0x00000000UL
#define EXTI_TRIGGER_RISING                 0x00000001UL
#define EXTI_TRIGGER_FALLING                0x00000002UL
#define EXTI_TRIGGER_RISING_FALLING         (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)
/**
  * @}
  */

/** @defgroup EXTI_GPIOSel  EXTI GPIOSel
  * @brief
  * @{
  */
#define EXTI_GPIOA                          0x00000000UL
#define EXTI_GPIOB                          0x00000001UL
#define EXTI_GPIOC                          0x00000002UL
#define EXTI_GPIOD                          0x00000003UL
#define EXTI_GPIOE                          0x00000004UL
#define EXTI_GPIOF                          0x00000005UL
#define EXTI_GPIOG                          0x00000006UL
#define EXTI_GPIOH                          0x00000007UL
#define EXTI_GPIOI                          0x00000008UL
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup EXTI_Exported_Macros EXTI Exported Macros
  * @{
  */

/**
  * @}
  */

/* Private constants --------------------------------------------------------*/
/** @defgroup EXTI_Private_Constants EXTI Private Constants
  * @{
  */
/**
  * @brief  EXTI Line property definition
  */
#define EXTI_PROPERTY_SHIFT                 24U
#define EXTI_CONFIG                         (0x02UL << EXTI_PROPERTY_SHIFT)
#define EXTI_GPIO                           ((0x04UL << EXTI_PROPERTY_SHIFT) | EXTI_CONFIG)
#define EXTI_PROPERTY_MASK                  (EXTI_CONFIG | EXTI_GPIO)

/**
  * @brief  EXTI bit usage
  */
#define EXTI_PIN_MASK                       0x0000001FUL

/**
  * @brief  EXTI Mask for interrupt & event mode
  */
#define EXTI_MODE_MASK                      (EXTI_MODE_EVENT | EXTI_MODE_INTERRUPT)

/**
  * @brief  EXTI Mask for trigger possibilities
  */
#define EXTI_TRIGGER_MASK                   (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)

/**
  * @brief  EXTI Line number
  */
#define EXTI_LINE_NB                        23UL

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup EXTI_Private_Macros EXTI Private Macros
  * @{
  */
#define IS_EXTI_LINE(__EXTI_LINE__)          ((((__EXTI_LINE__) & ~(EXTI_PROPERTY_MASK | EXTI_PIN_MASK)) == 0x00U) && \
                                             ((((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_CONFIG)   || \
                                              (((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_GPIO))    && \
                                              (((__EXTI_LINE__) & EXTI_PIN_MASK) < EXTI_LINE_NB))

#define IS_EXTI_MODE(__EXTI_LINE__)          ((((__EXTI_LINE__) & EXTI_MODE_MASK) != 0x00U) && \
                                              (((__EXTI_LINE__) & ~EXTI_MODE_MASK) == 0x00U))

#define IS_EXTI_TRIGGER(__EXTI_LINE__)       (((__EXTI_LINE__) & ~EXTI_TRIGGER_MASK) == 0x00U)

#define IS_EXTI_PENDING_EDGE(__EXTI_LINE__)  ((__EXTI_LINE__) == EXTI_TRIGGER_RISING_FALLING)

#define IS_EXTI_CONFIG_LINE(__EXTI_LINE__)   (((__EXTI_LINE__) & EXTI_CONFIG) != 0x00U)

#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF) || \
                                         ((__PORT__) == EXTI_GPIOG) || \
                                         ((__PORT__) == EXTI_GPIOH) || \
                                         ((__PORT__) == EXTI_GPIOI))

#define IS_EXTI_GPIO_PIN(__PIN__)       ((__PIN__) < 16U)

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup EXTI_Exported_Functions EXTI Exported Functions
  * @brief    EXTI Exported Functions
  * @{
  */

/** @defgroup EXTI_Exported_Functions_Group1 Configuration functions
  * @brief    Configuration functions
  * @{
  */
/* Configuration functions ****************************************************/
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef * const hexti, EXTI_ConfigTypeDef * const pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef * const hexti, EXTI_ConfigTypeDef * const pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef * const hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef * const hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef * const hexti, uint32_t ExtiLine);
/**
  * @}
  */

/** @defgroup EXTI_Exported_Functions_Group2 IO operation functions
  * @brief    IO operation functions
  * @{
  */
/* IO operation functions *****************************************************/
void              HAL_EXTI_IRQHandler(EXTI_HandleTypeDef * const hexti);
uint32_t          HAL_EXTI_GetPending(EXTI_HandleTypeDef const * const hexti, uint32_t Edge);
void              HAL_EXTI_ClearPending(EXTI_HandleTypeDef * const hexti, uint32_t Edge);
void              HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef * const hexti);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F2xx_HAL_EXTI_H */

