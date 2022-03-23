#include<iostream>
#include<vector>
using std::vector;
//冒泡排序
int main(){
    //读取第一个数n，表示有n个数字
    int n = 0;
    std::cin >> n;
    //输入n个数
    vector<int>arr;
    for(int i = 0; i < n; i++){
        int input;
        std::cin >> input;
        arr.push_back(input);
    }
    //排序
    for(int i = n; i > 0; i--){
        for(int j = 1; j < i; j++){
            if(arr[j - 1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    //输出
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}