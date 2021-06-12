#ifndef __BASE_QUEUE__
#define __BASE_QUEUE__

#include "../linkedlist/BaseLinkedList.hpp"

namespace sta
{

class Queue : public DeQueue
{
public:    
    void push(mydata_t data);
    void pop(void);
    bool isEmpty(void);
};

}

#endif //__BASE_QUEUE__