/**
  ******************************************************************************
  * @file    stm32l1xx_ex.h
  * @author  Reto Felix
  * @version V1.0.0
  * @date    30.03.2015
  * @brief   CMSIS STM32L1xx Device extended Peripheral Access Layer Header File.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32l1xx
  * @{
  */

#ifndef __STM32L1xx_EX_H
#define __STM32L1xx_EX_H

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
	__IO uint8_t	uiSPRMOD;
	__IO uint8_t	uiNRDP;
	__IO uint8_t	uiNSPRMOD;
	__IO uint16_t	uiUser;		//User option byte
	__IO uint16_t	uiNUser;
	__IO uint16_t	uiWRP1Low;	//Write protection
	__IO uint16_t	uiNWRP1Low;
	__IO uint16_t	uiWRP1High;
	__IO uint16_t	uiNWRP1High;
	__IO uint16_t	uiWRP2Low;
	__IO uint16_t	uiNWRP2Low;
	__IO uint16_t	uiWRP2High;
	__IO uint16_t	uiNWRP2High;
	__IO uint16_t	uiWRP3Low;
	__IO uint16_t	uiNWRP3Low;
	__IO uint16_t	uiWRP3High;
	__IO uint16_t	uiNWRP3High;
	__IO uint32_t	RESERVED[60U];    /*!< Reserved,                                    Address offset: 0x80U */
	__IO uint16_t	uiWRP4Low;
	__IO uint16_t	uiNWRP4Low;
	__IO uint16_t	uiWRP4High;
	__IO uint16_t	uiNWRP4High;
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
 #if defined (STM32L100xB)  \
  || defined (STM32L100xBA) \
  || defined (STM32L151xB)  \
  || defined (STM32L151xBA) \
  || defined (STM32L152xB)  \
  || defined (STM32L152xBA)
  // Cat.1 and Cat.2
  #define STM32_FSZ_BASE			0x1FF8004CUL
 #endif

 #if	defined (STM32L100xC)  \
  || defined (STM32L151xC)  \
  || defined (STM32L151xCA) \
  || defined (STM32L151xD)  \
  || defined (STM32L151xDX) \
  || defined (STM32L151xE)  \
  || defined (STM32L152xC)  \
  || defined (STM32L152xCA) \
  || defined (STM32L152xD)  \
  || defined (STM32L152xDX) \
  || defined (STM32L152xE)  \
  || defined (STM32L162xC)  \
  || defined (STM32L162xCA) \
  || defined (STM32L162xD)  \
  || defined (STM32L162xDX) \
  || defined (STM32L162xE)
  // Cat.3, Cat.4, Cat.5 and Cat.6
  #define STM32_FSZ_BASE			0x1FF800CCUL
 #endif
#endif

#if !defined(STM32_FLASH_SIZE)
 /*lint -emacro(923, STM32_FLASH_SIZE)*/ //cast from unsigned int to pointer
 #if defined(STM32L151xCA)  \
  || defined(STM32L151xD)   \
  || defined(STM32L151xDX)  \
  || defined (STM32L152xCA) \
  || defined(STM32L152xD)   \
  || defined(STM32L152xDX)  \
  || defined (STM32L162xCA) \
  || defined(STM32L162xD)   \
  || defined(STM32L162xDX)  \
  || defined(STM32L151xE)   \
  || defined (STM32L152xE)  \
  || defined (STM32L162xE)
  // Some Cat.3, Cat.4
  // For DEV_ID = 0x436U, the field value can be ‘0’ or ‘1’,
  // with ‘0’ for 384 Kbytes and ‘1’ for 256 Kbytes.
  #define STM32_FLASH_SIZE			((uint16_t)( (0U != (*((uint16_t const *)STM32_FSZ_BASE))) ? 256U : 384U ))
 #elif \
     defined (STM32L100xC)  \
  || defined (STM32L151xC)  \
  || defined (STM32L152xC)  \
  || defined (STM32L162xC)
  // Cat.2
  // For DEV_ID = 0x429U, only LSB part of F_SIZE: F_SIZE[7:0] is valid.
  // The MSB part F_SIZE[15:8] is reserved and must be ignored.
  #define STM32_FLASH_SIZE			((uint16_t)( (*((uint16_t const *)STM32_FSZ_BASE)) & 0x00FFU))
 #else
  #define STM32_FLASH_SIZE			(*((uint16_t const *)STM32_FSZ_BASE))
 #endif
#endif



#if defined(OB_BASE)
 #define STM32_OPT_BASE				OB_BASE
#else
 #define STM32_OPT_BASE				0x1FF80000UL
#endif

#define STM32_OPT_SIZE				sizeof(OPT_TypeDef)
#define STM32_OPT_END				((STM32_OPT_BASE + STM32_OPT_SIZE) - 1U)

