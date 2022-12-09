template<class itemType>
Node<itemType>::Node():next(nullptr){

} //default constructor

template<class itemType>
Node<itemType>::Node(const itemType& anItem):item(anItem), next(nullptr){

} //constructor

template<class itemType>
Node<itemType>::Node(const itemType& anItem, Node<itemType>* nextNodePtr):item(anItem), next(nextNodePtr){

} //constructor

template<class itemType>
void Node<itemType>::setItem(const itemType& anItem){
		item = anItem;
} //setter

template<class itemType>
void Node<itemType>::setNext(Node<itemType>* nextNodePtr){
		next = nextNodePtr; 
} //setter

template<class itemType>
itemType Node<itemType>::getItem() const{
		return item;
} //getter

template<class itemType>
Node<itemType>* Node<itemType>::getNext() const{
		return next; 
} //getter

