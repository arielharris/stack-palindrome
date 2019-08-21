// Ariel Harris
// stack.h
// Purpose: initiate the fucntions for the Stack class

#ifndef STACK_H
#define STACK_H

class Stack
{
 public:    // includes “Big 4” : constructor, destructor, overloaded, copy constructor
  explicit Stack(int stackSize = 16);    // constructor, gives default stack size, but if the user inputs a new size that one is used, the default doesn’t matter much b/c resizes
  ~Stack( );    //destructor
  Stack& operator=(const Stack& s);     //overloaded assignment operator
  Stack(const Stack& s);     //copy constructor
  bool push(char data);    //pass by value
  bool pop(char& data);     //pass by reference, return more than one thing from a function
  bool isEmpty( );

 private:  
  bool resize( );      //automatically resize, user does not initialize
  bool isFull( );
  char *list;      //the stack
  int size;
  int top;      //next item that would pop from top, but does not remove
};

#endif
