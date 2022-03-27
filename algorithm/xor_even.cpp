#include<iostream>
#include<vector>

int main(){
    //数字个数
    int num = 0;
    std::cin >> num;
    //数组
    int arr[num];
    for(int i = 0; i < num; i++){
        std::cin >> arr[i];
    }
    int ans = 0;
    //选出两个数的异或值
    for(int i = 0; i < num; i++){
        ans ^= arr[i];
    }
    //取出最右侧的1
    int loc = ans & (~ans + 1);
    int first = 0;
    //找第一个数
    for(int i = 0; i < num; i++){
        if((arr[i] & loc) != 0){
            first ^= arr[i];
        }
    }
    int second = ans ^ first;
    //调整顺序
    if(first > second){
        std::cout << second << " " << first;
    }
    else{
        std::cout << first << " " << second;
    }

    return 0;
}