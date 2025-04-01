#ifndef CGL_CAMERA_H
#define CGL_CAMERA_H

#include "Vector.h"

typedef struct {
  CglVector2u16 position;
  CglVector2u16 origin;
  CglVector2u16 size;

  float zoom;
  float rotation;
} CglCamera;

#endif // !CGL_CAMERA_H
