#include<iostream>

void func(int &a, int &b){
    a *= 2;
    b *= 3;
}
int main(){
    int a = 3, b = 4;
    func(a,b);
    std::cout << a << " " << b << std::endl;
    return 0;
}