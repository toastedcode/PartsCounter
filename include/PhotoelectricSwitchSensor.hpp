#include "./interface/Sensor.hpp"
#include "./interface/SensorListener.hpp"

class PhotoelectricSwitchSensor : public Sensor
{

public:

   PhotoelectricSwitchSensor(
      const int& readPin);

   virtual ~PhotoelectricSwitchSensor();

   // **************************************************************************
   //                                Sensor interface

   virtual void setEnabled(
     const bool& isEnabled);

   virtual bool isEnabled();

   virtual void setListener(
      SensorListener* listener);

   virtual void update();

private:

   bool isSensorEnabled;

   int readPin;

   SensorListener* listener;

   bool isTriggered;

};
