/**
  ******************************************************************************
  * @file    stm32l0xx_ex.h
  * @author  Reto Felix
  * @version V1.0.0
  * @date    30.03.2015
  * @brief   CMSIS STM32L0xx Device extended Peripheral Access Layer Header File.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32l0xx
  * @{
  */

#ifndef __STM32L0xx_EX_H
#define __STM32L0xx_EX_H

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
	__IO uint16_t	uiRDP;		//Read protection
	__IO uint16_t	uiNRDP;
	__IO uint16_t	uiUser;		//User option byte
	__IO uint16_t	uiNUser;
	__IO uint16_t	uiNWRP;		//Write protection
	__IO uint16_t	uiWRP;
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
 #define STM32_UID_BASE				0x1FF80050UL
#endif

/*lint -emacro(923, STM32_UNIQUE_DEVICE_ID?)*/ //cast from unsigned int to pointer
#define STM32_UNIQUE_DEVICE_ID0		(*((uint32_t const *)(STM32_UID_BASE + 0x0000U)))
#define STM32_UNIQUE_DEVICE_ID1		(*((uint32_t const *)(STM32_UID_BASE + 0x0004U)))
#define STM32_UNIQUE_DEVICE_ID2		(*((uint32_t const *)(STM32_UID_BASE + 0x0014U)))



#if defined(_PC_)
 static cUINT16 stm32_auiFlashSize[] = { 512U };		//512kB
 #if defined(FLASHSIZE_BASE)
  #undef FLASHSIZE_BASE
 #endif
 #define FLASHSIZE_BASE				stm32_auiFlashSize
#endif

#if defined(FLASHSIZE_BASE)
 #define STM32_FSZ_BASE				FLASHSIZE_BASE
#else
 #define STM32_FSZ_BASE				0x1FF8007CUL
#endif

/*lint -emacro(923, STM32_FLASH_SIZE)*/ //cast from unsigned int to pointer
#define STM32_FLASH_SIZE			(*((uint16_t const *)STM32_FSZ_BASE))



#if defined(OB_BASE)
 #define STM32_OPT_BASE				OB_BASE
#else
 #define STM32_OPT_BASE				0x1FF80000UL	/*!< Option       */
#endif

#define STM32_OPT_SIZE				sizeof(OPT_TypeDef)
#define STM32_OPT_END				((STM32_OPT_BASE + STM32_OPT_SIZE) - 1U)

#define STM32_OPT					__PERIPHERIE(OPT_TypeDef, STM32_OPT_BASE)



// read the factory reference calibration values
#if defined(_PC_)
 static cUINT16 stm32_auiVRefIntCal[] = { 0x067BU };
 #define STM32_VREFINT_CAL			stm32_auiVRefIntCal[0U]
#else
 /*lint -emacro(923, STM32_VREFINT_CAL)*/ //cast from unsigned int to pointer
 #define STM32_VREFINT_CAL			(*((uint16_t const *) 0x1FF80078UL))
#endif

#define STM32_VREFINT_MIN_MV		1202U		// mV
#define STM32_VREFINT_TYP_MV		1224U		// mV
#define STM32_VREFINT_MAX_MV		1242U		// mV



// read the factory temperature calibration values
#define STM32_TSENSE_TEMP1			30			// °C
#define STM32_TSENSE_TEMP2			130			// °C

#if defined(_PC_)
 static cUINT16 stm32_auitSense[] = { 0x040DU, 0x0523U };
 #define STM32_TSENSE_CAL1			(stm32_auitSense[0U])
 #define STM32_TSENSE_CAL2			(stm32_auitSense[1U])
#else
 /*lint -emacro(923, STM32_TSENSE_CAL?)*/ //cast from unsigned int to pointer
 #define STM32_TSENSE_CAL1			(*((uint16_t const *) 0x1FF8007AUL))
 #define STM32_TSENSE_CAL2			(*((uint16_t const *) 0x1FF8007EUL))
#endif



/**
  * @}
  */

#if !defined(DATA_EEPROM_END) && defined(DATA_EEPROM_BANK2_END)
 #define DATA_EEPROM_END			DATA_EEPROM_BANK2_END
#endif

#if !defined(DATA_EEPROM_SIZE) && defined(DATA_EEPROM_BASE) && defined(DATA_EEPROM_END)
 #define DATA_EEPROM_SIZE			((DATA_EEPROM_END + 1UL) - DATA_EEPROM_BASE)
#endif

//for compatibility with STM32L1xxx
#if !defined(FLASH_EEPROM_BASE) && defined(DATA_EEPROM_BASE)
 #define FLASH_EEPROM_BASE			DATA_EEPROM_BASE
#endif

#if !defined(FLASH_EEPROM_END) && defined(DATA_EEPROM_END)
 #define FLASH_EEPROM_END			DATA_EEPROM_END
#endif

#if !defined(FLASH_EEPROM_SIZE)
 #define FLASH_EEPROM_SIZE			DATA_EEPROM_SIZE
#endif


#if !defined(FLASH_FLAG_MASK)
 #define FLASH_FLAG_MASK			( FLASH_FLAG_EOP    | FLASH_FLAG_ENDHV  | FLASH_FLAG_WRPERR \
									| FLASH_FLAG_PGAERR | FLASH_FLAG_SIZERR | FLASH_FLAG_OPTVERR \
									| FLASH_FLAG_RDERR  | FLASH_FLAG_NOTZEROERR )
#endif

/** @addtogroup Exported_macro
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __STM32L0xx_EX_H */
/**
  * @}
  */

/**
  * @}
  */





