#ifndef HEADER_TASK_BASE
#define HEADER_TASK_BASE

class TaskBase
{
  public:
  static const unsigned int UINT_MAX = 0xFFFFu;
  void run(const unsigned int newTimeStamp);

  TaskBase(const unsigned int _runPeriodicity);

  protected:
  const unsigned int runPeriodicity;
  unsigned int currTimeStamp = 0;
    
  virtual void execute(const unsigned int newTime) = 0;

  private:
};

#endif
