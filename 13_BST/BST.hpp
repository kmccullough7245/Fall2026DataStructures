#ifndef BST_HPP
#define BST_HPP

#include "BTNode.hpp"

template<typename T>
class BST {
public:
    BST();
    bool BST<T>::empty() const;
    void insert(const T& val);
    //TODO
    bool contains(const T& val) const;

private:
    BTNode<T>* root;

};

#include "BST.tpp"
#endif