#include<iostream>
void func1(const std::string &word){
    int len = word.length();
    for(int i = 0; i < len; i++){
        if(isupper(word[i])){
            std::cout << "right " << std::endl;
            return;
        }
    }
}
void func2(std::string &word){
    int len = word.length();
    for(int i = 0; i < len; i++){
        if(isupper(word[i])){
            word[i] = tolower(word[i]);
        }
    }
}
int main(){
    std::string word;
    std::cin >> word;
    func2(word);
    std::cout << word << std::endl;
    return 0;
}