#include<iostream>
#include<string.h>

int main(){
    std::string word1, word2;
    std::cin >> word1 >> word2;
    if(word1 == word2){
        if(word1 > word2){
            std::cout << word1 << std::endl;
        }
        else{
            std::cout << word2 << std::endl;
        }
    }
    if(word1 != word2){
        if(word1 > word2){
            std::cout << word1 << std::endl;
        }
        else{
            std::cout << word2 << std::endl;
        }
    }
    return 0;
}