#define STM32_OPT					__PERIPHERIE(OPT_TypeDef, STM32_OPT_BASE)



// read the factory reference calibration values
#if defined(_PC_)
 static cUINT16 stm32_auiVRefIntCal[] = { 0x067BU };
 #define STM32_VREFINT_CAL			stm32_auiVRefIntCal[0U]
#else
 #if defined (STM32L100xB)  \
  || defined (STM32L100xBA) \
  || defined (STM32L151xB)  \
  || defined (STM32L151xBA) \
  || defined (STM32L152xB)  \
  || defined (STM32L152xBA)
  /*lint -emacro(923, STM32_VREFINT_CAL)*/ //cast from unsigned int to pointer
  #define STM32_VREFINT_CAL			(*((uint16_t const *) 0x1FF80078UL))
 #endif

 #if defined (STM32L100xC)  \
  || defined (STM32L151xC)  \
  || defined (STM32L151xCA) \
  || defined (STM32L151xD)  \
  || defined (STM32L151xDX) \
  || defined (STM32L151xE)  \
  || defined (STM32L152xC)  \
  || defined (STM32L152xCA) \
  || defined (STM32L152xD)  \
  || defined (STM32L152xDX) \
  || defined (STM32L152xE)  \
  || defined (STM32L162xC)  \
  || defined (STM32L162xCA) \
  || defined (STM32L162xD)  \
  || defined (STM32L162xDX) \
  || defined (STM32L162xE)
  /*lint -emacro(923, STM32_VREFINT_CAL)*/ //cast from unsigned int to pointer
  #define STM32_VREFINT_CAL			(*((uint16_t const *) 0x1FF800F8UL))
 #endif
#endif

#define STM32_VREFINT_MIN_MV		1202U		// mV
#define STM32_VREFINT_TYP_MV		1224U		// mV
#define STM32_VREFINT_MAX_MV		1242U		// mV



// read the factory temperature calibration values
#define STM32_TSENSE_TEMP1			30			// °C
#define STM32_TSENSE_TEMP2			110			// °C

#if defined(_PC_)
 static cUINT16 stm32_auitSense[] = { 0x040DU, 0x0523U };
 #define STM32_TSENSE_CAL1			(stm32_auitSense[0U])
 #define STM32_TSENSE_CAL2			(stm32_auitSense[1U])
#else
 #if defined (STM32L151xB)  \
  || defined (STM32L151xBA) \
  || defined (STM32L152xB)  \
  || defined (STM32L152xBA) \
  /*lint -emacro(923, STM32_TSENSE_CAL?)*/ //cast from unsigned int to pointer
  #define STM32_TSENSE_CAL1			(*((uint16_t const *) 0x1FF8007AUL))
  #define STM32_TSENSE_CAL2			(*((uint16_t const *) 0x1FF8007EUL))
 #endif

 #if defined (STM32L151xC)  \
  || defined (STM32L151xCA) \
  || defined (STM32L151xD)  \
  || defined (STM32L151xDX) \
  || defined (STM32L151xE)  \
  || defined (STM32L152xC)  \
  || defined (STM32L152xCA) \
  || defined (STM32L152xD)  \
  || defined (STM32L152xDX) \
  || defined (STM32L152xE)  \
  || defined (STM32L162xC)  \
  || defined (STM32L162xCA) \
  || defined (STM32L162xD)  \
  || defined (STM32L162xDX) \
  || defined (STM32L162xE)
  /*lint -emacro(923, STM32_TSENSE_CAL?)*/ //cast from unsigned int to pointer
  #define STM32_TSENSE_CAL1			(*((uint16_t const *) 0x1FF800FAUL))
  #define STM32_TSENSE_CAL2			(*((uint16_t const *) 0x1FF800FEUL))
 #endif
#endif



/**
  * @}
  */

#if !defined(FLASH_EEPROM_SIZE) && defined(FLASH_EEPROM_BASE) && defined(FLASH_EEPROM_END)
 #define FLASH_EEPROM_SIZE 			((FLASH_EEPROM_END + 1UL) - FLASH_EEPROM_BASE)
#endif

//for compatibility with STM32L0xxx
#if !defined(DATA_EEPROM_BASE) && defined(FLASH_EEPROM_BASE)
 #define DATA_EEPROM_BASE			FLASH_EEPROM_BASE
#endif

#if !defined(DATA_EEPROM_END) && defined(FLASH_EEPROM_END)
 #define DATA_EEPROM_END			FLASH_EEPROM_END
#endif

#if !defined(DATA_EEPROM_SIZE)
 #define DATA_EEPROM_SIZE			FLASH_EEPROM_SIZE
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

#endif /* __STM32L1xx_EX_H */
/**
  * @}
  */

/**
  * @}
  */





