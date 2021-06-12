#include <iostream>
#include "TestNodes.hpp"

using namespace sta;
using namespace std;

sln* TestNodes::getsln(mydata_t data)
{
    sln* node = new sln;
    node->data = data;
    node->next = NULL;
    return node;
}

dln* TestNodes::getdln(mydata_t data)
{
    dln* node = new dln;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void TestNodes::printList(sln* node)
{
    sln* temp = node;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void TestNodes::printCircularList(sln* node)
{
    sln* head = node;
    sln* temp = node;
    while ((temp != NULL) && (temp ->next!= head))
    {
        cout << temp->data << " ";
    }
    
    if (temp != NULL) cout << temp->data << endl;
}

void TestNodes::printList(dln* node)
{
    dln* temp = node;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

sln* TestNodes::getCircularList()
{
    mydata_t arr[5] = {4,2,1,5,6};
    sln* node = NULL;
    sln* head = NULL;
    for (unsigned int i = 0; i<(sizeof(arr)/sizeof(arr[0])); i++)
    {
        if (!node)
        {
            node = getsln(arr[i]);
            head = node;
        }
        else
        {
            node->next = getsln(arr[i]);
            node = node->next;
        }
        
    }
    node->next = NULL;
    return head;
}


