/**
  ******************************************************************************
  * @file    stm32g4xx_ex.h
  * @author  Reto Felix
  * @version V1.0.0
  * @date    30.03.2015
  * @brief   CMSIS STM32G4xx Device extended Peripheral Access Layer Header File.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32g4xx
  * @{
  */

#ifndef __STM32G4xx_EX_H
#define __STM32G4xx_EX_H

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
	__IO uint32_t	uiNUser;
	__IO uint32_t	uiUser;
	__IO uint32_t	uiNRopStart;
	__IO uint32_t	uiRdoStart;
	__IO uint32_t	uiNRopEnd;
	__IO uint32_t	uiRopEnd;
	__IO uint32_t	uiNWrpA;
	__IO uint32_t	uiWrpA;
	__IO uint32_t	uiNWrpB;
	__IO uint32_t	uiWrpB;
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
 #define STM32_UID_BASE				0x1FFF7590UL
#endif

/*lint -emacro(923, STM32_UNIQUE_DEVICE_ID?)*/ //cast from unsigned int to pointer
#define STM32_UNIQUE_DEVICE_ID0		(*((uint32_t const *)(STM32_UID_BASE + 0x0000U)))
#define STM32_UNIQUE_DEVICE_ID1		(*((uint32_t const *)(STM32_UID_BASE + 0x0004U)))
#define STM32_UNIQUE_DEVICE_ID2		(*((uint32_t const *)(STM32_UID_BASE + 0x0008U)))



#if defined(_PC_)
 #if defined(FLASHSIZE_BASE)
  #undef FLASHSIZE_BASE
 #endif
 static cUINT16 stm32_auiFlashSize[] = { 128U };		//128kB
 #define FLASHSIZE_BASE				stm32_auiFlashSize
 #define FLASH_SIZE_DATA_REGISTER	stm32_auiFlashSize	//for stm32l4xx_ex.h
#endif

#if defined(FLASHSIZE_BASE)
 #define STM32_FSZ_BASE				FLASHSIZE_BASE
#else
 #define STM32_FSZ_BASE				0x1FFF75E0UL
#endif

/*lint -emacro(923, STM32_FLASH_SIZE)*/ //cast from unsigned int to pointer
#define STM32_FLASH_SIZE			(*((uint16_t const *)STM32_FSZ_BASE))



#if defined(OB_BASE)
 #define STM32_OPT1_BASE			OB_BASE
#else
 #define STM32_OPT1_BASE			0x1FFF7800UL	/*!< Option1      */
#endif

#define STM32_OPT1_SIZE				sizeof(OPT_TypeDef)
#define STM32_OPT1_END				((STM32_OPT1_BASE + STM32_OPT1_SIZE) - 1U)

#define STM32_OPT1					__PERIPHERIE(OPT_TypeDef, STM32_OPT1_BASE)

#define STM32_OPT2_BASE				0x1FFFF800UL	/*!< Option2      */

#define STM32_OPT2_SIZE				sizeof(OPT_TypeDef)
#define STM32_OPT2_END				((STM32_OPT2_BASE + STM32_OPT2_SIZE) - 1U)

#define STM32_OPT2					__PERIPHERIE(OPT_TypeDef, STM32_OPT2_BASE)



// read the factory reference calibration values
#if defined(_PC_)
 static cUINT16 stm32_auiVRefIntCal[] = { 0x067BU };
 #define STM32_VREFINT_CAL			stm32_auiVRefIntCal[0U]
#else
 /*lint -emacro(923, STM32_VREFINT_CAL)*/ //cast from unsigned int to pointer
 #define STM32_VREFINT_CAL			(*((uint16_t const *) 0x1FFF75AAUL))
#endif

#define STM32_VREFINT_MIN_MV		1182U		// mV
#define STM32_VREFINT_TYP_MV		1212U		// mV
#define STM32_VREFINT_MAX_MV		1232U		// mV



// read the factory temperature calibration values
#define STM32_TSENSE_TEMP1			30			// °C
#define STM32_TSENSE_TEMP2			130			// °C

#if defined(_PC_)
 static cUINT16 stm32_auitSense[] = { 0x040DU, 0x0523U };
 #define STM32_TSENSE_CAL1			(stm32_auitSense[0U])
 #define STM32_TSENSE_CAL2			(stm32_auitSense[1U])
#else
 /*lint -emacro(923, STM32_TSENSE_CAL?)*/ //cast from unsigned int to pointer
 #define STM32_TSENSE_CAL1			(*((uint16_t const *) 0x1FFF75A8UL))
 #define STM32_TSENSE_CAL2			(*((uint16_t const *) 0x1FFF75CAUL))
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

#endif /* __STM32G4xx_EX_H */
/**
  * @}
  */

/**
  * @}
  */





