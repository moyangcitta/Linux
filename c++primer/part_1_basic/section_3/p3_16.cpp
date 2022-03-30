#include<iostream>
#include<string.h>
#include<vector>
int main(){
    std::vector<int>v1;
    //std::cout << v1[0] << std::cout;//初始状态为空
    std::vector<int>v2(10);
    std::cout << v2[9] << std::endl;
    std::vector<int>v3(10,42);
    std::cout << v3[9] << std::endl;
    std::vector<int>v4{10};
    std::cout << v4[0] << std::endl;
    std::vector<int>v5{10,42};
    std::cout << v5[1] << std::endl;
    std::vector<std::string>v6{10};
    std::cout << v6[0] << std::endl;
    std::vector<std::string>v7(10,"hi");
    std::cout << v7[9] << std::endl;
    return 0;
}