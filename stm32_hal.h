/**
  ******************************************************************************
  * @file    stm32_hal.h
  * @author  RF Canastra AG
  * @brief   HAL configuration file.
  *          Globale definitionen für die STM32 HAL Files.
  *          Ist beim Include dieser Datei Uses_HAL_CPU nicht definiert
  *          werden nur die STM Core-Dateien eingebunden ansonsten auch alle
  *          gewählten Peripheren. Dadurch kann ein Modul wählen ob er von der
  *          HAL nur die Core verwendet (Uses_HAL_CPU nicht definiert) oder
  *          auch die Periphere (Uses_HAL_CPU definiert).
  *          Dies beeinflusst die Übersetzungszeiten.
  *          Um die Übersetzungszeiten weiter zu verbessern können nicht benötigte
  *          Periphere-Module durch auskommentieren der #define HAL_* weiter
  *          unten entfernt werden.
  *          Auch können mit den Defines die Default Werte für Clock, ETH, ...
  *          übersteuert werden.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32_HAL_H
#define __STM32_HAL_H


/*lint -save*/
/*lint -e537*/	//	Repeated include file
/*lint -e829*/	//	A +headerwarn option was previously issued

#include <stdio.h>	//for size_t
#if !defined( _APPINCLUDE_H )
// #include "../../AppInclude.h"
 #include <stdint.h>
 #include "../../System/Canastra/ArmDef.h"			// ARM Extention, for _PC_
 #include "../../System/Canastra/Pragmas.h"
 #define STM32_HAL_DIAG
#endif
/*lint -restore*/
#ifdef __cplusplus
 extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* ########################## Module Selection ############################## */
/**
  * @brief This is the list of modules to be used in the HAL driver
  */
