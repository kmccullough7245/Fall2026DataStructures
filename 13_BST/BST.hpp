#ifndef BST_HPP
#define BST_HPP

#include "BTNode.hpp"

template<typename T>
class BST {
public:
    BST();
    bool BST<T>::empty() const;
    void insert(const T& val);
    const BTNode<T>* search(const T& val);
    //TODO
    bool contains(const T& val) const;
    const BTNode<T>* search_parent(const T& val);


private:
    BTNode<T>* root;
    const BTNode<T>* search(const BTNode<T>* node, const T& val);
};

#include "BST.tpp"
#endif