/**************************************************************************//**
 * @file     cmsis_msc.h
 * @brief    Microsoft C++ compiler MSC header file
 * @version  V6.0.0
 * @date     27. July 2024
 ******************************************************************************/
/*
 * Copyright (c) 2009-2023 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __CMSIS_MSC_H
#define __CMSIS_MSC_H

 /* CMSIS compiler control architecture macros */
#if ((defined (__TARGET_ARCH_6_M  ) && (__TARGET_ARCH_6_M   == 1U)) || \
     (defined (__TARGET_ARCH_6S_M ) && (__TARGET_ARCH_6S_M  == 1U))   )
#define __ARM_ARCH_6M__             1U
#define __ARM_ARCH_PROFILE          'M'
#define __ARM_FEATURE_LDREX         0x4U
#endif

#if (defined (__TARGET_ARCH_7_M ) && (__TARGET_ARCH_7_M  == 1U))
#define __ARM_ARCH_7M__             1U
#define __ARM_ARCH_PROFILE          'M'
#define __ARM_ARCH_ISA_THUMB        2U
#define __ARM_FEATURE_LDREX         0x7U
#define __ARM_FEATURE_SAT           1U
#endif

#if (defined (__TARGET_ARCH_7E_M) && (__TARGET_ARCH_7E_M == 1U))
#define __ARM_ARCH_7EM__            1U
#define __ARM_ARCH_PROFILE          'M'
#define __ARM_ARCH_ISA_THUMB        2U
#define __ARM_FEATURE_LDREX         0x7U
#define __ARM_FEATURE_SAT           1U
#define __ARM_FEATURE_DSP           1U
#endif

#if !defined(_ARMCC_INTRINSIC_H)
 #if !defined(ARMCC_INTRINSIC_H)
  #define ARMCC_INTRINSIC_H "../../../System/Keil/Armcc_Intrinsic.h"
 #endif
 #include ARMCC_INTRINSIC_H
#endif

#if !defined(UNUSED_ALWAYS)
 /*lint --emacro((920), UNUSED_ALWAYS)*/	//	casting from pointer to void
 /*lint -emacro(9229, UNUSED_ALWAYS)*/		//	casting from pointer to void
 //from _defs.h
 #define UNUSED_ALWAYS(arg) ((void)&(arg)) /*lint -esym(550, arg)*/ // Symbol not accessed
#endif  //UNUSED_ALWAYS

#ifndef   __INLINE
  #define __INLINE                               __inline
#endif
#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE                        static __inline
#endif
#ifndef   __STATIC_FORCEINLINE
  #define __STATIC_FORCEINLINE                   static __forceinline
#endif
#ifndef   __NO_RETURN
  #define __NO_RETURN
#endif
#ifndef   __USED
  #define __USED
#endif
#ifndef   __WEAK
  #define __WEAK                                 __weak
#endif
#ifndef   __PACKED
  #define __PACKED                               __packed
#endif
#ifndef   __PACKED_STRUCT
  #define __PACKED_STRUCT                        struct
#endif
#ifndef   __PACKED_UNION
  #define __PACKED_UNION                         union
#endif
#ifndef   __UNALIGNED_UINT32        /* deprecated */
  #define __UNALIGNED_UINT32(x)                  (*x)
#endif
#ifndef   __UNALIGNED_UINT16_WRITE
  __PACKED_STRUCT T_UINT16_WRITE { uint16_t v; };
  #define __UNALIGNED_UINT16_WRITE(addr, val)    (void)((((struct T_UINT16_WRITE *)(void *)(addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT16_READ
  __PACKED_STRUCT T_UINT16_READ { uint16_t v; };
  #define __UNALIGNED_UINT16_READ(addr)          (((const struct T_UINT16_READ *)(const void *)(addr))->v)
#endif
#ifndef   __UNALIGNED_UINT32_WRITE
  __PACKED_STRUCT T_UINT32_WRITE { uint32_t v; };
  #define __UNALIGNED_UINT32_WRITE(addr, val)    (void)((((struct T_UINT32_WRITE *)(void *)(addr))->v) = (val))
