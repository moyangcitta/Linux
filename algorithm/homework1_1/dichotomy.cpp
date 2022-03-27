#include<iostream>

int main(){
    int num;
    std::cin >> num;
    int find;
    std::cin >> find;
    int arr[num];
    for(int i = 0; i < num; i++){
        std::cin >> arr[i];
    }
    if((num == 0) || (find > arr[num])){
        std::cout << num + 1;
        return 0;
    }
    int left = 0, right = num - 1;
    while(left <= right){
        int middle = left + ((right - left) >> 1);
        if(arr[middle] >= find){
            right = middle;
        }
        else if(arr[middle] < find){
            left = middle + 1;
        }
        if((left == right) && (arr[middle] >= find)){
            std::cout << middle + 1;
            return 0;
        }
    }
    return 0;
}