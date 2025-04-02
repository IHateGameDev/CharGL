#include "../CharGL/Canvas.h"
#ifndef API_NI_STDLIB_H
# include API_STDLIB_H
#endif
#ifndef API_NI_STRING_H
# include API_STRING_H
#endif

API void cglCanvasInit(CglCanvas* canvas, CglVector2u16 size) {
  API_U32 bufferLength = size[0] * size[1];

  canvas->buffer = API_MALLOC(bufferLength);
  API_MEMSET(canvas->buffer, ' ', bufferLength);

  canvas->size[0] = size[0];
  canvas->size[1] = size[1];

  canvas->camera = nullptr;
}

API void cglCanvasFree(CglCanvas* canvas) {
  API_FREE(canvas->buffer);
  API_FREE(canvas->camera);
}

API void cglCanvasClear(CglCanvas* canvas, CGL_CHAR brush) {
  API_MEMSET(canvas->buffer, brush, canvas->size[0] * canvas->size[1]);
}

API void cglCanvasSetCamera(CglCanvas* canvas, CglCamera* camera) {
  canvas->camera = camera;
}

API void cglCanvasResetCamera(CglCanvas* canvas) {
  canvas->camera = nullptr;
}

inline bool checkBounds(const CglVector2u16 bounds[static 2], const CglVector2u16 point) {
  return (bounds[0][0] <= point[0] && bounds[1][0] >= point[0] &&   // Check x
          bounds[0][1] <= point[1] && bounds[1][1] >= point[1]);    // Check y
}

inline void cglDrawPixel(CglCanvas* canvas, const CglVector2u16 position, const CGL_CHAR* brush) {
  if(canvas->camera != nullptr)
  {
    CglCamera* camera = canvas->camera;
    API_U16 x0 = camera->origin[0] + camera->position[0];
    API_U16 y0 = camera->origin[1] + camera->position[1];

    if(checkBounds({{x0, y0}, {}}))

  } 
  CGL_POINT_SHADER(canvas->buffer, position[0], position[1], *brush);
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