#endif
#ifndef   __UNALIGNED_UINT32_READ
  __PACKED_STRUCT T_UINT32_READ { uint32_t v; };
  #define __UNALIGNED_UINT32_READ(addr)          (((const struct T_UINT32_READ *)(const void *)(addr))->v)
#endif
#ifndef   __ALIGNED
  #define __ALIGNED(x)
#endif
#ifndef   __RESTRICT
  #define __RESTRICT
#endif
#ifndef   __COMPILER_BARRIER
  #define __COMPILER_BARRIER()
#endif

/* ##########################  Core Instruction Access  ######################### */
/** \defgroup CMSIS_Core_InstructionInterface CMSIS Core Instruction Interface
  Access to dedicated instructions
  @{
*/

/**
  \brief   No Operation
  \details No Operation does nothing. This instruction can be used for code alignment purposes.
 */
#define __NOP( )                             __nop( )


/**
  \brief   Wait For Interrupt
  \details Wait For Interrupt is a hint instruction that suspends execution until one of a number of events occurs.
 */
#define __WFI( )                             __wfi( )


/**
  \brief   Wait For Event
  \details Wait For Event is a hint instruction that permits the processor to enter
           a low-power state until one of a number of events occurs.
 */
#define __WFE( )                             __wfe( )


/**
  \brief   Send Event
  \details Send Event is a hint instruction. It causes an event to be signaled to the CPU.
 */
#define __SEV( )                             __sev( )


/**
  \brief   Instruction Synchronization Barrier
  \details Instruction Synchronization Barrier flushes the pipeline in the processor,
           so that all instructions following the ISB are fetched from cache or memory,
           after the instruction has been completed.
 */
#define __ISB( ) do { \
                   __schedule_barrier( ); \
                   __isb(0xFU); \
                   __schedule_barrier( ); \
                   __pragma(warning(push)) \
                   __pragma(warning(disable:4127)) /* Bedingter Ausdruck ist konstant */ \
                } while(0U != 0U) \
                __pragma(warning(pop))

/**
  \brief   Data Synchronization Barrier
  \details Acts as a special kind of Data Memory Barrier.
           It completes when all explicit memory accesses before this instruction complete.
 */
#define __DSB( ) do { \
                   __schedule_barrier( ); \
                   __dsb(0xFU); \
                   __schedule_barrier( ); \
                   __pragma(warning(push)) \
                   __pragma(warning(disable:4127)) /* Bedingter Ausdruck ist konstant */ \
                } while(0U != 0U) \
                __pragma(warning(pop))

/**
  \brief   Data Memory Barrier
  \details Ensures the apparent order of the explicit memory operations before
           and after the instruction, without ensuring their completion.
 */
#define __DMB( ) do { \
                   __schedule_barrier( ); \
                   __dmb(0xFU); \
                   __schedule_barrier( ); \
                   __pragma(warning(push)) \
                   __pragma(warning(disable:4127)) /* Bedingter Ausdruck ist konstant */ \
                } while(0U != 0U) \
                __pragma(warning(pop))


/**
  \brief   Reverse byte order (32 bit)
  \details Reverses the byte order in unsigned integer value. For example, 0x12345678 becomes 0x78563412.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
#define __REV(value)                             __rev(value)


/**
  \brief   Reverse byte order (16 bit)
  \details Reverses the byte order within each halfword of a word. For example, 0x12345678 becomes 0x34127856.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
#if 0U // #ifndef __NO_EMBEDDED_ASM
__attribute__((section(".rev16_text"))) __STATIC_INLINE __ASM uint32_t __REV16(uint32_t const value)
{
  rev16 r0, r0
  bx lr
}
#else
#define	__REV16(value)                           __rev16(value)
#endif

/**
  \brief   Reverse byte order (16 bit)
  \details Reverses the byte order in a 16-bit value and returns the signed 16-bit result. For example, 0x0080 becomes 0x8000.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
#if 0U // #ifndef __NO_EMBEDDED_ASM
__attribute__((section(".revsh_text"))) __STATIC_INLINE __ASM int16_t __REVSH(int16_t const value)
{
  revsh r0, r0
  bx lr
}
#else
#define	__REVSH(value)                           __revsh(value)
#endif

/**
  \brief   Rotate Right in unsigned value (32 bit)
  \details Rotate Right (immediate) provides the value of the contents of a register rotated by a variable number of bits.
  \param [in]    op1  Value to rotate
  \param [in]    op2  Number of Bits to rotate
  \return               Rotated value
 */
