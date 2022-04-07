#include<iostream>
//用递归方式改写fact函数
int fact(int num){
    if(num == 1){
        return 1;
    }
    return num * fact(num - 1);
}
int main(){
    int j = fact(5);
    std::cout << "5! is " << j << std::endl;
    return 0;
}