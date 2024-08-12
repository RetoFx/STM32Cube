/**
  ******************************************************************************
  * @file    stm32u0xx_ll_i2c.h
  * @author  MCD Application Team
  * @brief   Header file of I2C LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U0xx_LL_I2C_H
#define STM32U0xx_LL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u0xx.h"

/** @addtogroup STM32U0xx_LL_Driver
  * @{
  */

#if defined (I2C1) || defined (I2C2) || defined (I2C3) || defined (I2C4)

/** @defgroup I2C_LL I2C
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2C_LL_Private_Constants I2C Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup I2C_LL_Private_Macros I2C Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup I2C_LL_ES_INIT I2C Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t Timing;              /*!< Specifies the SDA setup, hold time and the SCL high, low period values.
                                     This parameter must be set by referring to the STM32CubeMX Tool and
                                     the helper macro @ref __LL_I2C_CONVERT_TIMINGS().

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetTiming(). */

  uint32_t AnalogFilter;        /*!< Enables or disables analog noise filter.
                                     This parameter can be a value of @ref I2C_LL_EC_ANALOGFILTER_SELECTION.

                                     This feature can be modified afterwards using unitary functions
                                     @ref LL_I2C_EnableAnalogFilter() or LL_I2C_DisableAnalogFilter(). */

  uint32_t DigitalFilter;       /*!< Configures the digital noise filter.
                                     This parameter can be a number between Min_Data = 0x00U and Max_Data = 0x0FU.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetDigitalFilter(). */

  uint32_t OwnAddress1;         /*!< Specifies the device own address 1.
                                     This parameter must be a value between Min_Data = 0x00U and Max_Data = 0x3FFU.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetOwnAddress1(). */

  uint32_t TypeAcknowledge;     /*!< Specifies the ACKnowledge or Non ACKnowledge condition after the address receive
                                     match code or next received byte.
                                     This parameter can be a value of @ref I2C_LL_EC_I2C_ACKNOWLEDGE.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_AcknowledgeNextData(). */

  uint32_t OwnAddrSize;         /*!< Specifies the device own address 1 size (7-bit or 10-bit).
                                     This parameter can be a value of @ref I2C_LL_EC_OWNADDRESS1.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetOwnAddress1(). */
} LL_I2C_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_I2C_WriteReg function
  * @{
  */
#define LL_I2C_ICR_ADDRCF                   I2C_ICR_ADDRCF          /*!< Address Matched flag   */
#define LL_I2C_ICR_NACKCF                   I2C_ICR_NACKCF          /*!< Not Acknowledge flag   */
#define LL_I2C_ICR_STOPCF                   I2C_ICR_STOPCF          /*!< Stop detection flag    */
#define LL_I2C_ICR_BERRCF                   I2C_ICR_BERRCF          /*!< Bus error flag         */
#define LL_I2C_ICR_ARLOCF                   I2C_ICR_ARLOCF          /*!< Arbitration Lost flag  */
#define LL_I2C_ICR_OVRCF                    I2C_ICR_OVRCF           /*!< Overrun/Underrun flag  */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_I2C_ReadReg function
  * @{
  */
#define LL_I2C_ISR_TXE                      I2C_ISR_TXE             /*!< Transmit data register empty        */
#define LL_I2C_ISR_TXIS                     I2C_ISR_TXIS            /*!< Transmit interrupt status           */
#define LL_I2C_ISR_RXNE                     I2C_ISR_RXNE            /*!< Receive data register not empty     */
#define LL_I2C_ISR_ADDR                     I2C_ISR_ADDR            /*!< Address matched (slave mode)        */
#define LL_I2C_ISR_NACKF                    I2C_ISR_NACKF           /*!< Not Acknowledge received flag       */
#define LL_I2C_ISR_STOPF                    I2C_ISR_STOPF           /*!< Stop detection flag                 */
#define LL_I2C_ISR_TC                       I2C_ISR_TC              /*!< Transfer Complete (master mode)     */
#define LL_I2C_ISR_TCR                      I2C_ISR_TCR             /*!< Transfer Complete Reload            */
#define LL_I2C_ISR_BERR                     I2C_ISR_BERR            /*!< Bus error                           */
#define LL_I2C_ISR_ARLO                     I2C_ISR_ARLO            /*!< Arbitration lost                    */
#define LL_I2C_ISR_OVR                      I2C_ISR_OVR             /*!< Overrun/Underrun (slave mode)       */
#define LL_I2C_ISR_BUSY                     I2C_ISR_BUSY            /*!< Bus busy                            */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_I2C_ReadReg and  LL_I2C_WriteReg functions
  * @{
  */
#define LL_I2C_CR1_TXIE                     I2C_CR1_TXIE            /*!< TX Interrupt enable                         */
#define LL_I2C_CR1_RXIE                     I2C_CR1_RXIE            /*!< RX Interrupt enable                         */
#define LL_I2C_CR1_ADDRIE                   I2C_CR1_ADDRIE          /*!< Address match Interrupt enable (slave only) */
#define LL_I2C_CR1_NACKIE                   I2C_CR1_NACKIE          /*!< Not acknowledge received Interrupt enable   */
#define LL_I2C_CR1_STOPIE                   I2C_CR1_STOPIE          /*!< STOP detection Interrupt enable             */
#define LL_I2C_CR1_TCIE                     I2C_CR1_TCIE            /*!< Transfer Complete interrupt enable          */
#define LL_I2C_CR1_ERRIE                    I2C_CR1_ERRIE           /*!< Error interrupts enable                     */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ANALOGFILTER_SELECTION Analog Filter Selection
  * @{
  */
#define LL_I2C_ANALOGFILTER_ENABLE          0x00000000UL             /*!< Analog filter is enabled.  */
#define LL_I2C_ANALOGFILTER_DISABLE         I2C_CR1_ANFOFF          /*!< Analog filter is disabled. */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ADDRESSING_MODE Master Addressing Mode
  * @{
  */
#define LL_I2C_ADDRESSING_MODE_7BIT         0x00000000UL              /*!< Master operates in 7-bit addressing mode. */
#define LL_I2C_ADDRESSING_MODE_10BIT        I2C_CR2_ADD10            /*!< Master operates in 10-bit addressing mode.*/
/**
  * @}
  */

/** @defgroup I2C_LL_EC_OWNADDRESS1 Own Address 1 Length
  * @{
  */
#define LL_I2C_OWNADDRESS1_7BIT             0x00000000UL             /*!< Own address 1 is a 7-bit address. */
#define LL_I2C_OWNADDRESS1_10BIT            I2C_OAR1_OA1MODE        /*!< Own address 1 is a 10-bit address.*/
/**
  * @}
  */

/** @defgroup I2C_LL_EC_OWNADDRESS2 Own Address 2 Masks
  * @{
  */
#define LL_I2C_OWNADDRESS2_NOMASK           I2C_OAR2_OA2NOMASK      /*!< Own Address2 No mask.                 */
#define LL_I2C_OWNADDRESS2_MASK01           I2C_OAR2_OA2MASK01      /*!< Only Address2 bits[7:2] are compared. */
#define LL_I2C_OWNADDRESS2_MASK02           I2C_OAR2_OA2MASK02      /*!< Only Address2 bits[7:3] are compared. */
#define LL_I2C_OWNADDRESS2_MASK03           I2C_OAR2_OA2MASK03      /*!< Only Address2 bits[7:4] are compared. */
#define LL_I2C_OWNADDRESS2_MASK04           I2C_OAR2_OA2MASK04      /*!< Only Address2 bits[7:5] are compared. */
#define LL_I2C_OWNADDRESS2_MASK05           I2C_OAR2_OA2MASK05      /*!< Only Address2 bits[7:6] are compared. */
#define LL_I2C_OWNADDRESS2_MASK06           I2C_OAR2_OA2MASK06      /*!< Only Address2 bits[7U] are compared.   */
#define LL_I2C_OWNADDRESS2_MASK07           I2C_OAR2_OA2MASK07      /*!< No comparison is done.
                                                                         All Address2 are acknowledged.        */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_I2C_ACKNOWLEDGE Acknowledge Generation
  * @{
  */
#define LL_I2C_ACK                          0x00000000UL              /*!< ACK is sent after current received byte. */
#define LL_I2C_NACK                         I2C_CR2_NACK             /*!< NACK is sent after current received byte.*/
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ADDRSLAVE Slave Address Length
  * @{
  */
#define LL_I2C_ADDRSLAVE_7BIT               0x00000000UL              /*!< Slave Address in 7-bit. */
#define LL_I2C_ADDRSLAVE_10BIT              I2C_CR2_ADD10            /*!< Slave Address in 10-bit.*/
/**
  * @}
  */

/** @defgroup I2C_LL_EC_REQUEST Transfer Request Direction
  * @{
  */
#define LL_I2C_REQUEST_WRITE                0x00000000UL              /*!< Master request a write transfer. */
#define LL_I2C_REQUEST_READ                 I2C_CR2_RD_WRN           /*!< Master request a read transfer.  */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_MODE Transfer End Mode
  * @{
  */
#define LL_I2C_MODE_RELOAD                  I2C_CR2_RELOAD           /*!< Enable I2C Reload mode.     */
#define LL_I2C_MODE_AUTOEND                 I2C_CR2_AUTOEND          /*!< Enable I2C Automatic end mode
                                                                          with no HW PEC comparison.  */
#define LL_I2C_MODE_SOFTEND                 0x00000000UL              /*!< Enable I2C Software end mode
                                                                          with no HW PEC comparison.  */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_GENERATE Start And Stop Generation
  * @{
  */
#define LL_I2C_GENERATE_NOSTARTSTOP         0x00000000UL
/*!< Don't Generate Stop and Start condition. */
#define LL_I2C_GENERATE_STOP                (uint32_t)(0x80000000UL | I2C_CR2_STOP)
/*!< Generate Stop condition (Size should be set to 0).      */
#define LL_I2C_GENERATE_START_READ          (uint32_t)(0x80000000UL | I2C_CR2_START | I2C_CR2_RD_WRN)
/*!< Generate Start for read request. */
#define LL_I2C_GENERATE_START_WRITE         (uint32_t)(0x80000000UL | I2C_CR2_START)
/*!< Generate Start for write request. */
#define LL_I2C_GENERATE_RESTART_7BIT_READ   (uint32_t)(0x80000000UL | I2C_CR2_START | I2C_CR2_RD_WRN)
/*!< Generate Restart for read request, slave 7Bit address.  */
#define LL_I2C_GENERATE_RESTART_7BIT_WRITE  (uint32_t)(0x80000000UL | I2C_CR2_START)
/*!< Generate Restart for write request, slave 7Bit address. */
#define LL_I2C_GENERATE_RESTART_10BIT_READ  (uint32_t)(0x80000000UL | I2C_CR2_START | \
                                                       I2C_CR2_RD_WRN | I2C_CR2_HEAD10R)
/*!< Generate Restart for read request, slave 10Bit address. */
#define LL_I2C_GENERATE_RESTART_10BIT_WRITE (uint32_t)(0x80000000UL | I2C_CR2_START)
/*!< Generate Restart for write request, slave 10Bit address.*/
/**
  * @}
  */

/** @defgroup I2C_LL_EC_DIRECTION Read Write Direction
  * @{
  */
#define LL_I2C_DIRECTION_WRITE              0x00000000UL              /*!< Write transfer request by master,
                                                                          slave enters receiver mode.  */
#define LL_I2C_DIRECTION_READ               I2C_ISR_DIR              /*!< Read transfer request by master,
                                                                          slave enters transmitter mode.*/
/**
  * @}
  */

/** @defgroup I2C_LL_EC_DMA_REG_DATA DMA Register Data
  * @{
  */
#define LL_I2C_DMA_REG_DATA_TRANSMIT        0x00000000UL              /*!< Get address of data register used for
                                                                          transmission */
#define LL_I2C_DMA_REG_DATA_RECEIVE         0x00000001UL              /*!< Get address of data register used for
                                                                          reception */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Macros I2C Exported Macros
  * @{
  */

/** @defgroup I2C_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in I2C register
  * @param  __INSTANCE__ I2C Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_I2C_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in I2C register
  * @param  __INSTANCE__ I2C Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_I2C_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup I2C_LL_EM_CONVERT_TIMINGS Convert SDA SCL timings
  * @{
  */
/**
  * @brief  Configure the SDA setup, hold time and the SCL high, low period.
  * @param  __PRESCALER__ This parameter must be a value between  Min_Data=0 and Max_Data=0xFU.
  * @param  __SETUP_TIME__ This parameter must be a value between Min_Data=0 and Max_Data=0xFU.
                           (tscldel = (SCLDEL+1)xtpresc)
  * @param  __HOLD_TIME__  This parameter must be a value between Min_Data=0 and Max_Data=0xFU.
                           (tsdadel = SDADELxtpresc)
  * @param  __SCLH_PERIOD__ This parameter must be a value between Min_Data=0 and Max_Data=0xFFU.
                            (tsclh = (SCLH+1)xtpresc)
  * @param  __SCLL_PERIOD__ This parameter must be a value between  Min_Data=0 and Max_Data=0xFFU.
                            (tscll = (SCLL+1)xtpresc)
  * @retval Value between Min_Data=0 and Max_Data=0xFFFFFFFFUL
  */
#define __LL_I2C_CONVERT_TIMINGS(__PRESCALER__, __SETUP_TIME__, __HOLD_TIME__, __SCLH_PERIOD__, __SCLL_PERIOD__) \
  ((((uint32_t)(__PRESCALER__)    << I2C_TIMINGR_PRESC_Pos)  & I2C_TIMINGR_PRESC)   | \
   (((uint32_t)(__SETUP_TIME__)   << I2C_TIMINGR_SCLDEL_Pos) & I2C_TIMINGR_SCLDEL)  | \
   (((uint32_t)(__HOLD_TIME__)    << I2C_TIMINGR_SDADEL_Pos) & I2C_TIMINGR_SDADEL)  | \
   (((uint32_t)(__SCLH_PERIOD__)  << I2C_TIMINGR_SCLH_Pos)   & I2C_TIMINGR_SCLH)    | \
   (((uint32_t)(__SCLL_PERIOD__)  << I2C_TIMINGR_SCLL_Pos)   & I2C_TIMINGR_SCLL))
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Functions I2C Exported Functions
  * @{
  */

/** @defgroup I2C_LL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Enable I2C peripheral (PE = 1).
  * @rmtoll CR1          PE            LL_I2C_Enable
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_Enable(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_PE);
}

/**
  * @brief  Disable I2C peripheral (PE = 0).
  * @note   When PE = 0, the I2C SCL and SDA lines are released.
  *         Internal state machines and status bits are put back to their reset value.
  *         When cleared, PE must be kept low for at least 3 APB clock cycles.
  * @rmtoll CR1          PE            LL_I2C_Disable
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_Disable(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_PE);
}

/**
  * @brief  Check if the I2C peripheral is enabled or disabled.
  * @rmtoll CR1          PE            LL_I2C_IsEnabled
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabled(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_PE) == (I2C_CR1_PE)) ? 1UL : 0UL);
}

/**
  * @brief  Configure Noise Filters (Analog and Digital).
  * @note   If the analog filter is also enabled, the digital filter is added to analog filter.
  *         The filters can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll CR1          ANFOFF        LL_I2C_ConfigFilters\n
  *         CR1          DNF           LL_I2C_ConfigFilters
  * @param  I2Cx I2C Instance.
  * @param  AnalogFilter This parameter can be one of the following values:
  *         @arg @ref LL_I2C_ANALOGFILTER_ENABLE
  *         @arg @ref LL_I2C_ANALOGFILTER_DISABLE
  * @param  DigitalFilter This parameter must be a value between Min_Data=0x00U (Digital filter disabled)
                          and Max_Data=0x0FU (Digital filter enabled and filtering capability up to 15*ti2cclk).
  *         This parameter is used to configure the digital noise filter on SDA and SCL input.
  *         The digital filter will filter spikes with a length of up to DNF[3:0]*ti2cclk.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ConfigFilters(I2C_TypeDef * const I2Cx, uint32_t AnalogFilter, uint32_t DigitalFilter)
{
  MODIFY_REG(I2Cx->CR1, I2C_CR1_ANFOFF | I2C_CR1_DNF, AnalogFilter | (DigitalFilter << I2C_CR1_DNF_Pos));
}

/**
  * @brief  Configure Digital Noise Filter.
  * @note   If the analog filter is also enabled, the digital filter is added to analog filter.
  *         This filter can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll CR1          DNF           LL_I2C_SetDigitalFilter
  * @param  I2Cx I2C Instance.
  * @param  DigitalFilter This parameter must be a value between Min_Data=0x00U (Digital filter disabled)
                          and Max_Data=0x0FU (Digital filter enabled and filtering capability up to 15*ti2cclk).
  *         This parameter is used to configure the digital noise filter on SDA and SCL input.
  *         The digital filter will filter spikes with a length of up to DNF[3:0]*ti2cclk.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetDigitalFilter(I2C_TypeDef * const I2Cx, uint32_t DigitalFilter)
{
  MODIFY_REG(I2Cx->CR1, I2C_CR1_DNF, DigitalFilter << I2C_CR1_DNF_Pos);
}

/**
  * @brief  Get the current Digital Noise Filter configuration.
  * @rmtoll CR1          DNF           LL_I2C_GetDigitalFilter
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0U and Max_Data=0xFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetDigitalFilter(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR1, I2C_CR1_DNF) >> I2C_CR1_DNF_Pos);
}

/**
  * @brief  Enable Analog Noise Filter.
  * @note   This filter can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll CR1          ANFOFF        LL_I2C_EnableAnalogFilter
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableAnalogFilter(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ANFOFF);
}

/**
  * @brief  Disable Analog Noise Filter.
  * @note   This filter can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll CR1          ANFOFF        LL_I2C_DisableAnalogFilter
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableAnalogFilter(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ANFOFF);
}

/**
  * @brief  Check if Analog Noise Filter is enabled or disabled.
  * @rmtoll CR1          ANFOFF        LL_I2C_IsEnabledAnalogFilter
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledAnalogFilter(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_ANFOFF) != (I2C_CR1_ANFOFF)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA transmission requests.
  * @rmtoll CR1          TXDMAEN       LL_I2C_EnableDMAReq_TX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableDMAReq_TX(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_TXDMAEN);
}

/**
  * @brief  Disable DMA transmission requests.
  * @rmtoll CR1          TXDMAEN       LL_I2C_DisableDMAReq_TX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableDMAReq_TX(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_TXDMAEN);
}

/**
  * @brief  Check if DMA transmission requests are enabled or disabled.
  * @rmtoll CR1          TXDMAEN       LL_I2C_IsEnabledDMAReq_TX
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledDMAReq_TX(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_TXDMAEN) == (I2C_CR1_TXDMAEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA reception requests.
  * @rmtoll CR1          RXDMAEN       LL_I2C_EnableDMAReq_RX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableDMAReq_RX(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_RXDMAEN);
}

/**
  * @brief  Disable DMA reception requests.
  * @rmtoll CR1          RXDMAEN       LL_I2C_DisableDMAReq_RX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableDMAReq_RX(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_RXDMAEN);
}

/**
  * @brief  Check if DMA reception requests are enabled or disabled.
  * @rmtoll CR1          RXDMAEN       LL_I2C_IsEnabledDMAReq_RX
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledDMAReq_RX(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_RXDMAEN) == (I2C_CR1_RXDMAEN)) ? 1UL : 0UL);
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @rmtoll TXDR         TXDATA        LL_I2C_DMA_GetRegAddr\n
  *         RXDR         RXDATA        LL_I2C_DMA_GetRegAddr
  * @param  I2Cx I2C Instance
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref LL_I2C_DMA_REG_DATA_TRANSMIT
  *         @arg @ref LL_I2C_DMA_REG_DATA_RECEIVE
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t LL_I2C_DMA_GetRegAddr(I2C_TypeDef const * const I2Cx, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == LL_I2C_DMA_REG_DATA_TRANSMIT)
  {
    /* return address of TXDR register */
    data_reg_addr = (uint32_t) &(I2Cx->TXDR);
  }
  else
  {
    /* return address of RXDR register */
    data_reg_addr = (uint32_t) &(I2Cx->RXDR);
  }

  return data_reg_addr;
}

/**
  * @brief  Enable Clock stretching.
  * @note   This bit can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll CR1          NOSTRETCH     LL_I2C_EnableClockStretching
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableClockStretching(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_NOSTRETCH);
}

/**
  * @brief  Disable Clock stretching.
  * @note   This bit can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll CR1          NOSTRETCH     LL_I2C_DisableClockStretching
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableClockStretching(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_NOSTRETCH);
}

/**
  * @brief  Check if Clock stretching is enabled or disabled.
  * @rmtoll CR1          NOSTRETCH     LL_I2C_IsEnabledClockStretching
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledClockStretching(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_NOSTRETCH) != (I2C_CR1_NOSTRETCH)) ? 1UL : 0UL);
}

#if defined(I2C_CR1_WUPEN)
/**
  * @brief  Enable Wakeup from STOP.
  * @note   The macro IS_I2C_WAKEUP_FROMSTOP_INSTANCE(I2Cx) can be used to check whether or not
  *         WakeUpFromStop feature is supported by the I2Cx Instance.
  * @note   This bit can only be programmed when Digital Filter is disabled.
  * @rmtoll CR1          WUPEN         LL_I2C_EnableWakeUpFromStop
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableWakeUpFromStop(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_WUPEN);
}

/**
  * @brief  Disable Wakeup from STOP.
  * @note   The macro IS_I2C_WAKEUP_FROMSTOP_INSTANCE(I2Cx) can be used to check whether or not
  *         WakeUpFromStop feature is supported by the I2Cx Instance.
  * @rmtoll CR1          WUPEN         LL_I2C_DisableWakeUpFromStop
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableWakeUpFromStop(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_WUPEN);
}

/**
  * @brief  Check if Wakeup from STOP is enabled or disabled.
  * @note   The macro IS_I2C_WAKEUP_FROMSTOP_INSTANCE(I2Cx) can be used to check whether or not
  *         WakeUpFromStop feature is supported by the I2Cx Instance.
  * @rmtoll CR1          WUPEN         LL_I2C_IsEnabledWakeUpFromStop
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledWakeUpFromStop(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_WUPEN) == (I2C_CR1_WUPEN)) ? 1UL : 0UL);
}

#endif /* I2C_CR1_WUPEN */
/**
  * @brief  Enable General Call.
  * @note   When enabled the Address 0x00U is ACKed.
  * @rmtoll CR1          GCEN          LL_I2C_EnableGeneralCall
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableGeneralCall(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_GCEN);
}

/**
  * @brief  Disable General Call.
  * @note   When disabled the Address 0x00U is NACKed.
  * @rmtoll CR1          GCEN          LL_I2C_DisableGeneralCall
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableGeneralCall(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_GCEN);
}

/**
  * @brief  Check if General Call is enabled or disabled.
  * @rmtoll CR1          GCEN          LL_I2C_IsEnabledGeneralCall
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledGeneralCall(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_GCEN) == (I2C_CR1_GCEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable I2C Fast Mode Plus (FMP = 1).
  * @note   20mA I/O drive enable
  * @rmtoll CR1          FMP           LL_I2C_EnableFastModePlus
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableFastModePlus(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_FMP);
}

/**
  * @brief  Disable I2C Fast Mode Plus (FMP = 0).
  * @note   20mA I/O drive disable
  * @rmtoll CR1          FMP           LL_I2C_DisableFastModePlus
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableFastModePlus(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_FMP);
}

/**
  * @brief  Check if the I2C Fast Mode Plus is enabled or disabled.
  * @rmtoll CR1          FMP           LL_I2C_IsEnabledFastModePlus
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledFastModePlus(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_FMP) == (I2C_CR1_FMP)) ? 1UL : 0UL);
}

/**
  * @brief  Enable automatic clear of ADDR flag.
  * @rmtoll CR1          ADDRACLR      LL_I2C_EnableAutoClearFlag_ADDR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableAutoClearFlag_ADDR(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ADDRACLR);
}

/**
  * @brief  Disable automatic clear of ADDR flag.
  * @rmtoll CR1          ADDRACLR      LL_I2C_DisableAutoClearFlag_ADDR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableAutoClearFlag_ADDR(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ADDRACLR);
}

/**
  * @brief  Check if the automatic clear of ADDR flag is enabled or disabled.
  * @rmtoll CR1          ADDRACLR      LL_I2C_IsEnabledAutoClearFlag_ADDR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledAutoClearFlag_ADDR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_ADDRACLR) == (I2C_CR1_ADDRACLR)) ? 1UL : 0UL);
}

/**
  * @brief  Enable automatic clear of STOP flag.
  * @rmtoll CR1          STOPFACLR     LL_I2C_EnableAutoClearFlag_STOP
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableAutoClearFlag_STOP(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_STOPFACLR);
}

/**
  * @brief  Disable automatic clear of STOP flag.
  * @rmtoll CR1          STOPFACLR     LL_I2C_DisableAutoClearFlag_STOP
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableAutoClearFlag_STOP(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_STOPFACLR);
}

/**
  * @brief  Check if the automatic clear of STOP flag is enabled or disabled.
  * @rmtoll CR1          STOPFACLR     LL_I2C_IsEnabledAutoClearFlag_STOP
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledAutoClearFlag_STOP(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_STOPFACLR) == (I2C_CR1_STOPFACLR)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the Master to operate in 7-bit or 10-bit addressing mode.
  * @note   Changing this bit is not allowed, when the START bit is set.
  * @rmtoll CR2          ADD10         LL_I2C_SetMasterAddressingMode
  * @param  I2Cx I2C Instance.
  * @param  AddressingMode This parameter can be one of the following values:
  *         @arg @ref LL_I2C_ADDRESSING_MODE_7BIT
  *         @arg @ref LL_I2C_ADDRESSING_MODE_10BIT
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetMasterAddressingMode(I2C_TypeDef * const I2Cx, uint32_t AddressingMode)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_ADD10, AddressingMode);
}

/**
  * @brief  Get the Master addressing mode.
  * @rmtoll CR2          ADD10         LL_I2C_GetMasterAddressingMode
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_ADDRESSING_MODE_7BIT
  *         @arg @ref LL_I2C_ADDRESSING_MODE_10BIT
  */
__STATIC_INLINE uint32_t LL_I2C_GetMasterAddressingMode(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_ADD10));
}

/**
  * @brief  Set the Own Address1.
  * @rmtoll OAR1         OA1           LL_I2C_SetOwnAddress1\n
  *         OAR1         OA1MODE       LL_I2C_SetOwnAddress1
  * @param  I2Cx I2C Instance.
  * @param  OwnAddress1 This parameter must be a value between Min_Data=0 and Max_Data=0x3FFU.
  * @param  OwnAddrSize This parameter can be one of the following values:
  *         @arg @ref LL_I2C_OWNADDRESS1_7BIT
  *         @arg @ref LL_I2C_OWNADDRESS1_10BIT
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetOwnAddress1(I2C_TypeDef * const I2Cx, uint32_t OwnAddress1, uint32_t OwnAddrSize)
{
  MODIFY_REG(I2Cx->OAR1, I2C_OAR1_OA1 | I2C_OAR1_OA1MODE, OwnAddress1 | OwnAddrSize);
}

/**
  * @brief  Enable acknowledge on Own Address1 match address.
  * @rmtoll OAR1         OA1EN         LL_I2C_EnableOwnAddress1
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableOwnAddress1(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->OAR1, I2C_OAR1_OA1EN);
}

/**
  * @brief  Disable acknowledge on Own Address1 match address.
  * @rmtoll OAR1         OA1EN         LL_I2C_DisableOwnAddress1
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableOwnAddress1(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->OAR1, I2C_OAR1_OA1EN);
}

/**
  * @brief  Check if Own Address1 acknowledge is enabled or disabled.
  * @rmtoll OAR1         OA1EN         LL_I2C_IsEnabledOwnAddress1
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledOwnAddress1(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->OAR1, I2C_OAR1_OA1EN) == (I2C_OAR1_OA1EN)) ? 1UL : 0UL);
}

/**
  * @brief  Set the 7bits Own Address2.
  * @note   This action has no effect if own address2 is enabled.
  * @rmtoll OAR2         OA2           LL_I2C_SetOwnAddress2\n
  *         OAR2         OA2MSK        LL_I2C_SetOwnAddress2
  * @param  I2Cx I2C Instance.
  * @param  OwnAddress2 Value between Min_Data=0 and Max_Data=0x7FU.
  * @param  OwnAddrMask This parameter can be one of the following values:
  *         @arg @ref LL_I2C_OWNADDRESS2_NOMASK
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK01
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK02
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK03
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK04
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK05
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK06
  *         @arg @ref LL_I2C_OWNADDRESS2_MASK07
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetOwnAddress2(I2C_TypeDef * const I2Cx, uint32_t OwnAddress2, uint32_t OwnAddrMask)
{
  MODIFY_REG(I2Cx->OAR2, I2C_OAR2_OA2 | I2C_OAR2_OA2MSK, OwnAddress2 | OwnAddrMask);
}

/**
  * @brief  Enable acknowledge on Own Address2 match address.
  * @rmtoll OAR2         OA2EN         LL_I2C_EnableOwnAddress2
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableOwnAddress2(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->OAR2, I2C_OAR2_OA2EN);
}

/**
  * @brief  Disable  acknowledge on Own Address2 match address.
  * @rmtoll OAR2         OA2EN         LL_I2C_DisableOwnAddress2
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableOwnAddress2(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->OAR2, I2C_OAR2_OA2EN);
}

/**
  * @brief  Check if Own Address1 acknowledge is enabled or disabled.
  * @rmtoll OAR2         OA2EN         LL_I2C_IsEnabledOwnAddress2
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledOwnAddress2(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->OAR2, I2C_OAR2_OA2EN) == (I2C_OAR2_OA2EN)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the SDA setup, hold time and the SCL high, low period.
  * @note   This bit can only be programmed when the I2C is disabled (PE = 0).
  * @rmtoll TIMINGR      TIMINGR       LL_I2C_SetTiming
  * @param  I2Cx I2C Instance.
  * @param  Timing This parameter must be a value between Min_Data=0 and Max_Data=0xFFFFFFFFUL.
  * @note   This parameter is computed with the STM32CubeMX Tool.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetTiming(I2C_TypeDef * const I2Cx, uint32_t Timing)
{
  WRITE_REG(I2Cx->TIMINGR, Timing);
}

/**
  * @brief  Get the Timing Prescaler setting.
  * @rmtoll TIMINGR      PRESC         LL_I2C_GetTimingPrescaler
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0U and Max_Data=0xFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetTimingPrescaler(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_PRESC) >> I2C_TIMINGR_PRESC_Pos);
}

/**
  * @brief  Get the SCL low period setting.
  * @rmtoll TIMINGR      SCLL          LL_I2C_GetClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00U and Max_Data=0xFFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetClockLowPeriod(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLL) >> I2C_TIMINGR_SCLL_Pos);
}

/**
  * @brief  Get the SCL high period setting.
  * @rmtoll TIMINGR      SCLH          LL_I2C_GetClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00U and Max_Data=0xFFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetClockHighPeriod(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLH) >> I2C_TIMINGR_SCLH_Pos);
}

/**
  * @brief  Get the SDA hold time.
  * @rmtoll TIMINGR      SDADEL        LL_I2C_GetDataHoldTime
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0U and Max_Data=0xFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetDataHoldTime(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SDADEL) >> I2C_TIMINGR_SDADEL_Pos);
}

/**
  * @brief  Get the SDA setup time.
  * @rmtoll TIMINGR      SCLDEL        LL_I2C_GetDataSetupTime
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0U and Max_Data=0xFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetDataSetupTime(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TIMINGR, I2C_TIMINGR_SCLDEL) >> I2C_TIMINGR_SCLDEL_Pos);
}

/**
  * @}
  */

/** @defgroup I2C_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable TXIS interrupt.
  * @rmtoll CR1          TXIE          LL_I2C_EnableIT_TX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_TX(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_TXIE);
}

/**
  * @brief  Disable TXIS interrupt.
  * @rmtoll CR1          TXIE          LL_I2C_DisableIT_TX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_TX(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_TXIE);
}

/**
  * @brief  Check if the TXIS Interrupt is enabled or disabled.
  * @rmtoll CR1          TXIE          LL_I2C_IsEnabledIT_TX
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_TX(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_TXIE) == (I2C_CR1_TXIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable RXNE interrupt.
  * @rmtoll CR1          RXIE          LL_I2C_EnableIT_RX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_RX(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_RXIE);
}

/**
  * @brief  Disable RXNE interrupt.
  * @rmtoll CR1          RXIE          LL_I2C_DisableIT_RX
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_RX(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_RXIE);
}

/**
  * @brief  Check if the RXNE Interrupt is enabled or disabled.
  * @rmtoll CR1          RXIE          LL_I2C_IsEnabledIT_RX
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_RX(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_RXIE) == (I2C_CR1_RXIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Address match interrupt (slave mode only).
  * @rmtoll CR1          ADDRIE        LL_I2C_EnableIT_ADDR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_ADDR(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ADDRIE);
}

/**
  * @brief  Disable Address match interrupt (slave mode only).
  * @rmtoll CR1          ADDRIE        LL_I2C_DisableIT_ADDR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_ADDR(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ADDRIE);
}

/**
  * @brief  Check if Address match interrupt is enabled or disabled.
  * @rmtoll CR1          ADDRIE        LL_I2C_IsEnabledIT_ADDR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_ADDR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_ADDRIE) == (I2C_CR1_ADDRIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Not acknowledge received interrupt.
  * @rmtoll CR1          NACKIE        LL_I2C_EnableIT_NACK
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_NACK(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_NACKIE);
}

/**
  * @brief  Disable Not acknowledge received interrupt.
  * @rmtoll CR1          NACKIE        LL_I2C_DisableIT_NACK
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_NACK(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_NACKIE);
}

/**
  * @brief  Check if Not acknowledge received interrupt is enabled or disabled.
  * @rmtoll CR1          NACKIE        LL_I2C_IsEnabledIT_NACK
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_NACK(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_NACKIE) == (I2C_CR1_NACKIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable STOP detection interrupt.
  * @rmtoll CR1          STOPIE        LL_I2C_EnableIT_STOP
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_STOP(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_STOPIE);
}

/**
  * @brief  Disable STOP detection interrupt.
  * @rmtoll CR1          STOPIE        LL_I2C_DisableIT_STOP
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_STOP(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_STOPIE);
}

/**
  * @brief  Check if STOP detection interrupt is enabled or disabled.
  * @rmtoll CR1          STOPIE        LL_I2C_IsEnabledIT_STOP
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_STOP(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_STOPIE) == (I2C_CR1_STOPIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Transfer Complete interrupt.
  * @note   Any of these events will generate interrupt :
  *         Transfer Complete (TC)
  *         Transfer Complete Reload (TCR)
  * @rmtoll CR1          TCIE          LL_I2C_EnableIT_TC
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_TC(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_TCIE);
}

/**
  * @brief  Disable Transfer Complete interrupt.
  * @note   Any of these events will generate interrupt :
  *         Transfer Complete (TC)
  *         Transfer Complete Reload (TCR)
  * @rmtoll CR1          TCIE          LL_I2C_DisableIT_TC
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_TC(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_TCIE);
}

/**
  * @brief  Check if Transfer Complete interrupt is enabled or disabled.
  * @rmtoll CR1          TCIE          LL_I2C_IsEnabledIT_TC
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_TC(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_TCIE) == (I2C_CR1_TCIE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable Error interrupts.
  * @note   Any of these errors will generate interrupt :
  *         Arbitration Loss (ARLO)
  *         Bus Error detection (BERR)
  *         Overrun/Underrun (OVR)
  * @rmtoll CR1          ERRIE         LL_I2C_EnableIT_ERR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableIT_ERR(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR1, I2C_CR1_ERRIE);
}

/**
  * @brief  Disable Error interrupts.
  * @note   Any of these errors will generate interrupt :
  *         Arbitration Loss (ARLO)
  *         Bus Error detection (BERR)
  *         Overrun/Underrun (OVR)
  * @rmtoll CR1          ERRIE         LL_I2C_DisableIT_ERR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableIT_ERR(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR1, I2C_CR1_ERRIE);
}

/**
  * @brief  Check if Error interrupts are enabled or disabled.
  * @rmtoll CR1          ERRIE         LL_I2C_IsEnabledIT_ERR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledIT_ERR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR1, I2C_CR1_ERRIE) == (I2C_CR1_ERRIE)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C_LL_EF_FLAG_management FLAG_management
  * @{
  */

/**
  * @brief  Indicate the status of Transmit data register empty flag.
  * @note   RESET: When next data is written in Transmit data register.
  *         SET: When Transmit data register is empty.
  * @rmtoll ISR          TXE           LL_I2C_IsActiveFlag_TXE
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TXE(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_TXE) == (I2C_ISR_TXE)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Transmit interrupt flag.
  * @note   RESET: When next data is written in Transmit data register.
  *         SET: When Transmit data register is empty.
  * @rmtoll ISR          TXIS          LL_I2C_IsActiveFlag_TXIS
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TXIS(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_TXIS) == (I2C_ISR_TXIS)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Receive data register not empty flag.
  * @note   RESET: When Receive data register is read.
  *         SET: When the received data is copied in Receive data register.
  * @rmtoll ISR          RXNE          LL_I2C_IsActiveFlag_RXNE
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RXNE(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_RXNE) == (I2C_ISR_RXNE)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Address matched flag (slave mode).
  * @note   RESET: Clear default value.
  *         SET: When the received slave address matched with one of the enabled slave address.
  * @rmtoll ISR          ADDR          LL_I2C_IsActiveFlag_ADDR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_ADDR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_ADDR) == (I2C_ISR_ADDR)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Not Acknowledge received flag.
  * @note   RESET: Clear default value.
  *         SET: When a NACK is received after a byte transmission.
  * @rmtoll ISR          NACKF         LL_I2C_IsActiveFlag_NACK
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_NACK(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_NACKF) == (I2C_ISR_NACKF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Stop detection flag.
  * @note   RESET: Clear default value.
  *         SET: When a Stop condition is detected.
  * @rmtoll ISR          STOPF         LL_I2C_IsActiveFlag_STOP
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_STOP(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_STOPF) == (I2C_ISR_STOPF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Transfer complete flag (master mode).
  * @note   RESET: Clear default value.
  *         SET: When RELOAD=0, AUTOEND=0 and NBYTES date have been transferred.
  * @rmtoll ISR          TC            LL_I2C_IsActiveFlag_TC
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TC(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_TC) == (I2C_ISR_TC)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Transfer complete flag (master mode).
  * @note   RESET: Clear default value.
  *         SET: When RELOAD=1 and NBYTES date have been transferred.
  * @rmtoll ISR          TCR           LL_I2C_IsActiveFlag_TCR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TCR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_TCR) == (I2C_ISR_TCR)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Bus error flag.
  * @note   RESET: Clear default value.
  *         SET: When a misplaced Start or Stop condition is detected.
  * @rmtoll ISR          BERR          LL_I2C_IsActiveFlag_BERR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_BERR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_BERR) == (I2C_ISR_BERR)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Arbitration lost flag.
  * @note   RESET: Clear default value.
  *         SET: When arbitration lost.
  * @rmtoll ISR          ARLO          LL_I2C_IsActiveFlag_ARLO
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_ARLO(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_ARLO) == (I2C_ISR_ARLO)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Overrun/Underrun flag (slave mode).
  * @note   RESET: Clear default value.
  *         SET: When an overrun/underrun error occurs (Clock Stretching Disabled).
  * @rmtoll ISR          OVR           LL_I2C_IsActiveFlag_OVR
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_OVR(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_OVR) == (I2C_ISR_OVR)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of Bus Busy flag.
  * @note   RESET: Clear default value.
  *         SET: When a Start condition is detected.
  * @rmtoll ISR          BUSY          LL_I2C_IsActiveFlag_BUSY
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_BUSY(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->ISR, I2C_ISR_BUSY) == (I2C_ISR_BUSY)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Address Matched flag.
  * @rmtoll ICR          ADDRCF        LL_I2C_ClearFlag_ADDR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_ADDR(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_ADDRCF);
}

/**
  * @brief  Clear Not Acknowledge flag.
  * @rmtoll ICR          NACKCF        LL_I2C_ClearFlag_NACK
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_NACK(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_NACKCF);
}

/**
  * @brief  Clear Stop detection flag.
  * @rmtoll ICR          STOPCF        LL_I2C_ClearFlag_STOP
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_STOP(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_STOPCF);
}

/**
  * @brief  Clear Transmit data register empty flag (TXE).
  * @note   This bit can be clear by software in order to flush the transmit data register (TXDR).
  * @rmtoll ISR          TXE           LL_I2C_ClearFlag_TXE
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_TXE(I2C_TypeDef * const I2Cx)
{
  WRITE_REG(I2Cx->ISR, I2C_ISR_TXE);
}

/**
  * @brief  Clear Bus error flag.
  * @rmtoll ICR          BERRCF        LL_I2C_ClearFlag_BERR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_BERR(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_BERRCF);
}

/**
  * @brief  Clear Arbitration lost flag.
  * @rmtoll ICR          ARLOCF        LL_I2C_ClearFlag_ARLO
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_ARLO(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_ARLOCF);
}

/**
  * @brief  Clear Overrun/Underrun flag.
  * @rmtoll ICR          OVRCF         LL_I2C_ClearFlag_OVR
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_ClearFlag_OVR(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->ICR, I2C_ICR_OVRCF);
}

/**
  * @}
  */

/** @defgroup I2C_LL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Enable automatic STOP condition generation (master mode).
  * @note   Automatic end mode : a STOP condition is automatically sent when NBYTES data are transferred.
  *         This bit has no effect in slave mode or when RELOAD bit is set.
  * @rmtoll CR2          AUTOEND       LL_I2C_EnableAutoEndMode
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableAutoEndMode(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_AUTOEND);
}

/**
  * @brief  Disable automatic STOP condition generation (master mode).
  * @note   Software end mode : TC flag is set when NBYTES data are transferre, stretching SCL low.
  * @rmtoll CR2          AUTOEND       LL_I2C_DisableAutoEndMode
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableAutoEndMode(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR2, I2C_CR2_AUTOEND);
}

/**
  * @brief  Check if automatic STOP condition is enabled or disabled.
  * @rmtoll CR2          AUTOEND       LL_I2C_IsEnabledAutoEndMode
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledAutoEndMode(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR2, I2C_CR2_AUTOEND) == (I2C_CR2_AUTOEND)) ? 1UL : 0UL);
}

/**
  * @brief  Enable reload mode (master mode).
  * @note   The transfer is not completed after the NBYTES data transfer, NBYTES will be reloaded when TCR flag is set.
  * @rmtoll CR2          RELOAD       LL_I2C_EnableReloadMode
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableReloadMode(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_RELOAD);
}

/**
  * @brief  Disable reload mode (master mode).
  * @note   The transfer is completed after the NBYTES data transfer(STOP or RESTART will follow).
  * @rmtoll CR2          RELOAD       LL_I2C_DisableReloadMode
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableReloadMode(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR2, I2C_CR2_RELOAD);
}

/**
  * @brief  Check if reload mode is enabled or disabled.
  * @rmtoll CR2          RELOAD       LL_I2C_IsEnabledReloadMode
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledReloadMode(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR2, I2C_CR2_RELOAD) == (I2C_CR2_RELOAD)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the number of bytes for transfer.
  * @note   Changing these bits when START bit is set is not allowed.
  * @rmtoll CR2          NBYTES           LL_I2C_SetTransferSize
  * @param  I2Cx I2C Instance.
  * @param  TransferSize This parameter must be a value between Min_Data=0x00U and Max_Data=0xFFU.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetTransferSize(I2C_TypeDef * const I2Cx, uint32_t TransferSize)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_NBYTES, TransferSize << I2C_CR2_NBYTES_Pos);
}

/**
  * @brief  Get the number of bytes configured for transfer.
  * @rmtoll CR2          NBYTES           LL_I2C_GetTransferSize
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0U and Max_Data=0xFFU
  */
__STATIC_INLINE uint32_t LL_I2C_GetTransferSize(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_NBYTES) >> I2C_CR2_NBYTES_Pos);
}

/**
  * @brief  Prepare the generation of a ACKnowledge or Non ACKnowledge condition after the address receive match code
            or next received byte.
  * @note   Usage in Slave mode only.
  * @rmtoll CR2          NACK          LL_I2C_AcknowledgeNextData
  * @param  I2Cx I2C Instance.
  * @param  TypeAcknowledge This parameter can be one of the following values:
  *         @arg @ref LL_I2C_ACK
  *         @arg @ref LL_I2C_NACK
  * @retval None
  */
__STATIC_INLINE void LL_I2C_AcknowledgeNextData(I2C_TypeDef * const I2Cx, uint32_t TypeAcknowledge)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_NACK, TypeAcknowledge);
}

/**
  * @brief  Generate a START or RESTART condition
  * @note   The START bit can be set even if bus is BUSY or I2C is in slave mode.
  *         This action has no effect when RELOAD is set.
  * @rmtoll CR2          START           LL_I2C_GenerateStartCondition
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_GenerateStartCondition(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_START);
}

/**
  * @brief  Generate a STOP condition after the current byte transfer (master mode).
  * @rmtoll CR2          STOP          LL_I2C_GenerateStopCondition
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_GenerateStopCondition(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_STOP);
}

/**
  * @brief  Enable automatic RESTART Read request condition for 10bit address header (master mode).
  * @note   The master sends the complete 10bit slave address read sequence :
  *         Start + 2 bytes 10bit address in Write direction + Restart + first 7 bits of 10bit address
            in Read direction.
  * @rmtoll CR2          HEAD10R       LL_I2C_EnableAuto10BitRead
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_EnableAuto10BitRead(I2C_TypeDef * const I2Cx)
{
  CLEAR_BIT(I2Cx->CR2, I2C_CR2_HEAD10R);
}

/**
  * @brief  Disable automatic RESTART Read request condition for 10bit address header (master mode).
  * @note   The master only sends the first 7 bits of 10bit address in Read direction.
  * @rmtoll CR2          HEAD10R       LL_I2C_DisableAuto10BitRead
  * @param  I2Cx I2C Instance.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_DisableAuto10BitRead(I2C_TypeDef * const I2Cx)
{
  SET_BIT(I2Cx->CR2, I2C_CR2_HEAD10R);
}

/**
  * @brief  Check if automatic RESTART Read request condition for 10bit address header is enabled or disabled.
  * @rmtoll CR2          HEAD10R       LL_I2C_IsEnabledAuto10BitRead
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledAuto10BitRead(I2C_TypeDef const * const I2Cx)
{
  return ((READ_BIT(I2Cx->CR2, I2C_CR2_HEAD10R) != (I2C_CR2_HEAD10R)) ? 1UL : 0UL);
}

/**
  * @brief  Configure the transfer direction (master mode).
  * @note   Changing these bits when START bit is set is not allowed.
  * @rmtoll CR2          RD_WRN           LL_I2C_SetTransferRequest
  * @param  I2Cx I2C Instance.
  * @param  TransferRequest This parameter can be one of the following values:
  *         @arg @ref LL_I2C_REQUEST_WRITE
  *         @arg @ref LL_I2C_REQUEST_READ
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetTransferRequest(I2C_TypeDef * const I2Cx, uint32_t TransferRequest)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_RD_WRN, TransferRequest);
}

/**
  * @brief  Get the transfer direction requested (master mode).
  * @rmtoll CR2          RD_WRN           LL_I2C_GetTransferRequest
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_REQUEST_WRITE
  *         @arg @ref LL_I2C_REQUEST_READ
  */
__STATIC_INLINE uint32_t LL_I2C_GetTransferRequest(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_RD_WRN));
}

