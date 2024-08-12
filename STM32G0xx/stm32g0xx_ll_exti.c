/**
  ******************************************************************************
  * @file    stm32g0xx_ll_exti.c
  * @author  MCD Application Team
  * @brief   EXTI LL module driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
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
#include "stm32g0xx_ll_exti.h"
#if !defined(assert_param)
 #if defined(USE_FULL_ASSERT)
  #include "stm32_assert.h"
 #else
  #define assert_param(expr) ((void)0UL)
 #endif
#endif /* USE_FULL_ASSERT */

/** @addtogroup STM32G0xx_LL_Driver
  * @{
  */

#if defined (EXTI)

/** @defgroup EXTI_LL EXTI
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup EXTI_LL_Private_Macros
  * @{
  */

#define IS_LL_EXTI_LINE_0_31(__VALUE__)              (((__VALUE__) & ~LL_EXTI_LINE_ALL_0_31) == 0x00000000UL)
#if defined(STM32G081xx) || defined(STM32G071xx) || defined(STM32G0C1xx) || defined(STM32G0B1xx) || defined(STM32G0B0xx)
#define IS_LL_EXTI_LINE_32_63(__VALUE__)             (((__VALUE__) & ~LL_EXTI_LINE_ALL_32_63) == 0x00000000UL)
#endif /* STM32G081xx || STM32G071xx || STM32G0C1xx || STM32G0B1xx || STM32G0B0xx */
#define IS_LL_EXTI_MODE(__VALUE__)                   (((__VALUE__) == LL_EXTI_MODE_IT)            \
                                                   || ((__VALUE__) == LL_EXTI_MODE_EVENT)         \
                                                   || ((__VALUE__) == LL_EXTI_MODE_IT_EVENT))


