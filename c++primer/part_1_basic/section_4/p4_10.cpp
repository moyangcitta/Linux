#include<iostream>
//为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止
int main(){
    int num = 0;
    while(std::cin >> num && (num != 42));
    std::cout << "over!!!" << std::endl;
    return 0;
}