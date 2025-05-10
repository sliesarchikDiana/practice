#include <iostream>
#include <thread>
//example of data race - condition when different threads try to change the same memory region//
//solution - synchronization of threads//
void print(std::string str) {
for (int i = 0; i < 5; ++i) {
std::cout << str[0] << str[1] << str[2] << std::endl;
}
}
int main() {
    std::thread thr1(print, "abc");
    std::thread thr2(print, "def");
    std::thread thr3(print, "zxc");
    thr1.join();
    thr2.join();
    thr3.join();
}
