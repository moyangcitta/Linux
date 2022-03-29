#include<iostream>
#include<string.h>
void p();
void test();
void test1();
void test2();
void test3();
void test4();
int main(){
    p();
    //test();
    //test1();
    //test2();
    //test3();
    //test4();
    return 0;
}
void test4(){
    const std::string hexdigits = "0123456789ABCDEF";//可能的16进制数
    std::cout << "Enter a series of numbers between 0 and 15"
        << " sepatated by spaces. Hit ENTER when finished: "
        <<std::endl;
    std::string result;         //用于保存十六进制的字符串
    std::string::size_type n;   //用于保存从输入流读取的数
    while(std::cin >> n){
        if(n < hexdigits.size()){   //忽略无效输入
            result += hexdigits[n]; //得到对应的十六进制数
        }
    }
    std::cout << " Your hex number is: " << result << std::endl;
}
void test3(){
    std::string s("something string");
    if(!s.empty()){
        for(decltype(s.size()) index = 0; 
            index != s.size() && !isspace(s[index]); ++index){
                s[index] = toupper(s[index]);//将当前字符串改成大写形式
            }
    }
    std::cout << s << std::endl;
    
}
void test2(){
    std::string s("Hello World!!!");
    for(auto &c : s){
        c = toupper(c);
    }
    std::cout << s << std::endl;
}
void test1(){
    std::string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;//选择并返回操作数的数据类型
    for(auto c : s){
        if(ispunct(c)){//统计字符串中标点符号的数量
            ++punct_cnt;
        }
    }
    std::cout << punct_cnt << " punctuation characters in " << s << std::endl;
}
void test(){
    std::string str("some string");
    for(auto c : str){
        std::cout << c << std::endl;
    }
}
void p(){
    std::string s;
    std::cout << s[0] << std::endl;
}