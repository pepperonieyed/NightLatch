#include <Arduino.h>
#include <Arduino_GFX_Library.h>
#include <Arduino_GFX.h>

#include "nightlatch.hpp"

// Setup display driver (Arduino_GFX)
Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
  41, 40, 39, 42, 14, 21, 47, 48, 45, 9, 46, 3, 8, 16, 1, 15, 7, 6, 5, 4,
  0, 210, 30, 16, 0, 22, 13, 10, 1, 16000000
);
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(DISP_WIDTH, DISP_HEIGHT, bus, 1);

void setup() {
  // Initialise display driver
  gfx->begin();
  gfx->fillScreen(BLACK);

  pinMode(DISP_BL_PIN, OUTPUT);
  analogWrite(DISP_BL_PIN, 255);
}

void loop() {}