#ifdef Uses_HAL_CPU
 #define USE_HAL_DRIVER					//required if any other is used

 #define HAL_MODULE_ENABLED				//always used
 #define HAL_CORTEX_MODULE_ENABLED		//always used

 #define HAL_ADC_MODULE_ENABLED			//used in template
 #define HAL_CAN_MODULE_ENABLED
 //#define HAL_CAN_LEGACY_MODULE_ENABLED
 #define HAL_CEC_MODULE_ENABLED
 #define HAL_COMP_MODULE_ENABLED
 #define HAL_CORDIC_MODULE_ENABLED
 #define HAL_CRC_MODULE_ENABLED			//used in template
 #define HAL_CRYP_MODULE_ENABLED
 #define HAL_DAC_MODULE_ENABLED			//used in template
 #define HAL_DCMI_MODULE_ENABLED
 #define HAL_DFSDM_MODULE_ENABLED
 #define HAL_DMA_MODULE_ENABLED			//mostly used (for ADC, ...)
 #define HAL_DMA2D_MODULE_ENABLED
 #define HAL_DSI_MODULE_ENABLED
 #define HAL_ETH_MODULE_ENABLED
 #define HAL_EXTI_MODULE_ENABLED
 #define HAL_FDCAN_MODULE_ENABLED
 #define HAL_FIREWALL_MODULE_ENABLED
 #define HAL_FLASH_MODULE_ENABLED		//always used
 #define HAL_FMAC_MODULE_ENABLED
 #define HAL_FMPI2C_MODULE_ENABLED
 #define HAL_FMPSMBUS_MODULE_ENABLED
 #define HAL_GFXMMU_MODULE_ENABLED
 #define HAL_GPIO_MODULE_ENABLED		//mostly used
 #define HAL_HASH_MODULE_ENABLED
 #define HAL_HCD_MODULE_ENABLED
 #define HAL_HRTIM_MODULE_ENABLED
 #define HAL_I2C_MODULE_ENABLED			//used in template
 #define HAL_I2S_MODULE_ENABLED
 #define HAL_IRDA_MODULE_ENABLED
 #define HAL_IWDG_MODULE_ENABLED		//used in template
 #define HAL_LCD_MODULE_ENABLED
 #define HAL_LPTIM_MODULE_ENABLED
 #define HAL_LTDC_MODULE_ENABLED
 #define HAL_MMC_MODULE_ENABLED
 #define HAL_NAND_MODULE_ENABLED
 #define HAL_NOR_MODULE_ENABLED
 #define HAL_OPAMP_MODULE_ENABLED
 #define HAL_OSPI_MODULE_ENABLED
 #define HAL_PCCARD_MODULE_ENABLED
 #define HAL_PCD_MODULE_ENABLED
 #define HAL_PKA_MODULE_ENABLED
 #define HAL_PSSI_MODULE_ENABLED
 #define HAL_PWR_MODULE_ENABLED			//always used
 #define HAL_QSPI_MODULE_ENABLED		//used in template
 #define HAL_RCC_MODULE_ENABLED			//always used
 #define HAL_RNG_MODULE_ENABLED
 #define HAL_RTC_MODULE_ENABLED			//used in template
 #define HAL_SAI_MODULE_ENABLED
 #define HAL_SD_MODULE_ENABLED
 #define HAL_SDADC_MODULE_ENABLED
 #define HAL_SDRAM_MODULE_ENABLED
 #define HAL_SMARTCARD_MODULE_ENABLED
 #define HAL_SMBUS_MODULE_ENABLED
 #define HAL_SPDIFRX_MODULE_ENABLED
 #define HAL_SPI_MODULE_ENABLED			//often used (for NvMem)
 #define HAL_SRAM_MODULE_ENABLED
 #define HAL_SWPMI_MODULE_ENABLED
 #define HAL_TIM_MODULE_ENABLED			//often used (for DelayUS, PWM)
 #define HAL_TSC_MODULE_ENABLED
 #define HAL_UART_MODULE_ENABLED		//often used (for TestInterface)
 #define HAL_USART_MODULE_ENABLED		//used in template
 #define HAL_WWDG_MODULE_ENABLED		//used in template

 #define USE_HAL_CRYP_SUSPEND_RESUME	1U

 #define USE_FULL_LL_DRIVER

 #define USE_CORTEX_LL_DRIVER

 #define USE_ADC_LL_DRIVER
 #define USE_BUS_LL_DRIVER
 #define USE_COMP_LL_DRIVER
 #define USE_CORDIC_LL_DRIVER
 #define USE_CRC_LL_DRIVER
 #define USE_CRS_LL_DRIVER
 #define USE_DAC_LL_DRIVER
 #define USE_DMA_LL_DRIVER
 #define USE_DMA2D_LL_DRIVER
 #define USE_DMAMUX_LL_DRIVER
 #define USE_EXTI_LL_DRIVER
 #define USE_FMAC_LL_DRIVER
 #define USE_FMC_LL_DRIVER
 #define USE_FSMC_LL_DRIVER
 #define USE_GPIO_LL_DRIVER
 #define USE_HRTIM_LL_DRIVER
 #define USE_I2C_LL_DRIVER
 #define USE_IWDG_LL_DRIVER
 #define USE_LPTIM_LL_DRIVER
 #define USE_LPUART_LL_DRIVER
 #define USE_OPAMP_LL_DRIVER
 #define USE_PWR_LL_DRIVER
 #define USE_RCC_LL_DRIVER
 #define USE_RNG_LL_DRIVER
 #define USE_RTC_LL_DRIVER
 #define USE_SDMMC_LL_DRIVER
 #define USE_SPI_LL_DRIVER
 #define USE_SWPMI_LL_DRIVER
 #define USE_SYSTEM_LL_DRIVER
 #define USE_TIM_LL_DRIVER
 #define USE_UCPD_LL_DRIVER
 #define USE_USART_LL_DRIVER
 #define USE_USB_LL_DRIVER
 #define USE_UTILS_LL_DRIVER
 #define USE_WWDG_LL_DRIVER
#endif

/* ########################## NVIC API Virtualization  ###################### */
/**
	The CMSIS-Core has provisions for overriding NVIC APIs as required for implementing
	secure systems that control access to peripherals and related interrupts.
	These overrides allow an operating system to control the access privileges
	of application code to critical interrupts.

	The NVIC function virtualization is enabled with the following #define symbols:
  */

//#define CMSIS_NVIC_VIRTUAL
//#define CMSIS_VECTAB_VIRTUAL

/* ########################## HSE/HSI Values adaptation ##################### */
/* overwrite default values here */
/**
  * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSE is used as system clock source, directly or through the PLL).
  */
