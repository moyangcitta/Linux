#include<iostream>
#include<exception>
#include<stdexcept>

int main(){
    int num1 = 0, num2 = 0;
    while(std::cin >> num1 >> num2){
        try{
            if(num2 == 0){
                throw std::runtime_error("num2 is 0");
            }
            std::cout << num1 / num2 << std::endl;
            return 0;
        }
        catch(std::runtime_error err){
            std::cout << err.what()
                << "\ntry again ? y or n ?" << std::endl;
            char c;
            std::cin >> c;
            if(!std::cin || c == 'n'){
                break;
            }
        }
    }
    return 0;
}