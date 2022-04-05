#include<iostream>

int main(){
    int sum = 0, val = 1;
    while(sum += val, ++val, val <= 10);
    std::cout << sum << std::endl;
    return 0;
}