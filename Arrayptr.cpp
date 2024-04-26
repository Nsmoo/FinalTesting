#include <iostream>

int main() {
    int A[7] = {-5, 6, 12, -80, 5, 11, 0};
    int *ptr = A;
    int e;
    std::cout << "Enter element: ";
    std::cin >> e;

    ptr += e - 1;

    std::cout << *ptr << std::endl;
    return 0;
}