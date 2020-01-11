#ifndef HEADER_PROTOCOL_BASE
#define HEADER_PROTOCOL_BASE

#include "MessageBase.h"

class ProtocolBase
{
  public:
  virtual MessageBase* getMessage(const uint8_t msgType) const = 0;

  protected:

  private:
};

#endif
