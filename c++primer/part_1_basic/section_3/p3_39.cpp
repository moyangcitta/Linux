#include<iostream>
#include<cstring>
//比较两个string对象，同时比较两个c风格字符串
int main(){
    std::string a = "asdfjkl";
    std::string b = "asdfjkl;";
    if(a == b){
        std::cout << "right" << std::endl;
    }
    else{
        std::cout << "error" << std::endl;
    }
    char c[] = "asddfgdaslk";
    char d[] = "asdfkjl;kj";
    if(!strcmp(c,d)){
        std::cout << "right" << std::endl;
    }
    else{
        std::cout << "error" << std::endl;
    }
    return 0;
}