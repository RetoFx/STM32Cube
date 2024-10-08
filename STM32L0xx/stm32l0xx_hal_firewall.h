/**
  ******************************************************************************
  * @file    stm32l0xx_hal_firewall.h
  * @author  MCD Application Team
  * @brief   Header file of FIREWALL HAL module.
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
#ifndef __STM32L0xx_HAL_FIREWALL_H
#define __STM32L0xx_HAL_FIREWALL_H

#ifdef __cplusplus
 extern "C" {
#endif

#if !defined (STM32L010xB) && !defined (STM32L010x8) && !defined (STM32L010x6) && !defined (STM32L010x4) && !defined (STM32L011xx) && !defined (STM32L021xx) && !defined (STM32L031xx) && !defined (STM32L041xx)

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal_def.h"

/** @addtogroup STM32L0xx_HAL_Driver
  * @{
  */

/** @defgroup FIREWALL  FIREWALL
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup FIREWALL_Exported_Types FIREWALL Exported Types
  * @{
  */

/**
  * @brief FIREWALL Initialization Structure definition
  */
typedef struct
{
  uint32_t CodeSegmentStartAddress;        /*!< Protected code segment start address. This value is 24-bit long, the 8 LSB bits are
                                                reserved and forced to 0 in order to allow a 256-byte granularity. */

  uint32_t CodeSegmentLength;              /*!< Protected code segment length in bytes. This value is 22-bit long, the 8 LSB bits are
                                                reserved and forced to 0 for the length to be a multiple of 256 bytes. */

  uint32_t NonVDataSegmentStartAddress;    /*!< Protected non-volatile data segment start address. This value is 24-bit long, the 8 LSB
                                                bits are reserved and forced to 0 in order to allow a 256-byte granularity. */

  uint32_t NonVDataSegmentLength;          /*!< Protected non-volatile data segment length in bytes. This value is 22-bit long, the 8 LSB
                                                bits are reserved and forced to 0 for the length to be a multiple of 256 bytes. */

  uint32_t VDataSegmentStartAddress;       /*!< Protected volatile data segment start address. This value is 17-bit long, the 6 LSB bits
                                                are reserved and forced to 0 in order to allow a 64-byte granularity. */

  uint32_t VDataSegmentLength;             /*!< Protected volatile data segment length in bytes. This value is 17-bit long, the 6 LSB
                                                bits are reserved and forced to 0 for the length to be a multiple of 64 bytes. */

  uint32_t VolatileDataExecution;          /*!< Set VDE bit specifying whether or not the volatile data segment can be executed.
                                                 When VDS = 1 (set by parameter VolatileDataShared), VDE bit has no meaning.
                                                This parameter can be a value of @ref FIREWALL_VolatileData_Executable */

  uint32_t VolatileDataShared;             /*!< Set VDS bit in specifying whether or not the volatile data segment can be shared with a
                                                non-protected application code.
                                                This parameter can be a value of @ref FIREWALL_VolatileData_Shared */

}FIREWALL_InitTypeDef;


/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/
/** @defgroup FIREWALL_Exported_Constants FIREWALL Exported Constants
  * @{
  */

/** @defgroup FIREWALL_VolatileData_Executable   FIREWALL volatile data segment execution status
  * @{
  */
#define FIREWALL_VOLATILEDATA_NOT_EXECUTABLE                 (0x0000U)
#define FIREWALL_VOLATILEDATA_EXECUTABLE                     FW_CR_VDE
/**
  * @}
  */

/** @defgroup FIREWALL_VolatileData_Shared  FIREWALL volatile data segment share status
  * @{
  */
#define FIREWALL_VOLATILEDATA_NOT_SHARED                (0x0000U)
#define FIREWALL_VOLATILEDATA_SHARED                    FW_CR_VDS
/**
  * @}
  */

/** @defgroup FIREWALL_Pre_Arm FIREWALL pre arm status
  * @{
  */
#define FIREWALL_PRE_ARM_RESET                 (0x0000U)
#define FIREWALL_PRE_ARM_SET                   FW_CR_FPA

/**
  * @}
  */

/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/** @addtogroup FIREWALL_Private
  * @{
  */
