#ifndef HEADER_MESSAGE_BASE
#define HEADER_MESSAGE_BASE

#include "Messages.h"
#include "Vector.h"

class MessageBase
{
  public:
  MessageBase(const Messages& type);
  virtual ~MessageBase() {}
  virtual Vector<unsigned char> encode() = 0;
  virtual void decode(const unsigned char* data, const uint16_t size) = 0;
  Messages getType();

  protected:
  const Messages msgType;
  private:
};

#endif
