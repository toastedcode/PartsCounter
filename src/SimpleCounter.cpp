#include "../include/CommonDefs.hpp"
#include "../include/SimpleCounter.hpp"

// *****************************************************************************
//                                    Public
// *****************************************************************************

SimpleCounter::SimpleCounter() :
   sensor(0),
   display(0),
   count(0)

{
   updateDisplay();
}

SimpleCounter::~SimpleCounter()
{

}

void SimpleCounter::update()
{
   if (sensor)
   {
      sensor->update();
   }
}

void SimpleCounter::setSensor(
   Sensor* sensor)
{
   this->sensor = sensor;
   sensor->setListener(this);
}

void SimpleCounter::setDisplay(
   Display* display)
{
   this->display = display;

   updateDisplay();
}

void SimpleCounter::start()
{
   enabled = true;

   if (sensor)
   {
      sensor->setEnabled(true);
   }
}

void SimpleCounter::reset()
{
   count = 0;

   updateDisplay();
}

void SimpleCounter::stop()
{
   enabled = false;

   if (sensor)
   {
      sensor->setEnabled(false);
   }
}

inline int SimpleCounter::getCount()
{
   return (count);
}

// **************************************************************************
//                        SensorListener implementation

void SimpleCounter::onTiggered()
{
   PRINTF("onTriggered\n");

   if (enabled)
   {
      // TODO: Logging.

      count++;

      updateDisplay();
   }
}

// *****************************************************************************
//                                    Private
// *****************************************************************************

void SimpleCounter::updateDisplay()
{
   if (display)
   {
      display->setDisplayValue(getCount());
   }
}
