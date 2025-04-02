#ifndef IH_CONF_H
#define IH_CONF_H

// DISABLE STD LIB
// #define API_DISABLE_STD_LIB

// STD HEADERS
#ifndef API_STDINT_H
# define API_STDINT_H <stdint.h>
#endif

// STD TYPES REDEF
#ifndef API_UINT8
# define API_UINT8 uint8_t
#endif

#ifndef API_UINT16
# define API_UINT16 uint16_t
#endif

#ifndef API_UINT32
# define API_UINT32 uint32_t
#endif

#ifndef API_UINT64
# define API_UINT64 uint64_t
#endif

#ifndef API_INT8
# define API_INT8 int8_t
#endif

#ifndef API_INT16
# define API_INT16 int16_t
#endif

#ifndef API_INT32
# define API_INT32 int32_t
#endif

#ifndef API_INT64
# define API_INT64 int64_t
#endif

// ALLOC REDEF
#ifndef API_MALLOC
# define API_MALLOC(size) malloc(size)
#endif

#ifndef API_FREE
# define API_FREE(ptr) free(ptr)
#endif

#ifndef API_CALLOC
# define API_CALLOC(size) calloc(size)
#endif

#endif // !IH_CONF_H
