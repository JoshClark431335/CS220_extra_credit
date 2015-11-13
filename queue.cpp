#include "queue.h"

//Implementation of Node constructors
Node::Node(){
    next = NULL;
}

Node::Node(Node_entry item, Node * add_on){
    entry = item;
    next = add_on;
}

/**
 * Constructor
 */
Queue::Queue(){
    front = rear = NULL;
    count = 0;  
}

/**
 * Copy Constructor
 */
Queue::Queue(const Queue &original){
    Node *new_front, *new_rear, *original_node = original.front;
    if(original_node == NULL) new_front = new_rear = NULL;
    else {
        new_front = new_rear = new Node(original_node->entry);
        while(original_node->next != NULL){
            original_node = original_node->next;
            new_rear->next = new Node(original_node->entry); 
            new_rear = new_rear->next;
        }
    }

    front = new_front;
    rear = new_rear;
    count = original.count;
}

/**
 * Destructor
 */
Queue::~Queue(){
    while(!empty())
        serve();
}

/**
 * Overloaded = operator
 */
void Queue::operator = (const Queue & original){
    Node *new_front, *new_rear, *original_node = original.front;
    if(original_node == NULL) new_front = new_rear = NULL;
    else {
        new_front = new_rear = new Node(original_node->entry);
        while(original_node->next != NULL){
            original_node = original_node->next;
            new_rear->next = new Node(original_node->entry); 
            new_rear = new_rear->next;
        }
    }

    //clean out what was on our queue
    while(!empty()) serve();

    front = new_front;
    rear = new_rear;
    count = original.count;
}

/**
 * Put the value from the front of the Queue
 * into 'item'
 * @param item The empty container in which the front value will be stored
 * @return Error_code underflow if the queue is empty; success otherwise
 */
Error_code Queue::retrieve(Queue_entry &item) const {
    if(front == NULL) return underflow;

    item = front->entry;

    return success;
}

/**
 * Serve the front item off of the Queue
 * @return Error_code underflow if the queue is empty; success otherwise
 */
Error_code Queue::serve(){
    if(empty()) return underflow;

    Node * ye_olde_front = front;
    front = front->next;
    if(front == NULL) rear = NULL;

    delete ye_olde_front;
    count--;
    return success;
}


/**
 * Append item to the end of the Queue
 * @param item The data to add to the end of the queue
 * @return Error_code overflow if the queue is full; success otherwise
 */
Error_code Queue::append(const Queue_entry &item){
    Node * new_rear = new Node(item);
    if(new_rear == NULL) return overflow;

    if(front == NULL){
        front = rear = new_rear;
    } else {
        rear->next = new_rear;
        rear = new_rear;
    }

    count++;
    return success;
}

/**
 * @return True iff the queue is empty
 */
bool Queue::empty() const {
    return (front == NULL);
}

/**
 * @return the size of the queue
 *
 */
int Queue::size(){
    return count;
}



