#include <iostream>
#include "BaseQueue.hpp"

using namespace sta;
using namespace std;

void testQueue()
{
    Queue queue;
    queue.push(10);
    queue.push(13);
    queue.printList();
    queue.pop();
    queue.printList();
}

int main(int argc, char const *argv[])
{
    testQueue();
    return 0;
}
