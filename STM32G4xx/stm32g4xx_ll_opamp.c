/**
  ******************************************************************************
  * @file    stm32g4xx_ll_opamp.c
  * @author  MCD Application Team
  * @brief   OPAMP LL module driver
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
#include "stm32g4xx_ll_opamp.h"

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

#if defined (OPAMP1) || defined (OPAMP2) || defined (OPAMP3) || defined (OPAMP4) || defined (OPAMP5) || defined (OPAMP6)

/** @addtogroup OPAMP_LL OPAMP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/** @addtogroup OPAMP_LL_Private_Macros
  * @{
  */

/* Check of parameters for configuration of OPAMP hierarchical scope:         */
/* OPAMP instance.                                                            */

#define IS_LL_OPAMP_POWER_MODE(__POWER_MODE__)                                 \
  (   ((__POWER_MODE__) == LL_OPAMP_POWERMODE_NORMALSPEED)                     \
   || ((__POWER_MODE__) == LL_OPAMP_POWERMODE_HIGHSPEED))

#define IS_LL_OPAMP_FUNCTIONAL_MODE(__FUNCTIONAL_MODE__)                       \
  (   ((__FUNCTIONAL_MODE__) == LL_OPAMP_MODE_STANDALONE)                      \
   || ((__FUNCTIONAL_MODE__) == LL_OPAMP_MODE_FOLLOWER)                        \
   || ((__FUNCTIONAL_MODE__) == LL_OPAMP_MODE_PGA)                             \
   || ((__FUNCTIONAL_MODE__) == LL_OPAMP_MODE_PGA_IO0)                         \
   || ((__FUNCTIONAL_MODE__) == LL_OPAMP_MODE_PGA_IO0_BIAS)                    \
   || ((__FUNCTIONAL_MODE__) == LL_OPAMP_MODE_PGA_IO0_IO1_BIAS)                \
  )

#define IS_LL_OPAMP_INPUT_NONINVERTING(__INPUT_NONINVERTING__)                 \
  (   ((__INPUT_NONINVERTING__) == LL_OPAMP_INPUT_NONINVERT_IO0)               \
   || ((__INPUT_NONINVERTING__) == LL_OPAMP_INPUT_NONINVERT_IO1)               \
   || ((__INPUT_NONINVERTING__) == LL_OPAMP_INPUT_NONINVERT_IO2)               \
   || ((__INPUT_NONINVERTING__) == LL_OPAMP_INPUT_NONINVERT_IO3)               \
   || ((__INPUT_NONINVERTING__) == LL_OPAMP_INPUT_NONINVERT_DAC)               \
  )

#define IS_LL_OPAMP_INPUT_INVERTING(__INPUT_INVERTING__)                       \
  (   ((__INPUT_INVERTING__) == LL_OPAMP_INPUT_INVERT_IO0)                     \
   || ((__INPUT_INVERTING__) == LL_OPAMP_INPUT_INVERT_IO1)                     \
   || ((__INPUT_INVERTING__) == LL_OPAMP_INPUT_INVERT_CONNECT_NO)              \
  )

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup OPAMP_LL_Exported_Functions
  * @{
  */

/** @addtogroup OPAMP_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize registers of the selected OPAMP instance
  *         to their default reset values.
  * @note   If comparator is locked, de-initialization by software is
  *         not possible.
  *         The only way to unlock the comparator is a device hardware reset.
  * @param  OPAMPx OPAMP instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: OPAMP registers are de-initialized
  *          - ERROR: OPAMP registers are not de-initialized
  */
ErrorStatus LL_OPAMP_DeInit(OPAMP_TypeDef * const OPAMPx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_OPAMP_ALL_INSTANCE(OPAMPx));

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       OPAMP instance must not be locked.                                 */
  if (LL_OPAMP_IsLocked(OPAMPx) == 0UL)
  {
    LL_OPAMP_WriteReg(OPAMPx, CSR, 0x00000000UL);
  }
  else
  {
    /* OPAMP instance is locked: de-initialization by software is              */
    /* not possible.                                                           */
    /* The only way to unlock the OPAMP is a device hardware reset.            */
    status = ERROR;
  }

  /* Timer controlled mux mode register reset                                  */
  if (LL_OPAMP_IsTimerMuxLocked(OPAMPx) == 0UL)
  {
    LL_OPAMP_WriteReg(OPAMPx, TCMR, 0x00000000UL);
  }
  else if (LL_OPAMP_ReadReg(OPAMPx, TCMR) != 0x80000000UL)
  {
    /* OPAMP instance timer controlled mux is locked configured, deinit error  */
    /* The only way to unlock the OPAMP is a device hardware reset.            */
    status = ERROR;
  }
  else
  {
    /* OPAMP instance timer controlled mux is locked unconfigured, deinit OK */
  }

  return status;
}

