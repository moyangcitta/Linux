#include<iostream>
#include<vector>
#include<string.h>
//和3_14一样，不过读入字符串
int main(){
    std::string word;
    std::vector<std::string>words;
    while(std::cin >> word){
        words.push_back(word);
    }
    int len = words.size();
    for(int i = 0; i < len; i++){
        std::cout << words[i] << std::endl;
    }
    return 0;
}