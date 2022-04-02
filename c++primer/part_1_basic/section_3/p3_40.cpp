#include<iostream>
#include<cstring>

int main(){
    char a[] = "abc";
    char b[] = "def";
    char c[100];
    strcpy(c,a);
    strcat(c,b);
    std::cout << c << std::endl;

    return 0;
}