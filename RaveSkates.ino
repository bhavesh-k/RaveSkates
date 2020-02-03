#include <Adafruit_NeoPixel_ZeroDMA.h>

#define PIN       4     // must be 4 for ZeroDMA lib support
#define NUMPIXELS 28
Adafruit_NeoPixel_ZeroDMA pixels(NUMPIXELS, PIN, NEO_GRB);

#define DELAYVAL    10  // loop delay (in milliseconds)
#define BRIGHTNESS  160 // out of 255

int i = 0;
static uint16_t hues[3] = {38593, 50062, 28035};

void setup() {
  pixels.begin();
}

void loop() {
  if (i%2) {
    pixels.fill(pixels.gamma32(pixels.ColorHSV(hues[i/2], 255, BRIGHTNESS)),
                0,
                NUMPIXELS);
  }
  else
    pixels.clear();

  i = (i + 1) % 6;
  
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
}
