#include "CircularLinkedList.h"

template<typename T>
CircularLinkedList<T>::CircularLinkedList() {
    headNode = nullptr;
    tailNode = nullptr;
}

template<typename T>
void CircularLinkedList<T>::insertAtHead(T newData) {
    Node<T>* newNode = new Node<T>(newData);

    // Empty list
    if(headNode == nullptr) {
        headNode = newNode;
        tailNode = newNode;
        newNode->nextNode = newNode;
        return;
    }

    // Not empty
    Node<T>* tempNode = headNode;
    headNode = newNode;
    headNode->nextNode = tempNode;
    tailNode->nextNode = headNode;
}

template<typename T>
void CircularLinkedList<T>::insertAtTail(T newData) {
    Node<T>* newNode = new Node<T>(newData);

    // Empty list
    if(headNode == nullptr) {
        headNode = newNode;
        tailNode = newNode;
        newNode->nextNode = newNode;
        return;
    }

    // Not empty
    tailNode->nextNode = newNode;
    tailNode = newNode;
    newNode->nextNode = headNode;
}

template<typename T>
void CircularLinkedList<T>::insertAtPosition(T newData, int position) {
    Node<T>* newNode = new Node<T>(newData);

    // Invalid position
    if(position < 1) {
        return;
    }

    // Insert at head
    if(position == 1) {
        if(headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            newNode->nextNode = newNode;
            return;
        }
        Node<T>* tempNode = headNode;
        headNode = newNode;
        headNode->nextNode = tempNode;
        tailNode->nextNode = headNode;
        return;
    }

    // Empty list
    if(headNode == nullptr) {
        return;
    }

    Node<T>* currentNode = headNode;
    for(int i = 0; i < position - 2; i++) {
        currentNode = currentNode->nextNode;
        if(currentNode == headNode) {
            return;
        }
    }
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
    if(newNode->nextNode == headNode) {
        tailNode = newNode;
    }
}

template<typename T>
void CircularLinkedList<T>::deleteAtHead() {
    // Empty list
    if(headNode == nullptr) {
        return;
    }

    // List only has one element
    if(headNode == tailNode) {
        Node<T>* temp = headNode;
        headNode = nullptr;
        tailNode = nullptr;
        delete temp;
        return;
    }

    Node<T>* temp = headNode;
    headNode = headNode->nextNode;
    tailNode->nextNode = headNode;
    delete temp;
}

template<typename T>
void CircularLinkedList<T>::deleteAtTail() {
    // List is empty
    if(headNode == nullptr) {
        return;
    }

    // List only has one element
    if(headNode == tailNode) {
        Node<T>* temp = headNode;
        headNode = nullptr;
        tailNode = nullptr;
        delete temp;
        return;
    }

    Node<T>* temp = tailNode;
    Node<T>* currentNode = headNode;
    while(currentNode->nextNode != tailNode) {
        currentNode = currentNode->nextNode;
    }
    currentNode->nextNode = headNode;
    tailNode = currentNode;
    delete temp;
}

template<typename T>
void CircularLinkedList<T>::deleteAtPosition(int position) {
    // Invalid position
    if(position < 1) {
        return;
    }

    // Empty list
    if(headNode == nullptr) {
        return;
    }

    // Delete at head
    if(position == 1) {
        deleteAtHead();
        return;
    }

    Node<T>* currentNode = headNode;
    for(int i = 0; i < position - 2; i++) {
        currentNode = currentNode->nextNode;
        if(currentNode == tailNode) {
            return;
        }
    }

    // Delete at tail
    if(currentNode->nextNode == tailNode) {
        deleteAtTail();
        return;
    }

    Node<T>* temp = currentNode->nextNode;
    currentNode->nextNode = currentNode->nextNode->nextNode;
    delete temp;
}

template<typename T>
bool CircularLinkedList<T>::search(T data) const {
    if(headNode == nullptr) {
        return false;
    }

    Node<T>* currentNode = headNode;
    do{
        if(currentNode->data.isEqual(data)) {
            return true;
        }
        currentNode = currentNode->nextNode;
    } while(currentNode != headNode);

    return false;
}

template<typename T>
void CircularLinkedList<T>::printList() const {
    if(headNode == nullptr) {
        return;
    }

    Node<T>* currentNode = headNode;
    do {
        currentNode->data.print();
        if(currentNode != tailNode) {
            cout << "-->" << endl;
        } else {
            cout << endl;
        }
        currentNode = currentNode->nextNode;
    } while(currentNode != headNode);
}

template<typename T>
void CircularLinkedList<T>::printHeadNode() const {
    if(headNode == nullptr) {
        return;
    }
    headNode->data.print();
    cout << endl;
}

template<typename T>
void CircularLinkedList<T>::printLastNode() const {
    if(headNode == nullptr) {
        return;
    }
    tailNode->data.print();
    cout << endl;
}

template<typename T>
bool CircularLinkedList<T>::isListEmpty() const {
    if(headNode == nullptr) {
        return true;
    }
    return false;
}

template<typename T>
int CircularLinkedList<T>::countNodes() const {
    if(headNode == nullptr) {
        return 0;
    }

    int count = 0;
    Node<T>* currentNode = headNode;
    do {
        count++;
        currentNode = currentNode->nextNode;
    } while(currentNode != headNode);
    return count;
}

template<typename T>
void CircularLinkedList<T>::updateNodeValue(T value, T newValue) {
    if(headNode == nullptr) {
        return;
    }

    Node<T>* currentNode = headNode;
    do {
        if(currentNode->data.isEqual(value)) {
            currentNode->data = newValue;
        }
        currentNode = currentNode->nextNode;
    } while(currentNode != headNode);
}