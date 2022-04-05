#include<iostream>
#include<vector>

int main(){
    std::vector<int>arr1{0,1,1,2};
    std::vector<int>arr2{0,1,1,2,3,5,8};
    int i = 0;
    for(; (i < arr1.size()) && (i < arr2.size()); ++i){
        if(arr1[i] != arr2[i]){
            break;
        }
    }
    std::cout << i << std::endl;
    if((i == (arr1.size())) || (i == (arr2.size()))){
        std::cout << "true" << std::endl;
    }
    else{
        std::cout << "false" << std::endl;
    }
    return 0;
}