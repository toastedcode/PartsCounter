#pragma once

#include "./interface/Server.hpp"
#include "./interface/ServerListener.hpp"
#include "./interface/Sensor.hpp"
#include "./interface/SensorListener.hpp"
#include "Timer.hpp"
#include "TimerListener.hpp"
#include "./interface/Display.hpp"

class Counter : public ServerListener, SensorListener, TimerListener
{

public:

   Counter();

   virtual ~Counter();

   void update();

   void setServer(
      Server* server);

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
   //                        ServerListener implementation

   virtual void onConnected();

   virtual void onDisconnected();

   virtual void onConfirmed(
      const int& count,
      const int& sequenceNumber);

   // **************************************************************************
   //                        SensorListener implementation

   virtual void onTiggered();

   // **************************************************************************
   //                        TimerListener implementation

   virtual void onTimeout(
      Timer* timer);


private:

   void updateDisplay();

   Server* server;

   Sensor* sensor;

   Display* display;

   Timer* timer;

   bool enabled;

   int unconfirmedCount;

   int reportedCount;

   int confirmedCount;

   int confirmationFailure;

   int sequenceNumber;
};
