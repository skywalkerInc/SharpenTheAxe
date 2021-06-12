#include <iostream>
#include <stdint.h>
#include "BaseLinkedList.hpp"
#include "TestNodes.hpp"

using namespace sta;
using namespace std;

void testBaseLinkedList() {
    LinkedList linkedList;
    
    linkedList.append(12);
    linkedList.append(15);
    linkedList.append(7);
    linkedList.insert(8);
    linkedList.printList();
    NodeErr ret = linkedList.deleteNode(2);
    if (ret != NodeErr::NO_ERROR) cout << "deleteNode ret: "<< static_cast<unsigned int>(ret) << endl;
    linkedList.printList();
    cout << "linkedlist length: " << linkedList.getLength() << endl;
}

void testDeQueue()
{
    DeQueue deque;
    deque.append(10);
    deque.append(11);
    deque.insert(12);
    deque.insert(13);
    deque.printList();

    deque.pop_left();
    deque.printList();
    deque.pop_right();
    deque.printList();
}

void testCircular()
{
    TestNodes testnode;
    sln* head = testnode.getCircularList();
    testnode.printList(head);
}

int main() {
    testBaseLinkedList();
    testDeQueue();
    testCircular();
    return 0;
}