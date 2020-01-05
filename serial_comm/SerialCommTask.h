#ifndef HEADER_SERIAL_COMM_TASK
#define HEADER_SERIAL_COMM_TASK

#include "TaskBase.h"

class SerialCommTask : public TaskBase
{
  public:
  SerialCommTask(const uint16_t runPeriodicity, const unsigned long baudRate);

  protected:
  
  void execute(const unsigned long newTime);

  private:
};

#endif
