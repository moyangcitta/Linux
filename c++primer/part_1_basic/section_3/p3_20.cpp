#include<iostream>
#include<vector>
void test1(std::vector<int> *nums, int len);
int main(){
    int num;
    std::vector<int>nums;
    while(std::cin >> num){
        nums.push_back(num);
    }
    int len = nums.size();
    test1(nums,len);
    return 0;
}
void test1(std::vector<int> &nums, int len){
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += nums[i];
        if((i % 2) == 0){
            std::cout << sum << std::endl;
            sum = 0;
        }
    }
}