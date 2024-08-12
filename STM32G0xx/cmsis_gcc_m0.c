/*******************************************************************************
* @file cmsis_gcc_m0.c
********************************************************************************
*
* @Project:						"Canastra Library"
* @Copyright:					Canastra AG
*
*
* @section DESCRIPTION:
*	Add function for missing CMSIS APIs
*
* @section HISTORY:
*	27.09.2022	RAF	Created this file.
*
*
********************************************************************************
* @section LICENSE:
*	Die vorliegende Source-Datei ist urheberrechtlich geschützt und Eigentum
*	der Firma Canastra AG. Sie wurde im Zusammenhang mit dem vorliegenden
*	Projekt an den Kunden lizenziert. Sie darf ohne schriftliche Zustimmung
*	der Firma Canastra AG in keinem anderen Projekt verwendet werden, auch
*	nicht auszugsweise.
*******************************************************************************/

//****** Precompiled Header ****************************************************
//#include "stdafx.h"

//****** includes **************************************************************
#include "cmsis_compiler.h"               /* CMSIS compiler specific defines */

//****** debug *****************************************************************

//****** private defines *******************************************************

//****** private macros ********************************************************

//****** namespace *************************************************************

//****** private types *********************************************************

//****** private struct ********************************************************

//****** private template ******************************************************

//****** private class *********************************************************

//****** global const **********************************************************

//****** local const ***********************************************************

//****** global data ***********************************************************

//****** local data ************************************************************

//****** class static **********************************************************

//****** private function prototype ********************************************

//****** private inline function ***********************************************

//****** function **************************************************************

#if (defined (__ARM_ARCH_6M__ ) && (__ARM_ARCH_6M__  == 1U))
#if defined(CMSIS_NO_INLINE_INTRINSIC)

/**
  \brief   Reverse bit order of value
  \details Reverses the bit order of the given value.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
uint32_t __RBIT(uint32_t value)
{
  uint32_t result;
  uint32_t s = (4U /*sizeof(value)*/ * 8U) - 1U; /* extra shift needed at end */

  result = value;                      /* r will be reversed bits of v; first get LSB of v */
  for (value >>= 1U; value != 0U; value >>= 1U)
  {
    result <<= 1U;
    result |= (value & 1U);
    s--;
  }
  result <<= s;                        /* shift when v's highest bits are zero */
  return result;
}

/**
  \brief   Count leading zeros
  \details Counts the number of leading zeros of a data value.
  \param [in]  value  Value to count the leading zeros
  \return             number of leading zeros in value
 */
uint8_t __CLZ(uint32_t const value)
{
  /* Even though __builtin_clz produces a CLZ instruction on ARM, formally
     __builtin_clz(0) is undefined behaviour, so handle this case specially.
     This guarantees ARM-compatible results if happening to compile on a non-ARM
     target, and ensures the compiler doesn't decide to activate any
     optimisations using the logic "value was passed to __builtin_clz, so it
     is non-zero".
     ARM GCC 7.3 and possibly earlier will optimise this test away, leaving a
     single CLZ instruction.
   */
  if (value == 0U)
  {
    return 32U;
  }
  return __builtin_clz(value);
}

/**
  \brief   Signed Saturate
  \details Saturates a signed value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (1..32)
  \return             Saturated value
 */
int32_t __SSAT(int32_t const val, uint32_t const sat)
{
  if ((sat >= 1U) && (sat <= 32U))
  {
    const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
    const int32_t min = -1 - max ;
    if (val > max)
    {
      return max;
    }
    else if (val < min)
    {
      return min;
    }
  }
  return val;
}

/**
  \brief   Unsigned Saturate
  \details Saturates an unsigned value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (0..31)
  \return             Saturated value
 */
uint32_t __USAT(int32_t const val, uint32_t const sat)
{
  if (sat <= 31U)
  {
    uint32_t const max = ((1U << sat) - 1U);
    if (val > (int32_t)max)
    {
      return max;
    }
    else if (val < 0)
    {
      return 0U;
    }
  }
  return (uint32_t)val;
}

#endif /*defined(CMSIS_NO_INLINE_INTRINSIC)*/
#endif /*(defined (__ARM_ARCH_6M__ ) && (__ARM_ARCH_6M__  == 1U))*/


//****** end of file ***********************************************************