//#define HSE_VALUE    8000000UL  /*!< Value of the External oscillator in Hz (F0, F1, F3, L0, L1) */
//#define HSE_VALUE    25000000UL /*!< Value of the External oscillator in Hz (F1, F2, F4) */

//#define HSE_STARTUP_TIMEOUT    100UL   /*!< Time out for HSE start up, in ms */

/**
  * @brief Internal Multi Speed oscillator (MSI) value.
  */
//#if defined(MSI_VALUE)
// #define MSI_VALUE    65536UL    /*!< Value of the Internal oscillator in Hz */
// #define MSI_VALUE    131072UL   /*!< Value of the Internal oscillator in Hz */
// #define MSI_VALUE    262144UL   /*!< Value of the Internal oscillator in Hz */
// #define MSI_VALUE    524288UL   /*!< Value of the Internal oscillator in Hz */
// #define MSI_VALUE    1048000UL  /*!< Value of the Internal oscillator in Hz */
// #define MSI_VALUE    2097000UL  /*!< Value of the Internal oscillator in Hz */
// #define MSI_VALUE    4194000UL  /*!< Value of the Internal oscillator in Hz */
//#endif

/**
  * @brief External Low Speed oscillator (LSE) value.
  */
//#define LSE_VALUE  32768UL    /*!< Value of the External Low Speed oscillator in Hz */

//#define LSE_STARTUP_TIMEOUT    5000UL   /*!< Time out for LSE start up, in ms */

/**
  * @brief External clock source for I2S peripheral
  *        This value is used by the I2S HAL module to compute the I2S clock source
  *        frequency, this source is inserted directly through I2S_CKIN pad.
  */
//#define EXTERNAL_CLOCK_VALUE    12288000UL /*!< Value of the Internal oscillator in Hz (F2, F4) */
//#define EXTERNAL_CLOCK_VALUE    8000000UL /*!< Value of the External oscillator in Hz (F3) */

/* Tip: To avoid modifying this file each time you need to use different HSE,
   ===  you can define the HSE value in your toolchain compiler preprocessor. */

/* ########################### System Configuration ######################### */
/**
  * @brief This is the HAL system configuration section
  */
/* overwrite default values here */

#define  VDD_VALUE                    3300U /*!< Value of VDD in mv */
#define  TICK_INT_PRIORITY            0x00U /*!< tick interrupt priority */
#define  USE_RTOS                     0U
//#define  PREFETCH_ENABLE              1U
//#define  PREREAD_ENABLE               1U
//#define  INSTRUCTION_CACHE_ENABLE     1U
//#define  DATA_CACHE_ENABLE            1U
//#define  BUFFER_CACHE_DISABLE         0U

/* ################## SPI peripheral configuration ########################## */

/* CRC FEATURE: Use to activate CRC feature inside HAL SPI Driver (F4, F7 only)
* Activated: CRC code is present inside driver
* Deactivated: CRC code cleaned from driver
*/

#define USE_SPI_CRC                     0U

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */
#if !defined( NDEBUG )
 #define USE_FULL_ASSERT                1U
#endif

/* ################## Ethernet peripheral configuration ##################### */

/* Section 1 : Ethernet peripheral configuration */

/* MAC ADDRESS: MAC_ADDR0:MAC_ADDR1:MAC_ADDR2:MAC_ADDR3:MAC_ADDR4:MAC_ADDR5 */
#define MAC_ADDR0   0x02U
#define MAC_ADDR1   0x00U
#define MAC_ADDR2   0x00U
#define MAC_ADDR3   0x00U
#define MAC_ADDR4   0x00U
#define MAC_ADDR5   0x00U

/* Definition of the Ethernet driver buffers size and count */
#define ETH_RX_BUF_SIZE                ETH_MAX_PACKET_SIZE   /* buffer size for receive                           */
#define ETH_TX_BUF_SIZE                ETH_MAX_PACKET_SIZE   /* buffer size for transmit                          */
#define ETH_RXBUFNB                    ((uint32_t)4UL)       /* 4 Rx buffers of size ETH_RX_BUF_SIZE              */
#define ETH_TXBUFNB                    ((uint32_t)4UL)       /* 4 Tx buffers of size ETH_TX_BUF_SIZE              */

