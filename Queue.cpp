#include "Queue.h"
#include <iostream>
using namespace std;

// ================= Circular Array =================
QueueArray::QueueArray(int cap) {
    capacity = cap;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    size = 0; // start empty
}

// free allocated array
QueueArray::~QueueArray() {
    delete[] arr;
}

bool QueueArray::isFull() {
    return size == capacity;
}

bool QueueArray::isEmpty() {
    return size == 0;
}

void QueueArray::enqueue(int value) {
    // check if queue is full
    if (isFull()) {
        cout << "Queue is Full\n";
        return;
    }

    // move rear in circular way
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
}

void QueueArray::dequeue() {
    // check if queue is empty
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    // move front in circular way
    front = (front + 1) % capacity;
    size--;
}

int QueueArray::getFront() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return -1;
    }
    return arr[front];
}

// ================= Linked List =================
QueueLinkedList::QueueLinkedList() {
    front = rear = nullptr; // empty queue
}

// delete all nodes
QueueLinkedList::~QueueLinkedList() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool QueueLinkedList::isEmpty() {
    return front == nullptr;
}

void QueueLinkedList::enqueue(int value) {
    Node* newNode = new Node(value);

    // if queue is empty
    if (rear == nullptr) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void QueueLinkedList::dequeue() {
    // check if queue is empty
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    // if queue becomes empty after dequeue
    if (front == nullptr)
        rear = nullptr;

    delete temp;
}

int QueueLinkedList::getFront() {
    if (isEmpty()) {
        cout << "Queue is Empty\n";
        return -1;
    }
    return front->value;
}