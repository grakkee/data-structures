//This also serves as a priority Queue class

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "queue.h"

template <class ItemType>
class ArrayQueue: public QueueInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType line[DEFAULT_CAPACITY];
    int itemCount;
    int front;
    int back;
public:
    ArrayQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};

#include "arrayQueue.cpp"
#endif
