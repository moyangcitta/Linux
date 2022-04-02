#include<iostream>
#include<vector>
//逆序对问题，在一个数组中，左边的数如果比右边的数达，则这两个数构成一个
//逆序对，请打印逆序对数量
//打印逆序对
void print(int *nums, int left, int right){
    int middle = left + ((right - left) >> 1);
    int l = left;
    while(l <= middle){
        int r = middle + 1;
        while(r <= right){
            if(nums[l] < nums[r]){
                std::cout << nums[l] << ":" << nums[r] << std::endl;
            }
            r++;
        }
        l++;
    }
}
//分离函数
void split(int *nums, int left ,int right){
    if(left == right){
        return;
    }
    int middle = left + ((right - left) >> 1);
    split(nums,left,middle);
    split(nums,middle + 1,right);
    //打印函数
    print(nums,left,right);
}
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
    //分离函数
    int left = 0, right = len - 1;
    split(nums,left,right);
    return 0;
}