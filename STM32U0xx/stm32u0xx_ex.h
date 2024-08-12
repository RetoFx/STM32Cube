/**
  ******************************************************************************
  * @file    stm32u0xx_ex.h
  * @author  Reto Felix
  * @version V1.0.0
  * @date    06.05.2024
  * @brief   CMSIS STM32U0xx Device extended Peripheral Access Layer Header File.
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32u0xx
  * @{
  */

#ifndef __STM32U0xx_EX_H
#define __STM32U0xx_EX_H

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
 #error ("missing UID_BASE")
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
 #error ("missing FLASHSIZE_BASE")
#endif

/*lint -emacro(923, STM32_FLASH_SIZE)*/ //cast from unsigned int to pointer
#define STM32_FLASH_SIZE			(*((uint16_t const *)STM32_FSZ_BASE))



// read the factory reference calibration values
#if defined(_PC_)
 static cUINT16 stm32_auiVRefIntCal[] = { 0x067BU };
 #define STM32_VREFINT_CAL			stm32_auiVRefIntCal[0U]
#else
 /*lint -emacro(923, STM32_VREFINT_CAL)*/ //cast from unsigned int to pointer
 #define STM32_VREFINT_CAL			(*((uint16_t const *) 0x1FFF6EA4UL))
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
 #define STM32_TSENSE_CAL1			(*((uint16_t const *) 0x1FFF6E68UL))
 #define STM32_TSENSE_CAL2			(*((uint16_t const *) 0x1FFF6E6AUL))
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





