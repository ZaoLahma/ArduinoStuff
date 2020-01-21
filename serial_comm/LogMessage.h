#ifndef HEADER_LOG_MESSAGE
#define HEADER_LOG_MESSAGE

#include "MessageBase.h"
#include "Arduino.h"

class LogMessage : public MessageBase
{
  public:
  LogMessage(const String messge);
  Vector<unsigned char> encode();
  void decode(const unsigned char* data, const uint16_t size);

  protected:
  String payload;

  private:
};

#endif
