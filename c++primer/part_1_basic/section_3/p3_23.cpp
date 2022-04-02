#include<iostream>
#include<vector>
//创建一个含有10个整数的vector对象，然后使用迭代器把所有元素的值变成原来的两倍
int main(){
    std::vector<int>nums(10,1);
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
        *it *= 2;
    }
    for(auto c : nums){
        std::cout << c << std::endl;
    }
    return 0;
}