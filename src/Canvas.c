#include "../CharGL/Canvas.h"
#include <stdlib.h>
#include <string.h>

API void cglCanvasInit(CglCanvas* canvas, CglVector2u16 size) {
  uint32_t bufferLength = size[0] * size[1];

  canvas->buffer = API_MALLOC(bufferLength);
  memset(canvas->buffer, ' ', bufferLength);

  canvas->size[0] = size[0];
  canvas->size[1] = size[1];

  canvas->camera = nullptr;
}

API void cglCanvasFree(CglCanvas* canvas) {
  API_FREE(canvas->buffer);
  API_FREE(canvas->camera);
}

API void cglCanvasSetPixel(CglCanvas* canvas, char brush);
API void cglCanvasClear(CglCanvas* canvas, char brush);

API void cglCanvasPinCamera(CglCamera* camera);
API void cglCanvasUnpinCamera();

API void cglCanvasDrawSring(CglCanvas* canvas, CglVector2u16 position, const char* str);
API void cglCanvasDrawStringLine(CglCanvas* canvas, CglVector2u16 start, CglVector2u16 end, const char* str);

API void cglCanvasDrawLine(CglCanvas* canvas, CglVector2u16 start, CglVector2u16 end, char brush);

API void cglCanvasDrawRect(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, char brush);
API void cglCanvasDrawRectLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 size, char brush);

API void cglCanvasDrawTriangle(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], char brush);
API void cglCanvasDrawTriangleLines(CglCanvas* canvas, CglVector2u16 position, CglVector2u16 points[static 3], char brush);

API void cglCanvasDrawElipse(CglCanvas* canvas, CglVector2u16 position, uint16_t wRadius, uint16_t hRadius, char brush);
API void cglCanvasDrawElipseLines(CglCanvas* canvas, CglVector2u16 position, uint16_t wRadius, uint16_t hRadius, char brush);