/* Section 2: PHY configuration section */

/* DP83848 PHY Address*/
#define DP83848_PHY_ADDRESS             0x01U
/* PHY Reset delay these values are based on a 1 ms Systick interrupt*/
#define PHY_RESET_DELAY                 ((uint32_t)0x000000FFUL)
/* PHY Configuration delay */
#define PHY_CONFIG_DELAY                ((uint32_t)0x00000FFFUL)

#define PHY_READ_TO                     ((uint32_t)0x0000FFFFUL)
#define PHY_WRITE_TO                    ((uint32_t)0x0000FFFFUL)

/* Section 3: Common PHY Registers */

#define PHY_BCR                         ((uint16_t)0x00U)    /*!< Transceiver Basic Control Register              */
#define PHY_BSR                         ((uint16_t)0x01U)    /*!< Transceiver Basic Status Register               */

#define PHY_RESET                       ((uint16_t)0x8000U)  /*!< PHY Reset */
#define PHY_LOOPBACK                    ((uint16_t)0x4000U)  /*!< Select loop-back mode */
#define PHY_FULLDUPLEX_100M             ((uint16_t)0x2100U)  /*!< Set the full-duplex mode at 100 Mb/s            */
#define PHY_HALFDUPLEX_100M             ((uint16_t)0x2000U)  /*!< Set the half-duplex mode at 100 Mb/s            */
#define PHY_FULLDUPLEX_10M              ((uint16_t)0x0100U)  /*!< Set the full-duplex mode at 10 Mb/s             */
#define PHY_HALFDUPLEX_10M              ((uint16_t)0x0000U)  /*!< Set the half-duplex mode at 10 Mb/s             */
#define PHY_AUTONEGOTIATION             ((uint16_t)0x1000U)  /*!< Enable auto-negotiation function                */
#define PHY_RESTART_AUTONEGOTIATION     ((uint16_t)0x0200U)  /*!< Restart auto-negotiation function               */
#define PHY_POWERDOWN                   ((uint16_t)0x0800U)  /*!< Select the power down mode                      */
#define PHY_ISOLATE                     ((uint16_t)0x0400U)  /*!< Isolate PHY from MII                            */

#define PHY_AUTONEGO_COMPLETE           ((uint16_t)0x0020U)  /*!< Auto-Negotiation process completed              */
#define PHY_LINKED_STATUS               ((uint16_t)0x0004U)  /*!< Valid link established                          */
#define PHY_JABBER_DETECTION            ((uint16_t)0x0002U)  /*!< Jabber condition detected                       */

/* Section 4: Extended PHY Registers */

#define PHY_SR                          ((uint16_t)0x10U)    /*!< PHY status register Offset                      */
#define PHY_MICR                        ((uint16_t)0x11U)    /*!< MII Interrupt Control Register                  */
#define PHY_MISR                        ((uint16_t)0x12U)    /*!< MII Interrupt Status and Misc. Control Register */

#define PHY_LINK_STATUS                 ((uint16_t)0x0001U)  /*!< PHY Link mask                                   */
#define PHY_SPEED_STATUS                ((uint16_t)0x0002U)  /*!< PHY Speed mask                                  */
#define PHY_DUPLEX_STATUS               ((uint16_t)0x0004U)  /*!< PHY Duplex mask                                 */

#define PHY_MICR_INT_EN                 ((uint16_t)0x0002U)  /*!< PHY Enable interrupts                           */
#define PHY_MICR_INT_OE                 ((uint16_t)0x0001U)  /*!< PHY Enable output interrupt events              */

#define PHY_MISR_LINK_INT_EN            ((uint16_t)0x0020U)  /*!< Enable Interrupt on change of link status       */
#define PHY_LINK_INTERRUPT              ((uint16_t)0x2000U)  /*!< PHY link status interrupt mask                  */

#if (!defined( STM32C0 ) \
  && !defined( STM32F0 ) \
  && !defined( STM32L0 ) \
  && !defined( STM32G0 ) \
  && !defined( STM32U0 ) \
  && !defined( _PC_ ))
 #define HAL_BIT_BAND
#endif

