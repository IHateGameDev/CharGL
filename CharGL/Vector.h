#ifndef CGL_VECTOR_H
#define CGL_VECTOR_H

#include "conf.h"

#include API_STDINT_H

#define __CGL_VECTORS(type, sufix)                                      \
  typedef struct { type x; type y; } CglVector2##sufix;                 \
  typedef struct { type x; type y; type z; } CglVector3##sufix;         \
  typedef struct { type x; type y; type z; type w; } CglVector4##sufix

__CGL_VECTORS(API_U8, u8);
__CGL_VECTORS(API_U16, u16);
__CGL_VECTORS(float, f);

#endif // !CGL_VECTOR_H
