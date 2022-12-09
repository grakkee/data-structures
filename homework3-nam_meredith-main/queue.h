//This is the interface for the queue of the program

#ifndef QUEUE_H
#define QUEUE_H

template <class ItemType>
class QueueInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& newEntry) = 0;
    virtual bool dequeue() = 0;
    virtual ItemType peekFront() const = 0;
};
#endif