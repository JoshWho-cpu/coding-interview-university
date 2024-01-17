#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

template <typename T>
class Node {
public:
    Node(const T &value) : next(nullptr), data(value) {}
    ~Node() {} // will delete each node in linked list class, not defining a recursive destructor for the nodes
    Node(const Node source) : next(source.next), data(source.value) {}
    Node& operator=(const Node& source);    // want to write this as exercise, not using default
    const T &GetData() const {return data;} // const prevents changes to members of the class. appropriate for getters
    Node<T>* GetNext() const {return next;}
    void SetData(const T &value) {data = value;}
    void SetNext(const Node<T>* ptr) {next = ptr;}
private:
    Node<T> *next;
    T data;
};

#endif