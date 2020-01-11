#include "ProgState.h"
#include "HandshakeMessage.h"
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
      commIf->sendMsg(new HandshakeMessage());
      currState = State::CONNECTING;
    }
    break;

    case State::CONNECTING:
    {
      MessageBase* msg = messages.getNextMessage();
      while (NULL != msg)
      {
        if (Messages::HANDSHAKE == msg->getType())
        {
          currState = State::CONNECTED;
          commIf->sendMsg(new HandshakeMessage());
        }
        delete msg;
        msg = messages.getNextMessage();
      }
    }
    break;

    case State::CONNECTED:
    {
      commIf->sendMsg(new LogMessage("Still connected"));
    }
    break;

    default:
    break;
  }
}
