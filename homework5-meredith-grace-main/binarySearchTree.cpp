//BinarySearchTree.cpp

#include "binarySearchTree.h"
#include <iostream>
using namespace std;


template < class ItemType >
BinaryNode<ItemType>::BinaryNode()
{

    leftChildPtr = nullptr;

    rightChildPtr = nullptr;

}

template < class ItemType >
BinaryNode<ItemType>::BinaryNode ( const ItemType& anItem )
{

    //data assigned, set left and right to null

    item = anItem;

    leftChildPtr = nullptr;

    rightChildPtr = nullptr;

}


template < class ItemType >
BinaryNode<ItemType>::BinaryNode (const ItemType & anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr)
{

    //data assigned, set left and right pointers to specified trees

    item = anItem;

    leftChildPtr = leftPtr;

    rightChildPtr = rightPtr;

}

//Sets the data stored by the node to the specified value.
template < class ItemType >
void BinaryNode<ItemType>::setItem (const ItemType & anItem)
{

    item = anItem;

}

// Returns the data stored in the node's item data member. Caveat emptor when calling this function
template < class ItemType >
ItemType BinaryNode<ItemType>::getItem () const
{

    return item;

}

//Checks to see if the node is a leaf (ie if both left and right pointers point to null
template < class ItemType >
bool BinaryNode<ItemType>::isLeaf () const
{
    return ( leftChildPtr == nullptr && rightChildPtr == nullptr );

}

// Binary node getLeftChildPtr function.

template < class ItemType >
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr () const
{

    return leftChildPtr;

}

// Binary node getRightChildPtr function.

template < class ItemType >
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr () const
{

    return rightChildPtr;

}

//Binary node setLeftChildPtr function.

template < class ItemType >
void BinaryNode<ItemType>::setLeftChildPtr (BinaryNode<ItemType>* leftPtr)
{

    leftChildPtr = leftPtr;

}

//Binary node setRightChildPtr function.


template < class ItemType >
void BinaryNode<ItemType>::setRightChildPtr (BinaryNode<ItemType>* rightPtr)
{

    rightChildPtr = rightPtr;

}

template class BinaryNode<int>;

// determine the height of the tree. Uses recursion to find total height.

template < class ItemType >
int BinaryNodeTree<ItemType>::getHeightHelper (BinaryNode<ItemType>* subTreePtr) const
{
if ( subTreePtr == nullptr )
        return 0;
    else
    {
        return ( 1 + max( getHeightHelper( subTreePtr->getLeftChildPtr() ), getHeightHelper( subTreePtr->getRightChildPtr() ) ) );
    }

}

// determine the number of nodes in the tree. Uses recursion to find total number of nodes.


template < class ItemType >
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper (BinaryNode<ItemType>* subTreePtr) const
{
    if ( subTreePtr == nullptr )
        return 0;
else
    {
        return ( 1 + getNumberOfNodesHelper( subTreePtr->getLeftChildPtr() ) + getNumberOfNodesHelper( subTreePtr->getRightChildPtr() ) );
    }

}

//deallocate all dynamic memory for nodes in the tree.
template < class ItemType >
void BinaryNodeTree<ItemType>::destroyTree (BinaryNode<ItemType>* subTreePtr)
{
    if ( subTreePtr != nullptr )
    {

        destroyTree ( subTreePtr->getLeftChildPtr() );
        destroyTree ( subTreePtr->getRightChildPtr() );
        delete subTreePtr;

    }

}

// Adds a value to the binary tree in a way that maintains the balance of the tree.
template < class ItemType >
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd (BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
    if ( subTreePtr == nullptr )
        return newNodePtr;
   else
    {
        BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
        BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
        if ( getHeightHelper(leftPtr) > getHeightHelper(rightPtr) )
        {
            rightPtr = balancedAdd( rightPtr, newNodePtr );
            subTreePtr->setRightChildPtr(rightPtr);
        }
        else
        {
            leftPtr = balancedAdd( leftPtr, newNodePtr );
            subTreePtr->setLeftChildPtr(leftPtr);
        }
        return subTreePtr;
    }
}

