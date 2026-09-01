#include "SLList.hpp"
#include <iostream>


SLList::SLList() : head(nullptr), tail(nullptr), list_size(0) {


}
SLList::~SLList() {
    clear();
}

SLList::SLList(const SLList& other) {
    head = nullptr;
    tail = nullptr;
    list_size = 0;
    SLLNode* cur = other.head;
    while (cur) {
        push_back(cur->data);
        cur = cur->next;
    }
}

SLList& SLList::operator=(const SLList& other) {
    if (this != &other) {
        clear();
        head = nullptr;
        tail = nullptr;
        list_size = 0;
        SLLNode* cur = other.head;
        while (cur) {
            push_back(cur->data);
            cur = cur->next;
        }
    }
    return *this;
}



unsigned SLList::size() const {
    return list_size;
}

bool SLList::empty() const {
    return(size() == 0);
}

void SLList::push_front(int val) {
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;
    head = new SLLNode(val, head);
    list_size++;

    if(size() == 1) {
        tail = head;
    }
}

void SLList::print() const {
    std::cout << "{";

    SLLNode* cur = head;

    while(cur) {
        std::cout << cur->data;
        if (cur->next) {
            std::cout << "->";
        }
        cur = cur->next;
    }

    std::cout << "}";

}

void SLList::push_back(int val) {
    // SLLNode* cur = head;
    // if (head == nullptr) {
    //     SLLNode* new_node = new SLLNode(val);
    //     head = new_node;
    //     list_size++;
    //     return;
    // }
    // while (cur->next != nullptr) {
    //     cur = cur->next;
    // }
    // SLLNode* new_node = new SLLNode(val);
    // cur->next = new_node;
    if (empty()) {
        push_front(val);
        return;
    }
    tail->next =  new SLLNode(val); // Add the new node at the end
    tail = tail->next; // Update the tail

    list_size++;
}

void SLList::pop_front(void) {
    if (!empty()) {
        SLLNode* old_head = head;
        head = head->next;
        delete old_head;

        list_size--;
        if (empty()) { // If the last node was deleted
            tail = head; // Update the tail
        }
    }
}

// Pop Back
void SLList::pop_back(void) {
    if (!empty()) {
        if (list_size == 1) {
            clear();
            return;
        }
        SLLNode* old_tail = tail;
        SLLNode* cur = head;
        while (cur->next != old_tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = nullptr;
        delete old_tail;
        list_size--;
        if (empty()) { // If the last node was deleted
            head = tail; // Update the tail
        }

    }
}

void SLList::clear(void) {
    while(!empty()) {
        pop_front();
    }
}