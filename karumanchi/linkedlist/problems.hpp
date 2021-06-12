#ifndef __AUXILLIARY_LINKEDLIST__
#define __AUXILLIARY_LINKEDLIST__
    {
        
    }
#include "../linkedlist/BaseLinkedList.hpp"
#include "TestNodes.hpp"

namespace sta
{
typedef DoublyListNode dll;
typedef SinglyListNode sll;

class ProblemsLL : public DeQueue, public TestNodes
{
public:
    void insertNodeAtPos(dll* node, unsigned int pos);
    void deleteList();
    bool isCircular();
    dll* findCircularStart();
    

    
};

}
#endif // __AUXILLIARY_LINKEDLIST__