/**
  ******************************************************************************
  * @file    stm32f3xx_hal_adc.h
  * @author  MCD Application Team
  * @brief   Header file containing functions prototypes of ADC HAL library.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F3xx_ADC_H
#define __STM32F3xx_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal_def.h"

/* Include ADC HAL Extended module */
/* (include on top of file since ADC structures are defined in extended file) */
#include "stm32f3xx_hal_adc_ex.h"

/** @addtogroup STM32F3xx_HAL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Types ADC Exported Types
  * @{
  */
/**
  * @brief  HAL ADC state machine: ADC states definition (bitfields)
  * @note   ADC state machine is managed by bitfields, state must be compared
  *         with bit by bit.
  *         For example:
  *           " if (HAL_IS_BIT_SET(HAL_ADC_GetState(hadc1), HAL_ADC_STATE_REG_BUSY)) "
  *           " if (HAL_IS_BIT_SET(HAL_ADC_GetState(hadc1), HAL_ADC_STATE_AWD1)    ) "
  */
/* States of ADC global scope */
#define HAL_ADC_STATE_RESET             (0x00000000UL)    /*!< ADC not yet initialized or disabled */
#define HAL_ADC_STATE_READY             (0x00000001UL)    /*!< ADC peripheral ready for use */
#define HAL_ADC_STATE_BUSY_INTERNAL     (0x00000002UL)    /*!< ADC is busy to internal process (initialization, calibration) */
#define HAL_ADC_STATE_TIMEOUT           (0x00000004UL)    /*!< TimeOut occurrence */

/* States of ADC errors */
#define HAL_ADC_STATE_ERROR_INTERNAL    (0x00000010UL)    /*!< Internal error occurrence */
#define HAL_ADC_STATE_ERROR_CONFIG      (0x00000020UL)    /*!< Configuration error occurrence */
#define HAL_ADC_STATE_ERROR_DMA         (0x00000040UL)    /*!< DMA error occurrence */

/* States of ADC group regular */
#define HAL_ADC_STATE_REG_BUSY          (0x00000100UL)    /*!< A conversion on group regular is ongoing or can occur (either by continuous mode,
                                                                       external trigger, low power auto power-on, multimode ADC master control) */
#define HAL_ADC_STATE_REG_EOC           (0x00000200UL)    /*!< Conversion data available on group regular */
#define HAL_ADC_STATE_REG_OVR           (0x00000400UL)    /*!< Overrun occurrence */
#define HAL_ADC_STATE_REG_EOSMP         (0x00000800UL)    /*!< End Of Sampling flag raised  */

/* States of ADC group injected */
#define HAL_ADC_STATE_INJ_BUSY          (0x00001000UL)    /*!< A conversion on group injected is ongoing or can occur (either by auto-injection mode,
                                                                       external trigger, low power auto power-on, multimode ADC master control) */
#define HAL_ADC_STATE_INJ_EOC           (0x00002000UL)    /*!< Conversion data available on group injected */
#define HAL_ADC_STATE_INJ_JQOVF         (0x00004000UL)    /*!< Injected queue overflow occurrence */

/* States of ADC analog watchdogs */
#define HAL_ADC_STATE_AWD1              (0x00010000UL)    /*!< Out-of-window occurrence of analog watchdog 1 */
#define HAL_ADC_STATE_AWD2              (0x00020000UL)    /*!< Out-of-window occurrence of analog watchdog 2 */
#define HAL_ADC_STATE_AWD3              (0x00040000UL)    /*!< Out-of-window occurrence of analog watchdog 3 */

/* States of ADC multi-mode */
#define HAL_ADC_STATE_MULTIMODE_SLAVE   (0x00100000UL)    /*!< ADC in multimode slave state, controlled by another ADC master ( */


/**
  * @brief  ADC handle Structure definition
  */
typedef struct __ADC_HandleTypeDef
{
  ADC_TypeDef                   *Instance;              /*!< Register base address */

  ADC_InitTypeDef               Init;                   /*!< ADC required parameters */

  DMA_HandleTypeDef             *DMA_Handle;            /*!< Pointer DMA Handler */

  HAL_LockTypeDef               Lock;                   /*!< ADC locking object */

  __IO uint32_t                 State;                  /*!< ADC communication state (bitmap of ADC states) */

  __IO uint32_t                 ErrorCode;              /*!< ADC Error code */

#if defined(STM32F302xE) || defined(STM32F303xE) || defined(STM32F398xx) || \
    defined(STM32F302xC) || defined(STM32F303xC) || defined(STM32F358xx) || \
    defined(STM32F303x8) || defined(STM32F334x8) || defined(STM32F328xx) || \
    defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx)
  ADC_InjectionConfigTypeDef    InjectionConfig ;       /*!< ADC injected channel configuration build-up structure */
