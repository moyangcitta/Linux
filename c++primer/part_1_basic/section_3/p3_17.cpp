#include<iostream>
#include<string.h>
#include<vector>
//读入一组词并存入一个数组中，然后将所有词都改为大写形式
int main(){
    std::vector<std::string>words;
    std::string word;
    while(std::cin >> word){
        words.push_back(word);
    }
    int len = words.size();
    for(auto &i : words){
        for(auto &j : i){
            j = toupper(j);
        }
        std::cout << i << std::endl;
    }
    return 0;
}