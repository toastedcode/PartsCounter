#include <SevenSegmentTM1637.h>

#include "./interface/Display.hpp"

class SevenSegmentDisplay : public Display
{

public:

   SevenSegmentDisplay(
      const int& clockPin,
      const int& writePin);

   virtual ~SevenSegmentDisplay();

   // **************************************************************************
   //                             Display interface

   virtual void setDisplayValue(
      const int& value);

   virtual int getDisplayValue();

private:

   SevenSegmentTM1637* display;

   int displayValue;

};
