#include <iostream>
#include <thread>
//threads with lambda functions//
int main() {
    int thr1Int{2}, thr2Int{3}, thr3Int{4};
    std::thread thr1([&thr1Int](){thr1Int*=thr1Int;});
    std::thread thr2([&thr2Int](){thr2Int*=thr2Int;});
    std::thread thr3([&thr3Int](){thr3Int*=thr3Int;});
//demonstrations of unique thread IDs//
    std::cout<<"thread 1 ID is: "<<thr1.get_id()<<std::endl;
    std::cout<<"thread 2 ID is: "<<thr2.get_id()<<std::endl;
    std::cout<<"thread 3 ID is: "<<thr3.get_id()<<std::endl;
    thr1.join();
    thr2.join();
    thr3.join();

    std::cout<<thr1Int<<" "<<thr2Int<<" "<<thr3Int<<std::endl;




    return 0;
}