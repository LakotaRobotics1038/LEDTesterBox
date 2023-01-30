#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

// defines the test string
#define TEST_PIN 8
#define LED_COUNT 128
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, TEST_PIN, NEO_GRB + NEO_KHZ800);

//defines the power LED
#define POWER_PIN 4
#define POWER_COUNT 1
Adafruit_NeoPixel power = Adafruit_NeoPixel(POWER_COUNT, POWER_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  // put your setup code here, to run once:
  power.begin();
  leds.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  
  //whenever its on, turn this light green
  power.setPixelColor(0, GREEN);
  power.show();

  
  cascade (BLUE, TOP_DOWN, 10);
  cascade (PURPLE, TOP_DOWN, 10);
}

void cascade(unsigned long color, byte direction, byte wait)
{
  if (direction == TOP_DOWN)
  {
    for (int i = 0; i < LED_COUNT; i++)
    {
      clearLEDs();  // Turn off all LEDs
      leds.setPixelColor(i, color);  // Set just this one
      leds.show();
      delay(wait);
    }
  }
  else
  {
    for (int i = LED_COUNT - 1; i >= 0; i--)
    {
      clearLEDs();
      leds.setPixelColor(i, color);
      leds.show();
      delay(wait);
    }
  }
}
void clearLEDs()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}
