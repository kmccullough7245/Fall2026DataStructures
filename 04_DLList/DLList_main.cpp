#include "DLList.hpp"
#include <iostream>

// Used AI to make main for testing

int main() {

    std::cout << "===== TEST 1: EMPTY LIST =====" << std::endl;

    DLList<char> list;

    std::cout << "Size: " << list.size() << std::endl;
    std::cout << "Empty: " << list.empty() << std::endl;


    std::cout << "\n===== TEST 2: PUSH BACK =====" << std::endl;

    list.push_back('A');
    list.push_back('B');
    list.push_back('C');

    std::cout << "Expected: ABC" << std::endl;
    std::cout << "Actual:   ";
    list.print();

    std::cout << "Size: " << list.size() << std::endl;


    std::cout << "\n===== TEST 3: PUSH FRONT =====" << std::endl;

    list.push_front('X');

    std::cout << "Expected: XABC" << std::endl;
    std::cout << "Actual:   ";
    list.print();

    std::cout << "Size: " << list.size() << std::endl;


    std::cout << "\n===== TEST 4: AT =====" << std::endl;

    std::cout << "at(0), expected X: " << list.at(0) << std::endl;
    std::cout << "at(1), expected A: " << list.at(1) << std::endl;
    std::cout << "at(2), expected B: " << list.at(2) << std::endl;
    std::cout << "at(3), expected C: " << list.at(3) << std::endl;


    std::cout << "\n===== TEST 5: MODIFY USING AT =====" << std::endl;

    list.at(1) = 'Z';

    std::cout << "Expected: XZBC" << std::endl;
    std::cout << "Actual:   ";
    list.print();


    std::cout << "\n===== TEST 6: POP FRONT =====" << std::endl;

    list.pop_front();

    std::cout << "Expected: ZBC" << std::endl;
    std::cout << "Actual:   ";
    list.print();

    std::cout << "Size: " << list.size() << std::endl;


    std::cout << "\n===== TEST 7: POP BACK =====" << std::endl;

    list.pop_back();

    std::cout << "Expected: ZB" << std::endl;
    std::cout << "Actual:   ";
    list.print();

    std::cout << "Size: " << list.size() << std::endl;


    std::cout << "\n===== TEST 8: COPY CONSTRUCTOR =====" << std::endl;

    DLList<char> copy(list);

    std::cout << "Original: ";
    list.print();

    std::cout << "Copy:     ";
    copy.print();


    std::cout << "\n===== TEST 9: COPY INDEPENDENCE =====" << std::endl;

    copy.push_back('Q');

    std::cout << "Original should still be ZB: ";
    list.print();

    std::cout << "Copy should be ZBQ:         ";
    copy.print();


    std::cout << "\n===== TEST 10: ASSIGNMENT OPERATOR =====" << std::endl;

    DLList<char> assigned;
    assigned.push_back('1');
    assigned.push_back('2');

    std::cout << "Before assignment: ";
    assigned.print();

    assigned = list;

    std::cout << "Expected after assignment: ZB" << std::endl;
    std::cout << "Actual:                    ";
    assigned.print();


    std::cout << "\n===== TEST 11: SELF ASSIGNMENT =====" << std::endl;

    list = list;

    std::cout << "Expected: ZB" << std::endl;
    std::cout << "Actual:   ";
    list.print();


    std::cout << "\n===== TEST 12: CLEAR =====" << std::endl;

    list.clear();

    std::cout << "Size after clear: " << list.size() << std::endl;
    std::cout << "Empty after clear: " << list.empty() << std::endl;

    std::cout << "Printing cleared list: ";
    list.print();


    std::cout << "\n===== TEST 13: REUSE AFTER CLEAR =====" << std::endl;

    list.push_back('K');
    list.push_back('M');

    std::cout << "Expected: KM" << std::endl;
    std::cout << "Actual:   ";
    list.print();


    std::cout << "\n===== ALL TESTS FINISHED =====" << std::endl;

    return 0;
}