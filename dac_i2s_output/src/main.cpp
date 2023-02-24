#include <Arduino.h>
#include <SPIFFS.h>
#include "WAVFileReader.h"
#include "DACOutput.h"

SampleSource *sampleSource;
DACOutput *output;

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting up");

  SPIFFS.begin();

  Serial.println("Created sample source");

  sampleSource = new WAVFileReader("/marty_soundtest.wav");

  Serial.println("Starting I2S Output");
  output = new DACOutput();
  output->start(sampleSource);

  int AMP_EN = 27;
  // enable amp
  gpio_pad_select_gpio((gpio_num_t)AMP_EN);
  gpio_set_direction((gpio_num_t)AMP_EN, GPIO_MODE_OUTPUT);
  gpio_set_level((gpio_num_t)AMP_EN, 1);
}

void loop()
{
  // nothing to do here - everything is taken care of by tasks
}