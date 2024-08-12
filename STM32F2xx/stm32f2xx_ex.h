/**
  ******************************************************************************
  * @file    stm32f2xx_ex.h
  * @author  Reto Felix
  * @version V1.0.0
  * @date    30.03.2015
  * @brief   CMSIS STM32F2xx Device extended Peripheral Access Layer Header File.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f2xx
  * @{
  */

#ifndef __STM32F2xx_EX_H
#define __STM32F2xx_EX_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/** @addtogroup Device_Included
  * @{
  */

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef struct
{
	__IO uint8_t	uiUser1;	//User option byte
	__IO uint8_t	uiRDP1;		//Read protection
	__IO uint8_t	uiNUser1;
	__IO uint8_t	uiNRDP1;
	__IO uint8_t	uiUser2;
	__IO uint8_t	uiRDP2;
	__IO uint8_t	uiNUser2;
	__IO uint8_t	uiNRDP2;
	__IO uint16_t	uiNWRP1;	//Write protection
	__IO uint16_t	uiWRP1;
	__IO uint16_t	uiNWRP2;
	__IO uint16_t	uiWRP2;
} OPT_TypeDef;



#if defined(_PC_)
 static ctMEM stm32_auiOtp[528U] = { 0U };
 #define STM32_OTP_BASE				stm32_auiOtp
#else
 #define STM32_OTP_BASE				0x1FFF7800UL	/*!< OTP Area     */
#endif
#define STM32_OTP_SIZE				528UL			// Byte
#define STM32_OTP_END				((STM32_OTP_BASE + STM32_OTP_SIZE) - 1U)



#if defined(_PC_)
 #if defined(UID_BASE)
  #undef UID_BASE
 #endif
 static cUINT32 stm32_auiUID[] =	{ 0x11223344UL, 0x55667788UL, 0xAABBCCDDUL };
 #define UID_BASE					((ctMEM *)stm32_auiUID)
#endif

#if defined(UID_BASE)
 #define STM32_UID_BASE				UID_BASE
#else
 #define STM32_UID_BASE				0x1FFFFA10UL
#endif

/*lint -emacro(923, STM32_UNIQUE_DEVICE_ID?)*/ //cast from unsigned int to pointer
#define STM32_UNIQUE_DEVICE_ID0		(*((uint32_t const *)(STM32_UID_BASE + 0x0000U)))
#define STM32_UNIQUE_DEVICE_ID1		(*((uint32_t const *)(STM32_UID_BASE + 0x0004U)))
#define STM32_UNIQUE_DEVICE_ID2		(*((uint32_t const *)(STM32_UID_BASE + 0x0008U)))



#if defined(_PC_)
 #if defined(FLASHSIZE_BASE)
  #undef FLASHSIZE_BASE
 #endif
 static cUINT16 stm32_auiFlashSize[] = { 512U };		//512kB
 #define FLASHSIZE_BASE				stm32_auiFlashSize
 #define FLASH_SIZE_DATA_REGISTER	stm32_auiFlashSize	//for stm32l4xx_ex.h
#endif

#if defined(FLASHSIZE_BASE)
 #define STM32_FSZ_BASE				FLASHSIZE_BASE
#else
 #define STM32_FSZ_BASE				0x1FFF7A22UL
#endif

/*lint -emacro(923, STM32_FLASH_SIZE)*/ //cast from unsigned int to pointer
#define STM32_FLASH_SIZE			(*((uint16_t const *)STM32_FSZ_BASE))



#if defined(OB_BASE)
 #define STM32_OPT_BASE				OB_BASE
#else
 #define STM32_OPT_BASE				0x1FFFC000UL	/*!< Option       */
#endif

#define STM32_OPT_SIZE				sizeof(OPT_TypeDef)
#define STM32_OPT_END				((STM32_OPT_BASE + STM32_OPT_SIZE) - 1U)

#define STM32_OPT					__PERIPHERIE(OPT_TypeDef, STM32_OPT_BASE)



#define STM32_VREFINT_MIN_MV		1180U		// mV
#define STM32_VREFINT_TYP_MV		1210U		// mV
#define STM32_VREFINT_MAX_MV		1240U		// mV



#if !defined(RTC_BKP_NUMBER)
 #define RTC_BKP_NUMBER				20U
#endif



//#if defined(CCMDATARAM_BASE) && defined(CCMDATARAM_END)
// #define CCMDATARAM_SIZE	((CCMDATARAM_END + 1U) - CCMDATARAM_BASE)
//#endif



//#if defined(SRAM1_BASE) && !defined(SRAM1_SIZE) && !defined(SRAM1_END)
// #define SRAM1_SIZE	((uint32_t)(112U *1024U))	/*!< SRAM1(112 KB) base address in the alias region                             */
// #define SRAM1_END	(SRAM1_BASE + (SRAM1_SIZE - 1U))
//#endif
//
//#if defined(SRAM2_BASE) && !defined(SRAM2_SIZE) && !defined(SRAM2_END)
// #define SRAM2_SIZE	((uint32_t)(16U *1024U))	/*!< SRAM2(16 KB) base address in the alias region                              */
// #define SRAM2_END	(SRAM2_BASE + (SRAM2_SIZE - 1U))
//#endif
//
//#if defined(SRAM3_BASE) && !defined(SRAM3_SIZE) && !defined(SRAM3_END)
// #define SRAM3_SIZE	((uint32_t)(64U *1024U))	/*!< SRAM3(64 KB) base address in the alias region                              */
// #define SRAM3_END	(SRAM3_BASE + (SRAM3_SIZE - 1U))
//#endif
//
//#if defined(SRAM3_BASE) && defined(SRAM3_END)
// #define SRAM_END	SRAM3_END
//#elif defined(SRAM2_BASE) && defined(SRAM2_END)
// #define SRAM_END	SRAM2_END
//#elif defined(SRAM1_BASE) && defined(SRAM1_END)
// #define SRAM_END	SRAM1_END
//#endif



//#if defined(BKPSRAM_BASE) && !defined(BKPSRAM_SIZE) && !defined(BKPSRAM_END)
// #define BKPSRAM_SIZE	((uint32_t)(4U *1024U))	/*!< Backup SRAM(4 KB) base address in the alias region                         */
// #define BKPSRAM_END	(BKPSRAM_BASE + (BKPSRAM_SIZE - 1U))
//#endif



#if !defined(FLASH_FLAG_MASK)
 #define FLASH_FLAG_MASK			( FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR \
									| FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR )
#endif

/**
  * @}
  */


/** @addtogroup Exported_macro
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32F2xx_EX_H */
/**
  * @}
  */

/**
  * @}
  */





