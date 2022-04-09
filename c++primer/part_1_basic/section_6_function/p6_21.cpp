#include<iostream>

int compare(int a, int *b){
    return (a > *b ? a : *b);
}
int main(){
    int x =10;
    int *c = &x;
    std::cout << compare(x,c) << std::endl;
    return 0;
}