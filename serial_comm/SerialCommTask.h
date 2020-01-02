#ifndef HEADER_SERIAL_COMM_TASK
#define HEADER_SERIAL_COMM_TASK

#include "TaskBase.h"

class SerialCommTask : public TaskBase
{
  public:
  SerialCommTask(const unsigned int runPeriodicity, const long baudRate);

  protected:
  
  void execute(const unsigned int newTime);

  private:
};

#endif