// Attempts to remove target value from the binary tree
template < class ItemType >
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue (BinaryNode<ItemType>* subTreePtr, const ItemType target, bool &success)
{

    if ( subTreePtr == nullptr )
    {
        success = false;
        return nullptr;
    }
    else if ( subTreePtr->getItem() == target )
    {
        subTreePtr = moveValuesUpTree( subTreePtr );
        success = true;
        return subTreePtr;
    }
    else
    {
        BinaryNode<ItemType>* temp1 = removeValue ( subTreePtr->getLeftChildPtr(), target, success );
        BinaryNode<ItemType>* temp2 = removeValue ( subTreePtr->getRightChildPtr(), target, success );
        if ( temp1 != nullptr )
            return temp1;
        else
            return temp2;

    }
}

///Shifts nodes after the removal of a value to maintain the integrity of the pointers in the tree and not lose data.


template < class ItemType >
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree (BinaryNode<ItemType>* subTreePtr)
{

    BinaryNode<ItemType>* tempPtr;
    if ( subTreePtr->isLeaf() )
    {

        delete subTreePtr;

        subTreePtr = nullptr;

        return nullptr;

    }

    else if ( subTreePtr->getLeftChildPtr() != nullptr && subTreePtr->getRightChildPtr() == nullptr )
    {

        tempPtr = subTreePtr->getLeftChildPtr();

        delete subTreePtr;

        subTreePtr = nullptr;

        return tempPtr;

    }

    else if ( subTreePtr->getRightChildPtr() != nullptr && subTreePtr->getLeftChildPtr() == nullptr )
    {

        tempPtr = subTreePtr->getRightChildPtr();

        delete subTreePtr;

        subTreePtr = nullptr;

        return tempPtr;

    }

    else
    {

        tempPtr = subTreePtr->getLeftChildPtr();

        subTreePtr->setItem( tempPtr->getItem() );

        moveValuesUpTree( tempPtr );

    }

}

// Called by public getEntry and contains functions. Searches the tree for a node containing target value.

