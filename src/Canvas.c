#include "../CharGL/Canvas.h"
#ifndef API_NI_STDLIB_H
# include API_STDLIB_H
#endif
#ifndef API_NI_STRING_H
# include API_STRING_H
#endif

API void cglCanvasInit(CglCanvas* canvas, CglVector2u16 size) {
  API_U32 bufferLength = size.x * size.y;

  canvas->buffer = API_MALLOC(bufferLength);
  API_MEMSET(canvas->buffer, ' ', bufferLength);

  canvas->size = size;

  canvas->camera = nullptr;
}

API void cglCanvasFree(CglCanvas* canvas) {
  API_FREE(canvas->buffer);
  API_FREE(canvas->camera);
}

API void cglCanvasClear(CglCanvas* canvas, CGL_CHAR brush) {
  API_MEMSET(canvas->buffer, brush, canvas->size.x * canvas->size.y);
}

API void cglCanvasSetCamera(CglCanvas* canvas, CglCamera* camera) {
  canvas->camera = camera;
}

API void cglCanvasResetCamera(CglCanvas* canvas) {
  canvas->camera = nullptr;
}

inline void cglDrawPixel(CglCanvas* canvas, const CglVector2u16 position, CGL_CHAR brush) {
  if(canvas->camera != nullptr)
  {

  } 
  CGL_POINT_SHADER(canvas->buffer, position.x, position.y, brush);
}

API void cglCanvasDrawSring(CglCanvas* canvas, CglVector2u16 position, const char* str);
API void cglCanvasDrawStringLine(CglCanvas* canvas, CglVector2u16 start, CglVector2u16 end, const char* str);

API void cglCanvasDrawLine(CglCanvas* canvas, CglVector2u16 start, CglVector2u16 end, char brush);

API void cglCanvasDrawRect(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, char brush);
API void cglCanvasDrawRectLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, char brush);

API void cglCanvasDrawTriangle(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], char brush);
API void cglCanvasDrawTriangleLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], char brush);

API void cglCanvasDrawElipse(CglCanvas* canvas, CglVector2u16 position, uint16_t wRadius, uint16_t hRadius, char brush);
API void cglCanvasDrawElipseLines(CglCanvas* canvas, CglVector2u16 position, uint16_t wRadius, uint16_t hRadius, char brush);
