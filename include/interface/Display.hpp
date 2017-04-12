#pragma once

class Display
{

public:

   virtual void setDisplayValue(
      const int& value) = 0;

   virtual int getDisplayValue() = 0;
};