#define __ROR(op1, op2) __ror(op1, op2)


/**
  \brief   Breakpoint
  \details Causes the processor to enter Debug state.
           Debug tools can use this to investigate system state when the instruction at a particular address is reached.
  \param [in]    value  is ignored by the processor.
                 If required, a debugger can use it to store additional information about the breakpoint.
 */
#define __BKPT(value)                       __breakpoint(value)


/**
  \brief   Reverse bit order of value
  \details Reverses the bit order of the given value.
  \param [in]    value  Value to reverse
  \return               Reversed value
 */
#define __RBIT(value)                            __rbit(value)
__STATIC_FORCEINLINE uint32_t __rbit(uint32_t value)
{
  uint32_t result;
  uint32_t s = (4U /*sizeof(v)*/ * 8U) - 1U; /* extra shift needed at end */

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
#define __CLZ(value)    __clz(value)

#if ((__ARM_FEATURE_SAT    >= 1U) && \
     (__ARM_ARCH_ISA_THUMB >= 2U)    )

/**
  \brief   Signed Saturate
  \details Saturates a signed value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (1..32)
  \return             Saturated value
 */
#define __SSAT(value, sat) __ssat(value, sat)


/**
  \brief   Unsigned Saturate
  \details Saturates an unsigned value.
  \param [in]  value  Value to be saturated
  \param [in]    sat  Bit position to saturate to (0..31)
  \return             Saturated value
 */
#define __USAT(value, sat) __usat(value, sat)

#endif /* (__ARM_FEATURE_SAT >= 1U) */


#if (__ARM_FEATURE_LDREX >= 1U)
/**
  \brief   Remove the exclusive lock
  \details Removes the exclusive lock which is created by LDREX.
 */
#define __CLREX                           __clrex


/**
  \brief   LDR Exclusive (8 bit)
  \details Executes a exclusive LDR instruction for 8 bit value.
  \param [in]    ptr  Pointer to data
  \return             value of type uint8_t at (*ptr)
 */
#define __LDREXB(ptr)                                                        ((uint8_t ) __ldrex(ptr))


/**
  \brief   STR Exclusive (8 bit)
  \details Executes a exclusive STR instruction for 8 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
  \return          0  Function succeeded
  \return          1  Function failed
 */
#define __STREXB(value, ptr)                                                 __strex(value, ptr)
#endif /* (__ARM_FEATURE_LDREX >= 1U) */


#if (__ARM_FEATURE_LDREX >= 2U)
/**
  \brief   LDR Exclusive (16 bit)
  \details Executes a exclusive LDR instruction for 16 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint16_t at (*ptr)
 */
#define __LDREXH(ptr)                                                        ((uint16_t) __ldrex(ptr))


/**
  \brief   STR Exclusive (16 bit)
  \details Executes a exclusive STR instruction for 16 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
  \return          0  Function succeeded
  \return          1  Function failed
 */
#define __STREXH(value, ptr)                                                 __strex(value, ptr)
#endif /* (__ARM_FEATURE_LDREX >= 2U) */


#if (__ARM_FEATURE_LDREX >= 4U)
/**
  \brief   LDR Exclusive (32 bit)
  \details Executes a exclusive LDR instruction for 32 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint32_t at (*ptr)
 */
#define __LDREXW(ptr)                                                        ((uint32_t ) __ldrex(ptr))


/**
  \brief   STR Exclusive (32 bit)
  \details Executes a exclusive STR instruction for 32 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
  \return          0  Function succeeded
  \return          1  Function failed
 */
#define __STREXW(value, ptr)                                                 __strex(value, ptr)
#endif /* (__ARM_FEATURE_LDREX >= 4U) */


#if (__ARM_ARCH_ISA_THUMB >= 2U)
/**
  \brief   Rotate Right with Extend (32 bit)
  \details Moves each bit of a bitstring right by one bit.
           The carry input is shifted in at the left end of the bitstring.
  \param [in]    value  Value to rotate
  \return               Rotated value
 */
#define	__RRX(value)                                                         __rrx(value)


