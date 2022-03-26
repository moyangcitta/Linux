#include<iostream>

int main(){
    //数字个数
    int num = 0;
    std::cin >> num;
    //数组
    int arr[num];
    for(int i = 0; i < num; i++){
        std::cin >> arr[i];
    }
    //从三个方面入手，首先是起始位置
    if(arr[0] < arr[1]){
        std::cout << 0;
        return 0;
    }
    //其次是末尾位置
    if(arr[num - 1] < arr[num - 2]){
        std::cout << num - 1;
        return 0;
    }
    //最后从数组中间寻找，因为第一个是下降趋势，末尾是上升趋势，那么中间一定有局部最小值
    int left = 0, right = num - 1;
    while(left <= right){
        //取中间值
        int middle = left + (right - left) / 2;
        //中间值小于两边的值
        if(arr[middle] < arr[middle - 1] && arr[middle] < arr[middle + 1]){
            std::cout << middle;
            return 0;
        }
        //中间值大于左边的值，向左半部分寻找
        else if(arr[middle] > arr[middle - 1]){
            right = middle - 1;
        }
        //中间值大于右边的值，向右半部分寻找
        else if(arr[middle] > arr[middle + 1]){
            left = middle + 1;
        }
    }
    std::cout << -1;

    return 0;
}