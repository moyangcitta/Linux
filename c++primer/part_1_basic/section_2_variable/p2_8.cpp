#include<iostream>

int i = 42;

int main(){
    std::cout << "2\115\12" << std::endl;

    std::cout << "2\t\115" << std::endl;

    int i = 100;
    int j = i;
    std::cout << j << std::endl;

    int i = 100, sum = 0;
    for(int i = 0; i != 10; ++i){
        sum += i;
    }
    std::cout << i << " " << sum << std::endl;

    return 0;
}