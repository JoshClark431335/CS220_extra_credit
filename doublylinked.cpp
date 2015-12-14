#include "doublylinked.h"

template <class Node_entry>
Node<Node_entry>::Node(){
    next = back = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry val, Node<Node_entry> * link_back, 
    Node<Node_entry> * link_next){

    entry = val;
    next = link_next;
    back = link_back;
}

/**
 * Constructor
*/
template <class List_entry>
List<List_entry>::List(){
    count = 0;
    current = NULL;
    current_position = -1;
}

/**
 * Destructor
 * Destroys (deletes) all nodes in the list
*/
template <class List_entry>
List<List_entry>::~List(){
    clear();
}

/**
 * Copy Constructor
 * Makes a new List identical to the first for use as a pass by
 * value argument to a function
 * @param original is the List
*/
template <class List_entry>
List<List_entry>::List(const List<List_entry> &original){
	count 				= 0;
	current 			= NULL;
	current_position 	= -1;

	List_entry temp;
	for(int i = 0; i < original.size(); i++){
		original.retrieve(i, temp);
		insert(i, temp);
	}
}

/**
 * Overloaded = operator
 * Rewrites the List on the left side of an '=' to be identical
 * to the List on the right side
 * @param original is the List on the right side of an '='
*/
template <class List_entry>
void List<List_entry>::operator = (const List<List_entry> &original){
	clear();
	List_entry temp;
	for(int i = 0; i < original.size(); i++){
		original.retrieve(i, temp);
		insert(i, temp);
	}
}

/**
 * List.full()
 * Checks to see if the List can hold any more nodes
 * @return true if the List can't hold any more nodes, false otherwise
*/
template <class List_entry>
bool List<List_entry>::full() const{
    Node<List_entry> * temp = new Node<List_entry>();
    if(temp == NULL){
        return true;
    }
    delete temp;
    return false;
}

/**
 * List.empty()
 * Checks to see if the List is empty
 * @return true if the List has no nodes, false otherwise
*/
template <class List_entry>
bool List<List_entry>::empty() const{
    return (count == 0);
}

/**
 * List.clear()
 * Destroys (deletes) all nodes in the List
*/
template <class List_entry>
void List<List_entry>::clear(){
    if(count == 0) return;

    List_entry x;
    while(!empty()){
        remove(0, x);
    }

}

/**
 * List.retrieve(position, &item)
 * Without changing the List, assigns item to the entry value of
 * the node at the given position if position is valid
 * @param position gives the position in the List to retrieve the value
 * @param item is set equal to the entry value of the node at spot position
 * @return underflow if List is empty, range_error if position does not exist, and
 * success otherwise
*/
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const{
    if(count == 0) return underflow;
    if (position < 0 || position >= count) return range_error;
    set_position(position);
    x = current->entry;
    return success;
}

/**
 * As long as position is valid, replaces the Node entry at spot positin with item
 * @param position gives the spot in the List for which Node's entry is to be replaced
 * @param item is the new value for the Node's entry at spot position
 * @return underflow if List is empty, range_error if position
 * does not exist, and success otherwise
*/
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x){
    if (count == 0) return underflow;
    if (position < 0 || position >= count) return range_error;
    set_position(position);
    current->entry = x;
    return success;
}

/**
 * As long as position is valid, removes the Node at the given position from the
 * List after putting it's entry value in item
 * @param position gives the spot in the List of the Node to be removed
 * @param item holds the entry value of the node prior to its removal
 * @return underflow if List is empty, range_error if position does not exist, and success otherwise
*/
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x){
    if (count <= 0) return underflow;
    if (position < 0 || position >= count) return range_error;

    Node<List_entry> *old_node, *neighbor;

    set_position(position);
    old_node = current;

    if(current->back != NULL) { 
        neighbor = current->back;
        neighbor->next = current->next;
    }

    if(current->next != NULL) {
        neighbor = current->next;
        neighbor->back = current->back;
        current = neighbor;
    } else {
        current = current->back;
        current_position--;
    }

    x = old_node->entry; 
    delete old_node;
    count --;
    
    return success;

}

/**
 * This will give the number of entries in the list
 * @return the size of the list
*/
template <class List_entry>
int List<List_entry>::size() const{
    return count;
}

/**
 * This will insert x at position in the list, if the list is not full.
 * Any entries at >= position must have their position numbers increased by 1
 * @param position must be 0 <= position <= count, where count is the # of elements
 * @param x is the List_entry to add
*/
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x){

    if(position < 0 || position > count) return range_error;

    Node<List_entry> *new_node, *previous, *following;

    if(position == 0){
        if(count==0) following = NULL;
        else {
            set_position(0);
            following = current;
        }
        previous = NULL;
    } else {
        set_position(position - 1);
        previous = current;
        following = previous->next;
    }

    new_node = new Node<List_entry>(x, previous, following);
    if(new_node == NULL) return overflow;

    if(previous != NULL) previous->next = new_node;
    if(following != NULL) following->back = new_node;

    current = new_node;
    current_position = position;

    count++;
    return success;
}

/**
 * The action specified by function (*visit) has been performed on every
 * entry of the List, beginning at position 0 and doing each in turn
*/
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry&)){
    set_position(0);
    Node<List_entry> * q = current;
    while(q != NULL){
        (*visit)(q->entry);
        q = q->next;
    }
}

/**
 * Internal method for setting the 'head' position of the list
 * @param position is the position to set 0 <= position < count 
 * @return a Node * to the Node at position
*/
template <class List_entry>
void List<List_entry>::set_position(int position) const{
	if(count == 0) return;

    if(current_position < position){
        for(;current_position < position; current_position++){
            current = current->next;
        }
    } else {
        for(;current_position > position; current_position--){
            current = current->back;
        }
    }
}
