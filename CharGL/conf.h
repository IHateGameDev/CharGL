#ifndef IH_CONF_H
#define IH_CONF_H

// DISABLE STD LIB
// #define API_DISABLE_STD_LIB

// STD HEADERS
#ifndef API_STDINT_H
# define API_STDINT_H <stdint.h>
#endif

#ifndef API_STRING_H
# define API_STRING_H <string.h>
#endif

#ifndef API_STDLIB_H
# define API_STDLIB_H <stdlib.h>
#endif

// STD STRING FUNCTIONS
#ifndef API_MEMSET
# define API_MEMSET memset
#endif

// STD TYPES
#ifndef API_U8
# define API_U8 uint8_t
#endif

#ifndef API_U16
# define API_U16 uint16_t
#endif

#ifndef API_U32
# define API_U32 uint32_t
#endif

#ifndef API_U64
# define API_U64 uint64_t
#endif

#ifndef API_I8
# define API_I8 int8_t
#endif

#ifndef API_I16
# define API_I16 int16_t
#endif

#ifndef API_I32
# define API_I32 int32_t
#endif

#ifndef API_I64
# define API_I64 int64_t
#endif

// STDLIB FUNCTIONS
#ifndef API_MALLOC
# define API_MALLOC malloc
#endif

#ifndef API_FREE
# define API_FREE free
#endif

#ifndef API_CALLOC
# define API_CALLOC calloc
#endif

#endif // !IH_CONF_H
