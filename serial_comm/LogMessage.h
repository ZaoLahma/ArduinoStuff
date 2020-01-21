#ifndef HEADER_LOG_MESSAGE
#define HEADER_LOG_MESSAGE

#include "MessageBase.h"
#include "Arduino.h"

/**
 * Log message
 */
class LogMessage : public MessageBase
{
  public:
  LogMessage(const String messge);
  Vector<unsigned char> encode() const;
  void decode(const unsigned char* data, const uint16_t size);

  protected:
  String payload;

  private:
};

#endif
