#ifndef BASE_LINKEDLIST
#define BASE_LINKEDLIST

#include <stdint.h>

namespace sta { //SharpenTheAxe

typedef int mydata_t;

enum class NodeErr: uint8_t
{
    NO_ERROR = 0,
    NODE_NOT_FOUND,
    INPUT_IS_NULL,
    OTHER,
};

enum class NodeType: uint8_t
{
    SINGLE_LINKEDLIST = 0,
    DOUBLY_LINKEDLIST,
};

class Node
{
public:
    mydata_t data;
};

class SinglyListNode : public Node
{
public:
    SinglyListNode* next;
};

class DoublyListNode : public Node
{
public:
    DoublyListNode* next;
    DoublyListNode* prev;
};

typedef SinglyListNode ListNode;
typedef SinglyListNode* listnodeptr;

class LinkedList 
{
public:
    LinkedList(); //singly linked list

    // Add node at end
    void append(mydata_t node_data); //can be constant

    // Add node at begining
    void insert(mydata_t node_data); 

    // Return error if no node is deleted for any reason
    NodeErr deleteNode(mydata_t data); 

    // Return error if no node is updated for any reason
    NodeErr updateNode(mydata_t prev_val, mydata_t new_val);

    unsigned int getLength();

    // Print value of node
    void printList();
    
protected:
    listnodeptr getNewNode(mydata_t data);

    // Return node containing the data
    listnodeptr findNode(mydata_t data);

    // Return error if no node is deleted for any reason
    NodeErr deleteNode(listnodeptr node); 

    // Return error if no node is updated for any reason
    NodeErr updateNode(listnodeptr node, mydata_t new_val);

    // Get length of node starting from node pointer
    unsigned int getLength(listnodeptr node);

    listnodeptr head;
};

// Double Linkedlist
class DeQueue
{
public:
    DeQueue();
    void append(mydata_t data); //in
    void insert(mydata_t data); //put in left
    void pop_left(void);
    void pop_right(void);
    NodeErr updateNode(mydata_t prev_val, mydata_t new_val);
    void printList(void);
protected:
    DoublyListNode* getNewNode(mydata_t data);
    DoublyListNode* findNode(mydata_t data);
    
    NodeErr deleteNode(DoublyListNode* node);
    NodeErr updateNode(DoublyListNode* Node, mydata_t data);

    DoublyListNode* head;
    DoublyListNode* tail;

};

}
#endif //BASE_LINKEDLIST