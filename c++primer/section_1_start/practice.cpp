#include<iostream>

void test1();
void test2();
void test3();
void test4();

int main(){
    //test1();
    //test2();
    //test3();
    test4();
}

void test1(){
    std::cout << "hello, world" << std::endl;
}

void test2(){
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;
    std::cout << num1 * num2 << std::endl;
}

void test3(){
    std::cout << "please input two number: ";
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;
    while(num1 != num2){
        std::cout << num1 << std::endl;
        if(num1 > num2){
            num1--;
        }
        else{
            num1++;
        }
    }
}

void test4(){
    
}