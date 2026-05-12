#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

// Prints a clear section header in the console
void printHeader(const string& title) {
    cout << "\n================================================" << endl;
    cout << "  " << title << endl;
    cout << "================================================" << endl;
}

// ═════════════════════════════════════════════════════════════════════════════
int main() {

    // ── 0. Basic edge case checks ───────────────────────────────────────────
    printHeader("Edge Case Testing");

    LinkedList emptyList;
    emptyList.deleteValue(10); // try deleting from an empty list

    StackArray emptyStack(2);
    emptyStack.pop(); // popping from empty stack (underflow)

    QueueArray emptyQueue(3);
    emptyQueue.dequeue(); // dequeue from empty queue


    // ── 1. Singly Linked List ───────────────────────────────────────────────
    printHeader("Singly Linked List");

    LinkedList list;

    // Insert elements
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtHead(5); // list becomes: 5 → 10 → 20 → 30

    cout << "After insertions:" << endl;
    list.display();

    // Delete a middle value
    list.deleteValue(20);
    cout << "\nAfter deleting 20:" << endl;
    list.display();

    // Try deleting a value that doesn't exist
    list.deleteValue(99);

    // Delete head node
    list.deleteValue(5);
    cout << "\nAfter deleting 5 (head):" << endl;
    list.display();


    // ── 2. Array-Based Stack ────────────────────────────────────────────────
    printHeader("Stack — Array-Based");

    StackArray sa(3);

    // Push elements until full
    sa.push(100);
    sa.push(200);
    sa.push(300);
    sa.push(400); // should trigger overflow

    cout << "Peek: " << sa.peek() << endl;

    // Pop all elements
    cout << "Pop:  " << sa.pop() << endl;
    cout << "Pop:  " << sa.pop() << endl;
    cout << "Pop:  " << sa.pop() << endl;

    // Extra pop to test underflow
    cout << "Pop:  " << sa.pop() << endl;


    // ── 3. Linked List-Based Stack ──────────────────────────────────────────
    printHeader("Stack — Linked List-Based");

    StackLinkedList sll;

    // Push elements
    sll.push(1);
    sll.push(2);
    sll.push(3);

    cout << "Peek: " << sll.peek() << endl;

    // Pop step by step
    cout << "Pop:  " << sll.pop() << endl;
    cout << "Pop:  " << sll.pop() << endl;

    cout << "Is empty? " << (sll.isEmpty() ? "Yes" : "No") << endl;

    cout << "Pop:  " << sll.pop() << endl;

    cout << "Is empty? " << (sll.isEmpty() ? "Yes" : "No") << endl;

    // One more pop to check underflow
    cout << "Pop:  " << sll.pop() << endl;


    // ── 4. Circular Queue (Array-Based) ─────────────────────────────────────
    printHeader("Queue — Circular Array");

    QueueArray q1(5);

    // Initial enqueue
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    cout << "Front: " << q1.getFront() << endl;

    // Remove one element
    q1.dequeue();
    cout << "Front after dequeue: " << q1.getFront() << endl;

    // Fill the queue
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60); // may trigger overflow if full

    // Test circular behavior (wrap-around)
    q1.dequeue();
    q1.dequeue();

    q1.enqueue(70);
    q1.enqueue(80);

    cout << "Front after wrap-around: " << q1.getFront() << endl;


    // ── 5. Queue (Linked List-Based) ────────────────────────────────────────
    printHeader("Queue — Linked List");

    QueueLinkedList q2;

    // Enqueue elements
    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);

    cout << "Front: " << q2.getFront() << endl;

    // Remove one element
    q2.dequeue();
    cout << "Front after dequeue: " << q2.getFront() << endl;

    // Remove all to make it empty
    q2.dequeue();
    q2.dequeue();
    q2.dequeue();

    // Try removing from empty queue
    q2.dequeue();

    cout << "Is queue empty? " << (q2.isEmpty() ? "Yes" : "No") << endl;


    cout << "\nAll tests complete." << endl;
    return 0;
}