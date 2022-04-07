#include<iostream>
void func(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
int main(){
    int a = 1, b = 2;
    func(&a ,&b);
    std::cout << a << " " << b << std::endl;
    return 0;
}