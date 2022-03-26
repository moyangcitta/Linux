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
    //二分法，不需要遍历，只需要logN次就可以得到结果
    int left = 0, right = num - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        //因为不止一个数且需要找到下标最小的数，因此当找到一个数的时候需要往它的左边寻找下标较小的值
        //直到最后左值针和右指针相同时即为答案
        if(arr[middle] == find){
            right = middle;
        }
        else if(arr[middle] < find){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
        if(left == right && arr[left] == find){
            std::cout << left;
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}