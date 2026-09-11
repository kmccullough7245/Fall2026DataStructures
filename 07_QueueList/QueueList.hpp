#ifndef QUEUE_LIST_HPP
#define QUEUE_LIST_HPP
#include "../04_DLList/DLList.hpp"

template <typename T>
class QueueList {
public:
    // TODO:
    QueueList();
    
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
    DLList<T> list;
};

#include "QueueArray.tpp"
#endif