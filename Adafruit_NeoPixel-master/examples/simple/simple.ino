// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            11

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      150

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  testing(60);
  
}


//Jessie is trying random things
void testing(uint8_t wait) {
  //int colorsY[] {0,25,50,75,100,150,200,225};
  int i = 0;
  while(i<pixels.numPixels()){
    i+=10;
    for(int j=0; j<pixels.numPixels(); j++) {
        reset(60);
        pixels.setPixelColor(j, Wheel((i) & 255));
        pixels.show();
        delay(wait);
    }     
  }
}

void reset(uint8_t wait) {
  for(int i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  delay(wait);
}


void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (int i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      pixels.show();

      delay(wait);

      for (int i=0; i < pixels.numPixels(); i=i+3) {
        pixels.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

void bearbotics(uint8_t wait)
{
  
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

//RANDOM 
/*void rainbowGoingUp(uint8_t wait) {
  int colorsY[] {0,25,50,75,100,150,200,225};
  for(int i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  delay(wait);
  for(int i=0; i<pixels.numPixels(); i++) {
      for(int j=0; j<pixels.numPixels(); j++) {
        pixels.setPixelColor(j, Wheel((colorsY[i]) & 255));
        pixels.show();
        delay(wait);
      }

 void rainbowGoingUpWithBlank(uint8_t wait) {
  int colorsY[] {0,25,50,75,100,150,200,225};
  for(int i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  delay(wait);
  for(int i=0; i<pixels.numPixels(); i++) {
        pixels.setPixelColor(i, Wheel((colorsY[i]) & 255));
        pixels.show();
        delay(wait);
  }
  
  }
  void rainbowDotFollow(uint8_t wait) {
  //int colorsY[] {0,25,50,75,100,150,200,225};
  for(int i=0; i<pixels.numPixels(); i++) {
    for(int j=0; j<pixels.numPixels(); j++) {
        reset(60);
        pixels.setPixelColor(j, Wheel((i) & 255));
        pixels.show();
        delay(wait);
    }
  }
}*/







