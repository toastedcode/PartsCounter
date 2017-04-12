#pragma once

class Timer;

class TimerListener
{

public:

   virtual void onTimeout(
      Timer* timer) = 0;
};
