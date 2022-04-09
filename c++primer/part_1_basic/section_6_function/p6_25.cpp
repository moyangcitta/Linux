#include<iostream>
#include<cstring>
int main(int argc, char *argv[]){
    std::string c = "";
    for(int i = 1; i < argc; i++){
        c += argv[i];
    }
    std::cout << c << std::endl;
}