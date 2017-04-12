#pragma once

class ServerListener
{

public:

   virtual void onConnected() = 0;

   virtual void onDisconnected() = 0;

   virtual void onConfirmed(
      const int& count,
      const int& sequenceNumber) = 0;
};
