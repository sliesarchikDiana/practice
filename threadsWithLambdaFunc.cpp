#include <iostream>
#include <thread>

int main() {
    int thr1Int{2}, thr2Int{3}, thr3Int{4};
    std::thread thr1([&thr1Int](){thr1Int*=thr1Int;});
    std::thread thr2([&thr2Int](){thr2Int*=thr2Int;});
    std::thread thr3([&thr3Int](){thr3Int*=thr3Int;});
    thr1.join();
    thr2.join();
    thr3.join();

    std::cout<<thr1Int<<" "<<thr2Int<<" "<<thr3Int<<std::endl;

    return 0;
}