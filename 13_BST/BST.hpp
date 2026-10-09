#ifndef BST_HPP
#define BST_HPP

#include "BTNode.hpp"

template <typename T>
class BST {
public:
    BST();

    bool empty() const;
    void insert(const T& val);

    const BTNode<T>* search(const T& val) const;
    bool contains(const T& val) const;

    void inorder() const;
    void print() const;

    int height() const;
    int getBalance() const;

    bool remove(const T& val);

private:
    BTNode<T>* root;

    const BTNode<T>* search(const BTNode<T>* node, const T& val) const;

    void inorder(const BTNode<T>* node) const;
    void print(const BTNode<T>* node, int spaces) const;

    int height(const BTNode<T>* node) const;
    int getBalance(const BTNode<T>* node) const;
    BTNode<T>* remove(BTNode<T>* node, const T& val, bool& removed);
};

#include "BST.tpp"

#endif