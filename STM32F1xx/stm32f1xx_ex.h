/**
  ******************************************************************************
  * @file    stm32f1xx_ex.h
  * @author  Reto Felix
  * @version V1.0.0
  * @date    30.03.2015
  * @brief   CMSIS STM32F1xx Device extended Peripheral Access Layer Header File.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f1xx
  * @{
  */

#ifndef __STM32F1xx_EX_H
#define __STM32F1xx_EX_H

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
	__IO uint8_t	uiRDP;		//Read protection
	__IO uint8_t	uiNRDP;
	__IO uint8_t	uiUser;		//User option byte
	__IO uint8_t	uiNUser;
	__IO uint8_t	uiData0;
	__IO uint8_t	uiNData0;
	__IO uint8_t	uiData1;
	__IO uint8_t	uiNData1;
	__IO uint8_t	uiWRP0;		//Write protection
	__IO uint8_t	uiNWRP0;
	__IO uint8_t	uiWRP1;
	__IO uint8_t	uiNWRP1;
	__IO uint8_t	uiWRP2;
	__IO uint8_t	uiNWRP2;
	__IO uint8_t	uiWRP3;
	__IO uint8_t	uiNWRP3;
} OPT_TypeDef;



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
 #define STM32_UID_BASE				0x1FFFF7E8UL
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
 #define STM32_FSZ_BASE				0x1FFFF7E0UL
#endif

/*lint -emacro(923, STM32_FLASH_SIZE)*/ //cast from unsigned int to pointer
#define STM32_FLASH_SIZE			(*((uint16_t const *)STM32_FSZ_BASE))



#if defined(OB_BASE)
 #define STM32_OPT_BASE				OB_BASE
#else
 #define STM32_OPT_BASE				0x1FFFF800UL
#endif

#define STM32_OPT_SIZE				sizeof(OPT_TypeDef)
#define STM32_OPT_END				((STM32_OPT_BASE + STM32_OPT_SIZE) - 1U)

#define STM32_OPT					__PERIPHERIE(OPT_TypeDef, STM32_OPT_BASE)



#define STM32_VREFINT_MIN_MV		1160U		// mV
#define STM32_VREFINT_TYP_MV		1200U		// mV
#define STM32_VREFINT_MAX_MV		1240U		// mV	1260 @ 115°C



#if !defined(FLASH_FLAG_MASK)
 #define FLASH_FLAG_MASK			( FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR )
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

#endif /* __STM32F1xx_EX_H */
/**
  * @}
  */

/**
  * @}
  */





