template<class itemType>
Node<itemType>* LinkedStack<itemType>::getNodeAt(int position) const {
    if(position > 0){ //precondidtion 
        Node<itemType>* curPtr = headPtr; //count from start of chain
        for(int skip = 1; skip < position; skip++){
            curPtr = curPtr->getNext();
        }
        return curPtr;
    }
    return nullptr; 
}

template<class itemType>
LinkedStack<itemType>::LinkedStack(){
top = 0;
headPtr = nullptr;
}

template<class itemType>
LinkedStack<itemType>::LinkedStack(const LinkedStack<itemType>& aStack){
    top = aStack.top;
    headPtr = aStack.headPtr;
}

template<class itemType>
bool LinkedStack<itemType>::isEmpty() const {
    return top == 0; 
}

template<class itemType>
bool LinkedStack<itemType>::push(const itemType& newEntry){
    bool canPush = (top >= 0);
    if(canPush){
        Node<itemType>* newNodePtr = new Node<itemType>(newEntry);
        if(top == 0){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;

        }
        else{
            Node<itemType>* prevPtr = getNodeAt(top); //find node before where new node will be
            newNodePtr->setNext(prevPtr->getNext()); //insert new node after node that prevPtr points to
            prevPtr->setNext(newNodePtr);
        }
        top++;
    }  
    return canPush;
} //adds item

template<class itemType>
bool LinkedStack<itemType>::pop(){
    bool canPop = (top > 0);

    if(canPop){
         Node<itemType>* curPtr = nullptr;
        if(top == 1){ //remove first node in chain 
            curPtr = headPtr; //save pointer to node
            headPtr = headPtr->getNext(); //save pointer to next node
        }
        else{
            Node<itemType>* prevPtr = getNodeAt(top - 1); //find node before one to be removed
            curPtr = prevPtr->getNext(); //point to nod to remove
            prevPtr->setNext(curPtr->getNext()); //disconnect indicated node from chain by connecting the prior node with one after
        }

        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr =  nullptr;
        top--; //top position has decreased
    }
    return canPop;
} //removes item

template<class itemType>
itemType LinkedStack<itemType>::peek() const {
    bool ableToGet = (top > 0);
    if(ableToGet){
        Node<itemType>* nodePtr = getNodeAt(top);
        return nodePtr->getItem();
    }

    else{
        throw "failed to peek";
    }
} //retrieves item from the top of stack 