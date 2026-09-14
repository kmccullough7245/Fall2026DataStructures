#include "Deque.hpp"
#include <iostream>

int main() {

    Deque<int, 5> d;

    std::cout << "Initially empty: " << d.empty() << "\n";

    std::cout << "\n--- push_back tests ---\n";
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.print();

    std::cout << "\n--- push_front tests ---\n";
    d.push_front(5);
    d.push_front(1);
    d.print();

    std::cout << "\nDeque full: " << d.full() << "\n";

    std::cout << "\n--- pop_front test ---\n";
    std::cout << "Removed: " << d.pop_front() << "\n";
    d.print();

    std::cout << "\n--- pop_back test ---\n";
    std::cout << "Removed: " << d.pop_back() << "\n";
    d.print();

    std::cout << "\n--- remove remaining elements ---\n";

    while (!d.empty()) {
        std::cout << "Removed from front: " << d.pop_front() << "\n";
        d.print();
    }

    std::cout << "\nDeque empty: " << d.empty() << "\n";

    return 0;
}