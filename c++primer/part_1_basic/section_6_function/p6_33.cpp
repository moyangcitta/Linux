#include<iostream>
#include<vector>

void draw(std::vector<int>&arr, int len){
    if(len < 0){
        return;
    }
    std::cout << arr[len] << std::endl;
    --len;
    draw(arr, len);
    return ;
}
int main(){
    std::vector<int>arr{0,1,2,3,4,5,6,7,8,9};
    draw(arr,arr.size());
    return 0;
}