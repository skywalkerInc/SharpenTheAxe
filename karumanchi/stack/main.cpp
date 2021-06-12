#include <iostream>
#include "BaseStack.hpp"

using namespace sta;
using namespace std;

void testStack()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    cout << stack.peek() << endl;
}

int main()
{
    testStack();
    return 0;
}