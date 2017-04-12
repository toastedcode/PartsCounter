#pragma once

#include "SensorListener.hpp"

class Sensor
{

public:

   virtual void setEnabled(
     const bool& isEnabled) = 0;

   virtual bool isEnabled() = 0;

   virtual void setListener(
      SensorListener* listener) = 0;

   virtual void update() = 0;
};
