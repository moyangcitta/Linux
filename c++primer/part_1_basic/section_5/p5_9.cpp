#include<iostream>

int main(){
    std::string word;
    int sum = 0;
    while(std::cin >> word){
        for(int i = 0; i < word.length(); i++){
            switch(word[i]){
                case 'a': case 'e': case 'i': case 'o': case 'u':
                    sum++;
                    break;
                default:
                    break; 
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}