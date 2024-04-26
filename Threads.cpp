#include <iostream>
#include <thread>
#include<chrono>
#include <mutex>

std::mutex mtx;
int A = 0;

void write() {
    for (int i = 0; i < 10; i++) {
        mtx.lock();
        A = i;
        std::cout << "write: " << i << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void read() {
    for (int i = 0; i < 10; i++) {
        mtx.lock();
        std::cout << "read: " << A << std::endl;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main() {
    std::thread thread1(write);
    std::thread thread2(read);
    thread1.join();
    thread2.join();
    return 0;
}