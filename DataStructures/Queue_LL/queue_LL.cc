#include "queue_LL.h"
#include <stdlib.h>
#include <iostream>

template <class T>
Queue<T>::~Queue() {
    Node<T>* cur = head;
    Node<T>* next = nullptr;
    while (cur != nullptr) {
        next = cur->GetNext();
        delete cur;
        cur = next;
    }
}

template <class T>
void Queue<T>::enqueue(const T &value) {
    Node<T>* node = new Node(value);
    node->SetNext(nullptr);

    if (empty()) {
        head = tail = node;
    }
    else {
        tail->SetNext(node);
        tail = node;
    }

}

template <class T>
const T Queue<T>::dequeue() {
    if (empty()) {
        std::cerr << "Cannot dequeue from empty queue" << std::endl;
        exit(EXIT_FAILURE);
    }
    T data = head->GetData();
    Node<T>* temp = head;

    if (head == tail) { // empty case was taken care of. only one element
        tail = nullptr;
    }
    head = head->GetNext();
    delete temp;

    return data;
}

template <class T> 
bool Queue<T>::empty() {
    return (head == nullptr);
}

