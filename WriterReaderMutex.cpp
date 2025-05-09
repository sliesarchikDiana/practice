#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
//Condition variables та Predicate//
std::mutex mut;
std::string sharedData;
std::condition_variable conditionVariable;
bool condition = false;
void reader() {
    std::unique_lock<std::mutex> uniqueLock(mut);
    std::cout << "reader():: - mutex was locked" << std::endl;
    conditionVariable.wait(uniqueLock, [] {return condition;});
    std::cout << "reader is back on " << std::endl;
    std::cout << "Data is " << sharedData << std::endl;
}
void writer() {
    {
        std::lock_guard<std::mutex> lockGuard(mut);
        std::cout << "Writer has locked the mutex" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Writer modifies data" << std::endl;
        sharedData = "Modified data blah-blah-blah";
        condition = true;
    }
    conditionVariable.notify_one();
}

int main() {
    std::cout << sharedData << std::endl;
    std::thread thr1(reader);
    std::thread thr2(writer);
    thr1.join();
    thr2.join();
    std::cout << sharedData << std::endl;
}