#include "Node.h"

#ifndef QUEUE_LL_H
#define QUEUE_LL_H

template <class T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue();
    Queue(const Queue &source) = delete;
    Queue &operator=(const Queue &source) = delete;

    void enqueue(const T &value);
    const T dequeue();
    bool empty();
private:
    Node<T>* head;  // where items will be dequeued
    Node<T>* tail;  // where items will be enqueued
};

#endif