/**************************************************************************//**
 * @file     cmsis_armclangex.h
 * @brief    CMSIS compiler ARMCLANG (ARM compiler V6) header file
 * @version  V5.0.3
 * @date     27. March 2017
 ******************************************************************************/
/*
 * Copyright (c) 2009-2017 ARM Limited. All rights reserved.
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

#ifndef __CMSIS_ARMCLANGEX_H
#define __CMSIS_ARMCLANGEX_H

// #include <arm_compat.h>
 #include <arm_acle.h>

#ifndef __weak
  #define __weak   __WEAK
#endif /* __weak */
#ifndef __packed
  #define __packed __PACKED
#endif /* __packed */

#define __NOINLINE __attribute__((noinline))

#if !defined(__ARM_COMPAT_H)
/* from arm_compat.h */

#if __ARM_ARCH >= 6 || (__ARM_ARCH == 5 && __ARM_ARCH_ISA_THUMB)
#define __breakpoint(v) __asm__ __volatile__ ("bkpt %0" : : "i"(v) )
#else /* __ARM_ARCH < 6 && (__ARM_ARCH != 5 || !__ARM_ARCH_ISA_THUMB) */
static __inline__ void __attribute__((unavailable(
    "intrinsic not supported for this architecture"))) __breakpoint(int val);
#endif

#define __current_pc()                                                         \
  __extension__({                                                              \
    register unsigned int current_pc;                                          \
    __asm__ __volatile__("mov %0, pc" : "=r"(current_pc) : : );                \
    current_pc;                                                                \
  })

#define __current_sp()                                                         \
  __extension__({                                                              \
    register unsigned int current_sp;                                          \
    __asm__ __volatile__("mov %0, sp" : "=r"(current_sp) : : );                \
    current_sp;                                                                \
  })

#if (defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M' &&                \
    __ARM_ARCH == 6) || __ARM_ARCH_8M_BASE__
static __inline__ unsigned int __attribute__((unavailable(
    "intrinsic not supported for this architecture"))) __disable_fiq(void);
#else // (!defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' ||
      // __ARM_ARCH != 6) && !__ARM_ARCH_8M_BASE__
static __inline__ unsigned int __attribute__((__always_inline__, __nodebug__))
__disable_fiq(void) {
  unsigned int cpsr;
#if defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
  __asm__ __volatile__("mrs %[cpsr], faultmask\n"
                       "cpsid f\n"
                       : [cpsr] "=r"(cpsr));
  return cpsr & 0x1;
#elif __ARM_ARCH >= 6 /* !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
  __asm__ __volatile__("mrs %[cpsr], cpsr\n"
                       "cpsid f\n"
                       : [cpsr] "=r"(cpsr));
  return cpsr & 0x40;
#else /* __ARM_ARCH < 6 && !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
  unsigned int tmp;
  __asm__ __volatile__(
          "mrs	%[cpsr], CPSR\n"
          "bic	%[tmp], %[cpsr], #0x40\n"
          "msr	CPSR_c, %[tmp]\n"
          : [tmp]"=r"(tmp), [cpsr]"=r"(cpsr));
  return cpsr & 0x40;
#endif
}
#endif

#if (defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M' &&                \
    __ARM_ARCH == 6) || __ARM_ARCH_8M_BASE__
static __inline__ void __attribute__((unavailable(
    "intrinsic not supported for this architecture"))) __enable_fiq(void);
#else // (!defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' ||
      // __ARM_ARCH != 6) && !__ARM_ARCH_8M_BASE__
static __inline__ void __attribute__((__always_inline__, __nodebug__))
__enable_fiq(void) {
#if __ARM_ARCH >= 6
  __asm__ __volatile__("cpsie f");
#else /* __ARM_ARCH < 6 */
  unsigned int tmp;
  __asm__ __volatile__(
          "mrs	%[tmp], CPSR\n"
          "bic	%[tmp], %[tmp], #0x40\n"
          "msr	CPSR_c, %[tmp]\n"
          : [tmp]"=r"(tmp));
#endif
}
#endif

static __inline__ void __attribute__((__always_inline__, __nodebug__)) __force_stores(void) {
    __asm__ __volatile__ ("" : : : "memory", "cc");
}

static __inline__ void  __attribute__((__always_inline__, __nodebug__)) __memory_changed(void) {
    __asm__ __volatile__ ("" : : : "memory", "cc");
}

static __inline__ void  __attribute__((__always_inline__, __nodebug__)) __schedule_barrier(void) {
    __asm__ __volatile__ ("" : : : "memory", "cc");
}

static __inline__ int __attribute__((__always_inline__, __nodebug__))
__semihost(int val, const void *ptr) {
  register int v __asm__("r0") = val;
  register const void *p __asm__("r1") = ptr;
  __asm__ __volatile__(
#if defined(__thumb__)
#if defined(__ARM_ARCH_PROFILE) && __ARM_ARCH_PROFILE == 'M'
      "bkpt 0xab"
#else /* !defined(__ARM_ARCH_PROFILE) || __ARM_ARCH_PROFILE != 'M' */
#if defined(__USE_HLT_SEMIHOSTING)
      ".inst.n 0xbabc"
#else
      "svc 0xab"
#endif
#endif
#else /* !defined(__thumb__) */
#if defined(__USE_HLT_SEMIHOSTING)
      ".inst 0xe10f0070"
#else
      "svc 0x123456"
#endif
#endif
      : "+r"(v), "+r"(p)
      :
      : "memory", "cc");
  return v;
}

#if defined(__ARM_FP)
static __inline__ unsigned int __attribute__((__always_inline__, __nodebug__))
__vfp_status(unsigned int mask, unsigned int flags) {
  unsigned int fpscr;
  __asm__ __volatile__("vmrs %[fpscr], fpscr" : [fpscr] "=r"(fpscr));
  unsigned int set = mask & flags;
  unsigned int clear = mask & ~flags;
  unsigned int toggle = ~mask & flags;
  fpscr |= set;
  fpscr &= ~clear;
  fpscr ^= toggle;
  __asm__ __volatile__("vmsr fpscr, %[fpscr]" : : [fpscr] "r"(fpscr));
  return fpscr;
}
#else /* !defined(__ARM_FP) */
static __inline__ unsigned int __attribute__((
    unavailable("intrinsic not supported for targets without floating point")))
__vfp_status(unsigned int mask, unsigned int flags);
#endif

#endif /* __ARM_COMPAT_H */

#endif /* __CMSIS_ARMCLANGEX_H */
