#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

// ================= Circular Array Queue =================
class QueueArray {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    QueueArray(int cap);
    ~QueueArray(); // free dynamic array

    void enqueue(int value);
    void dequeue();

    bool isFull();
    bool isEmpty();

    int getFront();
};

// ================= Linked List Queue =================
class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList();
    ~QueueLinkedList(); // delete all nodes

    void enqueue(int value);
    void dequeue();

    bool isEmpty();

    int getFront();
};

#endif