#ifndef STACK_INTERFACE
#define STACK_INTERFACE

#include <iostream>
using namespace std;

template<class itemType>
class stackInterface{
public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const itemType& newEntry) = 0; //adds item
    virtual bool pop() = 0; //removes item
    virtual itemType peek() const = 0; //retrieves item from the top of stack 
    virtual ~stackInterface() { }
};
#endif