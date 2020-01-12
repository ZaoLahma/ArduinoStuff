#include "ProgState.h"
#include "HandshakeMessage.h"
#include "HeartbeatMessage.h"
#include "LogMessage.h"
#include "MessageReceiver.h"
#include "Utils.h"

ProgStateTask::ProgStateTask(const uint16_t runPeriodicity, SerialCommIf* _commIf) : TaskBase(runPeriodicity), currState(State::INIT), commIf(_commIf)
{
  commIf->registerMsgReceiver(&messages);
}

void ProgStateTask::execute(const unsigned long newTime)
{
  UNUSED(newTime);
  switch (currState)
  {
    case State::INIT:
    {
      currState = State::CONNECTING;
    }
    break;

    case State::CONNECTING:
    { 
      MessageBase* msg = NULL;
      while (NULL != (msg = messages.getNextMessage()))
      {
        if (Messages::HANDSHAKE == msg->getType())
        {
          currState = State::CONNECTED;
          commIf->sendMsg(new LogMessage("Sending heartbeat"));
          commIf->sendMsg(new HeartbeatMessage());
        }
        delete msg;
      }

      if (State::CONNECTED != currState)
      {
        commIf->sendMsg(new HandshakeMessage());
      }
      commIf->sendMsg(new LogMessage("In state connecting"));
    }
    break;

    case State::CONNECTED:
    {
      bool heartbeatReceived = false;
      MessageBase* msg = NULL;
      while (NULL != (msg = messages.getNextMessage()))
      {
        if (Messages::HEARTBEAT == msg->getType())
        {
          commIf->sendMsg(new LogMessage("Heartbeat received"));
          heartbeatReceived = true;
        }
      }

      if (!heartbeatReceived)
      {
        currState = State::CONNECTING;
      }
      else
      {
        commIf->sendMsg(new HeartbeatMessage());
      }
    }
    break;

    default:
    break;
  }
}