template < class ItemType >
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode (BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const
{

    if ( treePtr != nullptr )
    {

        if ( treePtr->getItem() == target )
        {

            success = true;

            return treePtr;

        }

        else
        {

            findNode( treePtr->getLeftChildPtr(), target, success );
            findNode( treePtr->getRightChildPtr(), target, success );

        }

    }

}


//Uses recursion to visit the entire target tree.

template < class ItemType >
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree (const BinaryNode<ItemType>* treePtr) const
{

    BinaryNode<ItemType>* newTree = nullptr;
    if ( treePtr != nullptr )
    {
        newTree = new BinaryNode<ItemType> ( treePtr->getItem() );
        newTree->setLeftChildPtr( copyTree( treePtr->getLeftChildPtr() ) );
        newTree->setRightChildPtr( copyTree ( treePtr->getRightChildPtr() ) );
    }

    return newTree;

}

// Visits root, then left, then right, performing an action specified in the user provided visit function. Uses recursion to visit the entire tree.
template < class ItemType >
void BinaryNodeTree<ItemType>::preorder (void visit (ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {

        ItemType theItem = treePtr->getItem ();

        visit (theItem);

        preorder (visit, treePtr->getLeftChildPtr ());

        preorder (visit, treePtr->getRightChildPtr ());

    }

}

// Visits left, then root, then right, performing an action specified in the user provided visit function.

template < class ItemType >
void BinaryNodeTree<ItemType>::inorder (void visit (ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {

        inorder (visit, treePtr->getLeftChildPtr ());

        ItemType theItem = treePtr->getItem ();

        visit (theItem);

        inorder (visit, treePtr->getRightChildPtr ());

    }

}

// Visits left, then right, then root, performing an action specified in the user provided visit function.

template < class ItemType >
void BinaryNodeTree<ItemType>::postorder (void visit (ItemType&), BinaryNode<ItemType>* treePtr) const
{
    if (treePtr != nullptr)
    {

        postorder (visit, treePtr->getLeftChildPtr ());

        postorder (visit, treePtr->getRightChildPtr ());

        ItemType theItem = treePtr->getItem ();

        visit (theItem);

    }

}

//Tree contains no nodes, so points to null.
template < class ItemType >
BinaryNodeTree<ItemType>::BinaryNodeTree ()
{

    rootPtr = nullptr;

}

//Creates root node with specified data.
template < class ItemType >
BinaryNodeTree<ItemType>::BinaryNodeTree ( const ItemType& rootItem )
{

    rootPtr = new BinaryNode<ItemType>(rootItem);

}

// Creates root node with specified data, with subtrees that are copies of the left and right subtrees provided.
template < class ItemType >
BinaryNodeTree<ItemType>::BinaryNodeTree (const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr,
                                          const BinaryNodeTree<ItemType>* rightTreePtr)
{

    rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr) );

}

// Binary tree copy constructor. Creates a new tree which is a copy of the tree provided.
template < class ItemType >
BinaryNodeTree<ItemType>::BinaryNodeTree (const BinaryNodeTree<ItemType>& tree)
{

    rootPtr = copyTree( tree.rootPtr );

}

//Binary tree destructor. Deallocates any dynamic memory for nodes in this tree using destroyTree function.
template < class ItemType >
BinaryNodeTree<ItemType>::~BinaryNodeTree()
{

    destroyTree(rootPtr);

}

//Binary tree isEmpty function. Checks to see if there are any nodes in the binary tree.
template < class ItemType >
bool BinaryNodeTree<ItemType>::isEmpty() const
{

    return ( rootPtr == nullptr );

}

// Binary tree getHeight function. Uses getHeightHelper function to determine the height of the tree.

template < class ItemType >
int BinaryNodeTree<ItemType>::getHeight() const
{

    return ( getHeightHelper(rootPtr) );

}

// Uses getNumberOfNodesHelper function to determine the number of nodes in the tree.

template < class ItemType >
int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{

    return ( getNumberOfNodesHelper(rootPtr) );

}

// Returns item stored in the root node of the tree.
template < class ItemType >
ItemType BinaryNodeTree<ItemType>::getRootData() const
{

    return ( rootPtr->getItem() );

}

//Sets the item in the root node of the binary tree to the user specified one.
template < class ItemType >
void BinaryNodeTree<ItemType>::setRootData (const ItemType& newData)
{

    if ( isEmpty() )
        rootPtr = new BinaryNode<ItemType>(newData);

    else
        rootPtr->setItem(newData);

}

// Adds specified value to the binary tree as a new node.

template < class ItemType >
bool BinaryNodeTree<ItemType>::add (const ItemType& newData)
{

    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);

    rootPtr = balancedAdd (rootPtr, newNodePtr);

    return true;

}

//Attempts to remove specified value from the binary tree using removeValue helper function.

template < class ItemType >
bool BinaryNodeTree<ItemType>::remove (const ItemType& data)
{

    bool success = false;

    rootPtr = removeValue( rootPtr, data, success );

    return success;

}

//Deallocates all nodes in the tree, discarding all data, and restores tree to an empty state.

template < class ItemType >
void BinaryNodeTree<ItemType>::clear()
{

    destroyTree(rootPtr);

    rootPtr = nullptr;

}

//Searches binary tree for target value.
template < class ItemType >
ItemType BinaryNodeTree<ItemType>::getEntry (const ItemType& anEntry) const
{

    bool success;

    BinaryNode<ItemType>* tempPtr = findNode( rootPtr, anEntry, success );

    if ( tempPtr != nullptr )
        return tempPtr->getItem();

    else
        cout << "ERROR: Item not found!" << endl;

}

//Searches binary tree for target value.
template < class ItemType >
bool BinaryNodeTree<ItemType>::contains (const ItemType& anEntry) const
{

    bool success = false;

    findNode( rootPtr, anEntry, success);

    return success;

}

/// Visits root, then left, then right, performing an action specified in the user provided visit function.

template < class ItemType >
void BinaryNodeTree<ItemType>::preorderTraverse (void visit (ItemType &)) const
{

    preorder( visit, rootPtr );

}

