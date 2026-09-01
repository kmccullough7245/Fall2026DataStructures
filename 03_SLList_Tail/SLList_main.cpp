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
    list.pop_back();
    std::cout << std::endl;
    list.print();
    std::cout << std::endl;

    SLList list2 = list;
    list2.print();

    return 0;

}