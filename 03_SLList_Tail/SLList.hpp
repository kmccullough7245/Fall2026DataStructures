#ifndef SLLIST_HPP
#define SLLIST_HPP

#include "SLNode.hpp"

class SLList{
    public:
    // No arg constructor
    SLList();
    ~SLList();
    SLList(const SLList& other);
    SLList& operator=(const SLList& other);
    unsigned    size() const; // Return the size of the list
    bool        empty() const; // Return true if list is empty
    void        push_front(int val); // Insert the node at the beginning
    void        print() const; // Print the list
    void        push_back(int val);
    void        pop_front(void); // Remove the first node from the list 
    void        pop_back(void); // Remove the last node from the list
    void        clear(void);

    private: 
    SLLNode* head; // First node in the linked list
    SLLNode* tail; // Last node in the linked list
    unsigned list_size; // The nmber of nodes in the linked list
};

#endif