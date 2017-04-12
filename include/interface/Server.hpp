#pragma once

#include "CommonDefs.hpp"
#include "ServerListener.hpp"

class Server
{

public:

   virtual void begin(
      const String& serverUrl,
      const int& port) = 0;

   virtual void loop() = 0;

   virtual bool connect();

   virtual bool disconnect() = 0;

   virtual bool isConnected() = 0;

   virtual bool sendOnline() = 0;

   virtual bool sendCount(
      const int& count,
      const int& sequenceNumber) = 0;

   virtual bool sendReset() = 0;

   virtual void setListener(
      const ServerListener* listener) = 0;
};
