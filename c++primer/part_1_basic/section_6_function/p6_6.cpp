#include<iostream>
int func(int num){
    int a = ++num;
    static int b = a;
    return b;
}

int main(){
    int i = 123;
    std::cout << func(i) << std::endl;
    return 0;
}