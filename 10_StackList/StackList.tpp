#include "StackList.hpp"
#include <stdexcept>
#include <iostream>


template <typename T>
StackList<T>::StackList() {
    top_node = nullptr;
}


template <typename T>
StackList<T>::~StackList() {
    while(!empty()) {
        pop();
    }
}

template <typename T>
void        StackList<T>::push(const T& val) {
    val->top_node;
    top_node = val;
}


template <typename T>
bool        StackList<T>::empty() const {
    if (top_node == nullptr) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
void        StackList<T>::print() const {
    std::cout << "{";

    SLLNode* cur = top_node;

    while(cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << "->";
        }
        cur = cur->next;
    }

    std::cout << "}";
}

template <typename T>
T           StackList<T>::pop() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    Node<T>* temp = top_node->next;
    temp->next = top_node;
    del(temp);
}

template <typename T>
const T&    StackList<T>::top() const {
    return top_node;
}
    