#ifndef HEADER_SERIAL_COMM_ACTOR
#define HEADER_SERIAL_COMM_ACTOR

#include "ActorBase.h"

class SerialCommActor : public ActorBase
{
  public:
  SerialCommActor(const unsigned int runPeriodicity);

  protected:
  void execute(const unsigned int newTime);

  private:
};

#endif
