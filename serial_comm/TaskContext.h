#ifndef HEADER_TASK_CONTEXT
#define HEADER_TASK_CONTEXT

#include "TaskBase.h"
#include "Vector.h"

class TaskContext
{
  public:
  void run();
  void add_task(TaskBase* const task);

  protected:
  Vector<TaskBase*> tasks = Vector<TaskBase*>(1);

  private:
};

#endif