/* Exported macro ------------------------------------------------------------*/
#if defined(HAL_BIT_BAND)
 #define HAL_SRAM_BIT_BAND_ADDRESS(reg, bit)		(*(__IO uint32_t *) \
													 ( SRAM_BB_BASE \
													 + (32U * (((uint32_t)&(reg)) - SRAM_BASE)) \
													 + (4U * (bit)) ) )
 #define HAL_SRAM_BIT_BAND_READ( reg, bit)			 HAL_SRAM_BIT_BAND_ADDRESS(reg, bit)
 #define HAL_SRAM_BIT_BAND_WRITE(reg, bit, value)	(HAL_SRAM_BIT_BAND_ADDRESS(reg, bit) = (value))

 #define HAL_PERIPH_BIT_BAND_ADDRESS(reg, bit)		(*(__IO uint32_t *) \
													 ( PERIPH_BB_BASE \
													 + (32U * (((uint32_t)&(reg)) - PERIPH_BASE)) \
													 + (4U * (bit)) ) )
 #define HAL_PERIPH_BIT_BAND_READ( reg, bit)		 HAL_PERIPH_BIT_BAND_ADDRESS(reg, bit)
 #define HAL_PERIPH_BIT_BAND_WRITE(reg, bit, value)	(HAL_PERIPH_BIT_BAND_ADDRESS(reg, bit) = (value))

 #define HAL_BKPSRAM_BIT_BAND_ADDRESS(reg, bit)		(*(__IO uint32_t *) \
													 ( BKPSRAM_BB_BASE \
													 + (32U * (((uint32_t)&(reg)) - BKPSRAM_BASE)) \
													 + (4U * (bit)) ) )
 #define HAL_BKPSRAM_BIT_BAND_READ( reg, bit)		 HAL_BKPSRAM_BIT_BAND_ADDRESS(reg, bit)
 #define HAL_BKPSRAM_BIT_BAND_WRITE(reg, bit, value)(HAL_BKPSRAM_BIT_BAND_ADDRESS(reg, bit) = (value))
#else
 #define HAL_SRAM_BIT_BAND_READ( reg, bit)			 ((0U != BIT_TEST32(reg, bit)) ? 1U : 0U)
 #define HAL_SRAM_BIT_BAND_WRITE(reg, bit, value)	 BIT_SET32(reg, bit, value)

 #define HAL_PERIPH_BIT_BAND_READ( reg, bit)		 ((0U != BIT_TEST32(reg, bit)) ? 1U : 0U)
 #define HAL_PERIPH_BIT_BAND_WRITE(reg, bit, value)	 BIT_SET32(reg, bit, value)

 #define HAL_BKPSRAM_BIT_BAND_READ( reg, bit)		 ((0U != BIT_TEST32(reg, bit)) ? 1U : 0U)
 #define HAL_BKPSRAM_BIT_BAND_WRITE(reg, bit, value) BIT_SET32(reg, bit, value)
#endif

/* ################## Register callback feature configuration ############### */
/**
  * @brief Set below the peripheral configuration  to "1U" to add the support
  *        of HAL callback registration/deregistration feature for the HAL
  *        driver(s). This allows user application to provide specific callback
  *        functions thanks to HAL_PPP_RegisterCallback() rather than overwriting
  *        the default weak callback functions (see each stm32l4xx_hal_ppp.h file
  *        for possible callback identifiers defined in HAL_PPP_CallbackIDTypeDef
  *        for each PPP peripheral).
  */
