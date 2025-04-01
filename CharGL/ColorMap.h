#ifndef CGL_COLOR_MAP_H
#define CGL_COLOR_MAP_H

#include "Color.h"
#include "Vector.h"
#include "sm.h"

typedef struct CglColorNode {
  CglVector2u16 position;
  CglColor color;
  uint16_t length;
  
  struct CglColorNode* next;
} CglColorNode;

typedef struct {
  CglColorNode* root;
  CglColorNode* end;
} CglColorMap;

API void cglColorMapInit(CglColorMap* map);
API void cglColorMapPush(CglColorMap* map, CglColorNode node);
API void cglColorMapEmplace(CglColorMap* map, CglVector2u16 position, CglColor color, uint16_t lengt);
API CglColorNode cglColorMapPop(CglColorMap* map);
API CglColorNode cslColorMapGet(CglColorMap map*);
API void cglColorMapFree(CglColorMap* map);

#endif // !CGL_COLOR_MAP_H