// Uses preorder helper function.
template < class ItemType >
void BinaryNodeTree<ItemType>::inorderTraverse (void visit (ItemType &)) const
{

    inorder( visit, rootPtr );

}

// Uses postorder helper function.

template < class ItemType >
void BinaryNodeTree<ItemType>::postorderTraverse (void visit (ItemType &)) const
{

    postorder( visit, rootPtr );

}

//Sets left hand tree to be a copy of right hand tree using copyTree helper function.
template < class ItemType >
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator= (const BinaryNodeTree & rightHandSide)
{

    if ( !isEmpty() )
        clear();

    rootPtr = copyTree(rightHandSide.rootPtr);

    return *this;

}

template class BinaryNodeTree<int>;

// Adds a value to the BST in a way that maintains its sorted property.
template < class ItemType >
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder (BinaryNode<ItemType>* subTreePtr,
                                                                 BinaryNode<ItemType>* newNodePtr)
{

    BinaryNode<ItemType>* tempPtr;

    if ( subTreePtr == nullptr )
        return newNodePtr;
    else if ( subTreePtr->getItem() > newNodePtr->getItem() )
    {
        tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr );
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr );
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;

}

// remove target value from the BST

template < class ItemType >
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue (BinaryNode<ItemType>* subTreePtr,
                                                               const ItemType target, bool & success)
{

    BinaryNode<ItemType>* tempPtr;
    if ( subTreePtr == nullptr )
    {

        success = false;

        return nullptr;

    }

    else if ( subTreePtr->getItem() == target )
    {

        subTreePtr = removeNode( subTreePtr );

        success = true;

        return subTreePtr;

    }

    else if ( subTreePtr->getItem() > target )
    {

        tempPtr = removeValue ( subTreePtr->getLeftChildPtr(), target, success );
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;

    }

    else
    {

        tempPtr = removeValue ( subTreePtr->getRightChildPtr(), target, success );
        subTreePtr->setRightChildPtr(tempPtr);
        return subTreePtr;

    }

}

// Shifts nodes once a value to be removed has been found
template < class ItemType >
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode (BinaryNode<ItemType>* nodePtr)
{

    BinaryNode<ItemType>* nodeToConnectPtr;

    if ( nodePtr->isLeaf() )
    {

        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;

    }

    else if ( nodePtr->getLeftChildPtr() == nullptr )
    {

        nodeToConnectPtr = nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;

    }

    else if   ( nodePtr->getRightChildPtr() == nullptr )
    {

        nodeToConnectPtr = nodePtr->getLeftChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;

    }
    else
    {

        BinaryNode<ItemType>* tempPtr;
        ItemType newNodeValue;

        tempPtr = removeLeftmostNode( nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr( tempPtr );
        nodePtr->setItem( newNodeValue );
        return nodePtr;

    }

}

/// Deletes the leftmost node of the left child of target tree
template < class ItemType >
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode (BinaryNode<ItemType>* nodePtr,
                                                                      ItemType & inorderSuccessor)
{

    if ( nodePtr->getLeftChildPtr() == nullptr )
    {

        inorderSuccessor = nodePtr->getItem();

        return removeNode(nodePtr);

    }

   else
    {

        BinaryNode<ItemType>* tempPtr;

        tempPtr = removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);

        nodePtr->setLeftChildPtr(tempPtr);

        return nodePtr;

    }

}

//Searches the tree for a node containing target value.
template < class ItemType >
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode (BinaryNode<ItemType>* treePtr,
                                                            const ItemType & target) const
{
    if ( treePtr == nullptr )
        return nullptr;
    else if ( treePtr->getItem() == target )
        return treePtr;
    else if ( treePtr->getItem() > target )
        return findNode( treePtr->getLeftChildPtr(), target );
    else
        return findNode( treePtr->getRightChildPtr(), target);

}

// Tree contains no nodes, so points to null.
template < class ItemType >
BinarySearchTree<ItemType>::BinarySearchTree()
{

    rootPtr = nullptr;

}

