#include "list_element.h"
#include <stdlib.h>
#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    LinkedList(const LinkedList &source) = delete;
    LinkedList &operator=(const LinkedList &source) = delete;

    int size();
    bool empty();
    const T &value_at(unsigned int index);
    void push_front(const T &value);
    const T &pop_front();
    void push_back(const T &value);
    const T &pop_back();
    const T &front();
    const T &back();
    void insert(unsigned int index, const T &value);
    void erase(unsigned int index);
    const T &value_n_from_end(int n);
    void reverse();
    void remove_value(const T &value);
private:
    Node<T>* head;
};

#endif