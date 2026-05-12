# 📦 Linear Data Structures in C++

Implementation of core linear data structures — **Linked Lists**, **Stacks**, and **Queues** — using C++, with a focus on memory management and the distinction between array-based and pointer-based (linked) memory allocation.

---

## 📁 Project Structure

```
.
├── Node.h            # Shared Node struct used across all structures
├── LinkedList.h      # Singly Linked List interface
├── LinkedList.cpp    # Singly Linked List implementation
├── Stack.h           # StackArray & StackLinkedList interfaces
├── Stack.cpp         # Stack implementations
├── Queue.h           # QueueArray (Circular) & QueueLinkedList interfaces
├── Queue.cpp         # Queue implementations
└── main.cpp          # Driver program — tests all data structures
```

---

## 🗂️ Data Structures Implemented

### 🔗 Singly Linked List
A sequence of nodes where each node holds a value and a pointer to the next node.

| Method | Description |
|---|---|
| `insertAtHead(int val)` | Inserts a new node at the beginning — O(1) |
| `insertAtEnd(int val)` | Inserts a new node at the end — O(n) |
| `deleteValue(int val)` | Deletes the first occurrence of the value — O(n) |
| `display()` | Prints all nodes in order |

---

### 📚 Stack (LIFO)
Two implementations provided:

#### 1. Array-Based (`StackArray`)
- Uses a dynamic array with a fixed capacity
- Handles **Stack Overflow** (push beyond capacity) and **Stack Underflow** (pop from empty)

#### 2. Linked List-Based (`StackLinkedList`)
- Dynamically sized — no capacity limit
- All operations run in **O(1)** time

| Method | Description |
|---|---|
| `push(int value)` | Adds element to the top |
| `pop()` | Removes and returns the top element |
| `peek()` | Returns the top element without removing it |
| `isEmpty()` | Returns `true` if the stack is empty |

---

### 🚶 Queue (FIFO)
Two implementations provided:

#### 1. Circular Array-Based (`QueueArray`)
- Uses `front`, `rear`, and `size` indices
- **Circular wraparound** ensures efficient reuse of array space
- Handles **Queue Overflow** and **Queue Underflow**

#### 2. Linked List-Based (`QueueLinkedList`)
- Maintains both `front` and `rear` pointers
- **O(1)** enqueue and dequeue operations

| Method | Description |
|---|---|
| `enqueue(int value)` | Adds element to the rear |
| `dequeue()` | Removes element from the front |
| `getFront()` | Returns the front element without removing it |
| `isEmpty()` | Returns `true` if the queue is empty |
| `isFull()` | Returns `true` if the queue is full (array-based only) |

---

## ⚙️ How to Compile & Run

```bash
g++ main.cpp LinkedList.cpp Stack.cpp Queue.cpp -o dsa_test
./dsa_test
```

---

## 🖥️ Program Output

```
================================================
  Edge Case Testing
================================================
Stack Underflow: cannot pop from an empty stack.
Queue is Empty

================================================
  Singly Linked List
================================================
After insertions:
Node 1: value is 5
Node 2: value is 10
Node 3: value is 20
Node 4: value is 30

After deleting 20:
Node 1: value is 5
Node 2: value is 10
Node 3: value is 30
Value 99 not found in the list.

After deleting 5 (head):
Node 1: value is 10
Node 2: value is 30

================================================
  Stack — Array-Based
================================================
Stack Overflow: cannot push 400 — stack is full (capacity = 3).
Peek: 300
Pop:  300
Pop:  200
Pop:  100
Pop:  Stack Underflow: cannot pop from an empty stack.
-1

================================================
  Stack — Linked List-Based
================================================
Peek: 3
Pop:  3
Pop:  2
Is empty? No
Pop:  1
Is empty? Yes
Pop:  Stack Underflow: cannot pop from an empty stack.
-1

================================================
  Queue — Circular Array
================================================
Front: 10
Front after dequeue: 20
Front after wrap-around: 40

================================================
  Queue — Linked List
================================================
Front: 100
Front after dequeue: 200
Queue is Empty
Queue is Empty
Is queue empty? Yes

All tests complete.
```

---

## 🧠 Key Concepts Demonstrated

- **Dynamic memory allocation** using `new` and `delete`
- **Destructor-based cleanup** to prevent memory leaks (every `new` has a corresponding `delete`)
- **Encapsulation** — all internal members (`top`, `front`, `rear`, `arr`) are `private`
- **Circular indexing** for the array-based queue using modulo: `rear = (rear + 1) % capacity`
- **Edge case handling** — overflow, underflow, empty-list operations, deleting non-existent values

---

## 🔍 Design Decisions

| Feature | Array-Based | Linked List-Based |
|---|---|---|
| Memory | Fixed at creation | Dynamic, grows as needed |
| Access | O(1) index access | O(1) at head/tail only |
| Overflow | Possible (fixed cap) | Not applicable |
| Memory overhead | Low (no pointers) | Per-node pointer overhead |
| Best for | Known max size | Unknown or varying size |

---

## 📝 Notes

- The `Node` struct is defined once in `Node.h` and shared across all linked-structure implementations
- The circular queue correctly handles **wrap-around** — elements can be enqueued at indices that were previously dequeued, ensuring no wasted space
- All classes use **include guards** (`#ifndef / #define / #endif`) to prevent double-inclusion errors
