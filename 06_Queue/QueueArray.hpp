#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP

template <typename T, int size = 100>
class QueueArray {
public:
    QueueArray();
    
    bool empty() const; 
    bool full() const;
    void print() const;
    void enqueue(const T&);
    const T& dequeue();

    // TODO:
    const T& front(); // Return first element in queue
    void clear(); // Remove all the elements in queue
    int size(); // Returns the size of the queue 

private: 
    T data[size];
    int front_idx, back_idx;
    int queue_size;
};

#include "QueueArray.tpp"
#endif