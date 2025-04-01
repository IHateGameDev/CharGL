#include "../CharGL/Color.h"

API void cglColorHSL(CglColor color, float h, float s, float l) {
  if (s == 0)
    color[0] = color[1] = color[2] = l;
  else {
    float q = l < 0.5 ? l * (1 + s) : l + s - l * s;
    float p = 2 * l - q;
    float hk = h / 360;

    float t[3] = { hk + 1.0 / 3, hk, hk - 1.0 / 3 };
    for (int i = 0; i < 3; i++) {
      if (t[i] < 0) t[i] += 1;
      if (t[i] > 1) t[i] -= 1;

      if (t[i] < 1.0 / 6)
        t[i] = p + (q - p) * 6 * t[i];

      else if (t[i] < 1.0 / 2)
        t[i] = q;

      else if (t[i] < 2.0 / 3)
        t[i] = p + (q - p) * (2.0 / 3 - t[i]) * 6;

      else
        t[i] = p;

      color[i] = (uint8_t)t[i] * 255;
    }
  }
}

API void cglColorHWB(CglColor color, float h, float w, float b) {
  float r, g, b_rgb;

  cglColorHSL(color, h, 1.0 - w, 0.5);
  r = color[0] / 255.0;
  g = color[1] / 255.0;
  b_rgb = color[2] / 255.0;

  r = (r + w) * (1 - b);
  g = (g + w) * (1 - b);
  b_rgb = (b_rgb + w) * (1 - b);

  color[0] = (uint8_t)(r * 255);
  color[1] = (uint8_t)(g * 255);
  color[2] = (uint8_t)(b_rgb * 255);
}

API void cglColorCMYK(CglColor color, float c, float m, float y, float k) {
  color[0] = 255 * (1 - c) * (1 - k);
  color[1] = 255 * (1 - m) * (1 - k);
  color[2] = 255 * (1 - y) * (1 - k);
}
