#include<iostream>
#include<vector>
//用cin读入一组整数并把它们存入一个vector对象
int main(){
    int num;
    std::vector<int>nums;
    while(std::cin >> num){
        nums.push_back(num);
    }
    int len = nums.size();
    for(int i = 0; i < len; i++){
        std::cout << nums[i] << std::endl;
    }
    return 0;
}