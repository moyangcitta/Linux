#include<iostream>
#include<cstring>

int main(){
    std::string c;
    std::string word;
    if(std::cin >> word){
        while(std::cin >> c){
            if(isupper(c[0])){
                if(c == word){
                    std::cout << word << std::endl;
                    return 0;
                }
                else{
                    word = c;
                }
            }
        }
    }    
    std::cout << "no" << std::endl;
    return 0;
}