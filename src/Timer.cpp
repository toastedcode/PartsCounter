#ifndef ARDUINO
#include <sys/time.h>
#endif

#include "../include/CommonDefs.hpp"
#include "../include/Timer.hpp"

// *****************************************************************************
//                                  Public
// *****************************************************************************

Timer::Timer(
   const Timer::TimerType& type,
   const int& period) :
      type(type),
      period(period),
      listener(0),
      inUse(false),
      startTime(0),
      expireTime(0)
{
}

Timer::~Timer()
{
}

void Timer::update()
{
   if (isStarted() && !isExpired())
   {
      unsigned long currentTime = getSystemTime();

      if (currentTime > expireTime)
      {
         if (isStarted() && (type == PERIODIC))
         {
            // Reset.
            startTime = getSystemTime();
            expireTime = (startTime + period);
         }
         else
         {
            // Set as expired.
            expireTime = 0;
         }

         // Alert the listener.
         if (listener)
         {
            listener->onTimeout(this);
         }
      }
   }
}

void Timer::start()
{
   if (period > 0)
   {
      startTime = getSystemTime();
      expireTime = (startTime + period);
   }
}

void Timer::stop()
{
   if (isStarted())
   {
      startTime = 0;
      expireTime = 0;
   }
}

inline bool Timer::isStarted() const
{
   return (startTime > 0);
}

inline bool Timer::isExpired() const
{
   return ((startTime > 0) && (expireTime == 0));
}

void Timer::setListener(
   TimerListener* listener)
{
   this->listener = listener;
}

// *****************************************************************************
//                                  Private
// *****************************************************************************

unsigned long Timer::getSystemTime()
{
   unsigned long milliseconds = 0;

#ifdef ARDUINO
   return (0);
#else
   struct timeval currentTime;

   gettimeofday(&currentTime, 0);

   unsigned long seconds = currentTime.tv_sec;
   unsigned long microseconds = currentTime.tv_usec;
   milliseconds = ((seconds * 1000L) + (unsigned long)(microseconds / 1000L + 0.5L));

#endif

   return (milliseconds);
}
