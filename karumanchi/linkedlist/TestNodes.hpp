#ifndef __TESTNODES__
#define __TESTNODES__

#include "../linkedlist/BaseLinkedList.hpp"

namespace sta
{

typedef DoublyListNode dln;
typedef SinglyListNode sln;

class TestNodes
{
public:
    sln* getCircularList();
    void printList(sln* node);
    void printList(dln* node);
    void printCircularList(sln* node);

protected:
    sln* getsln(mydata_t data);
    dln* getdln(mydata_t data);
};

} //sta

#endif // __TESTNODES__