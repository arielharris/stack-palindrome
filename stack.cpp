// Ariel Harris
// Stack class design
// Purpose: Define functions of Stack class w/ dynamic array

#include "stack.h"

Stack::Stack(int stackSize) // constructor
{
  if (stackSize < 4)
    size = 16;
  else
    size = stackSize; // size is stackSize

  // allocate memory & set top

  list = new char[size];
  //check memory - not done here

  top = 0;
  // push, then top++
  // top--, then pop
}

Stack::~Stack( ) // destructor
{
  delete [] list; // use [] for an array delete
}

Stack& Stack::operator=(const Stack& rhs) // overload
// as long as what is on the lhs != rhs, set the lhs to what ever is the rhs
{
  if (this != &rhs) {
    top = rhs.top;
    size = rhs.size;

    delete [] list;

    list = new char[size];

    for (int i = 0; i < top; i++)
      list[i] = rhs.list[i];
  }
  
  return *this;
}

Stack::Stack(const Stack& s) //copy
{
  *this = s;
}

bool Stack::push(char data)
// given a char push the value onto the stack and incriment top
// if the stack is full call resize then push
{
  if (isFull()){
    resize();
    if (resize()){
      list[top] = data;
      top++;
      return true;
    }
    else {
      return false;
    }
  }
  else {
    list[top] = data;
    top++;
    return true;
  }
}

bool Stack::pop(char& data)
// as long as the stack isn't empty, remove the top char and decrease top
{
  if (isEmpty()){
    return false;
  }
  else {    
    top--;
    data = list[top];
    return true;
  }
  
}

bool Stack::isEmpty( )
{
  return top == 0;
}

bool Stack::resize( )
{
  // compute new size - 1.5* orig
  int tempSize = double(size) * 1.5;
  
  // allocate to temp pointer
  char *temp = new char[tempSize];

  // check we got the memory, not done here
  // copy data from orig to temp
  for (int i = 0; i < size; i++)
    temp[i] = list[i];

  // dealloacte original
  delete [] list;

  // update size to new size
  size = tempSize;

  // original = temp
  list = temp;

  return true;
}

bool Stack::isFull( )
{
  return top == size; 
}

char *list;      //the stack

int size;

int top;      //next item that would pop from top, but does not remove



