#ifndef HEADER_PROTOCOL_BASE
#define HEADER_PROTOCOL_BASE

#include "MessageBase.h"

class ProtocolBase
{
  public:
  virtual Vector<unsigned char> encodeMessage(const MessageBase& message) const = 0;
  virtual MessageBase* decodeMessage(const unsigned char* data, const uint16_t size) const = 0;

  protected:

  private:
};

#endif
