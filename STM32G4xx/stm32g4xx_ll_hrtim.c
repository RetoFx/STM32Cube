/**
  ******************************************************************************
  * @file    stm32g4xx_ll_hrtim.c
  * @author  MCD Application Team
  * @brief   HRTIM LL module driver.
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
#include "stm32xxxx_ll.h"

/*lint -save -w1*/
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_ll_hrtim.h"
#include "stm32g4xx_ll_bus.h"

#if !defined(assert_param)
 #if defined(USE_FULL_ASSERT)
  #include "stm32_assert.h"
 #else
  #define assert_param(expr) ((void)0UL)
 #endif
#endif

/** @addtogroup STM32G4xx_LL_Driver
  * @{
  */

#if defined (HRTIM1)

/** @addtogroup HRTIM_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup HRTIM_LL_Exported_Functions
  * @{
  */
/**
  * @brief  Set HRTIM instance registers to their reset values.
  * @param  HRTIMx High Resolution Timer instance
  * @retval ErrorStatus enumeration value:
  *          - SUCCESS: HRTIMx registers are de-initialized
  *          - ERROR: invalid HRTIMx instance
  */
ErrorStatus LL_HRTIM_DeInit(HRTIM_TypeDef const * const HRTIMx)
{
  ErrorStatus result = SUCCESS;

  /* Check the parameters */
  assert_param(IS_HRTIM_ALL_INSTANCE(HRTIMx));
  LL_APB2_GRP1_ForceReset(LL_APB2_GRP1_PERIPH_HRTIM1);
  LL_APB2_GRP1_ReleaseReset(LL_APB2_GRP1_PERIPH_HRTIM1);
  return result;
}
/**
  * @}
  */

/**
  * @}
  */

#endif /* HRTIM1 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/*lint -restore*/
