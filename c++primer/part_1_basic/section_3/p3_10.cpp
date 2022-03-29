#include<iostream>
#include<string.h>

int main(){
    std::string words("some,string!!!");
    std::string none("");
    if(!words.empty()){
        for(auto &c : words){
            if(ispunct(c)){
                c = ' ';
            }
        }
    }
    std::cout << words << std::endl;
    return 0;
}