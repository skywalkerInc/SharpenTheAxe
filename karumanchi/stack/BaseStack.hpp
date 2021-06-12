#ifndef BASE_STACK
#define BASE_STACK

#include "../linkedlist/BaseLinkedList.hpp"
// Can be implemented by array, dynamic array and linkedlist
// This is linkedlist implementation
namespace sta 
{

class Stack : public LinkedList
{
public:
    void pop(void);
    void push(mydata_t value);
    bool isEmpty(void);
    mydata_t peek();
};

}
#endif // BASE_STACK