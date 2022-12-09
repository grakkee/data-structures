#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
using namespace std; 

#include"list_interface.h"
#include "Node.h"

template <class itemType>
class LinkedList : public ListInterface<itemType>{
    Node<itemType>* headPtr;
    int itemCount;

public:
    Node<itemType>* getNodeAt(int position) const; 
    LinkedList();
    LinkedList(const LinkedList<itemType>& aList);
    virtual ~LinkedList();
    virtual bool isEmpty() const;
    virtual int getLength() const;
    virtual bool insert(int newPosition, const itemType& newEntry);
    virtual bool remove(int position);
    virtual void clear();
    virtual itemType getEntry(int position) const;
    virtual itemType replace(int position, const itemType& newEntry);

};

#include "linkedList.cpp"
#endif 