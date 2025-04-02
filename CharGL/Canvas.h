#ifndef CGL_CANVAS_H
#define CGL_CANVAS_H

#include "Camera.h"
#include "cgl-conf.h"
#include "sm.h"

#ifndef CGL_POINT_SHADER
# define CGL_POINT_SHADER(buffer, x, y, brush) buffer[x*y] = brush
#endif

typedef struct {
  CGL_CHAR* buffer;
  CglVector2u16 size;

  CglCamera* camera;
} CglCanvas;

API void cglCanvasInit(CglCanvas* canvas, CglVector2u16 size);
API void cglCanvasFree(CglCanvas* canvas);

API void cglCanvasSetCamera(CglCanvas* canvas, CglCamera* camera);
API void cglCanvasResetCamera(CglCanvas* canvas);

API void cglCanvasClear(CglCanvas* canvas, CGL_CHAR brush);

API void cglCanvasDrawLineRight(CglCanvas* canvas, CglVector2u16 position, API_U16 length, CGL_CHAR brush);
API void cglCanvasDrawLineLeft(CglCanvas* canvas, CglVector2u16 position, API_U16 length, CGL_CHAR brush);
API void cglCanvasDrawLineUp(CglCanvas* canvas, CglVector2u16 position, API_U16 length, CGL_CHAR brush);
API void cglCanvasDrawLineDown(CglCanvas* canvas, CglVector2u16 position, API_U16 length, CGL_CHAR brush);
API void cglCanvasDrawLine(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 end, CGL_CHAR brush);

API void cglCanvasDrawSring(CglCanvas* canvas, CglVector2u16 position, const CGL_CHAR* str);
API void cglCanvasDrawSringBack(CglCanvas* canvas, CglVector2u16 position, const CGL_CHAR* str);
API void cglCanvasDrawSringUp(CglCanvas* canvas, CglVector2u16 position, const CGL_CHAR* str);
API void cglCanvasDrawSringDown(CglCanvas* canvas, CglVector2u16 position, const CGL_CHAR* str);
API void cglCanvasDrawStringLine(CglCanvas* canvas, CglVector2u16 start, CglVector2u16 end, const CGL_CHAR* str);

API void cglCanvasDrawRect(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, CGL_CHAR brush);
API void cglCanvasDrawRectLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, CGL_CHAR brush);

API void cglCanvasDrawTriangle(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], CGL_CHAR brush);
API void cglCanvasDrawTriangleLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], CGL_CHAR brush);

API void cglCanvasFloodFill(CglCanvas* canvas, CglVector2u16 start, CGL_CHAR replacement, CGL_CHAR brush);
#endif // !CGL_CANVAS_H
