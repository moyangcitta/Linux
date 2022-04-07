#include<iostream>
//用递归方式改写fact函数
int fact(int num){
    if(num == 1){
        return 1;
    }
    return num * fact(num - 1);
}
int main(){
    int num;
    std::cin >> num;
    int j = fact(num);
    std::cout << "num! is " << j << std::endl;
    return 0;
}