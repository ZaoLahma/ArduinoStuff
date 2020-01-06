#include "MessageBase.h"

MessageBase::MessageBase(const Messages& type) : msgType(type)
{
  
}

Messages MessageBase::getType()
{
  return msgType;
}
