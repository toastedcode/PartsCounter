#include "../include/CommonDefs.hpp"
#include "../include/PhotoelectricSwitchSensor.hpp"

static const int TRIGGER_THRESHOLD = 50;

PhotoelectricSwitchSensor::PhotoelectricSwitchSensor(
   const int& readPin) :
      isSensorEnabled(false),
      readPin(readPin),
      listener(0),
      isTriggered(false)
{
   pinMode(readPin, INPUT);
}

PhotoelectricSwitchSensor::~PhotoelectricSwitchSensor()
{
}

inline void PhotoelectricSwitchSensor::setEnabled(
  const bool& isEnabled)
{
   isSensorEnabled = isEnabled;
}

inline bool PhotoelectricSwitchSensor::isEnabled()
{
   return (isSensorEnabled);
}

inline void PhotoelectricSwitchSensor::setListener(
   SensorListener* listener)
{
   this->listener = listener;
}

void PhotoelectricSwitchSensor::update()
{
   int sensorValue = digitalRead(readPin);

   bool wasTriggered = isTriggered;

   isTriggered = (sensorValue > TRIGGER_THRESHOLD);

   if (!wasTriggered && isTriggered)
   {
      PRINTF("Triggered\n");

      if (listener != 0)
      {
         listener->onTiggered();
      }
   }
   else if (wasTriggered && !isTriggered)
   {
      PRINTF("Untriggered\n");
   }
}
