#if !defined( _HAL_STM32_FAMILY_H )
#define _HAL_STM32_FAMILY_H

#if defined( STM32C0 )
 #define CPU_FAMILY	STM32C0xx
#elif defined( STM32F0 )
 #define CPU_FAMILY	STM32F0xx
#elif defined( STM32F1 )
 #define CPU_FAMILY	STM32F1xx
#elif defined( STM32F2 )
 #define CPU_FAMILY	STM32F2xx
#elif defined( STM32F3 )
 #define CPU_FAMILY	STM32F3xx
#elif defined( STM32F4 )
 #define CPU_FAMILY	STM32F4xx
#elif defined( STM32G0 )
 #define CPU_FAMILY	STM32G0xx
#elif defined( STM32G4 )
 #define CPU_FAMILY	STM32G4xx
#elif defined( STM32L0 )
 #define CPU_FAMILY	STM32L0xx
#elif defined( STM32L1 )
 #define CPU_FAMILY	STM32L1xx
#elif defined( STM32L4 )
 #define CPU_FAMILY	STM32L4xx
#elif defined( STM32U0 )
 #define CPU_FAMILY	STM32U0xx
#else
 #error ("Not supported")
#endif

#endif
