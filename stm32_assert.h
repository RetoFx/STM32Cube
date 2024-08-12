/**
  ******************************************************************************
  * @file    stm32_assert.h
  * @author  MCD Application Team
  * @brief   STM32 assert template file.
  *          This file should be copied to the application folder and renamed
  *          to stm32_assert.h.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32_ASSERT_H
#define STM32_ASSERT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
#if !defined( _APPINCLUDE_H )
 #include "../../System/Canastra/ArmDef.h"					// ARM Extention
 #include "../../System/Canastra/sys_type.h"				// System Types
 #include "../../System/Canastra/sys_mac.h"					// System Macro
 #include "../../Utilities/Debug/DBG_Tools.h"				// Implements different DBG_*() macros
 #include "../../Utilities/Debug/DBG_Assert.h"				// Implements assert*()
#endif
/* Exported macro ------------------------------------------------------------*/
#if !defined(assert_param)
 #ifdef  USE_FULL_ASSERT
  #if !defined(__MODULE__)
   #define __MODULE__ __FILE__
  #endif
	/*lint -emacro(911, assert_param)*/          // Implicit expression promotion from typ to typ
	/*lint -emacro(912, assert_param)*/          // Implicit binary conversion from typ to typ
	/*lint -emacro(915, assert_param)*/          // Implicit conversion (initialization) int to unsigned short
	/*lint -emacro(920, assert_param)*/          // cast from int to void
	/*lint -emacro(921, assert_param)*/          // cast from int to unsigned int
	/*lint -emacro(923, assert_param)*/          // cast from unsigned int to pointer
	/*lint -emacro(1924, assert_param)*/         // C-style cast
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed(__MODULE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(char const * const file, size_t const line);
 #else /* USE_FULL_ASSERT */
  #define assert_param(expr) { }
 #endif /* USE_FULL_ASSERT */
#endif /* !defined(assert_param) */

#ifdef __cplusplus
}
#endif

#endif /* STM32_ASSERT_H */



