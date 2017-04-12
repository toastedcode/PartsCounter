#pragma once

#include "./interface/Sensor.hpp"
#include "./interface/SensorListener.hpp"
#include "./interface/Display.hpp"

class SimpleCounter : public SensorListener
{

public:

   SimpleCounter();

   virtual ~SimpleCounter();

   void update();

   void setSensor(
      Sensor* sensor);

   void setDisplay(
      Display* display);

   void start();

   void pause();

   void reset();

   void stop();

   int getCount();

   // **************************************************************************
   //                        SensorListener implementation

   virtual void onTiggered();


private:

   void updateDisplay();

   Sensor* sensor;

   Display* display;

   bool enabled;

   int count;
};
