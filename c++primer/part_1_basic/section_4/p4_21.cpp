#include<iostream>
#include<vector>
//使用条件运算符找到哪些元素的值是奇数，然后将其翻倍
int main(){
    int num = 0;
    std::vector<int>nums;
    while(std::cin >> num){
        num = (num % 2 == 0 ? num * 2 : num);
        nums.push_back(num);
    }
    int len = nums.size();
    for(int i = 0; i < len; i++){
        std::cout << nums[i] << std::endl;
    }
    return 0;
}