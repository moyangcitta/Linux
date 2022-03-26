#include<iostream>

int main(){
    //数字个数
    int num = 0;
    std::cin >> num;
    //要寻找的数字
    int find = 0;
    std::cin >> find;
    //数组
    int arr[num];
    for(int i = 0; i < num; i++){
        std::cin >> arr[i];
    }
    //查找某个位置
    //有多个数，需要找到下标最小的一个
    int left = 0, right = num - 1;
    while(left <= right){
        int middle = left + (right - left) / 2;
        //如果找到大于这个数的，继续向左边找
        if(arr[middle] >= find){
            right = middle;
        }
        //要找的数在中间值的右边，同时该中间值不是要寻找的值，因此排除该数
        else if(arr[middle] < find){
            left = middle + 1;
        }
        if(left == right && arr[left] >= find){
            std::cout << left;
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}