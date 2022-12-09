#ifndef LIST_INTERFACE
#define LIST_INTERFACE

#include <iostream>
using namespace std; 

template <class itemType>

class ListInterface{

public:
    virtual bool isEmpty() const = 0;
    virtual int getLength() const = 0;
    virtual bool insert(int newPosition, const itemType& newEntry) = 0;
    virtual bool remove(int position) = 0;
    virtual void clear() = 0;
    virtual itemType replace(int position, const itemType& newEntry) = 0; 
    virtual itemType getEntry(int position) const = 0; 
    virtual ~ListInterface() { }
};

#endif