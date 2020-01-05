#include "TaskContext.h"
#include "Arduino.h"

void TaskContext::run()
{
  for (uint16_t i = 0u; i < tasks.size(); ++i)
  {
    tasks.element_at(i)->run(millis());
  }
}

void TaskContext::add_task(TaskBase* const task)
{
  tasks.push_back(task);
}
