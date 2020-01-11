#include "ProtocolBase.h"

class SerialProtocol : public ProtocolBase
{
  public:
  MessageBase* getMessage(const uint8_t msgType) const;
  protected:
  private:
};