/**
  \brief   LDRT Unprivileged (8 bit)
  \details Executes a Unprivileged LDRT instruction for 8 bit value.
  \param [in]    ptr  Pointer to data
  \return             value of type uint8_t at (*ptr)
 */
#define __LDRBT(ptr)                      ((uint8_t )  __ldrt(ptr))


/**
  \brief   LDRT Unprivileged (16 bit)
  \details Executes a Unprivileged LDRT instruction for 16 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint16_t at (*ptr)
 */
#define __LDRHT(ptr)                      ((uint16_t)  __ldrt(ptr))


/**
  \brief   LDRT Unprivileged (32 bit)
  \details Executes a Unprivileged LDRT instruction for 32 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint32_t at (*ptr)
 */
#define __LDRT(ptr)                       ((uint32_t ) __ldrt(ptr))


/**
  \brief   STRT Unprivileged (8 bit)
  \details Executes a Unprivileged STRT instruction for 8 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
#define __STRBT(value, ptr)               __strt(value, ptr)


/**
  \brief   STRT Unprivileged (16 bit)
  \details Executes a Unprivileged STRT instruction for 16 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
#define __STRHT(value, ptr)               __strt(value, ptr)


/**
  \brief   STRT Unprivileged (32 bit)
  \details Executes a Unprivileged STRT instruction for 32 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
#define __STRT(value, ptr)                __strt(value, ptr)

#endif /* (__ARM_ARCH_ISA_THUMB >= 2U) */


#if (__ARM_ARCH >= 8U)
/**
  \brief   Load-Acquire (8 bit)
  \details Executes a LDAB instruction for 8 bit value.
  \param [in]    ptr  Pointer to data
  \return             value of type uint8_t at (*ptr)
 */
__STATIC_FORCEINLINE uint8_t __LDAB(volatile uint8_t *ptr)
{
  uint32_t result;

  __ASM volatile ("ldab %0, %1" : "=r" (result) : "Q" (*ptr) : "memory" );
  return ((uint8_t)result);    /* Add explicit type cast here */
}


/**
  \brief   Load-Acquire (16 bit)
  \details Executes a LDAH instruction for 16 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint16_t at (*ptr)
 */
__STATIC_FORCEINLINE uint16_t __LDAH(volatile uint16_t *ptr)
{
  uint32_t result;

  __ASM volatile ("ldah %0, %1" : "=r" (result) : "Q" (*ptr) : "memory" );
  return ((uint16_t)result);    /* Add explicit type cast here */
}


/**
  \brief   Load-Acquire (32 bit)
  \details Executes a LDA instruction for 32 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint32_t at (*ptr)
 */
__STATIC_FORCEINLINE uint32_t __LDA(volatile uint32_t *ptr)
{
  uint32_t result;

  __ASM volatile ("lda %0, %1" : "=r" (result) : "Q" (*ptr) : "memory" );
  return (result);
}


/**
  \brief   Store-Release (8 bit)
  \details Executes a STLB instruction for 8 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STLB(uint8_t value, volatile uint8_t *ptr)
{
  __ASM volatile ("stlb %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) : "memory" );
}


/**
  \brief   Store-Release (16 bit)
  \details Executes a STLH instruction for 16 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STLH(uint16_t value, volatile uint16_t *ptr)
{
  __ASM volatile ("stlh %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) : "memory" );
}


/**
  \brief   Store-Release (32 bit)
  \details Executes a STL instruction for 32 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
 */
