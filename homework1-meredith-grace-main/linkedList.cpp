template<class itemType>
Node<itemType>* LinkedList<itemType>::getNodeAt(int position) const {
    if((position >= 1) && (position <= itemCount)) { //precondidtion 
        Node<itemType>* curPtr = headPtr; //count from start of chain
        for(int skip = 1; skip < position; skip++){
            curPtr = curPtr->getNext();
        }
        return curPtr;
    }
    return nullptr; 
}

template<class itemType>
LinkedList<itemType>::LinkedList(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class itemType>
LinkedList<itemType>::LinkedList(const LinkedList<itemType>& aList){
    headPtr = aList.headPtr;
    itemCount = aList.itemcount;
}

template<class itemType>
bool LinkedList<itemType>::isEmpty() const {
    return itemCount == 0;
}

template<class itemType>
int LinkedList<itemType>::getLength() const{
    return itemCount;
}

template<class itemType>
bool LinkedList<itemType>::insert(int newPosition, const itemType& newEntry){
    bool ableToInsert = (newPosition >=1) && (newPosition <= itemCount + 1);\
    if(ableToInsert){
        Node<itemType>* newNodePtr = new Node<itemType>(newEntry); //create new node w/ new entry
        if(newPosition ==1){ //attach new node to chain
            newNodePtr->setNext(headPtr); //insert new node at beginning of chain 
            headPtr = newNodePtr; 
        }
        else{
            Node<itemType>* prevPtr = getNodeAt(newPosition - 1); //find node before where new node will be
            newNodePtr->setNext(prevPtr->getNext()); //insert new node after node that prevPtr points to
            prevPtr->setNext(newNodePtr);
        }
        itemCount++; // # of entries have increased
    }
    return ableToInsert;
}

template<class itemType>
bool LinkedList<itemType>::remove(int position){
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if(ableToRemove){
        Node<itemType>* curPtr = nullptr;
        if(position == 1){ //remove first node in chain 
            curPtr = headPtr; //save pointer to node
            headPtr = headPtr->getNext(); //save pointer to next node
        }
        else{
            Node<itemType>* prevPtr = getNodeAt(position - 1); //find node before one to be removed
            curPtr = prevPtr->getNext(); //point to nod to remove
            prevPtr->setNext(curPtr->getNext()); //disconnect indicated node from chain by connecting the prior node with one after
        }

        curPtr->setNext(nullptr);
        delete curPtr;
        curPtr =  nullptr;
        itemCount--; // # of entries has decreased
    }
    return ableToRemove; 
}

template<class itemType>
void LinkedList<itemType>::clear(){
    while(!isEmpty()){
        remove(1);
    }
}

template<class itemType>
itemType LinkedList<itemType>::getEntry(int position) const {
    bool ableToGet = (position >= 1) && (position <= itemCount); //precondition
    if(ableToGet){
        Node<itemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else{
        throw "invalid position";
    }
}

template<class itemType>
itemType LinkedList<itemType>::replace(int position, const itemType& newEntry){
    bool ableToGet = (position >=1) && (position <= itemCount); //precondition
    if(ableToGet){
        Node<itemType>* nodePtr = getNodeAt(position); 
        itemType oldEntry = nodePtr->getItem();
        nodePtr->setItem(newEntry);
        return oldEntry;
    }
    else{
        throw "invalid position";
    }
}

template<class itemType>
LinkedList<itemType>::~LinkedList(){
    clear();
}