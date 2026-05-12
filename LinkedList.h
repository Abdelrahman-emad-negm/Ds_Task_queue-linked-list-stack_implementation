#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

// ================= Singly Linked List =================
class LinkedList {
private:
    Node* head;  // pointer to first node

public:
    LinkedList();
    ~LinkedList();  // delete all nodes

    void insertAtHead(int val);  // insert at beginning
    void insertAtEnd(int val);   // insert at end
    void deleteValue(int val);   // delete first occurrence

    void display();  // print list
};

#endif