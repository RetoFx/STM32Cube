/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pka.h
  * @author  MCD Application Team
  * @brief   Header file of PKA HAL module.
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
#ifndef STM32L4xx_HAL_PKA_H
#define STM32L4xx_HAL_PKA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal_def.h"

/** @addtogroup STM32L4xx_HAL_Driver
  * @{
  */

#if defined(PKA) && defined(HAL_PKA_MODULE_ENABLED)

/** @addtogroup PKA
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PKA_Exported_Types PKA Exported Types
  * @{
  */

/** @defgroup HAL_state_structure_definition HAL state structure definition
  * @brief  HAL State structures definition
  * @{
  */
typedef enum
{
  HAL_PKA_STATE_RESET   = 0x00U,  /*!< PKA not yet initialized or disabled  */
  HAL_PKA_STATE_READY   = 0x01U,  /*!< PKA initialized and ready for use    */
  HAL_PKA_STATE_BUSY    = 0x02U,  /*!< PKA internal processing is ongoing   */
  HAL_PKA_STATE_ERROR   = 0x03U,  /*!< PKA error state                      */
}
HAL_PKA_StateTypeDef;

/**
  * @}
  */

#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
/** @defgroup HAL_callback_id HAL callback ID enumeration
  * @{
  */
typedef enum
{
  HAL_PKA_OPERATION_COMPLETE_CB_ID      = 0x00U,    /*!< PKA End of operation callback ID  */
  HAL_PKA_ERROR_CB_ID                   = 0x01U,    /*!< PKA Error callback ID             */
  HAL_PKA_MSPINIT_CB_ID                 = 0x02U,    /*!< PKA Msp Init callback ID          */
  HAL_PKA_MSPDEINIT_CB_ID               = 0x03U     /*!< PKA Msp DeInit callback ID        */
} HAL_PKA_CallbackIDTypeDef;

/**
  * @}
  */

#endif /* USE_HAL_PKA_REGISTER_CALLBACKS */

/** @defgroup PKA_Error_Code_definition PKA Error Code definition
  * @brief  PKA Error Code definition
  * @{
  */
