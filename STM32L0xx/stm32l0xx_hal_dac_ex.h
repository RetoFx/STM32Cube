/**
  ******************************************************************************
  * @file    stm32l0xx_hal_dac_ex.h
  * @author  MCD Application Team
  * @brief   Header file of DAC HAL Extension module.
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
#ifndef __STM32L0xx_HAL_DAC_EX_H
#define __STM32L0xx_HAL_DAC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

#if !defined(STM32L010xB) && !defined (STM32L010x8) && !defined (STM32L010x6) && !defined (STM32L010x4) && !defined (STM32L011xx) && !defined (STM32L021xx) && !defined (STM32L031xx) && !defined (STM32L041xx) && !defined (STM32L051xx) && !defined (STM32L071xx) && !defined (STM32L081xx)

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal_def.h"

/** @addtogroup STM32L0xx_HAL_Driver
  * @{
  */

/** @defgroup DACEx DACEx
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/** @defgroup DACEx_Exported_Constants DACEx Exported Constants
  * @{
  */

/** @defgroup DACEx_lfsrunmask_triangleamplitude DACEx lfsrunmask triangleamplitude
  * @{
  */
#define DAC_LFSRUNMASK_BIT0                (0x00000000UL) /*!< Unmask DAC channel LFSR bit0 for noise wave generation */
#define DAC_LFSRUNMASK_BITS1_0             (DAC_CR_MAMP1_0) /*!< Unmask DAC channel LFSR bit[1:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS2_0             (DAC_CR_MAMP1_1) /*!< Unmask DAC channel LFSR bit[2:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS3_0             ((uint32_t)DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)/*!< Unmask DAC channel LFSR bit[3:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS4_0             (DAC_CR_MAMP1_2) /*!< Unmask DAC channel LFSR bit[4:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS5_0             ((uint32_t)DAC_CR_MAMP1_2 | DAC_CR_MAMP1_0) /*!< Unmask DAC channel LFSR bit[5:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS6_0             ((uint32_t)DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1) /*!< Unmask DAC channel LFSR bit[6:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS7_0             ((uint32_t)DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0) /*!< Unmask DAC channel LFSR bit[7:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS8_0             (DAC_CR_MAMP1_3) /*!< Unmask DAC channel LFSR bit[8:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS9_0             ((uint32_t)DAC_CR_MAMP1_3 | DAC_CR_MAMP1_0) /*!< Unmask DAC channel LFSR bit[9:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS10_0            ((uint32_t)DAC_CR_MAMP1_3 | DAC_CR_MAMP1_1) /*!< Unmask DAC channel LFSR bit[10:0] for noise wave generation */
#define DAC_LFSRUNMASK_BITS11_0            ((uint32_t)DAC_CR_MAMP1_3 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0) /*!< Unmask DAC channel LFSR bit[11:0] for noise wave generation */
#define DAC_TRIANGLEAMPLITUDE_1            (0x00000000UL) /*!< Select max triangle amplitude of 1 */
#define DAC_TRIANGLEAMPLITUDE_3            (DAC_CR_MAMP1_0) /*!< Select max triangle amplitude of 3 */
#define DAC_TRIANGLEAMPLITUDE_7            (DAC_CR_MAMP1_1) /*!< Select max triangle amplitude of 7 */
#define DAC_TRIANGLEAMPLITUDE_15           ((uint32_t)DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0) /*!< Select max triangle amplitude of 15 */
#define DAC_TRIANGLEAMPLITUDE_31           (DAC_CR_MAMP1_2) /*!< Select max triangle amplitude of 31 */
#define DAC_TRIANGLEAMPLITUDE_63           ((uint32_t)DAC_CR_MAMP1_2 | DAC_CR_MAMP1_0) /*!< Select max triangle amplitude of 63 */
#define DAC_TRIANGLEAMPLITUDE_127          ((uint32_t)DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1) /*!< Select max triangle amplitude of 127 */
#define DAC_TRIANGLEAMPLITUDE_255          ((uint32_t)DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0) /*!< Select max triangle amplitude of 255U */
#define DAC_TRIANGLEAMPLITUDE_511          (DAC_CR_MAMP1_3) /*!< Select max triangle amplitude of 511 */
#define DAC_TRIANGLEAMPLITUDE_1023         ((uint32_t)DAC_CR_MAMP1_3 | DAC_CR_MAMP1_0) /*!< Select max triangle amplitude of 1023 */
#define DAC_TRIANGLEAMPLITUDE_2047         ((uint32_t)DAC_CR_MAMP1_3 | DAC_CR_MAMP1_1) /*!< Select max triangle amplitude of 2047 */
#define DAC_TRIANGLEAMPLITUDE_4095         ((uint32_t)DAC_CR_MAMP1_3 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0) /*!< Select max triangle amplitude of 4095 */

#define IS_DAC_LFSR_UNMASK_TRIANGLE_AMPLITUDE(VALUE) (((VALUE) == DAC_LFSRUNMASK_BIT0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS1_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS2_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS3_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS4_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS5_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS6_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS7_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS8_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS9_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS10_0) || \
                                                      ((VALUE) == DAC_LFSRUNMASK_BITS11_0) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_1) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_3) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_7) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_15) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_31) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_63) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_127) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_255) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_511) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_1023) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_2047) || \
                                                      ((VALUE) == DAC_TRIANGLEAMPLITUDE_4095))
/**
  * @}
  */


/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @defgroup DACEx_Exported_Functions DACEx Exported Functions
  * @{
  */

/** @defgroup DACEx_Exported_Functions_Group1  Extended features functions
  * @{
  */
/* Extension features functions ***********************************************/
HAL_StatusTypeDef HAL_DACEx_TriangleWaveGenerate(DAC_HandleTypeDef * const hdac, uint32_t Channel, uint32_t Amplitude);
HAL_StatusTypeDef HAL_DACEx_NoiseWaveGenerate(DAC_HandleTypeDef * const hdac, uint32_t Channel, uint32_t Amplitude);

#if defined (DAC_CHANNEL2_SUPPORT)
uint32_t HAL_DACEx_DualGetValue(DAC_HandleTypeDef const * const hdac);
HAL_StatusTypeDef HAL_DACEx_DualSetValue(DAC_HandleTypeDef * const hdac, uint32_t Alignment, uint32_t Data1, uint32_t Data2);
void HAL_DACEx_ConvCpltCallbackCh2(DAC_HandleTypeDef * const hdac);
void HAL_DACEx_ConvHalfCpltCallbackCh2(DAC_HandleTypeDef * const hdac);
void HAL_DACEx_ErrorCallbackCh2(DAC_HandleTypeDef * const hdac);
void HAL_DACEx_DMAUnderrunCallbackCh2(DAC_HandleTypeDef * const hdac);
#endif

/**
  * @}
  */

/**
  * @}
  */
/* Define the private group ***********************************/
/**************************************************************/
/** @defgroup DACEx_Private DACEx Private
  * @{
  */
/**
  * @}
  */
/**************************************************************/

/**
  * @}
  */

/**
  * @}
  */
#endif /* !STM32L010xB && !STM32L010x8 && !STM32L010x6 && !STM32L010x4 && !STM32L011xx && !STM32L021xx && !STM32L031xx && !STM32L041xx && !STM32L051xx && !STM32L071xx && !STM32L081xx*/

#ifdef __cplusplus
}
#endif

#endif /*__STM32L0xx_HAL_DAC_EX_H */


