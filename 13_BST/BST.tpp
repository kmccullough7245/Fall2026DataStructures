#include "BST.hpp"

template<typename T>
BST<T>::BST() : root(nullptr) {

}

template<typename T>
bool BST<T>::empty() const {
    return root = nullptr;
}

template<typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }

    BTNode<T>* cur = root;
    BTNode<T>* parent = root;

    // Iterate through BST
    while (cur) {
        parent = cur;
        if (val < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if (val < parent->data) {
        parent->left = new BTNode<T>(val);
    } else {
        parent->right = new BTNODE<T>(val);
    }

}

template <typename T>
const BTNode<T>* BST<T>::search(const BTNode<T>* node, const T& val) {
    // Base Case
    if (!node || node->data == val) {
        return node;
    } else if (val < node->data) {
        return search(node->left, val);
    } else {
        return search(node->right, val);
    }
}

template<typename T>
const BTNode<T>* BST<T>::search(const T& val) {
    search(val);
}