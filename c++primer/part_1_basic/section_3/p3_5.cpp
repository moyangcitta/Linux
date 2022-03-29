#include<iostream>
#include<string.h>
//编写一段程序从标准输入中读入多个字符串并将他们连接在一起，并用空格分隔
void test1();

int main(){
    test1();
    return 0;
}

void test1(){
    std::string word;
    std::string sentence;
    std::string space(" ");
    while(std::cin >> word){
        sentence += word + space;
    }
    std::cout << sentence << std::endl;
}