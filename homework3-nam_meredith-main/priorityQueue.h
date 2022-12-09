#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "queue.h"

template <class ItemType>
class PriorityQueue: public QueueInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 100;
    ItemType line[DEFAULT_CAPACITY - 1];
    int itemCount;
    int front;
    int back;
public:
    PriorityQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
};

#include "priorityQueue.cpp"
#endif
