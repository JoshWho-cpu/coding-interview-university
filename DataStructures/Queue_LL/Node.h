#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    Node(const T &value) : next(nullptr), data(value) {}
    ~Node() {} // will delete each node in linked list class, not defining a recursive destructor for the nodes
    Node(const Node &source) = delete; // won't be using
    Node& operator=(const Node& source) = default;    // have implemented before, but default is good enough

    const T &GetData() const {return data;} // const prevents changes to members of the class. appropriate for getters
    Node<T>* GetNext() const {return next;}
    void SetData(const T &value) {data = value;}
    void SetNext(Node<T>* ptr) {next = ptr;}
private:
    Node<T>* next;
    T data;
};

#endif