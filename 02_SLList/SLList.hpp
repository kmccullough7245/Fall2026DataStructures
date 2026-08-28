#ifndef SLLIST_HPP
#define SLLIST_HPP

#include "SLNode.hpp"

class SLList{
    public:
    // No arg constructor
    SLList();
    unsigned    size() const; // Return the size of the list
    bool        empty() const; // Return true if list is empty
    void        push_front(int val); // Insert the node at the beginning
    void        print() const; // Print the list
    //TODO: void push_back in the end


    private: 
    SLLNode* head; // First node in the linked list
    unsigned list_size; // The nmber of nodes in the linked list
};

#endif