#endif /* STM32F302xE || STM32F303xE || STM32F398xx || */
       /* STM32F302xC || STM32F303xC || STM32F358xx || */
       /* STM32F303x8 || STM32F334x8 || STM32F328xx || */
       /* STM32F301x8 || STM32F302x8 || STM32F318xx    */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1U)
  void (* ConvCpltCallback)(struct __ADC_HandleTypeDef * const hadc);              /*!< ADC conversion complete callback */
  void (* ConvHalfCpltCallback)(struct __ADC_HandleTypeDef * const hadc);          /*!< ADC conversion DMA half-transfer callback */
  void (* LevelOutOfWindowCallback)(struct __ADC_HandleTypeDef * const hadc);      /*!< ADC analog watchdog 1 callback */
  void (* ErrorCallback)(struct __ADC_HandleTypeDef * const hadc);                 /*!< ADC error callback */
  void (* InjectedConvCpltCallback)(struct __ADC_HandleTypeDef * const hadc);      /*!< ADC group injected conversion complete callback */       /*!< ADC end of sampling callback */
  void (* MspInitCallback)(struct __ADC_HandleTypeDef * const hadc);               /*!< ADC Msp Init callback */
  void (* MspDeInitCallback)(struct __ADC_HandleTypeDef * const hadc);             /*!< ADC Msp DeInit callback */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}ADC_HandleTypeDef;

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1U)
/**
  * @brief  HAL ADC Callback ID enumeration definition
  */
typedef enum
{
  HAL_ADC_CONVERSION_COMPLETE_CB_ID     = 0x00U,  /*!< ADC conversion complete callback ID */
  HAL_ADC_CONVERSION_HALF_CB_ID         = 0x01U,  /*!< ADC conversion DMA half-transfer callback ID */
  HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID   = 0x02U,  /*!< ADC analog watchdog 1 callback ID */
  HAL_ADC_ERROR_CB_ID                   = 0x03U,  /*!< ADC error callback ID */
  HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID = 0x04U,  /*!< ADC group injected conversion complete callback ID */
  HAL_ADC_MSPINIT_CB_ID                 = 0x09U,  /*!< ADC Msp Init callback ID          */
  HAL_ADC_MSPDEINIT_CB_ID               = 0x0AU   /*!< ADC Msp DeInit callback ID        */
} HAL_ADC_CallbackIDTypeDef;

/**
  * @brief  HAL ADC Callback pointer definition
  */
typedef  void (*pADC_CallbackTypeDef)(ADC_HandleTypeDef * const hadc); /*!< pointer to a ADC callback function */

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/

/** @defgroup ADC_Exported_Macro ADC Exported Macros
  * @{
  */
/** @brief  Reset ADC handle state
  * @param  __HANDLE__ ADC handle
  * @retval None
  */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1U)
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  do{                                                                          \
     (__HANDLE__)->State = HAL_ADC_STATE_RESET;                                \
     (__HANDLE__)->MspInitCallback = NULL;                                     \
     (__HANDLE__)->MspDeInitCallback = NULL;                                   \
    } while(0U)
#else
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET)
#endif

/**
  * @}
  */



/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1 Initialization and de-initialization functions
 * @{
 */
/* Initialization and de-initialization functions  **********************************/
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef * const hadc);
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef * const hadc);
void                    HAL_ADC_MspInit(ADC_HandleTypeDef * const hadc);
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef * const hadc);

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1U)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef * const hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef * const hadc, HAL_ADC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group2 Input and Output operation functions
 * @{
 */
/* Blocking mode: Polling */
HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef * const hadc);
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef * const hadc);
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef * const hadc, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_PollForEvent(ADC_HandleTypeDef * const hadc, uint32_t EventType, uint32_t Timeout);

/* Non-blocking mode: Interruption */
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef * const hadc);
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef * const hadc);

/* Non-blocking mode: DMA */
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef * const hadc, uint32_t * const pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef * const hadc);

/* ADC retrieve conversion value intended to be used with polling or interruption */
uint32_t                HAL_ADC_GetValue(ADC_HandleTypeDef const * const hadc);

/* ADC IRQHandler and Callbacks used in non-blocking modes (Interruption and DMA) */
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef * const hadc);
void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef * const hadc);
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef * const hadc);
void                    HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef * const hadc);
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef * const hadc);
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group3 Peripheral Control functions
 * @{
 */
/* Peripheral Control functions ***********************************************/
HAL_StatusTypeDef       HAL_ADC_ConfigChannel(ADC_HandleTypeDef * const hadc, ADC_ChannelConfTypeDef const * const sConfig);
HAL_StatusTypeDef       HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef * const hadc, ADC_AnalogWDGConfTypeDef const * const AnalogWDGConfig);
/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group4 Peripheral State functions
 *  @brief   ADC Peripheral State functions
 * @{
 */
/* Peripheral State functions *************************************************/
uint32_t                HAL_ADC_GetState(ADC_HandleTypeDef const * const hadc);
uint32_t                HAL_ADC_GetError(ADC_HandleTypeDef const * const hadc);
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

#endif /*__STM32F3xx_ADC_H */

