#ifndef CGL_MATH_H
#define CGL_MATH_H

#include "Vector.h"
#include "conf.h"
#include "sm.h"

#ifndef API_NI_MATH_H
# include API_MATH_H
#endif

#ifndef SGL_PI
# define SGL_PI 3.14f //maybe extendet 1592
#endif

#ifndef DEG2RAD
# define DEG2RAD(degress) degress * (CGL_PI / 180.f)
#endif

#ifndef RAD2DEG
# define RAD2DEG(radians) radians * (180.f / CGL_PI)
#endif

inline void cglRotatePoint(CglVector2u16* point, CglVector2u16 center, float radians) {

}

#endif // !CGL_MATH_H
