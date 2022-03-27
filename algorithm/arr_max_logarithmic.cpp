#include<iostream>
#include<cstdlib>

//对数器
void logarithmic();

//递归函数
int arr_Max(int *arr, int left, int right){
    if(left == right){
        return arr[left];
    }
    //从中间开始，将数组一分为2
    int middle = left + ((right - left) >> 1);
    int max = arr_Max(arr,left,middle) > arr_Max(arr,middle + 1,right) ? arr_Max(arr,left,middle) : arr_Max(arr,middle + 1,right);
    return max;
}

int main(){
    //准备
    int num = 0;
    std::cin >> num;
    int arr[num];
    for(int i = 0; i < num; i++){
        std::cin >> arr[i];
    }
    int left = 0, right = num - 1;
    int max = arr_Max(arr,left,right);
    std::cout << max;
    
    return 0;
}

void logarithmic(){

}