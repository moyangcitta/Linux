#include<iostream>

int func(){
    static int num = 0;
    return ++num;
}
int main(){
    for(int i = 0; i < 5; i++){
        std::cout << func() << std::endl;
    }
    return 0;
}