/**
  * @brief  Configure the slave address for transfer (master mode).
  * @note   Changing these bits when START bit is set is not allowed.
  * @rmtoll CR2          SADD           LL_I2C_SetSlaveAddr
  * @param  I2Cx I2C Instance.
  * @param  SlaveAddr This parameter must be a value between Min_Data=0x00U and Max_Data=0x3FU.
  * @retval None
  */
__STATIC_INLINE void LL_I2C_SetSlaveAddr(I2C_TypeDef * const I2Cx, uint32_t SlaveAddr)
{
  MODIFY_REG(I2Cx->CR2, I2C_CR2_SADD, SlaveAddr);
}

/**
  * @brief  Get the slave address programmed for transfer.
  * @rmtoll CR2          SADD           LL_I2C_GetSlaveAddr
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0U and Max_Data=0x3FU
  */
__STATIC_INLINE uint32_t LL_I2C_GetSlaveAddr(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CR2, I2C_CR2_SADD));
}

/**
  * @brief  Handles I2Cx communication when starting transfer or during transfer (TC or TCR flag are set).
  * @rmtoll CR2          SADD          LL_I2C_HandleTransfer\n
  *         CR2          ADD10         LL_I2C_HandleTransfer\n
  *         CR2          RD_WRN        LL_I2C_HandleTransfer\n
  *         CR2          START         LL_I2C_HandleTransfer\n
  *         CR2          STOP          LL_I2C_HandleTransfer\n
  *         CR2          RELOAD        LL_I2C_HandleTransfer\n
  *         CR2          NBYTES        LL_I2C_HandleTransfer\n
  *         CR2          AUTOEND       LL_I2C_HandleTransfer\n
  *         CR2          HEAD10R       LL_I2C_HandleTransfer
  * @param  I2Cx I2C Instance.
  * @param  SlaveAddr Specifies the slave address to be programmed.
  * @param  SlaveAddrSize This parameter can be one of the following values:
  *         @arg @ref LL_I2C_ADDRSLAVE_7BIT
  *         @arg @ref LL_I2C_ADDRSLAVE_10BIT
  * @param  TransferSize Specifies the number of bytes to be programmed.
  *                       This parameter must be a value between Min_Data=0 and Max_Data=255.
  * @param  EndMode This parameter can be one of the following values:
  *         @arg @ref LL_I2C_MODE_RELOAD
  *         @arg @ref LL_I2C_MODE_AUTOEND
  *         @arg @ref LL_I2C_MODE_SOFTEND
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_I2C_GENERATE_NOSTARTSTOP
  *         @arg @ref LL_I2C_GENERATE_STOP
  *         @arg @ref LL_I2C_GENERATE_START_READ
  *         @arg @ref LL_I2C_GENERATE_START_WRITE
  *         @arg @ref LL_I2C_GENERATE_RESTART_7BIT_READ
  *         @arg @ref LL_I2C_GENERATE_RESTART_7BIT_WRITE
  *         @arg @ref LL_I2C_GENERATE_RESTART_10BIT_READ
  *         @arg @ref LL_I2C_GENERATE_RESTART_10BIT_WRITE
  * @retval None
  */
