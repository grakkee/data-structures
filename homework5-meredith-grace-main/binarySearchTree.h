//BinarySearchTree.h

#ifndef RANDOMVALUEGENERATION_BINARYSEARCHTREE_H
#define RANDOMVALUEGENERATION_BINARYSEARCHTREE_H

template < class ItemType >
class BinaryNode {

private:

    ItemType item;

    BinaryNode<ItemType>* leftChildPtr;

    BinaryNode<ItemType>* rightChildPtr;

public:

    //constructors and destructors

    BinaryNode ();

    BinaryNode (const ItemType & anItem);

    BinaryNode (const ItemType & anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

    //public operations

    void setItem (const ItemType & anItem);

    ItemType getItem () const;

    bool isLeaf () const;

    BinaryNode<ItemType>* getLeftChildPtr () const;

    BinaryNode<ItemType>* getRightChildPtr () const;

    void setLeftChildPtr (BinaryNode<ItemType>* leftPtr);

    void setRightChildPtr (BinaryNode<ItemType>* rightPtr);

};

/**
Unsorted binary tree class. Uses binary nodes to build the tree. Adapted from textbook code.
*/

template < class ItemType >
class BinaryNodeTree {

private:

    BinaryNode<ItemType>* rootPtr;

protected:

    //helper functions

    int getHeightHelper (BinaryNode<ItemType>* subTreePtr) const;

    int getNumberOfNodesHelper (BinaryNode<ItemType>* subTreePtr) const;

    void destroyTree (BinaryNode<ItemType>* subTreePtr);

    BinaryNode<ItemType>* balancedAdd (BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);

    BinaryNode<ItemType>* removeValue (BinaryNode<ItemType>* subTreePtr, const ItemType target, bool & success);

    BinaryNode<ItemType>* moveValuesUpTree (BinaryNode<ItemType>* subTreePtr);

    BinaryNode<ItemType>* findNode (BinaryNode<ItemType>* treePtr, const ItemType & target, bool & success) const;

    BinaryNode<ItemType>* copyTree (const BinaryNode<ItemType>* treePtr) const;

    void preorder (void visit (ItemType &), BinaryNode<ItemType>* treePtr) const;

    void inorder (void visit (ItemType &), BinaryNode<ItemType>* treePtr) const;

    void postorder (void visit (ItemType &), BinaryNode<ItemType>* treePtr) const;

public:

    //constructors and destructors

    BinaryNodeTree ();

    BinaryNodeTree (const ItemType & rootItem);

    BinaryNodeTree (const ItemType & rootItem, const BinaryNodeTree<ItemType>* leftTreePtr,
                    const BinaryNodeTree<ItemType>* rightTreePtr);

    BinaryNodeTree (const BinaryNodeTree<ItemType>& tree);

    virtual ~ BinaryNodeTree ();

    //public operations

    bool isEmpty () const;

    int getHeight () const;

    int getNumberOfNodes () const;

    ItemType getRootData () const;

    void setRootData (const ItemType & newData);

    bool add (const ItemType & newData);

    bool remove (const ItemType & data);

    void clear ();

    ItemType getEntry (const ItemType & anEntry) const;

    bool contains (const ItemType & anEntry) const;

    void preorderTraverse (void visit (ItemType &)) const;

    void inorderTraverse (void visit (ItemType &)) const;

    void postorderTraverse (void visit (ItemType &)) const;

    //overloaded operators

    BinaryNodeTree<ItemType>& operator= (const BinaryNodeTree & rightHandSide);

};

//Sorted binary tree class.

template < class ItemType >
class BinarySearchTree:public BinaryNodeTree<ItemType>{

private:

    BinaryNode<ItemType>* rootPtr;

protected:

    //helper functions

    BinaryNode<ItemType>* insertInorder (BinaryNode<ItemType>* subTreePtr,
                                         BinaryNode<ItemType>* newNodePtr);

    BinaryNode<ItemType>* removeValue (BinaryNode<ItemType>* subTreePtr,
                                       const ItemType target, bool & success);

    BinaryNode<ItemType>* removeNode (BinaryNode<ItemType>* nodePtr);

    BinaryNode<ItemType>* removeLeftmostNode (BinaryNode<ItemType>* nodePtr,
                                              ItemType & inorderSuccessor);

    BinaryNode<ItemType>* findNode (BinaryNode<ItemType>* treePtr,
                                    const ItemType & target) const;

public:

    //constructors and destructors

    BinarySearchTree ();

    BinarySearchTree (const ItemType & rootItem);

    BinarySearchTree (const BinarySearchTree<ItemType>&tree);

    virtual ~ BinarySearchTree ();

    //public operations

    bool isEmpty () const;

    int getHeight () const;

    int getNumberOfNodes () const;

    ItemType getRootData () const;

    void setRootData (const ItemType & newData);

    bool add (const ItemType & newEntry);

    bool remove (const ItemType & anEntry);

    void clear ();

    ItemType getEntry (const ItemType & anEntry) const;

    bool contains (const ItemType & anEntry) const;

    void preorderTraverse (void visit (ItemType &)) const;

    void inorderTraverse (void visit (ItemType &)) const;

    void postorderTraverse (void visit (ItemType &)) const;

    //overloaded operators

    BinarySearchTree<ItemType>& operator= (const BinarySearchTree<ItemType>& rightHandSide);

};

#endif //RANDOMVALUEGENERATION_BINARYSEARCHTREE_H

