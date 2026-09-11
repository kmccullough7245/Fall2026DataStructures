#include "CLList.hpp"

#include <iostream>

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}

template <typename T>
CLList<T>::CLList(const CLList<T>& other) {
    tail = nullptr;
    list_size = 0;
    if (!other.empty()) {
        SLLNode<T>* cur = other.tail->next;
        do {
            push_back(cur->data);
            cur = cur->next;
        } while (cur != other.tail->next);
    }
}

template <typename T>
CLList<T>&  CLList<T>::operator=(const CLList<T>& other) {
    if (this != &other) {
        clear();
        tail = nullptr;
        list_size = 0;
        SLLNode<T>* cur = other.tail->next;
        do {
            push_back(cur->data);
            cur = cur->next;
        } while (cur != other.tail->next);
    }
    return *this; 
}


template <typename T>
CLList<T>::~CLList() {
    clear();
}

template <typename T> 
unsigned CLList<T>::size() const{
    return list_size;
}

template <typename T>
void CLList<T>::push_front(const T& val) {
    if (empty()) {
        tail = new SLLNode<T>(val);
        tail->next = tail;
    } else {
        tail->next = new SLLNode<T>(val, tail->next);
    }
    list_size++;
}

template <typename T>
void CLList<T>::push_back(const T& val) {
    if (empty()) {
        push_front(val);
        return;
    } else {
        SLLNode<T>* front = tail->next; 
        tail->next = new SLLNode<T>(val);
        tail->next->next = front;
        tail = tail->next;
    }
    list_size++;
}

template <typename T>
bool CLList<T>::empty() const {
    return list_size == 0;
}

template <typename T>
void CLList<T>::print() const {
    if (list_size == 0) {
        return;
    }
    SLLNode<T>* cur = tail->next;
    do {
        std::cout << cur->data;
        if (cur != tail) { // not the last node
            std::cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
}

template <typename T>
void CLList<T>::pop_front() {
    if (empty()) {
        return;
    }
    SLLNode<T>* to_delete = tail->next;
    if(list_size == 1) {
        tail = nullptr;
    } else {
        tail->next = to_delete->next;
    }
    delete to_delete;
    list_size--;
}

template <typename T>
void CLList<T>::pop_back(void) {
    if (empty()) {
        return;
    }
    SLLNode<T>* to_delete = tail;
    SLLNode<T>* new_tail = tail->next;
    if (list_size == 1) {
        tail = nullptr;
    } else {
        for (int i = 0; i < (list_size - 2); i++) {
            new_tail = new_tail->next;
        }
        new_tail->next = to_delete->next;
        tail = new_tail;
        delete to_delete;
    }
    list_size--;
}

template <typename T> 
void CLList<T>::clear(void) {
    while(!empty()) {
        pop_front();
    }
}

template <typename T> 
T& CLList<T>::at(unsigned index) {
    SLLNode<T>* cur = tail->next;
    if (index <= list_size) {
        for (int i = 0; i < index; i++) {
        cur = cur->next;
        }
        return cur->data;
    } else {
        throw std::out_of_range("index is out of bounds");
    }
    
}