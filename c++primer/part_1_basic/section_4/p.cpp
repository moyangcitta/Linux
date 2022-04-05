#include<iostream>
#include<vector>
#include<cstring>

int main(){
    std::vector<int>ivec(10,1);
    std::vector<int>::size_type cnt = ivec.size();
    for(std::vector<int>::size_type ix = 0; ix != ivec.size();
        ix++, cnt--)
        ivec[ix] = cnt;
    int len = ivec.size();
    for(int i = 0; i < len; i++){
        std::cout << ivec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}