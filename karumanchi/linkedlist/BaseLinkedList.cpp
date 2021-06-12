#include <iostream> //Including standard library
#include "BaseLinkedList.hpp" //first search in same directory then searches in standard library path
using namespace std;

namespace sta {

LinkedList::LinkedList() {
    head = NULL;
    cout << "LinkedList Initialized" << endl;
}

void LinkedList::append(mydata_t node_data) {
    listnodeptr newnode = getNewNode(node_data);

    // Check if list is empty then insert at head
    if (head == NULL) {
        head = newnode;
        return;
    }

    // Travel to end of node and insert
    listnodeptr node = head;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = newnode;
}

void LinkedList::insert(mydata_t node_data){
    listnodeptr newnode = getNewNode(node_data);

    // Check if list is empty
    if (head == NULL) {
        head = newnode;
        return;
    }

    // If list is not empty
    listnodeptr node = head;
    head = newnode;
    head->next = node;
    
}

NodeErr LinkedList::deleteNode(mydata_t data) {
    // Find the node
    listnodeptr node = findNode(data);
    
    // Delete the node
    return deleteNode(node);
}

NodeErr LinkedList::updateNode(mydata_t prev_val, mydata_t new_val) {
    listnodeptr node = findNode(prev_val);

    return updateNode(node, new_val);
}

unsigned int LinkedList::getLength() {
    return getLength(head);
}

listnodeptr LinkedList::findNode(mydata_t data) {
    listnodeptr node = head;
    while ( (node != NULL) && (node->data != data)) node = node->next;

    return node;
}

NodeErr LinkedList::deleteNode(listnodeptr node) {
    if (node == NULL) return NodeErr::INPUT_IS_NULL;

    listnodeptr prev = head;
    // Find previous node
    while ( (prev != NULL) && (prev->next != node)) prev = prev->next;

    if (prev == NULL) return NodeErr::NODE_NOT_FOUND;
    
    // Link node's previous and next nodes
    prev->next = node->next;

    free(node);
    return NodeErr::NO_ERROR;
}

NodeErr LinkedList::updateNode(listnodeptr node, mydata_t new_val) {
    if (node == NULL) return NodeErr::INPUT_IS_NULL;

    node->data = new_val;
    return NodeErr::NO_ERROR;
}

listnodeptr LinkedList::getNewNode(mydata_t data) {
    listnodeptr listNode = new ListNode;
    listNode->data = data;
    listNode->next = NULL;
    return listNode;
}

unsigned int LinkedList::getLength(listnodeptr node) {
    unsigned int len = 0;
    for (listnodeptr ptr = node; ptr != NULL; ptr = ptr->next) len++;
    return len;
}

void LinkedList::printList() {
    listnodeptr node;
    node = head;
    while (node != NULL) {
        cout << node->data << " "; //Printing data side by side
        node = node->next;
    }

    cout << endl;
}

// DEQUEUE CLASS
DeQueue::DeQueue()
{
    head = NULL;
    tail = NULL;
}

void DeQueue::append(mydata_t data)
{
    DoublyListNode* node = getNewNode(data);

    if (head == NULL) 
    {
        head = node;
        tail = node;
        return;
    }

    node->prev = tail;
    tail->next = node;
    tail = node;
}

void DeQueue::insert(mydata_t data)
{
    DoublyListNode* node = getNewNode(data);

    if (head == NULL)
    {
        head = node;
        tail = node;
        return;
    }

    head->prev = node;
    node->next = head;
    head = node;
}

void DeQueue::pop_left(void)
{
    if (head != NULL)
    {
        DoublyListNode *temp = head;

        head = head->next;
        if (head == NULL) tail = NULL;

        free(temp);
    }
}

void DeQueue::pop_right(void)
{
    
    if(tail != NULL)
    {
        DoublyListNode* temp = tail;

        tail = tail->prev;
        if (tail == NULL) 
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        
        free(temp);
    }
}

DoublyListNode* DeQueue::getNewNode(mydata_t data)
{
    DoublyListNode* node = new DoublyListNode;
    node->next = NULL;
    node->prev = NULL;
    node->data = data;
    return node;
}

DoublyListNode* DeQueue::findNode(mydata_t data)
{
    if (head == NULL) return NULL;

    if (tail->data == data) return tail;

    DoublyListNode* node = head;
    while ((node != NULL) && (node->data != data)) node = node->next;
    return node;
}
    
NodeErr DeQueue::deleteNode(DoublyListNode* node)
{
    if (node == NULL) return NodeErr::INPUT_IS_NULL;
    
    DoublyListNode* temp = head;
    while((temp != NULL) && (temp->next != node)) temp = temp->next;

    if (temp == NULL) return NodeErr::NODE_NOT_FOUND;
    temp->next = node->next;
    node->next->prev = temp;

    free(node);
    return NodeErr::NO_ERROR;   
}

NodeErr DeQueue::updateNode(mydata_t prev, mydata_t data)
{
    DoublyListNode* node = findNode(data);
    return updateNode(node, data);
}

NodeErr DeQueue::updateNode(DoublyListNode* node, mydata_t data)
{
    if (node == NULL) return NodeErr::INPUT_IS_NULL;
    node->data = data;
    return NodeErr::NO_ERROR;
}

void DeQueue::printList(void)
{
    DoublyListNode* node = head;
    while (node != NULL) 
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}


}