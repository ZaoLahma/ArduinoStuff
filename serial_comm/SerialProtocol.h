#include "ProtocolBase.h"

class SerialProtocol : public ProtocolBase
{
  public:
  Vector<unsigned char> encodeMessage(const MessageBase& message) const;
  MessageBase* decodeMessage(const unsigned char* data, const uint16_t size) const;
  
  protected:
  private:
};
