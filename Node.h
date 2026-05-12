#ifndef NODE_H
#define NODE_H

// Node structure used in linked list, stack, and queue
struct Node {
    int value;     // stored data
    Node* next;    // pointer to next node

    // constructor to initialize node
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

#endif