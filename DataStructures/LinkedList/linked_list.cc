#include "linked_list.h"

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* cur = head;
    Node<T>* next = nullptr;
    while (cur != nullptr) {
        next = cur->GetNext();
        delete cur;
        cur = next;
    }
}

template <class T> 
int LinkedList<T>::size() {
    Node<T>* cur = head;
    unsigned int count = 0;
    while (cur != nullptr) {
        cur = cur->GetNext();
    }
    return count;
}

template <class T> 
bool LinkedList<T>::empty() {
    return head==nullptr;
}

template <class T> 
const T &LinkedList<T>::value_at(unsigned int index) {
    Node<T>* cur = head;
    for (unsigned int i = 0; i < index && cur != nullptr; i++) {
        cur = cur->GetNext;
    }
    if (cur == nullptr) {
        std::cerr << "Index out of bounds." << std::endl;
        exit(EXIT_FAILURE);
    }
    return cur->GetData;
}

template <class T> 
void LinkedList<T>::push_front(const T &value) {
    Node<T> *node = new Node<T>(value);
    node->SetNext(head);
    head = node;
}

template <class T>
const T &LinkedList<T>::pop_front() {
    T value = head->GetData();
    Node<T>* node = head;
    head = head->GetNext();
    delete node;
    return value;
}

template <class T>
void LinkedList<T>::push_back(const T &value) {
    Node<T>* node = new Node(value);
    if (head == nullptr) {
        head = node;
        return;
    }
    Node<T>* cur = head;
    while (cur->GetNext() != nullptr) {
        cur = cur->GetNext();
    }
    cur->SetNext(node);
}

template <class T> 
const T &LinkedList<T>::pop_back() {
    if (empty()) {
        std::cerr << "Linked List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    while (cur->GetNext() != nullptr) {
        prev = cur;
        cur = cur->GetNext();
    }

    T value = cur->GetData();

    if (prev == nullptr) {
        head = nullptr;
    }
    else {
        prev->SetNext(nullptr);
    }

    delete cur;
    return value;
}

template <class T>
const T &LinkedList<T>::front() {
    if (empty()) {
        std::cerr << "List is empty, nothing to return" << std::endl;
        exit(EXIT_FAILURE);
    }

    return head->GetData();
}

template <class T>
const T &LinkedList<T>::back() {
    if (empty()) {
        std::cerr << "List is empty, nothing to return" << std::endl;
        exit(EXIT_FAILURE);
    }

    Node<T>* cur = head;
    while (cur->GetNext() != nullptr) {
        cur = cur->GetNext();
    }
    return cur->GetData();
}

template <class T>
void LinkedList<T>::insert(unsigned int index, const T &value) {
    Node<T>* cur = head;
    for (unsigned int i = 0; i < index && cur != nullptr, i++) {
        cur = cur->GetNext();
    }
    if (cur == nullptr) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }
    Node<T>* node = new Node(value);
    node->SetNext(cur->GetNext());
    cur->SetNext(node);
}

template <class T>
void LinkedList<T>::erase(unsigned int index) {
    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    for (unsigned int i = 0; i < index && cur != nullptr, i++) {
        prev = cur;
        cur = cur->GetNext();
    }
    if (cur == nullptr) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (prev == nullptr) {
        head = current->GetNext();
    }
    else {
        prev->SetNext(cur->GetNext());
    }

    delete cur;
}

template <class T> 
const T &LinkedList<T>::value_n_from_end(int n) {
    Node<T>* cur = head;
    
    for (unsigned int i = 0; i < n && cur != nullptr, i++) {
        cur = cur->GetNext();
    }
    if (cur == nullptr) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    Node<T>* nth = head;
    
    while (cur != nullptr) {
        nth = nth->GetNext();
        cur = cur->GetNext();
    }

    return nth->GetData();
}

template <class T> 
void LinkedList<T>::reverse() {
    Node<T>* prev = nullptr;
    Node<T>* cur = head;
    Node<T>* next;

    while (cur != nullptr) {
        next = cur->GetNext();
        cur->SetNext(prev);
        prev = cur;
        cur = next;
    }

    head = prev;
}

template <class T>
void LinkedList<T>::remove_value(const T &value) {
    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    while (cur != nullptr) {
        if (cur->GetData() != value) {
            if (prev == nullptr) {
                head = cur->GetNext();
            } else {
                prev->SetNext(cur->GetNext());
            }
            delete cur;
            break;
        }
        prev = cur;
        cur = cur->GetNext()
    }
}
