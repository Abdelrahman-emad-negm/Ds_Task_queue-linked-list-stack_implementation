#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr; // initialize empty list
}

LinkedList::~LinkedList() {
    // delete all nodes to avoid memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void LinkedList::insertAtHead(int val) {
    // create new node and make it the new head
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);

    // if list is empty
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;

        // traverse to last node
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::deleteValue(int val) {
    // if list is empty
    if (head == nullptr)
        return;

    Node* temp = head;
    Node* prev = nullptr;

    // search for the value
    while (temp != nullptr && temp->value != val) {
        prev = temp;
        temp = temp->next;
    }

    // if value found
    if (temp != nullptr) {
        if (prev == nullptr) {
            // deleting head
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
    }
    else {
        cout << "Value " << val << " not found in the list." << endl;
    }
}

void LinkedList::display() {
    Node* temp = head;
    int count = 1;

    // check if list is empty
    if (temp == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    // print all nodes
    while (temp != nullptr) {
        cout << "Node " << count << ": value is " << temp->value << endl;
        temp = temp->next;
        count++;
    }
}