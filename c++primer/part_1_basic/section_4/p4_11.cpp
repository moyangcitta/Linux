#include<iostream>
//测试a、b、c、d的关系
int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if(a > b && b > c && c > d){
        std::cout << "right" << std::endl;
    }
    else{
        std::cout << "error" << std::endl;
    }
    return 0;
}