#define USE_HAL_ADC_REGISTER_CALLBACKS        0U
#define USE_HAL_CAN_REGISTER_CALLBACKS        0U
#define USE_HAL_CEC_REGISTER_CALLBACKS        0U
#define USE_HAL_COMP_REGISTER_CALLBACKS       0U
#define USE_HAL_CORDIC_REGISTER_CALLBACKS     0U
#define USE_HAL_CRYP_REGISTER_CALLBACKS       0U
#define USE_HAL_DAC_REGISTER_CALLBACKS        0U
#define USE_HAL_DCMI_REGISTER_CALLBACKS       0U
#define USE_HAL_DFSDM_REGISTER_CALLBACKS      0U
#define USE_HAL_DMA2D_REGISTER_CALLBACKS      0U
#define USE_HAL_DSI_REGISTER_CALLBACKS        0U
#define USE_HAL_ETH_REGISTER_CALLBACKS        0U
#define USE_HAL_FDCAN_REGISTER_CALLBACKS      0U
#define USE_HAL_FMAC_REGISTER_CALLBACKS       0U
#define USE_HAL_GFXMMU_REGISTER_CALLBACKS     0U
#define USE_HAL_HASH_REGISTER_CALLBACKS       0U
#define USE_HAL_HRTIM_REGISTER_CALLBACKS      0U
#define USE_HAL_HCD_REGISTER_CALLBACKS        0U
#define USE_HAL_I2C_REGISTER_CALLBACKS        0U
#define USE_HAL_I2S_REGISTER_CALLBACKS        0U
#define USE_HAL_IRDA_REGISTER_CALLBACKS       0U
#define USE_HAL_IWDG_REGISTER_CALLBACKS       0U
#define USE_HAL_LPTIM_REGISTER_CALLBACKS      0U
#define USE_HAL_LTDC_REGISTER_CALLBACKS       0U
#define USE_HAL_MMC_REGISTER_CALLBACKS        0U
#define USE_HAL_NAND_REGISTER_CALLBACKS       0U
#define USE_HAL_NOR_REGISTER_CALLBACKS        0U
#define USE_HAL_OPAMP_REGISTER_CALLBACKS      0U
#define USE_HAL_OSPI_REGISTER_CALLBACKS       0U
#define USE_HAL_PCCARD_REGISTER_CALLBACKS     0U
#define USE_HAL_PCD_REGISTER_CALLBACKS        0U
#define USE_HAL_QSPI_REGISTER_CALLBACKS       0U
#define USE_HAL_RNG_REGISTER_CALLBACKS        0U
#define USE_HAL_RTC_REGISTER_CALLBACKS        0U
#define USE_HAL_SAI_REGISTER_CALLBACKS        0U
#define USE_HAL_SD_REGISTER_CALLBACKS         0U
#define USE_HAL_SMARTCARD_REGISTER_CALLBACKS  0U
#define USE_HAL_SMBUS_REGISTER_CALLBACKS      0U
#define USE_HAL_SPI_REGISTER_CALLBACKS        0U
#define USE_HAL_SRAM_REGISTER_CALLBACKS       0U
#define USE_HAL_SWPMI_REGISTER_CALLBACKS      0U
#define USE_HAL_TIM_REGISTER_CALLBACKS        0U
#define USE_HAL_TSC_REGISTER_CALLBACKS        0U
#define USE_HAL_UART_REGISTER_CALLBACKS       0U
#define USE_HAL_USART_REGISTER_CALLBACKS      0U
#define USE_HAL_WWDG_REGISTER_CALLBACKS       0U


// implement weak function (VC can't overwrite in other modul)
#define	HAL_WEAK_CALLBACK(rtn, func)				__weak	rtn	func
#if !defined( _PC_ )
 // implement weak function
 #define	HAL_WEAK_CALLBACK_USED(rtn, func)		__weak	rtn	func
#else
 // rename weak function to overwrite in other modul
 #define	HAL_WEAK_CALLBACK_USED(rtn, func)		__weak	rtn	func##_
#endif

#define	HAL_ADC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_ADCEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_CAN_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_CEC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_COMP_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_CORDIC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_CRYPT_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_CRYPTEX_WEAK_CALLBACK(rtn, func)		HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_DAC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_DACEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_DMCI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_DFSDM_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_DMA2D_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_DSI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_FDCAN_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_ETH_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_FLASH_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_FMAC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_FMPI2C_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_GFXMMU_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_GPIO_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_HASH_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_HCD_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_HRTIM_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_I2C_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK_USED(rtn, func)
#define	HAL_I2S_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_I2SEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_IRDA_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_LPTIM_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_LTDC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_MMC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_NAND_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_OSPI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_PCCARD_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_PCD_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_PCDEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_PWR_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_PWREX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_QSPI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_RCC_WEAK_DEINIT(rtn, func)				HAL_WEAK_CALLBACK_USED(rtn, func)
#define	HAL_RCC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_RCCEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_RNG_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_RTC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_RTCEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SAI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SDADC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SDRAM_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SD_WEAK_CALLBACK(rtn, func)				HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SDEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SMARTCARD_WEAK_CALLBACK(rtn, func)		HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SMARTCARDEX_WEAK_CALLBACK(rtn, func)	HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SMBUS_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SPDIFRX_WEAK_CALLBACK(rtn, func)		HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SPI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK_USED(rtn, func)
#define	HAL_SRAM_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SWPMI_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_SYSTICK_WEAK(rtn, func)					HAL_WEAK_CALLBACK_USED(rtn, func)
#define	HAL_SYSTICK_WEAK_CALLBACK(rtn, func)		HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_TIM_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_TIMEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_TSC_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_UART_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK_USED(rtn, func)
#define	HAL_UARTEX_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_USART_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK_USED(rtn, func)
#define	HAL_USARTEX_WEAK_CALLBACK(rtn, func)		HAL_WEAK_CALLBACK(rtn, func)
#define	HAL_WWDG_WEAK_CALLBACK(rtn, func)			HAL_WEAK_CALLBACK(rtn, func)

