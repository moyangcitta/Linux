#include<iostream>
#include<string.h>

int main(){
    std::string words("some string");
    for(char &c : words){
        if(isalpha(c)){
            c = 'X';
        }
    }
    std::cout << words << std::endl;

    return 0;
}