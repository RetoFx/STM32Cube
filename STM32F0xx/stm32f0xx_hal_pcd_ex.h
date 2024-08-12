/**
  ******************************************************************************
  * @file    stm32f0xx_hal_pcd_ex.h
  * @author  MCD Application Team
  * @brief   Header file of PCD HAL Extension module.
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
#ifndef STM32F0xx_HAL_PCD_EX_H
#define STM32F0xx_HAL_PCD_EX_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal_def.h"

#if defined (USB)
/** @addtogroup STM32F0xx_HAL_Driver
  * @{
  */

/** @addtogroup PCDEx
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup PCDEx_Exported_Functions PCDEx Exported Functions
  * @{
  */
/** @addtogroup PCDEx_Exported_Functions_Group1 Peripheral Control functions
  * @{
  */



HAL_StatusTypeDef  HAL_PCDEx_PMAConfig(PCD_HandleTypeDef * const hpcd, uint16_t ep_addr,
                                       uint16_t ep_kind, uint32_t pmaadress);


HAL_StatusTypeDef HAL_PCDEx_ActivateLPM(PCD_HandleTypeDef * const hpcd);
HAL_StatusTypeDef HAL_PCDEx_DeActivateLPM(PCD_HandleTypeDef * const hpcd);


HAL_StatusTypeDef HAL_PCDEx_ActivateBCD(PCD_HandleTypeDef * const hpcd);
HAL_StatusTypeDef HAL_PCDEx_DeActivateBCD(PCD_HandleTypeDef * const hpcd);
void HAL_PCDEx_BCD_VBUSDetect(PCD_HandleTypeDef * const hpcd);

void HAL_PCDEx_LPM_Callback(PCD_HandleTypeDef * const hpcd, PCD_LPM_MsgTypeDef msg);
void HAL_PCDEx_BCD_Callback(PCD_HandleTypeDef * const hpcd, PCD_BCD_MsgTypeDef msg);

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
#endif /* defined (USB) */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* STM32F0xx_HAL_PCD_EX_H */
