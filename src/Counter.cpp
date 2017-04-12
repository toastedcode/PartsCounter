#include "../include/CommonDefs.hpp"
#include "../include/Counter.hpp"

// *****************************************************************************
//                                    Public
// *****************************************************************************

static const int TIMER_PERIOD = 1000;  // 1 second

static const int CONFIRMATION_FAILURE_THRESHOLD = 10;  // 10 period (second)

Counter::Counter() :
   server(0),
   sensor(0),
   display(0),
   enabled(false),
   unconfirmedCount(0),
   reportedCount(0),
   confirmedCount(0)
{
   timer = new Timer(Timer::PERIODIC, TIMER_PERIOD);
   timer->setListener(this);

   updateDisplay();
}

Counter::~Counter()
{

}

void Counter::update()
{
   if (timer)
   {
      timer->update();
   }

   if (sensor)
   {
      sensor->update();
   }
}

void Counter::setServer(
   Server* server)
{
   this->server = server;
}

void Counter::setSensor(
   Sensor* sensor)
{
   this->sensor = sensor;
   sensor->setListener(this);
}

void Counter::setDisplay(
   Display* display)
{
   this->display = display;

   updateDisplay();
}

void Counter::start()
{
   enabled = true;

   if (sensor)
   {
      sensor->setEnabled(true);
   }

   if (timer)
   {
      timer->start();
   }
}

void Counter::reset()
{
   unconfirmedCount = 0;
   reportedCount = 0;
   confirmedCount = 0;

   if (server && server->isConnected())
   {
      // TODO: No ACK mechanism for reset.
      server->sendReset();
   }

   updateDisplay();
}

void Counter::stop()
{
   enabled = false;

   if (sensor)
   {
      sensor->setEnabled(false);
   }

   if (timer)
   {
      timer->stop();
   }
}

inline int Counter::getCount()
{
   return (unconfirmedCount + reportedCount + confirmedCount);
}

// **************************************************************************
//                        ServerListener implementation

void Counter::onConnected()
{
   // TODO: Logging.
}

void Counter::onDisconnected()
{
   // TODO: Logging.
}

void Counter::onConfirmed(
   const int& count,
   const int& sequenceNumber)
{
   if (sequenceNumber != this->sequenceNumber)
   {
      // TODO: Logging.
   }
   else if (count != reportedCount)
   {
      // TODO: Logging.
   }
   else
   {
      // Move reported count into confirmed count.
      confirmedCount += reportedCount;
      reportedCount = 0;
      confirmationFailure = 0;
   }
}

// **************************************************************************
//                        SensorListener implementation

void Counter::onTiggered()
{
   PRINTF("onTriggered\n");

   if (enabled)
   {
      // TODO: Logging.

      unconfirmedCount++;

      updateDisplay();
   }
}

// **************************************************************************
//                        TimerListener implementation

void Counter::onTimeout(
   Timer* timer)
{
   PRINTF("onTimeout\n");

   if (enabled)
   {
      // If we have any counts to report ...
      if (unconfirmedCount > 0)
      {
         // If we have a connection to the server ...
         if (server && server->isConnected())
         {
            // If we have no outstanding reported counts ...
            if (reportedCount == 0)
            {
               // Report the count.
               if (server->sendCount(unconfirmedCount, sequenceNumber))
               {
                  // Increment the sequence number.
                  sequenceNumber++;

                  // Move unconfirmed count into reported count.
                  reportedCount = unconfirmedCount;
                  unconfirmedCount = 0;
               }
               else
               {
                  // Failed to send.
                  // TODO: Logging.
               }
            }
            else
            {
               // We haven't heard back from the server for another period.
               confirmationFailure++;

               if (confirmationFailure >= CONFIRMATION_FAILURE_THRESHOLD)
               {
                  // TODO: Logging.

                  // Move reported back into unconfirmed.
                  unconfirmedCount += reportedCount;
                  reportedCount = 0;
                  confirmationFailure = 0;
               }
            }
         }
      }
   }
   else
   {
      // Stop this rogue timer.
      timer->stop();
   }
}

// *****************************************************************************
//                                    Private
// *****************************************************************************

void Counter::updateDisplay()
{
   if (display)
   {
      display->setDisplayValue(getCount());
   }
}
