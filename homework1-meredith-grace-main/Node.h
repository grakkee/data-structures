#ifndef NODE
#define NODE

template <class itemType>
class Node{
    itemType item;
    Node<itemType>* next;

public:
    Node();
    Node(const itemType& anItem);
    Node(const itemType& anItem, Node<itemType>* nextNodePtr);

    void setItem(const itemType& anitem);
    void setNext(Node<itemType>* nextNodePtr);
    itemType getItem() const;
    Node<itemType>* getNext() const;

};

#include "Node.cpp"
#endif