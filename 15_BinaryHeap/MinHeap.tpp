#include "MinHeap.hpp"

template <typename T>
void MinHeap<T>::swap(const T& v1, const T& v2){
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template <typename T>
void MinHeap<T>::print() const {
    for (const T& val : data) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

template <typename T>
void MinHeap<T>::insert(const T& val) {
    data.push_back(val);
    int index = data.size() -1;
    percolateUp(index);
    
}

template <typename T>
int MinHeap<T>::getParent(int index) const {

}

template <typename T>
int MinHeap<T>::getLeftChild(int index) const {

}

template <typename T>
int MinHeap<T>::getRightChild(int index) const {

}

template <typename T>
void MinHeap<T>::percolateUp(int index) {
    
}