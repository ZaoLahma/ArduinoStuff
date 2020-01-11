#ifndef HEADER_LOG_MESSAGE
#define HEADER_LOG_MESSAGE

#include "MessageBase.h"
#include "Arduino.h"

class LogMessage : public MessageBase
{
  public:
  LogMessage(const String messge);
  Vector<char> encode();
  void decode(const char* data, const uint16_t size);

  protected:
  String payload;

  private:
};

#endif
