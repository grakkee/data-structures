template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue() : front(), back(DEFAULT_CAPACITY - 1), itemCount(){
}

template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template <class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry){
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
        if(newEntry > line[back]){
            line[back] = newEntry;
            itemCount++;
        }
        return 1;
    }
    else{
        return 0;
    }
} 

template <class ItemType>
bool PriorityQueue<ItemType>::dequeue(){
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
ItemType PriorityQueue<ItemType>::peekFront() const{
    return line[front];
}


















