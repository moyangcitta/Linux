#include<iostream>
//用递归方式改写fact函数
int fact(int num){
    if(num < 0){
        return -1 * num;
    }
    return num;
}
int main(){
    int num;
    std::cin >> num;
    int j = fact(num);
    std::cout << "abs(num) is " << j << std::endl;
    return 0;
}