template <class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(), back(DEFAULT_CAPACITY - 1), itemCount(){
}

template <class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template <class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry){
    bool canAdd = itemCount < DEFAULT_CAPACITY;
    //back == front; //This means that the queue is full

    if(itemCount < DEFAULT_CAPACITY){
        /*if(front == -1){
            front = back;
        }
        line[back] = newEntry;
        back++;
        if(back >= DEFAULT_CAPACITY){
            back = 0;
        }
        itemCount++;
        return 1;*/
        back = (back + 1) % DEFAULT_CAPACITY;
        line[back] = newEntry;
        itemCount++;
        return 1;
    }
    else{
        return 0;
    }
} 

template <class ItemType>
bool ArrayQueue<ItemType>::dequeue(){
    if(!isEmpty()){
        //line[front] = line[front + 1];
        /*front++;
        if(front >= DEFAULT_CAPACITY){
            front = -1;
        }
        itemCount--;
        return 1;*/
        front = (front + 1) % DEFAULT_CAPACITY;
        itemCount--;
        return 1;
    }
    else{
        return 0;
    }
}

template <class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const{
    return line[front];
}
