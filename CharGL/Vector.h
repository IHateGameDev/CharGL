#ifndef CGL_VECTOR_H
#define CGL_VECTOR_H

#include <stdint.h>

#define __CGL_VECTORS(type, sufix)      \
  typedef type CglVector2##sufix [2];   \
  typedef type CglVector3##sufix [3];   \
  typedef type CglVector4##sufix [4]

__CGL_VECTORS(uint8_t, u8);
__CGL_VECTORS(uint16_t, u16);
__CGL_VECTORS(float, f);

#endif // !CGL_VECTOR_H
