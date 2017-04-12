#include "../include/SevenSegmentDisplay.hpp"

SevenSegmentDisplay::SevenSegmentDisplay(
   const int& clockPin,
   const int& writePin) :
      display(0),
      displayValue(0)
{
   display = new SevenSegmentTM1637(clockPin, writePin);

   display->begin();
   display->setBacklight(100);  // Set brightness to 100%
}

SevenSegmentDisplay::~SevenSegmentDisplay()
{
   delete display;
}

void SevenSegmentDisplay::setDisplayValue(
   const int& value)
{
   this->displayValue = displayValue;

   display->print(value);
}

int SevenSegmentDisplay::getDisplayValue()
{
   return (displayValue);
}
