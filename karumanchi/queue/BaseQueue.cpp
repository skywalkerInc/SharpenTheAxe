#include <iostream>
#include "BaseQueue.hpp"

using namespace sta;
using namespace std;


void Queue::push(mydata_t data)
{
    insert(data);   
}

void Queue::pop(void)
{
    pop_right();
}

bool Queue::isEmpty(void)
{
    return (head == NULL);
}