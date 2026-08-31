#include "SLList.hpp"
#include <iostream>

int main(void) {
    SLList list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_back(5);

    list.print();
    list.pop_front();
    std::cout << std::endl;
    list.print();
    std::cout << std::endl;
    std::cout << list.size() << std::endl;
    list.clear();
    list.print();
    std::cout << std::endl;
    return 0;

}