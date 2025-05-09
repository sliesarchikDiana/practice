#include <iostream>
#include <thread>
//Lambda functions//
int main() {
    int testInt = 4;
    auto add = [&testInt](){
        testInt+=5;
        return testInt;
    };
    std::cout<<"Result after the first lambda function: "<<add()<<std::endl;

    auto multiply = [&testInt](){
        testInt*=testInt;
        return testInt;
    };
    std::cout<<"Result after the second lambda function: "<< multiply()<<std::endl;


    return 0;
}