__STATIC_INLINE void LL_I2C_HandleTransfer(I2C_TypeDef * const I2Cx, uint32_t SlaveAddr, uint32_t SlaveAddrSize,
                                           uint32_t TransferSize, uint32_t EndMode, uint32_t Request)
{
  /* Declaration of tmp to prevent undefined behavior of volatile usage */
  uint32_t tmp = ((uint32_t)(((uint32_t)SlaveAddr & I2C_CR2_SADD) |
                             ((uint32_t)SlaveAddrSize & I2C_CR2_ADD10) |
                             (((uint32_t)TransferSize << I2C_CR2_NBYTES_Pos) & I2C_CR2_NBYTES) |
                             (uint32_t)EndMode | (uint32_t)Request) & (~0x80000000UL));

  /* update CR2 register */
  MODIFY_REG(I2Cx->CR2, I2C_CR2_SADD | I2C_CR2_ADD10 |
             (I2C_CR2_RD_WRN & (uint32_t)(Request >> (31U - I2C_CR2_RD_WRN_Pos))) |
             I2C_CR2_START | I2C_CR2_STOP | I2C_CR2_RELOAD |
             I2C_CR2_NBYTES | I2C_CR2_AUTOEND | I2C_CR2_HEAD10R,
             tmp);
}

/**
  * @brief  Indicate the value of transfer direction (slave mode).
  * @note   RESET: Write transfer, Slave enters in receiver mode.
  *         SET: Read transfer, Slave enters in transmitter mode.
  * @rmtoll ISR          DIR           LL_I2C_GetTransferDirection
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_DIRECTION_WRITE
  *         @arg @ref LL_I2C_DIRECTION_READ
  */
