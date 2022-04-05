#include<iostream>
#include<cstring>
#include<vector>

int main(){
    std::string word;
    std::string follow;
    int max = 0;
    std::string words;
    if(std::cin >> word){
        int record = 1;
        while(std::cin >> follow){
            if(word == follow){
                ++record;
                if(record > max){
                    max = record;
                    words = word;
                }
            }
            else{
                record = 1;
                word = follow;
            }
        }
    }
    std::cout << max << " " << words << std::endl;
    return 0;
}