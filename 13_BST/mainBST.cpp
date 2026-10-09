
// Create BST, insert nodes, check contain method
#include "BST.hpp"
#include <string>
#include <iostream>
int main(void) {
BST<std::string> tree;
    tree.insert("hello");
    tree.insert("apple");
    tree.insert("zoo");
    tree.insert("carrot");
    tree.insert("laptop");
    tree.insert("car");
    tree.insert("pen");
    tree.print();
    tree.remove("car");
    tree.print();
    tree.remove("apple");
    tree.print();
    tree.remove("hello");
    tree.print();
return 0;
}
