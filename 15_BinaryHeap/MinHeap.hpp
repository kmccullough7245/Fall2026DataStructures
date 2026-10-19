#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <vector>

template <typename T>
class MinHeap {
public:
    void insert(const T& val);
    void print() const;
    bool empty() const;

private: 
    std::vector<T> data;
    void swap(const T& v1, const T& v2);
    int getParent(int index) const;
    int getLeftChild(int index) const;
    int getRightChild(int index) const;
    void percolateUp(int index);

};

#include "MinHeap.tpp"

#endif