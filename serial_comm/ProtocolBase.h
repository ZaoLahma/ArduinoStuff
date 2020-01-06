#ifndef HEADER_PROTOCOL_BASE
#define HEADER_PROTOCOL_BASE

class ProtocolBase
{
  public:
  MessageBase* decode(const char* data) = 0;

  protected:

  private:
};

#endif
