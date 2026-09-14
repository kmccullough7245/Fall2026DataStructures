#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

template <typename t, int capacity = 100>
class StackArrary {
public:
    StackArray();
    void push(const T& val);
    void pop();
    bool full() const;
    bool empty() const;
    void print() const; //TODO
    const T& top() const;


private: 
    T data[capacity];
    int top_idx; 
};

#endif