#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

public:
    CircularLinkedList();
    void insertAtHead(T newData);
    void insertAtTail(T newData);
    void insertAtPosition(T newData, int position);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPosition(int position);
    int search(T data) const;
    void printList() const;
    void printHeadNode() const;
    void printLastNode() const;
    bool isListEmpty() const;
    int countNodes() const;
    void updateNodeValue(T value, T newValue);
    Node<T>* getHeadNode();
};

#include "CircularLinkedList.cpp" // Include the implementation file
#endif // CIRCULARLINKEDLIST_H
