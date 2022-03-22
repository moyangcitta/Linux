#include<iostream>
#include"Sales_item.h"

void test1();
void test2();//读取多个具有相同ISBN的销售记录，输出所有记录的和
int test3();//检查两个对象是否具有相同的ISBN

int main(){
    //test1();
    //test2();
    //test3();
    //return test3();//测试test3
    return 0;
}

void test1(){
    Sales_item item;
    while(std::cin >> item){
        std::cout << item << std::endl;
    }
}

void test2(){
    Sales_item item, temp;
    std::cin >> item;
    temp = item;
    while(std::cin >> item){
        temp += item;
    }
    std::cout << temp << std::endl;
}

int test3(){
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    //检查ISBN是否相同
    if(item1.isbn() == item2.isbn()){
        std::cout << item1 + item2 << std::endl;
        return 0;
    }
    else{
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;//没有直接退出程序？
    }
}
