#include<iostream>
#include<exception>
#include<stdexcept>

int main(){
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;
    if(num2 == 0){
        throw std::runtime_error("num2 is 0");
    }
    std::cout << num1 / num2 << std::endl;
    return 0;
}