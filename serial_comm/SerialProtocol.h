#include "ProtocolBase.h"

/**
 * SerialProtocol is responsible for
 * constructing Message instances from 
 * incoming byte encoded data, and
 * constructing byte encoded data from
 * Message instances.
 */
class SerialProtocol : public ProtocolBase
{
  public:
  Vector<unsigned char> encodeMessage(const MessageBase& message) const;
  MessageBase* decodeMessage(const unsigned char* data, const uint16_t size) const;
  
  protected:
  private:
};
