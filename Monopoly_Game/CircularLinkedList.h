#pragma once

#include <iostream>
#include <string>

using namespace std;

template<typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

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
    bool search(T data) const;
    void printList() const;
    void printHeadNode() const;
    void printLastNode() const;
    bool isListEmpty() const;
    int countNodes() const;
    void updateNodeValue(T value, T newValue);
};