#include<iostream>
#include<cstddef>
#include<vector>
//编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值
int main(){
    unsigned scores[11];
    unsigned grade;
    while(std::cin >> grade){
        if(grade <= 100){
            ++scores[grade/10];
        }
    }
    for(auto i : scores){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}