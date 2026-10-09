#include <iostream>

template <typename T>
BST<T>::BST() : root(nullptr) {
}

template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    BTNode<T>* newNode = new BTNode<T>(val);

    if (empty()) {
        root = newNode;
        return;
    }

    BTNode<T>* cur = root;
    BTNode<T>* parent = nullptr;

    while (cur != nullptr) {
        parent = cur;

        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    if (val < parent->data) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
}

template <typename T>
const BTNode<T>* BST<T>::search(const T& val) const {
    return search(root, val);
}

template <typename T>
const BTNode<T>* BST<T>::search(const BTNode<T>* node, const T& val) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data == val) {
        return node;
    }

    if (val < node->data) {
        return search(node->left, val);
    }

    return search(node->right, val);
}

template <typename T>
bool BST<T>::contains(const T& val) const {
    return search(val) != nullptr;
}

template <typename T>
void BST<T>::inorder() const {
    inorder(root);
    std::cout << std::endl;
}

template <typename T>
void BST<T>::inorder(const BTNode<T>* node) const {
    if (node == nullptr) {
        return;
    }

    inorder(node->left);

    std::cout << node->data << " ";

    inorder(node->right);
}

template <typename T>
void BST<T>::print() const {
    if (empty()) {
        std::cout << "Tree is empty" << std::endl;
        return;
    }

    print(root, 0);
}

template <typename T>
void BST<T>::print(const BTNode<T>* node, int spaces) const {
    if (node == nullptr) {
        return;
    }

    spaces += 5;

    print(node->right, spaces);

    std::cout << std::endl;

    for (int i = 5; i < spaces; i++) {
        std::cout << " ";
    }

    std::cout << node->data << std::endl;

    print(node->left, spaces);
}

template <typename T>
int BST<T>::height() const {
    return height(root);
}

template <typename T>
int BST<T>::height(const BTNode<T>* node) const {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }

    return rightHeight + 1;
}

template <typename T>
int BST<T>::getBalance() const {
    return getBalance(root);
}

template <typename T>
int BST<T>::getBalance(const BTNode<T>* node) const {
    if (node == nullptr) {
        return 0;
    }

    return height(node->left) - height(node->right);
}

template <typename T>
bool BST<T>::remove(const T& val) {
    bool removed = false;
    root = remove(root, val, removed);
    return removed;
}

template <typename T>
BTNode<T>* BST<T>::remove(BTNode<T>* node, const T& val, bool& removed) {
    if (node == nullptr) {
        return nullptr;
    }

    if (val < node->data) {
        node->left = remove(node->left, val, removed);
    }
    else if (node->data < val) {
        node->right = remove(node->right, val, removed);
    }
    else {
        removed = true;
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        if (node->left == nullptr) {
            BTNode<T>* temp = node->right;
            delete node;
            return temp;
        }

        if (node->right == nullptr) {
            BTNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        BTNode<T>* successor = node->right;

        while (successor->left != nullptr) {
            successor = successor->left;
        }

        node->data = successor->data;

        bool successorRemoved = false;
        node->right = remove(node->right, successor->data, successorRemoved);
    }

    return node;
}