#include<iostream>
#include"chapter6.h"

int main(){
    int num;
    std::cin >> num;
    int j = fact(num);
    std::cout << "abs(num) is " << j << std::endl;
    return 0;
}