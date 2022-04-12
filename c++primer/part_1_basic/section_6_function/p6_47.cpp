#include<iostream>
#include<vector>
void abc(std::vector<int>&arr, int n){
    if(n == arr.size()){
        return;
    }
    abc(arr,n + 1);
    #ifndef NDEBUG
        std::cerr << __func__ << "size is " << sizeof(arr) << std::endl;
    #endif
    std::cout << arr[n] << std::endl;
    
    return;
}
int main(){
    std::vector<int>arr{0,1,2,3,4,5,6,7,8,9};
    int i = 0;
    abc(arr,i);

    return 0;
}