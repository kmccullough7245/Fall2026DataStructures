#include "StackArray.hpp"


template <typename t, int capacity = 100>
StackArray<T, capacity>::Stack() : top_idx(-1) {

}

template <typename t, int capacity = 100>
void StackArray<T, capacity>::push(const T& val) {
    if (full()) {
        throw std::out_of_range("push: Full Stack");
    } else {
        data[++top_idx] = val;
    }
}

template <typename t, int capacity = 100>
void StackArray<T, capacity>::pop() {
    if (empty()) {
        throw std::out_of_range("pop: Empty Stack");
    } else {
        return data[top_idx--];
    }   
}

template <typename t, int capacity = 100>
bool StackArray<T, capacity>::full() const {
    return top_idx == capacity - 1;

}
    
template <typename t, int capacity = 100>
bool StackArray<T, capacity>::empty() const {
    return tip_idx == -1;
}
    
template <typename t, int capacity = 100>
const T& Stack<T, capacity>::top() const {
    if (empty()) {
        throw std::out_of_range("top: Empty Stack");
    } else {
        return data[top_idx];
    }   
}