#define HAL_PKA_ERROR_NONE      (0x00000000UL)
#define HAL_PKA_ERROR_ADDRERR   (0x00000001UL)
#define HAL_PKA_ERROR_RAMERR    (0x00000002UL)
#define HAL_PKA_ERROR_TIMEOUT   (0x00000004UL)
#define HAL_PKA_ERROR_OPERATION (0x00000008UL)
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
#define HAL_PKA_ERROR_INVALID_CALLBACK  (0x00000010UL)    /*!< Invalid Callback error */
#endif /* USE_HAL_PKA_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup PKA_handle_Structure_definition PKA handle Structure definition
  * @brief  PKA handle Structure definition
  * @{
  */
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
typedef struct __PKA_HandleTypeDef
#else
typedef struct
#endif  /* USE_HAL_PKA_REGISTER_CALLBACKS */
{
  PKA_TypeDef                   *Instance;              /*!< Register base address */
  __IO HAL_PKA_StateTypeDef     State;                  /*!< PKA state */
  __IO uint32_t                 ErrorCode;              /*!< PKA Error code */
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
  void (* OperationCpltCallback)(struct __PKA_HandleTypeDef * const hpka); /*!< PKA End of operation callback */
  void (* ErrorCallback)(struct __PKA_HandleTypeDef * const hpka);         /*!< PKA Error callback            */
  void (* MspInitCallback)(struct __PKA_HandleTypeDef * const hpka);       /*!< PKA Msp Init callback         */
  void (* MspDeInitCallback)(struct __PKA_HandleTypeDef * const hpka);     /*!< PKA Msp DeInit callback       */
#endif  /* USE_HAL_PKA_REGISTER_CALLBACKS */
} PKA_HandleTypeDef;
/**
  * @}
  */

#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
/** @defgroup PKA_Callback_definition PKA Callback pointer definition
  * @brief  PKA Callback pointer definition
  * @{
  */
typedef  void (*pPKA_CallbackTypeDef)(PKA_HandleTypeDef * const hpka); /*!< Pointer to a PKA callback function */
/**
  * @}
  */
#endif /* USE_HAL_PKA_REGISTER_CALLBACKS */
/** @defgroup PKA_Operation PKA operation structure definition
  * @brief  Input and output data definition
  * @{
  */
typedef struct
{
  uint32_t scalarMulSize;              /*!< Number of element in scalarMul array */
  uint32_t modulusSize;                /*!< Number of element in modulus, coefA, pointX and pointY arrays */
  uint32_t coefSign;                   /*!< Curve coefficient a sign */
  uint8_t const *coefA;                /*!< Pointer to curve coefficient |a| (Array of modulusSize elements) */
  uint8_t const *modulus;              /*!< Pointer to curve modulus value p (Array of modulusSize elements) */
  uint8_t const * pointX;               /*!< Pointer to point P coordinate xP (Array of modulusSize elements) */
  uint8_t const * pointY;               /*!< Pointer to point P coordinate yP (Array of modulusSize elements) */
  uint8_t const *scalarMul;            /*!< Pointer to scalar multiplier k   (Array of scalarMulSize elements) */
  uint32_t const * pMontgomeryParam;    /*!< Pointer to Montgomery parameter  (Array of modulusSize/4 elements) */
} PKA_ECCMulFastModeInTypeDef;

typedef struct
{
  uint32_t scalarMulSize;              /*!< Number of element in scalarMul array */
  uint32_t modulusSize;                /*!< Number of element in modulus, coefA, pointX and pointY arrays */
  uint32_t coefSign;                   /*!< Curve coefficient a sign */
  uint8_t const *coefA;                /*!< Pointer to curve coefficient |a| (Array of modulusSize elements) */
  uint8_t const *modulus;              /*!< Pointer to curve modulus value p (Array of modulusSize elements) */
  uint8_t const * pointX;               /*!< Pointer to point P coordinate xP (Array of modulusSize elements) */
  uint8_t const * pointY;               /*!< Pointer to point P coordinate yP (Array of modulusSize elements) */
  uint8_t const *scalarMul;            /*!< Pointer to scalar multiplier k   (Array of scalarMulSize elements) */
} PKA_ECCMulInTypeDef;

typedef struct
{
  uint32_t modulusSize;                /*!< Number of element in coefA, coefB, modulus, pointX and pointY arrays */
  uint32_t coefSign;                   /*!< Curve coefficient a sign */
  uint8_t const *coefA;                /*!< Pointer to curve coefficient |a| (Array of modulusSize elements) */
  uint8_t const *coefB;                /*!< Pointer to curve coefficient b   (Array of modulusSize elements) */
  uint8_t const *modulus;              /*!< Pointer to curve modulus value p (Array of modulusSize elements) */
  uint8_t const * pointX;               /*!< Pointer to point P coordinate xP (Array of modulusSize elements) */
  uint8_t const * pointY;               /*!< Pointer to point P coordinate yP (Array of modulusSize elements) */
} PKA_PointCheckInTypeDef;

typedef struct
{
  uint32_t size;                       /*!< Number of element in popA array */
  uint8_t const * pOpDp;                /*!< Pointer to operand dP   (Array of size/2 elements) */
  uint8_t const * pOpDq;                /*!< Pointer to operand dQ   (Array of size/2 elements) */
  uint8_t const * pOpQinv;              /*!< Pointer to operand qinv (Array of size/2 elements) */
  uint8_t const * pPrimeP;              /*!< Pointer to prime p      (Array of size/2 elements) */
  uint8_t const * pPrimeQ;              /*!< Pointer to prime Q      (Array of size/2 elements) */
  uint8_t const * popA;                 /*!< Pointer to operand A    (Array of size elements) */
} PKA_RSACRTExpInTypeDef;

typedef struct
{
  uint32_t primeOrderSize;             /*!< Number of element in primeOrder array */
  uint32_t modulusSize;                /*!< Number of element in modulus array */
  uint32_t coefSign;                   /*!< Curve coefficient a sign */
  uint8_t const *coef;                 /*!< Pointer to curve coefficient |a|     (Array of modulusSize elements) */
  uint8_t const *modulus;              /*!< Pointer to curve modulus value p     (Array of modulusSize elements) */
  uint8_t const *basePointX;           /*!< Pointer to curve base point xG       (Array of modulusSize elements) */
  uint8_t const *basePointY;           /*!< Pointer to curve base point yG       (Array of modulusSize elements) */
  uint8_t const * pPubKeyCurvePtX;      /*!< Pointer to public-key curve point xQ (Array of modulusSize elements) */
  uint8_t const * pPubKeyCurvePtY;      /*!< Pointer to public-key curve point yQ (Array of modulusSize elements) */
  uint8_t const *RSign;                /*!< Pointer to signature part r          (Array of primeOrderSize elements) */
  uint8_t const *SSign;                /*!< Pointer to signature part s          (Array of primeOrderSize elements) */
  uint8_t const *hash;                 /*!< Pointer to hash of the message e     (Array of primeOrderSize elements) */
  uint8_t const * primeOrder;           /*!< Pointer to order of the curve n      (Array of primeOrderSize elements) */
} PKA_ECDSAVerifInTypeDef;

typedef struct
{
  uint32_t primeOrderSize;             /*!< Number of element in primeOrder array */
  uint32_t modulusSize;                /*!< Number of element in modulus array */
  uint32_t coefSign;                   /*!< Curve coefficient a sign */
  uint8_t const *coef;                 /*!< Pointer to curve coefficient |a|     (Array of modulusSize elements) */
  uint8_t const *modulus;              /*!< Pointer to curve modulus value p     (Array of modulusSize elements) */
  uint8_t const *integer;              /*!< Pointer to random integer k          (Array of primeOrderSize elements) */
  uint8_t const *basePointX;           /*!< Pointer to curve base point xG       (Array of modulusSize elements) */
  uint8_t const *basePointY;           /*!< Pointer to curve base point yG       (Array of modulusSize elements) */
  uint8_t const *hash;                 /*!< Pointer to hash of the message       (Array of primeOrderSize elements) */
  uint8_t const * privateKey;           /*!< Pointer to private key d             (Array of primeOrderSize elements) */
  uint8_t const * primeOrder;           /*!< Pointer to order of the curve n      (Array of primeOrderSize elements) */
} PKA_ECDSASignInTypeDef;

typedef struct
{
  uint8_t *RSign;                      /*!< Pointer to signature part r          (Array of modulusSize elements) */
  uint8_t *SSign;                      /*!< Pointer to signature part s          (Array of modulusSize elements) */
} PKA_ECDSASignOutTypeDef;

typedef struct
{
  uint8_t * ptX;                        /*!< Pointer to point P coordinate xP     (Array of modulusSize elements) */
  uint8_t * ptY;                        /*!< Pointer to point P coordinate yP     (Array of modulusSize elements) */
} PKA_ECDSASignOutExtParamTypeDef, PKA_ECCMulOutTypeDef;


typedef struct
{
  uint32_t expSize;                    /*!< Number of element in pExp array */
  uint32_t OpSize;                     /*!< Number of element in pOp1 and pMod arrays */
  uint8_t const * pExp;                 /*!< Pointer to Exponent             (Array of expSize elements) */
  uint8_t const * pOp1;                 /*!< Pointer to Operand              (Array of OpSize elements) */
  uint8_t const * pMod;                 /*!< Pointer to modulus              (Array of OpSize elements) */
} PKA_ModExpInTypeDef;


typedef struct
{
  uint32_t expSize;                    /*!< Number of element in pExp and pMontgomeryParam arrays */
  uint32_t OpSize;                     /*!< Number of element in pOp1 and pMod arrays */
  uint8_t const * pExp;                 /*!< Pointer to Exponent             (Array of expSize elements) */
  uint8_t const * pOp1;                 /*!< Pointer to Operand              (Array of OpSize elements) */
  uint8_t const * pMod;                 /*!< Pointer to modulus              (Array of OpSize elements) */
  uint32_t const * pMontgomeryParam;    /*!< Pointer to Montgomery parameter (Array of expSize/4 elements) */
} PKA_ModExpFastModeInTypeDef;

typedef struct
{
  uint32_t size;                       /*!< Number of element in pOp1 array */
  uint8_t const * pOp1;                 /*!< Pointer to Operand (Array of size elements) */
} PKA_MontgomeryParamInTypeDef;

typedef struct
{
  uint32_t size;                       /*!< Number of element in pOp1 and pOp2 arrays */
  uint32_t const * pOp1;                /*!< Pointer to Operand 1 (Array of size elements) */
  uint32_t const * pOp2;                /*!< Pointer to Operand 2 (Array of size elements) */
} PKA_AddInTypeDef, PKA_SubInTypeDef, PKA_MulInTypeDef, PKA_CmpInTypeDef;

typedef struct
{
  uint32_t size;                       /*!< Number of element in pOp1 array */
  uint32_t const * pOp1;                /*!< Pointer to Operand 1       (Array of size elements) */
  uint8_t const * pMod;                 /*!< Pointer to modulus value n (Array of size*4 elements) */
} PKA_ModInvInTypeDef;

typedef struct
{
  uint32_t OpSize;                     /*!< Number of element in pOp1 array */
  uint32_t modSize;                    /*!< Number of element in pMod array */
  uint32_t const * pOp1;                /*!< Pointer to Operand 1       (Array of OpSize elements) */
  uint8_t const * pMod;                 /*!< Pointer to modulus value n (Array of modSize elements) */
} PKA_ModRedInTypeDef;

typedef struct
{
  uint32_t size;                       /*!< Number of element in pOp1 and pOp2 arrays */
  uint32_t const * pOp1;                /*!< Pointer to Operand 1 (Array of size elements) */
  uint32_t const * pOp2;                /*!< Pointer to Operand 2 (Array of size elements) */
  uint8_t const * pOp3;                /*!< Pointer to Operand 3 (Array of size*4 elements) */
} PKA_ModAddInTypeDef, PKA_ModSubInTypeDef, PKA_MontgomeryMulInTypeDef;

/**
  * @}
  */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup PKA_Exported_Constants PKA Exported Constants
  * @{
  */

/** @defgroup PKA_Mode PKA mode
  * @{
  */
#define PKA_MODE_MONTGOMERY_PARAM                 (0x00000001UL)
#define PKA_MODE_MODULAR_EXP                      (0x00000000UL)
#define PKA_MODE_MODULAR_EXP_FAST_MODE            (0x00000002UL)
#define PKA_MODE_ECC_MUL                          (0x00000020UL)
#define PKA_MODE_ECC_MUL_FAST_MODE                (0x00000022UL)
#define PKA_MODE_ECDSA_SIGNATURE                  (0x00000024UL)
#define PKA_MODE_ECDSA_VERIFICATION               (0x00000026UL)
#define PKA_MODE_POINT_CHECK                      (0x00000028UL)
#define PKA_MODE_RSA_CRT_EXP                      (0x00000007UL)
#define PKA_MODE_MODULAR_INV                      (0x00000008UL)
#define PKA_MODE_ARITHMETIC_ADD                   (0x00000009UL)
#define PKA_MODE_ARITHMETIC_SUB                   (0x0000000AUL)
#define PKA_MODE_ARITHMETIC_MUL                   (0x0000000BUL)
#define PKA_MODE_COMPARISON                       (0x0000000CUL)
#define PKA_MODE_MODULAR_RED                      (0x0000000DUL)
#define PKA_MODE_MODULAR_ADD                      (0x0000000EUL)
#define PKA_MODE_MODULAR_SUB                      (0x0000000FUL)
#define PKA_MODE_MONTGOMERY_MUL                   (0x00000010UL)
/**
  * @}
  */

/** @defgroup PKA_Interrupt_configuration_definition PKA Interrupt configuration definition
  * @brief PKA Interrupt definition
  * @{
  */
#define PKA_IT_PROCEND                            PKA_CR_PROCENDIE
#define PKA_IT_ADDRERR                            PKA_CR_ADDRERRIE
#define PKA_IT_RAMERR                             PKA_CR_RAMERRIE

/**
  * @}
  */

/** @defgroup PKA_Flag_definition PKA Flag definition
  * @{
  */
#define PKA_FLAG_PROCEND                          PKA_SR_PROCENDF
#define PKA_FLAG_ADDRERR                          PKA_SR_ADDRERRF
#define PKA_FLAG_RAMERR                           PKA_SR_RAMERRF

/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup PKA_Exported_Macros PKA Exported Macros
  * @{
  */

/** @brief  Reset PKA handle state.
  * @param  __HANDLE__ specifies the PKA Handle
  * @retval None
  */
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
#define __HAL_PKA_RESET_HANDLE_STATE(__HANDLE__)                do{                                                   \
                                                                    (__HANDLE__)->State = HAL_PKA_STATE_RESET;       \
                                                                    (__HANDLE__)->MspInitCallback = NULL;            \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                                  } while(0U)
#else
#define __HAL_PKA_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_PKA_STATE_RESET)
#endif /* USE_HAL_PKA_REGISTER_CALLBACKS */

/** @brief  Enable the specified PKA interrupt.
  * @param  __HANDLE__ specifies the PKA Handle
  * @param  __INTERRUPT__ specifies the interrupt source to enable.
  *        This parameter can be one of the following values:
  *            @arg @ref PKA_IT_PROCEND End Of Operation interrupt enable
  *            @arg @ref PKA_IT_ADDRERR Address error interrupt enable
  *            @arg @ref PKA_IT_RAMERR RAM error interrupt enable
  * @retval None
  */
#define __HAL_PKA_ENABLE_IT(__HANDLE__, __INTERRUPT__)          ((__HANDLE__)->Instance->CR |= (__INTERRUPT__))

/** @brief  Disable the specified PKA interrupt.
  * @param  __HANDLE__ specifies the PKA Handle
  * @param  __INTERRUPT__ specifies the interrupt source to disable.
  *        This parameter can be one of the following values:
  *            @arg @ref PKA_IT_PROCEND End Of Operation interrupt enable
  *            @arg @ref PKA_IT_ADDRERR Address error interrupt enable
  *            @arg @ref PKA_IT_RAMERR RAM error interrupt enable
  * @retval None
  */
#define __HAL_PKA_DISABLE_IT(__HANDLE__, __INTERRUPT__)         ((__HANDLE__)->Instance->CR &= (~(__INTERRUPT__)))

/** @brief  Check whether the specified PKA interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the PKA Handle
  * @param  __INTERRUPT__ specifies the PKA interrupt source to check.
  *        This parameter can be one of the following values:
  *            @arg @ref PKA_IT_PROCEND End Of Operation interrupt enable
  *            @arg @ref PKA_IT_ADDRERR Address error interrupt enable
  *            @arg @ref PKA_IT_RAMERR RAM error interrupt enable
  * @retval The new state of __INTERRUPT__ (SET or RESET)
  */
#define __HAL_PKA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)      ((((__HANDLE__)->Instance->CR \
                                                                   & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

/** @brief  Check whether the specified PKA flag is set or not.
  * @param  __HANDLE__ specifies the PKA Handle
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg @ref PKA_FLAG_PROCEND End Of Operation
  *            @arg @ref PKA_FLAG_ADDRERR Address error
  *            @arg @ref PKA_FLAG_RAMERR RAM error
  * @retval The new state of __FLAG__ (SET or RESET)
  */
#define __HAL_PKA_GET_FLAG(__HANDLE__, __FLAG__)                (((((__HANDLE__)->Instance->SR) \
                                                                   & (__FLAG__)) == (__FLAG__)) ? SET : RESET)

