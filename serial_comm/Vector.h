#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include "Arduino.h"

template <class T>
class Vector
{
  public:
  Vector<T>(const unsigned int vectorCapacity) : elementCapacity(vectorCapacity), numDataElements(0)
  {
    elements = new T[elementCapacity];
  }

  ~Vector<T>()
  {
    delete[] elements;
  }

  void push_back(const T& element)
  {
    if (!(numDataElements < elementCapacity))
    {
      //Copy all values to new array
      elementCapacity = 2 * elementCapacity;
      T* elementsCopy = new T[elementCapacity];
      for (unsigned int i = 0; i < numDataElements; ++i)
      {
        elementsCopy[i] = elements[i];
      }
      delete[] elements;
      elements = elementsCopy;
    }
    
    elements[numDataElements] = element;
    numDataElements++;
  }

  T& element_at(const unsigned int index)
  {
    return elements[index];
  }

  const unsigned int get_size()
  {
    return numDataElements;
  }

  void clear()
  {
    numDataElements = 0;
  }
  
  protected:
  unsigned int elementCapacity;
  
  T* elements;

  private:
  unsigned int numDataElements;
  
};

#endif
