#include<iostream>
void compare(int *arr, int left, int right);
//递归函数，将数组中的每个数拆分，并逐一进行比较
void split(int *arr, int left, int right){
    if(left == right){
        return;
    }
    int middle = left + ((right - left) >> 1);
    split(arr,left,middle);
    split(arr,middle + 1,right);
    compare(arr,left,right);
    return;
}
//比较函数
void compare(int *arr, int left, int right){
    int middle = left + ((right - left) >> 1);
    //数组的长度等于数的数量
    int helper[right + 1];
    //helper起始位置
    int k = left, l = left, r = middle + 1;
    while((l <= middle) && (r <= right)){
        helper[k++] = arr[l] <= arr[r] ? arr[l++] : arr[r++];
    }
    while(l <= middle){
        helper[k++] = arr[l++];
    }
    while(r <= right){
        helper[k++] = arr[r++];
    }
    //将helper数组中的数输入到arr中
    for(int i = left; i <= right; i++){
        arr[i] = helper[i];
    }
    return;
}
//归并排序
int main(){
    int len = 0;
    std::cin >> len;
    int arr[len];
    for(int i = 0; i < len; i++){
        std::cin >> arr[i];
    }
    int left = 0, right = len - 1;
    
    split(arr,left,right);
    for(int i = 0; i < len; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}