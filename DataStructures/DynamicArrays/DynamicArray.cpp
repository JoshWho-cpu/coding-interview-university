#include <iostream>

class DynamicArray { // dynamic array class
    void DynamicArray::resize(int newcapacity);
public:
    int _size;
    int _capacity;
    int* ptr;
    DynamicArray() : _size(0), _capacity(16), ptr(new int[16]) {}
    int size();
    int capacity();
    bool is_empty();
    int at(int index);
    void push(int item);
    void insert(int index, int item);
    void prepend(int item);
    int pop();
    void deleteat(int index);
    void remove(int item);
    int DynamicArray::find(int item);
};

int DynamicArray::size() {
    return _size;
}

int DynamicArray::capacity() {
    return _capacity;
}

bool DynamicArray::is_empty() {
    return !_size;
}

int DynamicArray::at(int index) {
    if (index < 0 || index >= _size) {exit(1);}  // check out of bounds
    return ptr[index];
}

void DynamicArray::push(int item) {
    if (_size == _capacity) {
        resize(_capacity*2);
        _capacity*=2;
    }
    ptr[_size++] = item;
}

void DynamicArray::insert(int index, int item) {
    if (_size == _capacity) { // need to resize more memory
        resize(_capacity*2);
        _capacity *= 2;
    }
    int cur = _size;
    while (cur > index) {
        ptr[cur+1] = ptr[cur];
        cur--;
    }
    ptr[_size++] = item;
}

void DynamicArray::prepend(int item) {
    insert(0, item);
}

int DynamicArray::pop() {
    if (_size < _capacity/2) {
        resize(_capacity/2);
        _capacity /= 2;
    }
    return ptr[--_size];    // don't really need to "remove". adjusting size adjusts accessible values
}

void DynamicArray::deleteat(int index) {
    index++;
    while (index < _size) {
        ptr[index-1] = ptr[index];
        index++;
    }
    _size--;
}

void DynamicArray::remove(int item) {
    unsigned int i = find(item);
    while (i != -1) {
        deleteat(i);
        i = find(item);
    }
}

int DynamicArray::find(int item) {
    for (unsigned int i = 0; i < _size; i++) {
        if (ptr[i] == item) {return i;}
    }
    return -1;
}

void DynamicArray::resize(int newcapacity) {
    int* resized = new int[newcapacity];    // allocate
    for (unsigned int i = 0; i < _size; i++) { // copy
        resized[i] = ptr[i];
    }
    delete ptr; // delete old
    ptr = resized; // updates
}

int main() {
    DynamicArray arr; // initial array

    return 0;
}