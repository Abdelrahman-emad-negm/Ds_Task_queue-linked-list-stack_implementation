#ifndef STACK_H
#define STACK_H

#include "Node.h"

// ================= Array Stack =================
class StackArray {
private:
    int* arr;
    int top;
    int capacity;

public:
    StackArray(int capacity = 100);
    ~StackArray();  // free allocated array                  

    void push(int value);
    int  pop();
    int  peek();
    bool isEmpty();
    bool isFull();
};

// ================= Linked List Stack =================
class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList();
    ~StackLinkedList();  // delete all nodes   

    void push(int value);
    int  pop();
    int  peek();
    bool isEmpty();
};

#endif