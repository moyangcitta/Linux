#include<iostream>
#include<vector>
#include<cstring>

int main(){
    const std::vector<std::string> scores = {"F","D","C","B","A","A++"};
    int score = 0;
    while(std::cin >> score){
        if(score == 100){
            std::cout << "A++";
            continue;
        }
        else if(score >= 90){
            std::cout << "A";
        }
        else if(score >= 80){
            std::cout << "B";
        }
        else if(score >= 70){
            std::cout << "C";
        }
        else if(score >= 60){
            std::cout << "D";
        }
        else{
            std::cout << "F";
            continue;
        }
        if(score % 10 > 7){
            std::cout << "+" << std::endl;
        }
        else if(score % 10 < 3){
            std::cout << "-" << std::endl;
        }
        else{
            std::cout << std::endl;
        }
    }
    return 0;
}