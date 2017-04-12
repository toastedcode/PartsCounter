#pragma once

class Timer;

class TimerListener
{

public:

   virtual ~TimerListener() = 0;

   virtual void onTimeout(
      Timer* timer) = 0;
};