/** @brief  Clear the PKA pending flags which are cleared by writing 1 in a specific bit.
  * @param  __HANDLE__ specifies the PKA Handle
  * @param  __FLAG__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg @ref PKA_FLAG_PROCEND End Of Operation
  *            @arg @ref PKA_FLAG_ADDRERR Address error
  *            @arg @ref PKA_FLAG_RAMERR RAM error
  * @retval None
  */
#define __HAL_PKA_CLEAR_FLAG(__HANDLE__, __FLAG__)              ((__HANDLE__)->Instance->CLRFR = (__FLAG__))

/** @brief  Enable the specified PKA peripheral.
  * @param  __HANDLE__ specifies the PKA Handle
  * @retval None
  */
#define __HAL_PKA_ENABLE(__HANDLE__)                            (SET_BIT((__HANDLE__)->Instance->CR,  PKA_CR_EN))

/** @brief  Disable the specified PKA peripheral.
  * @param  __HANDLE__ specifies the PKA Handle
  * @retval None
  */
#define __HAL_PKA_DISABLE(__HANDLE__)                           (CLEAR_BIT((__HANDLE__)->Instance->CR, PKA_CR_EN))

/** @brief  Start a PKA operation.
  * @param  __HANDLE__ specifies the PKA Handle
  * @retval None
  */