#define IS_FIREWALL_CODE_SEGMENT_ADDRESS(ADDRESS)        (((ADDRESS) >= FLASH_BASE) && ((ADDRESS) < (FLASH_BASE + FLASH_SIZE)))
#define IS_FIREWALL_CODE_SEGMENT_LENGTH(ADDRESS, LENGTH) (((ADDRESS) + (LENGTH)) <= (FLASH_BASE + FLASH_SIZE))

#define IS_FIREWALL_NONVOLATILEDATA_SEGMENT_ADDRESS(ADDRESS)        (((ADDRESS) >= FLASH_BASE) && ((ADDRESS) < (FLASH_BASE + FLASH_SIZE)))
#define IS_FIREWALL_NONVOLATILEDATA_SEGMENT_LENGTH(ADDRESS, LENGTH) (((ADDRESS) + (LENGTH)) <= (FLASH_BASE + FLASH_SIZE))

#define IS_FIREWALL_VOLATILEDATA_SEGMENT_ADDRESS(ADDRESS)        (((ADDRESS) >= SRAM_BASE) && ((ADDRESS) < (SRAM_BASE + SRAM_SIZE_MAX)))
#define IS_FIREWALL_VOLATILEDATA_SEGMENT_LENGTH(ADDRESS, LENGTH) (((ADDRESS) + (LENGTH)) <= (SRAM_BASE + SRAM_SIZE_MAX))


#define IS_FIREWALL_VOLATILEDATA_SHARE(SHARE) (((SHARE) == FIREWALL_VOLATILEDATA_NOT_SHARED) || \
                                               ((SHARE) == FIREWALL_VOLATILEDATA_SHARED))

#define IS_FIREWALL_VOLATILEDATA_EXECUTE(EXECUTE) (((EXECUTE) == FIREWALL_VOLATILEDATA_NOT_EXECUTABLE) || \
                                                   ((EXECUTE) == FIREWALL_VOLATILEDATA_EXECUTABLE))
/**
  * @}
  */


/* Exported macros -----------------------------------------------------------*/
/** @defgroup FIREWALL_Exported_Macros FIREWALL Exported Macros
  * @{
  */

/** @brief  Check whether the FIREWALL is enabled or not.
  * @retval FIREWALL enabling status (TRUE or FALSE).
  */
#define  __HAL_FIREWALL_IS_ENABLED()  HAL_IS_BIT_CLR(SYSCFG->CFGR2, SYSCFG_CFGR2_FWDISEN)


/** @brief Enable FIREWALL pre arm.
  * @note When FPA bit is set, any code executed outside the protected segment
  *       closes the Firewall, otherwise it generates a system reset.
  * @note This macro provides the same service as HAL_FIREWALL_EnablePreArmFlag() API
  *       but can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  */
#define __HAL_FIREWALL_PREARM_ENABLE()                                                 \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  SET_BIT(FIREWALL->CR, FW_CR_FPA) ;                                   \
                  /* Read bit back to ensure it is taken into account by Peripheral */ \
                  /* (introduce proper delay inside macro execution) */                \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_FPA) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0U)



/** @brief Disable FIREWALL pre arm.
  * @note When FPA bit is set, any code executed outside the protected segment
  *       closes the Firewall, otherwise, it generates a system reset.
  * @note This macro provides the same service as HAL_FIREWALL_DisablePreArmFlag() API
  *       but can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  */
#define __HAL_FIREWALL_PREARM_DISABLE()                                                \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  CLEAR_BIT(FIREWALL->CR, FW_CR_FPA) ;                                 \
                  /* Read bit back to ensure it is taken into account by Peripheral */ \
                  /* (introduce proper delay inside macro execution) */                \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_FPA) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0U)

/** @brief Enable volatile data sharing in setting VDS bit.
  * @note When VDS bit is set, the volatile data segment is shared with non-protected
  *       application code. It can be accessed whatever the Firewall state (opened or closed).
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  */
#define __HAL_FIREWALL_VOLATILEDATA_SHARED_ENABLE()                                    \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  SET_BIT(FIREWALL->CR, FW_CR_VDS) ;                                   \
                  /* Read bit back to ensure it is taken into account by Peripheral */ \
                  /* (introduce proper delay inside macro execution) */                \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDS) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0U)

