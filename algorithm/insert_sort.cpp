#include<iostream>
#include<vector>

void swap(int *arr, int i, int j);

int main(){
    //输入一个num，代表数字个数
    int num = 0;
    std::cin >> num;

    //输入n个数
    int arr[num];
    for(int i = 0; i < num; i++){
        int temp;
        std::cin >> temp;
        arr[i] = temp;
    }

    //插入排序
    //如果前一个数大于当前数，则交换位置，直到该数大于前面的数或到数组开始位置
    for(int i = 1; i < num; i++){
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
            swap(arr, j, j - 1);
        }
    }

    //输出
    for(int i = 0; i < num; i++){
        std::cout << arr[i] << " ";
    }
}

//异或操作
void swap(int *arr, int i, int j){
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[j] ^ arr[i];
    arr[i] = arr[i] ^ arr[j];
}