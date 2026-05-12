#include "Stack.h"
#include <iostream>
using namespace std;

// ================= Array Stack =================
StackArray::StackArray(int cap) {
    capacity = cap;
    arr = new int[capacity];   // allocate array
    top = -1;                  // stack starts empty
}

// free allocated array
StackArray::~StackArray() {
    delete[] arr;
    arr = nullptr;
}

bool StackArray::isEmpty() {
    return top == -1;
}

bool StackArray::isFull() {
    return top == capacity - 1;
}

void StackArray::push(int value) {
    // check overflow
    if (isFull()) {
        cout << "Stack Overflow: cannot push " << value
            << " — stack is full (capacity = " << capacity << ")." << endl;
        return;
    }
    arr[++top] = value;   // insert at top
}

int StackArray::pop() {
    // check underflow
    if (isEmpty()) {
        cout << "Stack Underflow: cannot pop from an empty stack." << endl;
        return -1;
    }
    return arr[top--];   // remove top element
}

int StackArray::peek() {
    if (isEmpty()) {
        cout << "Stack is empty — nothing to peek." << endl;
        return -1;
    }
    return arr[top];
}

// ================= Linked List Stack =================
StackLinkedList::StackLinkedList() : top(nullptr) {}

// delete all nodes
StackLinkedList::~StackLinkedList() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

bool StackLinkedList::isEmpty() {
    return top == nullptr;
}

void StackLinkedList::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;   // link to previous top
    top = newNode;         // update top
}

int StackLinkedList::pop() {
    // check underflow
    if (isEmpty()) {
        cout << "Stack Underflow: cannot pop from an empty stack." << endl;
        return -1;
    }
    Node* temp = top;
    int val = temp->value;
    top = top->next;
    delete temp;
    return val;
}

int StackLinkedList::peek() {
    if (isEmpty()) {
        cout << "Stack is empty — nothing to peek." << endl;
        return -1;
    }
    return top->value;
}