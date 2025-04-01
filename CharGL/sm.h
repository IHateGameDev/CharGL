#ifndef IH_SM_H
#define IH_SM_H

/*
**  Example:
**    typedef struct {
**      int sP1 private;                       // Compiler show warning if use this member
**      float sP2;                             // Compiler don't show warning
**    } SomeStc
*/
#ifndef private
# define private __attribute__((deprecated("This is private struct member")))
#endif

/*
**  Example:
**    friendly void someFun(SomeStc* stc) {
**      stc->sP2 = stc->sP1;                   // No have warning
**    }
*/
#ifndef friendly
# define friendly __attribute__((deprecated("Use private members whit no have warnings")))
#endif

/*
**  Example:
**    typedef struct {
**      local int sP1;                         // Can't use out def file
**    } SomeStc2
*/
#ifndef local
# define local __attribute__((visibility("internal")))
#endif

/*
**  Example:
**    typedef struct {
**      mlocal int sP1;                        // Can't use out module
**    } SomeStc3
*/
#ifndef mlocal
# define mlocal __attribute__((visibility("hidden")))
#endif

#ifndef API
# ifndef API_SHARED_BUILD
#   define API_SHARED_BUILD 0
# endif // !API_SHARED_BUILD

# ifndef API_SHARED_USE
#   define API_SHARED_USE 0
# endif // !API_SHARED_USE

# include <bx/platform.h>
# if BX_PLATFORM_WINDOWS || BX_PLATFORM_WINRT
#   define API_SYM_EXP __declspec(dllexport)
#   define API_SYM_IMP __declspec(dllimport)
# else
#   define API_SYM_EXP __attribute__((visibility("default")))
#   define API_SYM_IMP
# endif // BX_PLATFORM_WIN*

# if API_SHARED_BUILD
#   define API_SHARED_LIB API_SYM_EXP
# elif API_SHARED_USE
#   define API_SHARED_LIB API_SYM_IMP
# else
#   define API_SHARED_LIB
# endif // API_SHARED_*

# ifdef __cplusplus
#   define API extern "C" API_SHARED_LIB
# else
#   define API API_SHARED_LIB
# endif
#endif

/*
**  Example: 
**    ...
**    ON_DEBUG(
**      if(!errID)
**        printf("Error ID: %u", errID)
**    )
**    ...
*/
#ifdef DEBUG
# define ON_DEBUG(action) do { action } while (0)
#else
# define ON_DEBUG(action)
#endif

#ifndef API_MALLOC
# define API_MALLOC(size) malloc(size)
#endif

#ifndef API_FREE
# define API_FREE(ptr) free(ptr)
#endif

#ifndef API_CALLOC
# define API_CALLOC(size) calloc(size)
#endif

#endif // !IH_SM_H
