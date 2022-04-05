#include<iostream>

void test1(){  
    int grade = 0;
    std::cin >> grade;
    std::string finalgrade = (grade > 90) ? "high pass"
        : (grade > 75) ? "pass" : (grade > 60) ? "low pass" : "fail";
}
void test2(){
    int grade = 0;
    std::cin >> grade;
    if(grade > 90){
        std::cout << "high pass";
    }
    else if(grade > 75){
        std::cout << "pass";
    }
    else if(grade > 60){
        std::cout << "low pass";
    }
    else{
        std::cout << "fail";
    }
}
int main(){
    return 0;
}