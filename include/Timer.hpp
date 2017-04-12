#pragma once

#include "TimerListener.hpp"

class Timer
{

public:

   enum TimerType
   {
      ONE_SHOT,
      PERIODIC
   };

   Timer(
      const TimerType& type,
      const int& period);

   virtual ~Timer();

   void update();

   void start();

   void stop();

   bool isStarted() const;

   bool isExpired() const;

   void setListener(
      TimerListener* listener);

private:

   unsigned long getSystemTime();

   TimerType type;

   int period;

   TimerListener* listener;

   bool inUse;

   unsigned long startTime;

   unsigned long expireTime;
};
