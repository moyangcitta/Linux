#include<iostream>
//编写一段程序，利用指针将数组中的元素置为0
int main(){
    int nums[10] = {0,1,2,3,4,5,6,7,8,9};
    int *point = nums;
    for(int i = 0; i < 10; i++){
        *(point + i) = 0;
    }
    for(auto &c : nums){
        std::cout << c << std::endl;
    }
    return 0;
}