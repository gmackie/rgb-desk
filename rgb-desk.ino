#include <Adafruit_NeoPixel.h>
// constants won't change. They're used here to set pin numbers:
const int ledPin = D2; // the number of the neopixel strip 
const int numLeds = 255;
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, ledPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin(); 
  strip.setBrightness(80); // 1/3 brightness
}

void loop() {
  rainbow(30);
  delay(10);
}

void rainbow(uint8_t wait) {
  uint16_t i, j; 
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, wheel((i*1+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value. The colours are a transition r - g - b - back to r.
uint32_t wheel(byte wheelPos) {
  if(wheelPos < 85) {
    return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
  } 
  else if(wheelPos < 170) {
    wheelPos -= 85;
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  } 
  else {
    wheelPos -= 170;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
}
