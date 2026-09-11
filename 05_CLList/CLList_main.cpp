#include "CLList.hpp"
#include <iostream>

// USED AI TO BUILD MAIN TO TEST

int main() {

    std::cout << "===== TEST 1: EMPTY LIST =====\n";

    CLList<double> list;

    std::cout << "Expected size: 0\n";
    std::cout << "Actual size:   " << list.size() << "\n";

    std::cout << "Expected empty: 1\n";
    std::cout << "Actual empty:   " << list.empty() << "\n";


    std::cout << "\n===== TEST 2: PUSH FRONT =====\n";

    list.push_front(1.1);
    list.push_front(1.2);
    list.push_front(1.3);

    std::cout << "Expected: 1.3 -> 1.2 -> 1.1\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";

    std::cout << "Expected size: 3\n";
    std::cout << "Actual size:   " << list.size() << "\n";


    std::cout << "\n===== TEST 3: PUSH BACK =====\n";

    list.push_back(1.4);
    list.push_back(1.5);

    std::cout << "Expected: 1.3 -> 1.2 -> 1.1 -> 1.4 -> 1.5\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";

    std::cout << "Expected size: 5\n";
    std::cout << "Actual size:   " << list.size() << "\n";


    std::cout << "\n===== TEST 4: AT =====\n";

    std::cout << "at(0), expected 1.3: " << list.at(0) << "\n";
    std::cout << "at(1), expected 1.2: " << list.at(1) << "\n";
    std::cout << "at(2), expected 1.1: " << list.at(2) << "\n";
    std::cout << "at(3), expected 1.4: " << list.at(3) << "\n";
    std::cout << "at(4), expected 1.5: " << list.at(4) << "\n";


    std::cout << "\n===== TEST 5: MODIFY USING AT =====\n";

    list.at(2) = 9.9;

    std::cout << "Expected: 1.3 -> 1.2 -> 9.9 -> 1.4 -> 1.5\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 6: POP FRONT =====\n";

    list.pop_front();

    std::cout << "Expected: 1.2 -> 9.9 -> 1.4 -> 1.5\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";

    std::cout << "Expected size: 4\n";
    std::cout << "Actual size:   " << list.size() << "\n";


    std::cout << "\n===== TEST 7: POP BACK =====\n";

    list.pop_back();

    std::cout << "Expected: 1.2 -> 9.9 -> 1.4\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";

    std::cout << "Expected size: 3\n";
    std::cout << "Actual size:   " << list.size() << "\n";


    std::cout << "\n===== TEST 8: COPY CONSTRUCTOR =====\n";

    CLList<double> copy(list);

    std::cout << "Original expected: 1.2 -> 9.9 -> 1.4\n";
    std::cout << "Original actual:   ";
    list.print();
    std::cout << "\n";

    std::cout << "Copy expected:     1.2 -> 9.9 -> 1.4\n";
    std::cout << "Copy actual:       ";
    copy.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 9: COPY INDEPENDENCE =====\n";

    copy.push_back(7.7);

    std::cout << "Original should NOT change:\n";
    std::cout << "Expected: 1.2 -> 9.9 -> 1.4\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";

    std::cout << "Copy expected: 1.2 -> 9.9 -> 1.4 -> 7.7\n";
    std::cout << "Copy actual:   ";
    copy.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 10: ASSIGNMENT OPERATOR =====\n";

    CLList<double> assigned;

    assigned.push_front(100.0);
    assigned.push_front(200.0);

    std::cout << "Before assignment: ";
    assigned.print();
    std::cout << "\n";

    assigned = list;

    std::cout << "Expected: 1.2 -> 9.9 -> 1.4\n";
    std::cout << "Actual:   ";
    assigned.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 11: SELF ASSIGNMENT =====\n";

    list = list;

    std::cout << "Expected: 1.2 -> 9.9 -> 1.4\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 12: CLEAR =====\n";

    list.clear();

    std::cout << "Expected size: 0\n";
    std::cout << "Actual size:   " << list.size() << "\n";

    std::cout << "Expected empty: 1\n";
    std::cout << "Actual empty:   " << list.empty() << "\n";

    std::cout << "Printing empty list: ";
    list.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 13: REUSE AFTER CLEAR =====\n";

    list.push_front(5.5);
    list.push_back(6.6);

    std::cout << "Expected: 5.5 -> 6.6\n";
    std::cout << "Actual:   ";
    list.print();
    std::cout << "\n";


    std::cout << "\n===== TEST 14: ONE ELEMENT POP FRONT =====\n";

    CLList<int> oneFront;
    oneFront.push_front(10);

    std::cout << "Before: ";
    oneFront.print();
    std::cout << "\n";

    oneFront.pop_front();

    std::cout << "Expected size: 0\n";
    std::cout << "Actual size:   " << oneFront.size() << "\n";
    std::cout << "Expected empty: 1\n";
    std::cout << "Actual empty:   " << oneFront.empty() << "\n";


    std::cout << "\n===== TEST 15: ONE ELEMENT POP BACK =====\n";

    CLList<int> oneBack;
    oneBack.push_front(10);

    std::cout << "Before: ";
    oneBack.print();
    std::cout << "\n";

    oneBack.pop_back();

    std::cout << "Expected size: 0\n";
    std::cout << "Actual size:   " << oneBack.size() << "\n";
    std::cout << "Expected empty: 1\n";
    std::cout << "Actual empty:   " << oneBack.empty() << "\n";


    std::cout << "\n===== TEST 16: PUSH_BACK ON EMPTY LIST =====\n";

    CLList<int> backEmpty;

    backEmpty.push_back(42);

    std::cout << "Expected: 42\n";
    std::cout << "Actual:   ";
    backEmpty.print();
    std::cout << "\n";

    std::cout << "Expected size: 1\n";
    std::cout << "Actual size:   " << backEmpty.size() << "\n";


    std::cout << "\n===== ALL TESTS FINISHED =====\n";

    return 0;
}