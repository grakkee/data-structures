#ifndef LINKED_STACK
#define LINKED_STACK

#include <iostream>
using namespace std;

#include "stack.h"
#include "node.h"

template<class itemType>
class LinkedStack: public stackInterface<itemType>{
    Node<itemType>* headPtr;
    int top;
public:
    Node<itemType>* getNodeAt(int position) const;
    LinkedStack();
    LinkedStack(const LinkedStack<itemType>& aStack);
    virtual ~LinkedStack(){ }
    virtual bool isEmpty() const;
    virtual bool push(const itemType& newEntry); //adds item
    virtual bool pop(); //removes item
    virtual itemType peek() const; //retrieves item from the top of stack 

};
#include "linkedStack.cpp"
#endif