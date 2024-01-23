#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

template <class T>
class queue{
    static const int QueueCapacity = 5;
    static const int QueuePositions = QueueCapacity + 1;
public:
    queue(): insert(0), pop(0) {}
    ~queue() = default;
    queue(const queue& source) = delete;
    queue &operator=(const queue& source) = default;

    void enqueue(const T& value);
    const T& dequeue();
    bool empty();
    bool full();
private:
    int insert;
    int pop;
    T data_[QueuePositions];
};

#endif 