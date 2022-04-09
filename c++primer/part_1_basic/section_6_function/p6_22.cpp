#include<iostream>
void merge(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 0, b = 1;
    merge(&a, &b);
    std::cout << a << " " << b << std::endl;
    return 0;
}