#if defined( _PC_ )
 #if defined( LPTR )
  #undef LPTR			// defined minwinbase.h
 #endif
#endif

/* Includes ------------------------------------------------------------------*/
/*lint -save -w1*/
/*lint -e9023*/	//  Multiple use of '#/##' operators in definition of macro
/*lint -e9024*/	//  #/##' operator used in macro

/**
  * @brief Include assert header file
  */

#include "stm32_assert.h"

/**
  * @brief Include familie's header file
  */

#if !defined(STM32_HAL_DIAG)
 PRAGMA_DIAG_PUSH
#endif
PRAGMA_DIAG_IGNORED_BAD_FUNCTION_CAST
PRAGMA_DIAG_IGNORED_CAST_ALIGN
PRAGMA_DIAG_IGNORED_CAST_QUAL
PRAGMA_DIAG_IGNORED_CONSTANT_LOGICAL_OPERAND	//Nur bug in STM32F3
PRAGMA_DIAG_IGNORED_CONVERSION
PRAGMA_DIAG_IGNORED_COVERED_SWITCH_DEFAULT
PRAGMA_DIAG_IGNORED_DECLARATION_AFTER_STATEMENT	//mixing declarations and code is incompatible with standards before C99
PRAGMA_DIAG_IGNORED_DEPRECATED_REGISTER
PRAGMA_DIAG_IGNORED_DISCARDED_QUALIFIERS
PRAGMA_DIAG_IGNORED_IGNORED_ATTRIBUTES
PRAGMA_DIAG_IGNORED_MISSING_FIELD_INITIALIZERS
PRAGMA_DIAG_IGNORED_MISSING_NORETURN
PRAGMA_DIAG_IGNORED_MISSING_VARIABLE_DECLARATIONS
PRAGMA_DIAG_IGNORED_OLD_STYLE_DECLARATION
PRAGMA_DIAG_IGNORED_PADDED
PRAGMA_DIAG_IGNORED_SIGN_COMPARE
PRAGMA_DIAG_IGNORED_SWITCH_ENUM
PRAGMA_DIAG_IGNORED_UNREACHABLE_CODE
PRAGMA_DIAG_IGNORED_UNUSED_PARAMETER


#define STM32_FAMILY_PATH(family) TOSTR(./family/family.h)

#include "./stm32_family.h"
PRAGMA_DIAG_PUSH
PRAGMA_DIAG_IGNORED_NONPORTABLE_INCLUDE_PATH
#include STM32_FAMILY_PATH(CPU_FAMILY)
PRAGMA_DIAG_POP

#if defined( STM32L4 )
 #if defined(USART_CR1_FIFOEN)
  #if !defined(STM32L4PLUS)
   #error ("STM32L4PLUS not defined. Please add to project settings")
  #endif
 #else
  #if defined(STM32L4PLUS)
   #error ("STM32L4PLUS defined. Please remove from project settings")
  #endif
 #endif
#endif

#if !defined(STM32_HAL_DIAG)
 PRAGMA_DIAG_POP
#endif

#ifdef __cplusplus
}
#endif

/*lint -e9023*/	//  Multiple use of '#/##' operators in definition of macro
/*lint -e9024*/	//  #/##' operator used in macro
/*lint -restore*/
#endif /* __STM32_HAL_H */



