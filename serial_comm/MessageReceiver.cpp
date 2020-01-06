#include "MessageReceiver.h"

#include "Arduino.h"

MessageReceiver::MessageReceiver() : currMessage(0u)
{
  
}

MessageBase* MessageReceiver::getNextMessage()
{
  MessageBase* retVal = NULL;
  if (messages.size() > currMessage)
  {
    retVal = messages.element_at(currMessage);
    currMessage++;
  }

  return retVal;
}

void MessageReceiver::receiveMessage(MessageBase* msg)
{
  messages.push_back(msg);
}
