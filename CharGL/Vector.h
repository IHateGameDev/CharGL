#ifndef CGL_VECTOR_H
#define CGL_VECTOR_H

#include "conf.h"

#include API_STDINT_H

#define __CGL_VECTORS(type, sufix)      \
  typedef type CglVector2##sufix [2];   \
  typedef type CglVector3##sufix [3];   \
  typedef type CglVector4##sufix [4]

__CGL_VECTORS(API_UINT8, u8);
__CGL_VECTORS(API_UINT16, u16);
__CGL_VECTORS(API_UINT32, f);

#endif // !CGL_VECTOR_H
