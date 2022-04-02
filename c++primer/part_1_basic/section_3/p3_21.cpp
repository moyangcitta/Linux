#include<iostream>
#include<vector>

int main(){
    std::vector<int>v1;
    std::vector<int>::iterator i = v1.begin();
    //std::cout << v1.begin() << std::endl;
    std::vector<int> v2(10);
    std::vector<int>::iterator j = v2.begin();
    for(; j != v2.end(); j++){
        std::cout << *j << std::endl;
    }
    return 0;
}