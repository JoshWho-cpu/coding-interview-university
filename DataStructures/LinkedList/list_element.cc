#include "list_element.h"

template <typename T> 
Node<T>& Node<T>::operator=(const Node<T>& source) {
    if (this!= source) {
        this->data = source.data;
        this->next = source.next;
    }
    return *this;
}