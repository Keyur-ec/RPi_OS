#pragma once

#define SCTRL_RESERVED              ( 3 << 20 ) | ( 3 << 22 ) | ( 1 << 20 ) | ( 1 << 11 )
#define SCTRL_EE_LITTLE_ENDIAN      ( 0 << 25 )
#define SCTRL_EOE_LITTLE_ENDIAN     ( 0 << 24 )
#define SCTRL_I_CACHE_DISABLED      ( 0 << 12 )
#define SCTRL_D_CACHE_DISABLED      ( 0 << 2 )
#define SCTRL_MMU_DISABLED          ( 0 << 0 )
#define SCTRL_MMU_ENABLED           ( 1 << 0 )
#define SCTRL_VALUE_MMU_DISABLED    ( SCTRL_RESERVED | SCTRL_EE_LITTLE_ENDIAN | SCTRL_I_CACHE_DISABLED | SCTRL_D_CACHE_DISABLED | SCTRL_MMU_DISABLED )

#define HCR_RW                      ( 1 << 31 )
#define HCR_VALUE                   HCR_RW

#define SCR_RESERVED                ( 3 << 4 )
#define SCR_RW                      ( 1 << 10 )
#define SCR_NS                      ( 1 << 0 )
#define SCR_VALUE                   ( SCR_RESERVED | SCR_RW | SCR_NS )

#define SPSR_MASK_ALL               ( 7 << 6 )
#define SPSR_EL1h                   ( 5 << 0 )
#define SPSR_EL2h                   ( 9 << 0 )
#define SPSR_VALUE                  ( SPSR_MASK_ALL | SPSR_EL1h )
