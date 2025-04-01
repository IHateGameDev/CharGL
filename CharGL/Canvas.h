#ifndef CGL_CANVAS_H
#define CGL_CANVAS_H

#include "Vector.h"
#include "sm.h"

typedef struct {
  char* buffer;
  CglVector2u16 size;
} CglCanvas;

API void cglCanvasInit(CglCanvas* canvas, CglVector2u16 size);
API void cglCanvasFree(CglCanvas* canvas);

API void cglCanvasSetPixel(CglCanvas* canvas, char brush);
API void cglCanvasClear(CglCanvas* canvas, char brush);

API void cglCanvasDrawSring(CglCanvas* canvas, CglVector2u16 position, const char* str);
API void cglCanvasDrawStringLine(CglCanvas* canvas, CglVector2u16 start, CglVector2u16 end, const char* str);

API void cglCanvasDrawRect(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, char brush);
API void cglCanvasDrawRectLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, char brush);

API void cglCanvasDrawTriangle(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], char brush);
API void cglCanvasDrawTriangleLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], char brush);

#endif // !CGL_CANVAS_H