__STATIC_FORCEINLINE void __STL(uint32_t value, volatile uint32_t *ptr)
{
  __ASM volatile ("stl %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) : "memory" );
}


/**
  \brief   Load-Acquire Exclusive (8 bit)
  \details Executes a LDAB exclusive instruction for 8 bit value.
  \param [in]    ptr  Pointer to data
  \return             value of type uint8_t at (*ptr)
 */
#define __LDAEXB                 (uint8_t)__builtin_arm_ldaex


/**
  \brief   Load-Acquire Exclusive (16 bit)
  \details Executes a LDAH exclusive instruction for 16 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint16_t at (*ptr)
 */
#define __LDAEXH                 (uint16_t)__builtin_arm_ldaex


/**
  \brief   Load-Acquire Exclusive (32 bit)
  \details Executes a LDA exclusive instruction for 32 bit values.
  \param [in]    ptr  Pointer to data
  \return        value of type uint32_t at (*ptr)
 */
#define __LDAEX                  (uint32_t)__builtin_arm_ldaex


/**
  \brief   Store-Release Exclusive (8 bit)
  \details Executes a STLB exclusive instruction for 8 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
  \return          0  Function succeeded
  \return          1  Function failed
 */
#define __STLEXB                 (uint32_t)__builtin_arm_stlex


/**
  \brief   Store-Release Exclusive (16 bit)
  \details Executes a STLH exclusive instruction for 16 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
  \return          0  Function succeeded
  \return          1  Function failed
 */
#define __STLEXH                 (uint32_t)__builtin_arm_stlex


/**
  \brief   Store-Release Exclusive (32 bit)
  \details Executes a STL exclusive instruction for 32 bit values.
  \param [in]  value  Value to store
  \param [in]    ptr  Pointer to location
  \return          0  Function succeeded
  \return          1  Function failed
 */
#define __STLEX                  (uint32_t)__builtin_arm_stlex

#endif /* (__ARM_ARCH >= 8U) */

/** @}*/ /* end of group CMSIS_Core_InstructionInterface */


/* ###########################  Core Function Access  ########################### */
/** \ingroup  CMSIS_Core_FunctionInterface
    \defgroup CMSIS_Core_RegAccFunctions CMSIS Core Register Access Functions
  @{
 */

/**
  \brief   Enable IRQ Interrupts
  \details Enables IRQ interrupts by clearing special-purpose register PRIMASK.
           Can only be executed in Privileged modes.
 */
/* intrinsic void __enable_irq();     */


/**
  \brief   Disable IRQ Interrupts
  \details Disables IRQ interrupts by setting special-purpose register PRIMASK.
           Can only be executed in Privileged modes.
 */
/* intrinsic void __disable_irq();    */

#if (__ARM_ARCH_ISA_THUMB >= 2U)
/**
  \brief   Enable FIQ
  \details Enables FIQ interrupts by clearing special-purpose register FAULTMASK.
           Can only be executed in Privileged modes.
 */
#define __enable_fault_irq( )                __enable_fiq( )


/**
  \brief   Disable FIQ
  \details Disables FIQ interrupts by setting special-purpose register FAULTMASK.
           Can only be executed in Privileged modes.
 */
#define __disable_fault_irq( )               __disable_fiq( )
#endif



/**
  \brief   Get FPSCR
  \details Returns the current value of the Floating Point Status/Control register.
  \return               Floating Point Status/Control register value
 */
__STATIC_FORCEINLINE uint32_t __get_FPSCR(void)
{
#if (defined(__ARM_FP) && (__ARM_FP >= 1U))
  return (__builtin_arm_get_fpscr());
#else
  return (0U);
#endif
}


/**
  \brief   Set FPSCR
  \details Assigns the given value to the Floating Point Status/Control register.
  \param [in]    fpscr  Floating Point Status/Control value to set
 */
__STATIC_FORCEINLINE void __set_FPSCR(uint32_t fpscr)
{
#if (defined(__ARM_FP) && (__ARM_FP >= 1U))
  __builtin_arm_set_fpscr(fpscr);
#else
  (void)fpscr;
#endif
}

/** @} end of CMSIS_Core_RegAccFunctions */

// Include the profile specific settings:
#if __ARM_ARCH_PROFILE == 'A'
  #include "./a-profile/cmsis_msc_a.h"
#elif __ARM_ARCH_PROFILE == 'R'
  #include "./r-profile/cmsis_msc_r.h"
#elif __ARM_ARCH_PROFILE == 'M'
  #include "./m-profile/cmsis_msc_m.h"
#else
  #error "Unknown Arm architecture profile"
#endif

#if defined(CMSIS_PERIPHERIE_ADR)
 #define __PERIPHERIE(TYPE,ADR)           ((TYPE *) ADR)
#else
 #define __PERIPHERIE(TYPE,ADR)           (&(__##ADR))
 #define __PERIPHERIE_STRUCT
#endif


#endif /* __CMSIS_MSC_H */