#define IS_LL_EXTI_TRIGGER(__VALUE__)                (((__VALUE__) == LL_EXTI_TRIGGER_NONE)       \
                                                   || ((__VALUE__) == LL_EXTI_TRIGGER_RISING)     \
                                                   || ((__VALUE__) == LL_EXTI_TRIGGER_FALLING)    \
                                                   || ((__VALUE__) == LL_EXTI_TRIGGER_RISING_FALLING))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup EXTI_LL_Exported_Functions
  * @{
  */

/** @addtogroup EXTI_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize the EXTI registers to their default reset values.
  * @retval An ErrorStatus enumeration value:
  *          - 0x00U: EXTI registers are de-initialized
  */
uint32_t LL_EXTI_DeInit(void)
{
  /* Interrupt mask register set to default reset values */
  LL_EXTI_WriteReg(IMR1,   0xFFF80000UL);
  /* Event mask register set to default reset values */
  LL_EXTI_WriteReg(EMR1,   0x00000000UL);
  /* Rising Trigger selection register set to default reset values */
  LL_EXTI_WriteReg(RTSR1,  0x00000000UL);
  /* Falling Trigger selection register set to default reset values */
  LL_EXTI_WriteReg(FTSR1,  0x00000000UL);
  /* Software interrupt event register set to default reset values */
  LL_EXTI_WriteReg(SWIER1, 0x00000000UL);
  /* Pending register set to default reset values */
#if defined(STM32G0C1xx) || defined(STM32G0B1xx)
  LL_EXTI_WriteReg(RPR1,    0x0017FFFFUL);
  LL_EXTI_WriteReg(FPR1,    0x0017FFFFUL);
#elif defined(STM32G081xx) || defined(STM32G071xx) || defined(STM32G061xx) || defined(STM32G051xx)
  LL_EXTI_WriteReg(RPR1,    0x0007FFFFUL);
  LL_EXTI_WriteReg(FPR1,    0x0007FFFFUL);
#elif defined(STM32G041xx) || defined(STM32G031xx)
  LL_EXTI_WriteReg(RPR1,    0x0001FFFFUL);
  LL_EXTI_WriteReg(FPR1,    0x0001FFFFUL);
#elif defined(STM32G0B0xx) || defined(STM32G070xx) || defined(STM32G050xx) || defined(STM32G030xx)
  LL_EXTI_WriteReg(RPR1,    0x0000FFFFUL);
  LL_EXTI_WriteReg(FPR1,    0x0000FFFFUL);
#endif /* STM32G0C1xx || STM32G0B1xx */

#if defined(STM32G081xx) || defined(STM32G071xx)
  /* Interrupt mask register 2 set to default reset values */
  LL_EXTI_WriteReg(IMR2, 0x00000003UL);
  /* Event mask register 2 set to default reset values */
  LL_EXTI_WriteReg(EMR2, 0x00000000UL);
#elif defined(STM32G0C1xx) || defined(STM32G0B1xx)
  /* Interrupt mask register 2 set to default reset values */
  LL_EXTI_WriteReg(IMR2, 0x0000001FUL);
  /* Event mask register 2 set to default reset values */
  LL_EXTI_WriteReg(EMR2, 0x00000000UL);
  /* Rising Trigger selection register set to default reset values */
  LL_EXTI_WriteReg(RTSR2, 0x00000000UL);
  /* Falling Trigger selection register set to default reset values */
  LL_EXTI_WriteReg(FTSR2, 0x00000000UL);
  /* Software interrupt event register set to default reset values */
  LL_EXTI_WriteReg(SWIER2, 0x00000000UL);
  /* Pending register set to default reset values */
  LL_EXTI_WriteReg(RPR2, 0x00000004UL);
  LL_EXTI_WriteReg(FPR2, 0x00000004UL);
#elif defined(STM32G0B0xx)
  /* Interrupt mask register 2 set to default reset values */
  LL_EXTI_WriteReg(IMR2, 0x00000010UL);
  /* Event mask register 2 set to default reset values */
  LL_EXTI_WriteReg(EMR2, 0x00000000UL);
#endif /* STM32G081xx || STM32G071xx */

  return 0x00U;
}

/**
  * @brief  Initialize the EXTI registers according to the specified parameters in EXTI_InitStruct.
  * @param  EXTI_InitStruct pointer to a @ref LL_EXTI_InitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - 0x00U: EXTI registers are initialized
  *          - any other value : wrong configuration
  */
uint32_t LL_EXTI_Init(LL_EXTI_InitTypeDef const * const EXTI_InitStruct)
{
  uint32_t status = 0x00U;

  /* Check the parameters */
  assert_param(IS_LL_EXTI_LINE_0_31(EXTI_InitStruct->Line_0_31));
#if defined(STM32G081xx) || defined(STM32G071xx) || defined(STM32G0C1xx) || defined(STM32G0B1xx) || defined(STM32G0B0xx)
  assert_param(IS_LL_EXTI_LINE_32_63(EXTI_InitStruct->Line_32_63));
#endif /* STM32G081xx || STM32G071xx || STM32G0C1xx || STM32G0B1xx || STM32G0B0xx */
  assert_param(IS_FUNCTIONAL_STATE(EXTI_InitStruct->LineCommand));
  assert_param(IS_LL_EXTI_MODE(EXTI_InitStruct->Mode));

  /* ENABLE LineCommand */
  if (EXTI_InitStruct->LineCommand != DISABLE)
  {
    assert_param(IS_LL_EXTI_TRIGGER(EXTI_InitStruct->Trigger));

    /* Configure EXTI Lines in range from 0 to 31 */
    if (EXTI_InitStruct->Line_0_31 != LL_EXTI_LINE_NONE)
    {
      switch (EXTI_InitStruct->Mode)
      {
        case LL_EXTI_MODE_IT:
          /* First Disable Event on provided Lines */
          LL_EXTI_DisableEvent_0_31(EXTI_InitStruct->Line_0_31);
          /* Then Enable IT on provided Lines */
          LL_EXTI_EnableIT_0_31(EXTI_InitStruct->Line_0_31);
          break;
        case LL_EXTI_MODE_EVENT:
          /* First Disable IT on provided Lines */
          LL_EXTI_DisableIT_0_31(EXTI_InitStruct->Line_0_31);
          /* Then Enable Event on provided Lines */
          LL_EXTI_EnableEvent_0_31(EXTI_InitStruct->Line_0_31);
          break;
        case LL_EXTI_MODE_IT_EVENT:
          /* Directly Enable IT & Event on provided Lines */
          LL_EXTI_EnableIT_0_31(EXTI_InitStruct->Line_0_31);
          LL_EXTI_EnableEvent_0_31(EXTI_InitStruct->Line_0_31);
          break;
        default:
          status = 0x01U;
          break;
      }
      if (EXTI_InitStruct->Trigger != LL_EXTI_TRIGGER_NONE)
      {
        switch (EXTI_InitStruct->Trigger)
        {
          case LL_EXTI_TRIGGER_RISING:
            /* First Disable Falling Trigger on provided Lines */
            LL_EXTI_DisableFallingTrig_0_31(EXTI_InitStruct->Line_0_31);
            /* Then Enable Rising Trigger on provided Lines */
            LL_EXTI_EnableRisingTrig_0_31(EXTI_InitStruct->Line_0_31);
            break;
          case LL_EXTI_TRIGGER_FALLING:
            /* First Disable Rising Trigger on provided Lines */
            LL_EXTI_DisableRisingTrig_0_31(EXTI_InitStruct->Line_0_31);
            /* Then Enable Falling Trigger on provided Lines */
            LL_EXTI_EnableFallingTrig_0_31(EXTI_InitStruct->Line_0_31);
            break;
          case LL_EXTI_TRIGGER_RISING_FALLING:
            LL_EXTI_EnableRisingTrig_0_31(EXTI_InitStruct->Line_0_31);
            LL_EXTI_EnableFallingTrig_0_31(EXTI_InitStruct->Line_0_31);
            break;
          default:
            status |= 0x02U;
            break;
        }
      }
    }
#if defined(STM32G081xx) || defined(STM32G071xx) || defined(STM32G0C1xx) || defined(STM32G0B1xx) || defined(STM32G0B0xx)
    /* Configure EXTI Lines in range from 32 to 63 */
    if (EXTI_InitStruct->Line_32_63 != LL_EXTI_LINE_NONE)
    {
      switch (EXTI_InitStruct->Mode)
      {
        case LL_EXTI_MODE_IT:
          /* First Disable Event on provided Lines */
          LL_EXTI_DisableEvent_32_63(EXTI_InitStruct->Line_32_63);
          /* Then Enable IT on provided Lines */
          LL_EXTI_EnableIT_32_63(EXTI_InitStruct->Line_32_63);
          break;
        case LL_EXTI_MODE_EVENT:
          /* First Disable IT on provided Lines */
          LL_EXTI_DisableIT_32_63(EXTI_InitStruct->Line_32_63);
          /* Then Enable Event on provided Lines */
          LL_EXTI_EnableEvent_32_63(EXTI_InitStruct->Line_32_63);
          break;
        case LL_EXTI_MODE_IT_EVENT:
          /* Directly Enable IT & Event on provided Lines */
          LL_EXTI_EnableIT_32_63(EXTI_InitStruct->Line_32_63);
          LL_EXTI_EnableEvent_32_63(EXTI_InitStruct->Line_32_63);
          break;
        default:
          status |= 0x04U;
          break;
      }
    }
#endif /* STM32G081xx || STM32G071xx || STM32G0C1xx || STM32G0B1xx || STM32G0B0xx */
  }
  /* DISABLE LineCommand */
  else
  {
    /* De-configure EXTI Lines in range from 0 to 31 */
    LL_EXTI_DisableIT_0_31(EXTI_InitStruct->Line_0_31);
    LL_EXTI_DisableEvent_0_31(EXTI_InitStruct->Line_0_31);
#if defined(STM32G081xx) || defined(STM32G071xx) || defined(STM32G0C1xx) || defined(STM32G0B1xx) || defined(STM32G0B0xx)
    /* De-configure EXTI Lines in range from 32 to 63 */
    LL_EXTI_DisableIT_32_63(EXTI_InitStruct->Line_32_63);
    LL_EXTI_DisableEvent_32_63(EXTI_InitStruct->Line_32_63);
#endif /* STM32G081xx || STM32G071xx || STM32G0C1xx || STM32G0B1xx || STM32G0B0xx */
  }

  return status;
}

/**
  * @brief  Set each @ref LL_EXTI_InitTypeDef field to default value.
  * @param  EXTI_InitStruct Pointer to a @ref LL_EXTI_InitTypeDef structure.
  * @retval None
  */
void LL_EXTI_StructInit(LL_EXTI_InitTypeDef * const EXTI_InitStruct)
{
  EXTI_InitStruct->Line_0_31      = LL_EXTI_LINE_NONE;
#if defined(STM32G081xx) || defined(STM32G071xx) || defined(STM32G0C1xx) || defined(STM32G0B1xx) || defined(STM32G0B0xx)
  EXTI_InitStruct->Line_32_63     = LL_EXTI_LINE_NONE;
#endif /* STM32G081xx || STM32G071xx || STM32G0C1xx || STM32G0B1xx || STM32G0B0xx */
  EXTI_InitStruct->LineCommand    = DISABLE;
  EXTI_InitStruct->Mode           = LL_EXTI_MODE_IT;
  EXTI_InitStruct->Trigger        = LL_EXTI_TRIGGER_FALLING;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (EXTI) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */


/*lint -restore*/
