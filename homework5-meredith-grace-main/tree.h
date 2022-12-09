#ifndef TREE_INTERFACE
#define TREE_INTERFACE

template<class itemType>
class TreeInterface {
public: 
    virtual bool isEmpty() const = 0;
    virtual int getHeight() const = 0;
    virtual int getNumberOfNodes() const = 0;
    virtual itemType getRootData() const = 0;
    virtual bool add(const itemType& anEntry) = 0;
    virtual bool remove(const itemType& anEntry) = 0;
    virtual void clear() = 0;
    virtual itemType getEntry(const itemType& anEntry) const = 0;
    virtual bool contains(const itemType& anEntry) const  = 0;
    virtual ~TreeInterface() { }
};
#endif