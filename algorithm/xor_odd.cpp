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
    int ans = 0;
    for(int i = 0; i < num; i++){
        ans ^= arr[i];
    }
    std::cout << ans;
}