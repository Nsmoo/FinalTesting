#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> A;

    try {
        A.pushFront(5);
        A.pushFront(10);
        A.pushBack(15);
        A.pushAfter(-5, 5);
        A.pushByInd(80, 2);

        std::cout << "List: ";
        A.print();

        int i = A.find(-5);
        if (i != -1) {
            std::cout << "-5 found at index " << i << "\n";
        }
        else {
            std::cout << "There is no such element" << "\n";
        }

        A.del(5);
        A.delByInd(2);

        std::cout << "List after deleting: ";
        A.print();

        A.delFront();
        A.delBack();

        std::cout << "List after removing first and last elements: ";
        A.print();

        std::cout << "Element at index 1: " << A.getByIndex(1) << "\n";

        A.pushByInd(30, 10);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
