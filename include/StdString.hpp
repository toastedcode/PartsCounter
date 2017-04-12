#pragma once

#include <algorithm>
#include <sstream>
#include <string>

class StdString
{

public:

   StdString();

   StdString(
      const char& c);

   explicit StdString(
      const char* cString);

   StdString(
      const std::string& cppString);

   StdString(
      const StdString& stdString);

   template <typename T>
   StdString(
      const T& i)
   {
      std::ostringstream oss;

      oss << i;
      cppString = oss.str();
   }

   int length() const;

   const char* c_str() const;

   StdString operator+(
      const StdString& stdString) const;

   StdString operator+(
      const char* rhs) const;

   void operator+=(
      const StdString& rhs);

   bool operator==(
      const StdString& rhs) const;

   bool operator!=(
      const StdString& rhs) const;

   bool operator<(
      const StdString& rhs) const;

   char charAt(
      const int& index) const;

   float toFloat() const;

   int toInt() const;

   void toLowerCase();

   StdString substring(
      const int& from,
      const int& to = -1) const;

   int indexOf(
      const StdString& stdString,
      const int& from = 0) const;

   int indexOf(
      const char& c,
      const int& from = 0) const;

private:

   std::string cppString;
};

inline StdString::StdString() : cppString("")
{
}

inline StdString::StdString(
   const char& c) : cppString(1, c)
{
}


inline StdString::StdString(
   const char* cString) : cppString(cString)
{
}

inline StdString::StdString(
   const std::string& cppString) : cppString(cppString)
{
}

inline StdString::StdString(
   const StdString& stdString) : cppString(stdString.cppString)
{
}

inline int StdString::length() const
{
   return (cppString.length());
}

inline const char* StdString::c_str() const
{
   return (cppString.c_str());
}

inline StdString StdString::operator+(
   const StdString& rhs) const
{
   return (StdString(cppString + rhs.cppString));
}

inline StdString  StdString::operator+(
   const char* rhs) const
{
   return (StdString(cppString + rhs));
}

inline void StdString::operator+=(
   const StdString& rhs)
{
   cppString += rhs.cppString;
}

inline bool StdString::operator==(
   const StdString& rhs) const
{
   return (cppString == rhs.cppString);
}

inline bool StdString::operator!=(
   const StdString& rhs) const
{
   return (cppString != rhs.cppString);
}

inline bool StdString::operator<(
   const StdString& rhs) const
{
   return (cppString < rhs.cppString);
}

inline char StdString::charAt(
   const int& index) const
{
   return (cppString.at(index));
}

inline float StdString::toFloat() const
{
   float f= 0;
   std::istringstream(cppString) >> f;
   return (f);
}

inline int StdString::toInt() const
{
   int i= 0;
   std::istringstream(cppString) >> i;
   return (i);
}

inline void StdString::toLowerCase()
{
   std::transform(cppString.begin(), cppString.end(), cppString.begin(), ::tolower);
}

inline StdString StdString::substring(
   const int& from,
   const int& to) const
{
   return (StdString(cppString.substr(from, (to - from))));
}

inline int StdString::indexOf(
   const StdString& stdString,
   const int& from) const
{
   std::size_t pos = cppString.find(stdString.cppString, from);
   return ((pos != std::string::npos) ? static_cast<int>(pos) : -1);
}

inline int StdString::indexOf(
   const char& c,
   const int& from) const
{
   return (indexOf(StdString(c), from));
}
