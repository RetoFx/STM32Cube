/**
  ******************************************************************************
  * @file    stm32f2xx_hal_pwr_ex.c
  * @author  MCD Application Team
  * @brief   Extended PWR HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of PWR extension peripheral:
  *           + Peripheral Extended features functions
  *
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal.h"
/*lint -save -w1*/

/** @addtogroup STM32F2xx_HAL_Driver
  * @{
  */

/** @defgroup PWREx PWREx
  * @brief PWR HAL module driver
  * @{
  */

#ifdef HAL_PWR_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup PWREx_Private_Constants
  * @{
  */
#define PWR_BKPREG_TIMEOUT_VALUE     1000U
/**
  * @}
  */


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/** @defgroup PWREx_Exported_Functions PWR Exported Functions
  *  @{
  */

/** @defgroup PWREx_Exported_Functions_Group1 Peripheral Extended features functions
  *  @brief Peripheral Extended features functions
  *
@verbatim

 ===============================================================================
                 ##### Peripheral extended features functions #####
 ===============================================================================

    *** Main and Backup Regulators configuration ***
    ================================================
    [..]
      (+) The backup domain includes 4 Kbytes of backup SRAM accessible only from
          the CPU, and address in 32-bit, 16-bit or 8-bit mode. Its content is
          retained even in Standby or VBAT mode when the low power backup regulator
          is enabled. It can be considered as an internal EEPROM when VBAT is
          always present. You can use the HAL_PWREx_EnableBkUpReg() function to
          enable the low power backup regulator.

      (+) When the backup domain is supplied by VDD (analog switch connected to VDD)
          the backup SRAM is powered from VDD which replaces the VBAT power supply to
          save battery life.

      (+) The backup SRAM is not mass erased by a tamper event. It is read
          protected to prevent confidential data, such as cryptographic private
          key, from being accessed. The backup SRAM can be erased only through
          the Flash interface when a protection level change from level 1 to
          level 0 is requested.
      -@- Refer to the description of Read protection (RDP) in the Flash
          programming manual.

        Refer to the product datasheets for more details.

    *** FLASH Power Down configuration ****
    =======================================
    [..]
      (+) By setting the FPDS bit in the PWR_CR register by using the
          HAL_PWREx_EnableFlashPowerDown() function, the Flash memory also enters power
          down mode when the device enters Stop mode. When the Flash memory
          is in power down mode, an additional startup delay is incurred when
          waking up from Stop mode.

@endverbatim
  * @{
  */

/**
  * @brief Enables the Backup Regulator.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWREx_EnableBkUpReg(void)
{
  uint32_t tickstart = 0U;

  HAL_PERIPH_BIT_BAND_WRITE(PWR->CSR, BRE_BIT_NUMBER, ENABLE);

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Wait till Backup regulator ready flag is set */
  while(__HAL_PWR_GET_FLAG(PWR_FLAG_BRR) == RESET)
  {
    if((HAL_GetTick() - tickstart ) > PWR_BKPREG_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
  return HAL_OK;
}

/**
  * @brief Disables the Backup Regulator.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PWREx_DisableBkUpReg(void)
{
  uint32_t tickstart = 0U;

  HAL_PERIPH_BIT_BAND_WRITE(PWR->CSR, BRE_BIT_NUMBER, DISABLE);

  /* Get tick */
  tickstart = HAL_GetTick();

  /* Wait till Backup regulator ready flag is set */
  while(__HAL_PWR_GET_FLAG(PWR_FLAG_BRR) != RESET)
  {
    if((HAL_GetTick() - tickstart ) > PWR_BKPREG_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }
  return HAL_OK;
}

/**
  * @brief Enables the Flash Power Down in Stop mode.
  * @retval None
  */
void HAL_PWREx_EnableFlashPowerDown(void)
{
  HAL_PERIPH_BIT_BAND_WRITE(PWR->CR, FPDS_BIT_NUMBER, ENABLE);
}

/**
  * @brief Disables the Flash Power Down in Stop mode.
  * @retval None
  */
void HAL_PWREx_DisableFlashPowerDown(void)
{
  HAL_PERIPH_BIT_BAND_WRITE(PWR->CR, FPDS_BIT_NUMBER, DISABLE);
}

/**
  * @}
  */

/**
  * @}
  */
#endif /* HAL_PWR_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/*lint -restore*/
