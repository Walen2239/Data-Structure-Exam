#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include <string>

class Node {
public:
    int ID;
    std::string Name;
    int Age;
    Node* next;
};

class SLL {
public:
    Node* head;
    Node* tail;
    Node* current;

    // 1. Initialize
    SLL();

    // 2. ENQUEUE (Add to end - corrected name to Enqueue)
    void Enqueue(int id, const std::string& name, int age);

    // 3. Dequeue (Remove Head)
    bool Dequeue();

    // 4. Move Next
    void moveNext();

    // 5. Move Previous
    void movePrevious();

    // 6. Print Head
    void printHead();

    // 7. Print Tail
    void printTail();

    // 8. Print Current
    void printCurrent();

    // 9. Print All
    void printAll();
};

#endif // SINGLY_LINKED_LIST_H