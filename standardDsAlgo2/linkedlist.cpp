#include <bits/stdc++.h>
using namespace std;

Class Node {
    int val;
    Node* next;
    Node(int val): val(val), next(nullptr) {}
};

Node* Reverse(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) return head;

    Node* ret = Reverse(head->next);

    head->next->next = head;
    head->next = nullptr;

    return ret;
}

int main() {
    Node *head = new Node(0);
    Node *iter = head;
    for(int i=0; i<5; ++i) {
        Node* newnode = new Node(1);
        iter->next = newnode;
        iter = iter->next;
    }

    Node* newhead = Reverse(head);
    
}