__STATIC_INLINE uint32_t LL_I2C_GetTransferDirection(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->ISR, I2C_ISR_DIR));
}

/**
  * @brief  Return the slave matched address.
  * @rmtoll ISR          ADDCODE       LL_I2C_GetAddressMatchCode
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00U and Max_Data=0x3FU
  */
__STATIC_INLINE uint32_t LL_I2C_GetAddressMatchCode(I2C_TypeDef const * const I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->ISR, I2C_ISR_ADDCODE) >> I2C_ISR_ADDCODE_Pos << 1U);
}

/**
  * @brief  Read Receive Data register.
  * @rmtoll RXDR         RXDATA        LL_I2C_ReceiveData8
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00U and Max_Data=0xFFU
  */
__STATIC_INLINE uint8_t LL_I2C_ReceiveData8(I2C_TypeDef const * const I2Cx)
{
  return (uint8_t)(READ_BIT(I2Cx->RXDR, I2C_RXDR_RXDATA));
}

/**
  * @brief  Write in Transmit Data Register .
  * @rmtoll TXDR         TXDATA        LL_I2C_TransmitData8
  * @param  I2Cx I2C Instance.
  * @param  Data Value between Min_Data=0x00U and Max_Data=0xFFU
  * @retval None
  */
__STATIC_INLINE void LL_I2C_TransmitData8(I2C_TypeDef * const I2Cx, uint8_t Data)
{
  WRITE_REG(I2Cx->TXDR, Data);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup I2C_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_I2C_Init(I2C_TypeDef * const I2Cx, LL_I2C_InitTypeDef const * const I2C_InitStruct);
ErrorStatus LL_I2C_DeInit(I2C_TypeDef const * const I2Cx);
void LL_I2C_StructInit(LL_I2C_InitTypeDef * const I2C_InitStruct);


/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* I2C1 || I2C2 || I2C3 || I2C4 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32U0xx_LL_I2C_H */
