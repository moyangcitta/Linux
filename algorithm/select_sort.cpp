#include<iostream>
#include<vector>
using std::vector;

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
    //选择排序
    for(int i = 0; i < n; i++){
        for(int j = (i + 1); j < n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    //输出结果
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}