/** @brief Disable volatile data sharing in resetting VDS bit.
  * @note When VDS bit is reset, the volatile data segment is not shared and cannot be
  *       hit by a non protected executable code when the Firewall is closed. If it is
  *       accessed in such a condition, a system reset is generated by the Firewall.
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  */
#define __HAL_FIREWALL_VOLATILEDATA_SHARED_DISABLE()                                   \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  CLEAR_BIT(FIREWALL->CR, FW_CR_VDS) ;                                 \
                  /* Read bit back to ensure it is taken into account by Peripheral */ \
                  /* (introduce proper delay inside macro execution) */                \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDS) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0U)

/** @brief Enable volatile data execution in setting VDE bit.
  * @note VDE bit is ignored when VDS is set. IF VDS = 1, the Volatile data segment can be
  *       executed whatever the VDE bit value.
  * @note When VDE bit is set (with VDS = 0), the volatile data segment is executable. When
  *       the Firewall call is closed, a "call gate" entry procedure is required to open
  *       first the Firewall.
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  */
#define __HAL_FIREWALL_VOLATILEDATA_EXECUTION_ENABLE()                                 \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  SET_BIT(FIREWALL->CR, FW_CR_VDE) ;                                   \
                  /* Read bit back to ensure it is taken into account by Peripheral */ \
                  /* (introduce proper delay inside macro execution) */                \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDE) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0U)

/** @brief Disable volatile data execution in resetting VDE bit.
  * @note VDE bit is ignored when VDS is set. IF VDS = 1, the Volatile data segment can be
  *       executed whatever the VDE bit value.
  * @note When VDE bit is reset (with VDS = 0), the volatile data segment cannot  be executed.
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  */
#define __HAL_FIREWALL_VOLATILEDATA_EXECUTION_DISABLE()                                \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  CLEAR_BIT(FIREWALL->CR, FW_CR_VDE) ;                                 \
                  /* Read bit back to ensure it is taken into account by Peripheral */ \
                  /* (introduce proper delay inside macro execution) */                \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDE) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0U)


/** @brief Check whether or not the volatile data segment is shared.
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  * @retval VDS bit setting status (TRUE or FALSE).
  */
#define __HAL_FIREWALL_GET_VOLATILEDATA_SHARED() ((FIREWALL->CR & FW_CR_VDS) == FW_CR_VDS)

/** @brief Check whether or not the volatile data segment is declared executable.
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  * @retval VDE bit setting status (TRUE or FALSE).
  */
#define __HAL_FIREWALL_GET_VOLATILEDATA_EXECUTION() ((FIREWALL->CR & FW_CR_VDE) == FW_CR_VDE)

/** @brief Check whether or not the Firewall pre arm bit is set.
  * @note This macro can be executed inside a code area protected by the Firewall.
  * @note This macro can be executed whatever the Firewall state (opened or closed) when
  *       NVDSL register is equal to 0. Otherwise (when NVDSL register is different from
  *       0, that is, when the non volatile data segment is defined), the macro can be
  *       executed only when the Firewall is opened.
  * @retval FPA bit setting status (TRUE or FALSE).
  */
#define __HAL_FIREWALL_GET_PREARM() ((FIREWALL->CR & FW_CR_FPA) == FW_CR_FPA)


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup FIREWALL_Exported_Functions FIREWALL Exported Functions
  * @{
  */

/** @defgroup FIREWALL_Exported_Functions_Group1 Initialization Functions
  * @brief    Initialization and Configuration Functions
  * @{
  */

/* Initialization functions  ********************************/
HAL_StatusTypeDef HAL_FIREWALL_Config(FIREWALL_InitTypeDef const * const fw_init);
void HAL_FIREWALL_GetConfig(FIREWALL_InitTypeDef * const fw_config);
void HAL_FIREWALL_EnableFirewall(void);
void HAL_FIREWALL_EnablePreArmFlag(void);
void HAL_FIREWALL_DisablePreArmFlag(void);

/**
  * @}
  */

/**
  * @}
  */
/* Define the private group ***********************************/
/**************************************************************/
/** @defgroup FIREWALL_Private FIREWALL Private
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


#endif /* #if !defined (STM32L010xB) && !defined (STM32L010x8) && !defined (STM32L010x6) && !defined (STM32L010x4) && !defined (STM32L011xx) && !defined (STM32L021xx) && !defined (STM32L031xx) && !defined (STM32L041xx) */

#ifdef __cplusplus
}
#endif

#endif /* __STM32L0xx_HAL_FIREWALL_H */
