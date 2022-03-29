#include<iostream>
#include<string.h>
//编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词
//cin读取会忽略开头的空白，并从第一个真正的字符开始读起，直到遇见下一个空白
//getline从给定的输入流中读入内容，直到遇到换行符为止
int main(){
    std::string line;
    std::string word;
    while(std::cin >> word){
        std::cout << word << std::endl;
    }
    while(getline(std::cin,line)){
        std::cout << line << std::endl;
    }
    return 0;
}