#define __HAL_PKA_START(__HANDLE__)                             (SET_BIT((__HANDLE__)->Instance->CR,  PKA_CR_START))
/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup PKA_Exported_Functions
  * @{
  */

/** @addtogroup PKA_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef HAL_PKA_Init(PKA_HandleTypeDef * const hpka);
HAL_StatusTypeDef HAL_PKA_DeInit(PKA_HandleTypeDef * const hpka);
void              HAL_PKA_MspInit(PKA_HandleTypeDef * const hpka);
void              HAL_PKA_MspDeInit(PKA_HandleTypeDef * const hpka);

#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1U)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_PKA_RegisterCallback(PKA_HandleTypeDef * const hpka, HAL_PKA_CallbackIDTypeDef CallbackID,
                                           pPKA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_PKA_UnRegisterCallback(PKA_HandleTypeDef * const hpka, HAL_PKA_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_PKA_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup PKA_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
/* High Level Functions *******************************************************/
HAL_StatusTypeDef HAL_PKA_ModExp(PKA_HandleTypeDef * const hpka, PKA_ModExpInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExp_IT(PKA_HandleTypeDef * const hpka, PKA_ModExpInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_ModExpFastMode(PKA_HandleTypeDef * const hpka, PKA_ModExpFastModeInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExpFastMode_IT(PKA_HandleTypeDef * const hpka, PKA_ModExpFastModeInTypeDef const * const in);
void HAL_PKA_ModExp_GetResult(PKA_HandleTypeDef const * const hpka, uint8_t * const pRes);

HAL_StatusTypeDef HAL_PKA_ECDSASign(PKA_HandleTypeDef * const hpka, PKA_ECDSASignInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECDSASign_IT(PKA_HandleTypeDef * const hpka, PKA_ECDSASignInTypeDef const * const in);
void HAL_PKA_ECDSASign_GetResult(PKA_HandleTypeDef const * const hpka, PKA_ECDSASignOutTypeDef const * const out,
                                 PKA_ECDSASignOutExtParamTypeDef const * const outExt);

HAL_StatusTypeDef HAL_PKA_ECDSAVerif(PKA_HandleTypeDef * const hpka, PKA_ECDSAVerifInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECDSAVerif_IT(PKA_HandleTypeDef * const hpka, PKA_ECDSAVerifInTypeDef const * const in);
uint32_t HAL_PKA_ECDSAVerif_IsValidSignature(PKA_HandleTypeDef const * const hpka);

HAL_StatusTypeDef HAL_PKA_RSACRTExp(PKA_HandleTypeDef * const hpka, PKA_RSACRTExpInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_RSACRTExp_IT(PKA_HandleTypeDef * const hpka, PKA_RSACRTExpInTypeDef const * const in);
void HAL_PKA_RSACRTExp_GetResult(PKA_HandleTypeDef const * const hpka, uint8_t * const pRes);

HAL_StatusTypeDef HAL_PKA_PointCheck(PKA_HandleTypeDef * const hpka, PKA_PointCheckInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_PointCheck_IT(PKA_HandleTypeDef * const hpka, PKA_PointCheckInTypeDef const * const in);
uint32_t HAL_PKA_PointCheck_IsOnCurve(PKA_HandleTypeDef const * const hpka);

HAL_StatusTypeDef HAL_PKA_ECCMul(PKA_HandleTypeDef * const hpka, PKA_ECCMulInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCMul_IT(PKA_HandleTypeDef * const hpka, PKA_ECCMulInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_ECCMulFastMode(PKA_HandleTypeDef * const hpka, PKA_ECCMulFastModeInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCMulFastMode_IT(PKA_HandleTypeDef * const hpka, PKA_ECCMulFastModeInTypeDef const * const in);
void HAL_PKA_ECCMul_GetResult(PKA_HandleTypeDef const * const hpka, PKA_ECCMulOutTypeDef * const out);

HAL_StatusTypeDef HAL_PKA_Add(PKA_HandleTypeDef * const hpka, PKA_AddInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Add_IT(PKA_HandleTypeDef * const hpka, PKA_AddInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_Sub(PKA_HandleTypeDef * const hpka, PKA_SubInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Sub_IT(PKA_HandleTypeDef * const hpka, PKA_SubInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_Cmp(PKA_HandleTypeDef * const hpka, PKA_CmpInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Cmp_IT(PKA_HandleTypeDef * const hpka, PKA_CmpInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_Mul(PKA_HandleTypeDef * const hpka, PKA_MulInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Mul_IT(PKA_HandleTypeDef * const hpka, PKA_MulInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_ModAdd(PKA_HandleTypeDef * const hpka, PKA_ModAddInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModAdd_IT(PKA_HandleTypeDef * const hpka, PKA_ModAddInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_ModSub(PKA_HandleTypeDef * const hpka, PKA_ModSubInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModSub_IT(PKA_HandleTypeDef * const hpka, PKA_ModSubInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_ModInv(PKA_HandleTypeDef * const hpka, PKA_ModInvInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModInv_IT(PKA_HandleTypeDef * const hpka, PKA_ModInvInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_ModRed(PKA_HandleTypeDef * const hpka, PKA_ModRedInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModRed_IT(PKA_HandleTypeDef * const hpka, PKA_ModRedInTypeDef const * const in);
HAL_StatusTypeDef HAL_PKA_MontgomeryMul(PKA_HandleTypeDef * const hpka, PKA_MontgomeryMulInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_MontgomeryMul_IT(PKA_HandleTypeDef * const hpka, PKA_MontgomeryMulInTypeDef const * const in);
void HAL_PKA_Arithmetic_GetResult(PKA_HandleTypeDef const * const hpka, uint32_t * const pRes);

HAL_StatusTypeDef HAL_PKA_MontgomeryParam(PKA_HandleTypeDef * const hpka, PKA_MontgomeryParamInTypeDef const * const in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_MontgomeryParam_IT(PKA_HandleTypeDef * const hpka, PKA_MontgomeryParamInTypeDef const * const in);
void HAL_PKA_MontgomeryParam_GetResult(PKA_HandleTypeDef const * const hpka, uint32_t * const pRes);


HAL_StatusTypeDef HAL_PKA_Abort(PKA_HandleTypeDef * const hpka);
void HAL_PKA_RAMReset(PKA_HandleTypeDef * const hpka);
void HAL_PKA_OperationCpltCallback(PKA_HandleTypeDef * const hpka);
void HAL_PKA_ErrorCallback(PKA_HandleTypeDef * const hpka);
void HAL_PKA_IRQHandler(PKA_HandleTypeDef * const hpka);
/**
  * @}
  */

/** @addtogroup PKA_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_PKA_StateTypeDef HAL_PKA_GetState(PKA_HandleTypeDef const * const hpka);
uint32_t             HAL_PKA_GetError(PKA_HandleTypeDef const * const hpka);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(PKA) && defined(HAL_PKA_MODULE_ENABLED) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32L4xx_HAL_PKA_H */
