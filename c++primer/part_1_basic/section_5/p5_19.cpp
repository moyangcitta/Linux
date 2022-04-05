#include<iostream>
#include<cstring>

int main(){
    std::string word1;
    std::string word2;
    do{
        std::cin >> word1 >> word2;
        if(word1.size() > word2.size()){
            std::cout << word2 << std::endl;
        }
        else{
            std::cout << word1 << std::endl;
        }
    }while(1);
    return 0;
}