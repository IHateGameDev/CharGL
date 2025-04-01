#ifndef CGL_COLOR_H
#define CGL_COLOR_H

#include <stdint.h>
#include "sm.h"

typedef uint8_t CglColor[3];

API void cglColorHSL(CglColor color, float h, float s, float l);

API void cglColorHWB(CglColor color, float h, float w, float b);

API void cglColorCMYK(CglColor color, float c, float m, float y, float k);

#endif // !CGL_COLOR_H
