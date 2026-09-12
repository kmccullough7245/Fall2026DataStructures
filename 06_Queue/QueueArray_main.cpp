#include "QueueArray.hpp"
#include <iostream>


// USED AI TO MAKE MAIN FOR TESTING 

int main() {

    QueueArray<int, 5> q;

    // =========================
    // TEST 1: EMPTY QUEUE
    // =========================
    std::cout << "===== TEST 1: EMPTY QUEUE =====" << std::endl;
    std::cout << "Expected empty: 1" << std::endl;
    std::cout << "Actual empty:   " << q.empty() << std::endl;
    std::cout << "Expected size: 0" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 2: ENQUEUE
    // =========================
    std::cout << "\n===== TEST 2: ENQUEUE =====" << std::endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Expected: 10 20 30" << std::endl;
    std::cout << "Actual:   ";
    q.print();

    std::cout << "Expected size: 3" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 3: FRONT
    // =========================
    std::cout << "\n===== TEST 3: FRONT =====" << std::endl;

    std::cout << "Expected front: 10" << std::endl;
    std::cout << "Actual front:   " << q.front() << std::endl;


    // =========================
    // TEST 4: DEQUEUE
    // =========================
    std::cout << "\n===== TEST 4: DEQUEUE =====" << std::endl;

    std::cout << "Expected dequeued: 10" << std::endl;
    std::cout << "Actual dequeued:   " << q.dequeue() << std::endl;

    std::cout << "Expected queue: 20 30" << std::endl;
    std::cout << "Actual queue:   ";
    q.print();

    std::cout << "Expected size: 2" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 5: FILL QUEUE
    // =========================
    std::cout << "\n===== TEST 5: FULL QUEUE =====" << std::endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    std::cout << "Expected: 20 30 40 50 60" << std::endl;
    std::cout << "Actual:   ";
    q.print();

    std::cout << "Expected full: 1" << std::endl;
    std::cout << "Actual full:   " << q.full() << std::endl;

    std::cout << "Expected size: 5" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 6: WRAP AROUND
    // =========================
    std::cout << "\n===== TEST 6: WRAP AROUND =====" << std::endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(70);
    q.enqueue(80);

    std::cout << "Expected: 40 50 60 70 80" << std::endl;
    std::cout << "Actual:   ";
    q.print();

    std::cout << "Expected front: 40" << std::endl;
    std::cout << "Actual front:   " << q.front() << std::endl;

    std::cout << "Expected size: 5" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 7: CLEAR
    // =========================
    std::cout << "\n===== TEST 7: CLEAR =====" << std::endl;

    q.clear();

    std::cout << "Expected empty: 1" << std::endl;
    std::cout << "Actual empty:   " << q.empty() << std::endl;

    std::cout << "Expected size: 0" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 8: REUSE AFTER CLEAR
    // =========================
    std::cout << "\n===== TEST 8: REUSE AFTER CLEAR =====" << std::endl;

    q.enqueue(100);
    q.enqueue(200);

    std::cout << "Expected: 100 200" << std::endl;
    std::cout << "Actual:   ";
    q.print();

    std::cout << "Expected front: 100" << std::endl;
    std::cout << "Actual front:   " << q.front() << std::endl;

    std::cout << "Expected size: 2" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    // =========================
    // TEST 9: DEQUEUE TO EMPTY
    // =========================
    std::cout << "\n===== TEST 9: DEQUEUE TO EMPTY =====" << std::endl;

    q.dequeue();
    q.dequeue();

    std::cout << "Expected empty: 1" << std::endl;
    std::cout << "Actual empty:   " << q.empty() << std::endl;

    std::cout << "Expected size: 0" << std::endl;
    std::cout << "Actual size:   " << q.size2() << std::endl;


    std::cout << "\n===== ALL TESTS FINISHED =====" << std::endl;

    return 0;
}