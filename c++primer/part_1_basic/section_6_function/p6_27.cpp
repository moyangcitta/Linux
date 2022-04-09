#include<iostream>
#include<initializer_list>

void sum(std::initializer_list<int> arr){
    int sum = 0;
    for(auto it = arr.begin(); it != arr.end(); ++it){
        sum += *it;
    }
    std::cout << sum << std::endl;
}

int main(){
    std::initializer_list<int> arr{0,1,2,3,4,5,6,7,8,9};
    sum(arr);
    return 0;
}