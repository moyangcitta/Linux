#include<iostream>
#include<vector>
//将数组中每个数之前小于该数的和累加起来并输出
//套在求和之中的一个排序问题
void rec(int *nums, int left, int right, std::vector<int>&record);
//分离函数
void split(int *nums, int left, int right, std::vector<int>&record){
    if(left == right){
        return;
    }
    int middle = left + ((right - left) >> 1);
    split(nums,left,middle,record);
    split(nums,middle + 1,right,record);
    rec(nums,left,right,record);
}
//记录函数
void rec(int *nums, int left, int right, std::vector<int>&record){
    int middle = left + ((right - left) >> 1);
    int l = left;
    while(l <= middle){
        int r = middle + 1;
        while(r <= right){
            if(nums[l] < nums[r]){
                record[l] += 1;
            }
            r++;
        }
        l++;
    }
}
//主函数
int main(){
    int len = 0;
    std::cout << "please input array's length: ";
    std::cin >> len;
    int num = 0;
    int nums[len];
    std::cout << "please input array: ";
    for(int i = 0; i < len; i++){
        std::cin >> nums[i];
    }
    //用于记录大于该数的个数
    std::vector<int>record(len,0);
    int left = 0, right = len - 1;
    split(nums,left,right,record);
    //输出累加和
    int sum = 0;
    for(int i = 0; i < len; i++){
        sum += record[i] * nums[i];
    }
    std::cout << sum << std::endl;
    return 0;
}