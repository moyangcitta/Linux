#include<iostream>
#include"Sales_item.h"

int main(){
    Sales_item item;
    int item_Nu = 1;//计数器
    if(std::cin >> item){
        Sales_item temp;
        Sales_item sum = item;
        while(std::cin >> temp){
            if(item.isbn() == temp.isbn()){
                sum += temp;
                item_Nu++;
            }
            else{
                std::cout << sum << std::endl;
                item = temp;
                item_Nu = 1;
                sum = temp;
            }
        }
        if(item_Nu == 1){
        std::cout << sum << std::endl;
    }
    }
    else{
        std::cout << "no data?" << std::endl;
        return -1;
    }

    return 0;
}