#include <PartsCounter.h>

static const int SENSOR_PIN = 1;
static const int CLOCK_PIN = 2;
static const int DISPLAY_PIN = 3;

SimpleCounter counter;

void setup()
{
  counter.setSensor(new PhotoelectricSwitchSensor(SENSOR_PIN));
  counter.setDisplay(new SevenSegmentDisplay(CLOCK_PIN, DISPLAY_PIN));

  counter.start();
}

void loop()
{
  counter.update();
}


