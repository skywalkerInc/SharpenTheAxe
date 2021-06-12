#include <iostream>
#include "BaseStack.hpp"

using namespace sta;
using namespace std;

void Stack::pop(void)
{
    deleteNode(head);
}

void Stack::push(mydata_t value)
{
    insert(value);
}

mydata_t Stack::peek()
{
    return head->data;
}

bool Stack::isEmpty()
{
    return (head == NULL);
}