//Creates root node with specified data.
template < class ItemType >
BinarySearchTree<ItemType>::BinarySearchTree (const ItemType & rootItem)
{

    rootPtr = new BinaryNode<ItemType>(rootItem);

}

//Creates a new tree which is a copy of the tree provided.
template < class ItemType >
BinarySearchTree<ItemType>::BinarySearchTree (const BinarySearchTree<ItemType>& tree)
{

    rootPtr = this->copyTree( tree.rootPtr );

}

// Deallocates any dynamic memory for nodes in this tree using destroyTree function.

template < class ItemType >
BinarySearchTree<ItemType>::~BinarySearchTree ()
{

    this->destroyTree(rootPtr);

}

//Checks to see if there are any nodes in the binary tree.
template < class ItemType >
bool BinarySearchTree<ItemType>::isEmpty () const
{

    return ( rootPtr == nullptr );

}

//Uses getHeightHelper function to determine the height of the tree.
template < class ItemType >
int BinarySearchTree<ItemType>::getHeight () const
{

    return ( this->getHeightHelper(rootPtr) );

}

//Uses getNumberOfNodesHelper function to determine the number of nodes in the tree.
template < class ItemType >
int BinarySearchTree<ItemType>::getNumberOfNodes () const
{

    return ( this->getNumberOfNodesHelper(rootPtr) );

}

// Returns item stored in the root node of the tree.

template < class ItemType >
ItemType BinarySearchTree<ItemType>::getRootData () const
{

    return ( rootPtr->getItem() );

}

//if the BST is empty, creates a new node with root value

template < class ItemType >
void BinarySearchTree<ItemType>::setRootData (const ItemType& newData)
{

    if ( isEmpty() )
        rootPtr = new BinaryNode<ItemType>(newData);

}
//Adds specified value to the BST
template < class ItemType >
bool BinarySearchTree<ItemType>::add (const ItemType& newEntry)
{

    BinaryNode<ItemType>* temp = new BinaryNode<ItemType>(newEntry);

    rootPtr = insertInorder( rootPtr, temp );

    return true;

}

//Attempts to remove specified value from the binary tree
template < class ItemType >
bool BinarySearchTree<ItemType>::remove (const ItemType& anEntry)
{

    bool success = false;

    rootPtr = removeValue( rootPtr, anEntry, success );

    return success;

}

//Deallocates all nodes in the tree
template < class ItemType >
void BinarySearchTree<ItemType>::clear ()
{

    this->destroyTree(rootPtr);

    rootPtr = nullptr;

}
//Searches binary tree for target value
template < class ItemType >
ItemType BinarySearchTree<ItemType>::getEntry (const ItemType & anEntry) const
{

    BinaryNode<ItemType>* itemLoc = findNode(rootPtr, anEntry);

    if ( itemLoc != nullptr )
        return itemLoc->getItem();

    else
        cout << "ERROR: Item not found!" << endl;

}

// Searches BST for target value
template < class ItemType >
bool BinarySearchTree<ItemType>::contains (const ItemType & anEntry) const
{

    BinaryNode<ItemType>* itemLoc = findNode(rootPtr, anEntry);

    if ( itemLoc == nullptr )
        return false;

    else
        return true;

}

template < class ItemType >
void BinarySearchTree<ItemType>::preorderTraverse (void visit (ItemType&)) const
{

    this->preorder( visit, rootPtr );

}

template < class ItemType >
void BinarySearchTree<ItemType>::inorderTraverse (void visit (ItemType&)) const
{

    this->inorder( visit, rootPtr );

}

template < class ItemType >
void BinarySearchTree<ItemType>::postorderTraverse (void visit (ItemType&)) const
{

    this->postorder( visit, rootPtr );

}

// Sets left hand BST to be a copy of right hand BST using copyTree helper function.

template < class ItemType >
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator= (const BinarySearchTree<ItemType>& rightHandSide)
{

    if ( !isEmpty() )
        clear();

    rootPtr = this->copyTree(rightHandSide.rootPtr);

    return *this;

}

template class BinarySearchTree<int>;