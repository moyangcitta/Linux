#include<iostream>
#include<vector>

int main(){
    int nums1[5] = {0,1,2,3,4};
    int nums2[5] = {0,1,2,3,3};
    int nums3[5] = {0,1,2,3,4};
    for(int i = 0; i < 5; i++){
        if(nums1[i] != nums3[i]){
            std::cout << "error" << std::endl;
            return 0;
        }
    }
    std::cout << "right" << std::endl;
    std::vector<int>a(10,0);
    std::vector<int>b(11,0);
    if(a == b){
        std::cout << "error" << std::endl;
    }
    else{
        std::cout << "right" << std::endl;
    }

    return 0;
}