/**
  * @brief  Initialize some features of OPAMP instance.
  * @note   This function reset bit of calibration mode to ensure
  *         to be in functional mode, in order to have OPAMP parameters
  *         (inputs selection, ...) set with the corresponding OPAMP mode
  *         to be effective.
  * @param  OPAMPx OPAMP instance
  * @param  OPAMP_InitStruct Pointer to a @ref LL_OPAMP_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: OPAMP registers are initialized
  *          - ERROR: OPAMP registers are not initialized
  */
ErrorStatus LL_OPAMP_Init(OPAMP_TypeDef * const OPAMPx, LL_OPAMP_InitTypeDef const * const OPAMP_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_OPAMP_ALL_INSTANCE(OPAMPx));
  assert_param(IS_LL_OPAMP_POWER_MODE(OPAMP_InitStruct->PowerMode));
  assert_param(IS_LL_OPAMP_FUNCTIONAL_MODE(OPAMP_InitStruct->FunctionalMode));
  assert_param(IS_LL_OPAMP_INPUT_NONINVERTING(OPAMP_InitStruct->InputNonInverting));

  /* Note: OPAMP inverting input can be used with OPAMP in mode standalone    */
  /*       or PGA with external capacitors for filtering circuit.             */
  /*       Otherwise (OPAMP in mode follower), OPAMP inverting input is       */
  /*       not used (not connected to GPIO pin).                              */
  if (OPAMP_InitStruct->FunctionalMode != LL_OPAMP_MODE_FOLLOWER)
  {
    assert_param(IS_LL_OPAMP_INPUT_INVERTING(OPAMP_InitStruct->InputInverting));
  }

  /* Note: Hardware constraint (refer to description of this function):       */
  /*       OPAMP instance must not be locked.                                 */
  if (LL_OPAMP_IsLocked(OPAMPx) == 0U)
  {
    /* Configuration of OPAMP instance :                                      */
    /*  - PowerMode                                                             */
    /*  - Functional mode                                                     */
    /*  - Input non-inverting                                                 */
    /*  - Input inverting                                                     */
    /* Note: Bit OPAMP_CSR_CALON reset to ensure to be in functional mode.    */
    if (OPAMP_InitStruct->FunctionalMode != LL_OPAMP_MODE_FOLLOWER)
    {
      MODIFY_REG(OPAMPx->CSR,
                 OPAMP_CSR_HIGHSPEEDEN
                 | OPAMP_CSR_CALON
                 | OPAMP_CSR_VMSEL
                 | OPAMP_CSR_VPSEL
                 | OPAMP_CSR_PGGAIN_4 | OPAMP_CSR_PGGAIN_3
                 ,
                 OPAMP_InitStruct->PowerMode
                 | OPAMP_InitStruct->FunctionalMode
                 | OPAMP_InitStruct->InputNonInverting
                 | OPAMP_InitStruct->InputInverting
                );
    }
    else
    {
      MODIFY_REG(OPAMPx->CSR,
                 OPAMP_CSR_HIGHSPEEDEN
                 | OPAMP_CSR_CALON
                 | OPAMP_CSR_VMSEL
                 | OPAMP_CSR_VPSEL
                 | OPAMP_CSR_PGGAIN_4 | OPAMP_CSR_PGGAIN_3
                 ,
                 OPAMP_InitStruct->PowerMode
                 | LL_OPAMP_MODE_FOLLOWER
                 | OPAMP_InitStruct->InputNonInverting
                );
    }
  }
  else
  {
    /* Initialization error: OPAMP instance is locked.                        */
    status = ERROR;
  }

  return status;
}

/**
  * @brief Set each @ref LL_OPAMP_InitTypeDef field to default value.
  * @param OPAMP_InitStruct pointer to a @ref LL_OPAMP_InitTypeDef structure
  *                         whose fields will be set to default values.
  * @retval None
  */
void LL_OPAMP_StructInit(LL_OPAMP_InitTypeDef * const OPAMP_InitStruct)
{
  /* Set OPAMP_InitStruct fields to default values */
  OPAMP_InitStruct->PowerMode         = LL_OPAMP_POWERMODE_NORMALSPEED;
  OPAMP_InitStruct->FunctionalMode    = LL_OPAMP_MODE_FOLLOWER;
  OPAMP_InitStruct->InputNonInverting = LL_OPAMP_INPUT_NONINVERT_IO0;
  /* Note: Parameter discarded if OPAMP in functional mode follower,          */
  /*       set anyway to its default value.                                   */
  OPAMP_InitStruct->InputInverting    = LL_OPAMP_INPUT_INVERT_CONNECT_NO;
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

#endif /* OPAMP1 || OPAMP2 || OPAMP3 || OPAMP4  || OPAMP5 || OPAMP6 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */


/*lint -restore*/
