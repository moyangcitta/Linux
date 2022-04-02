#include<iostream>
#include<vector>

int main(){
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> b(std::begin(a),std::end(a));
    for(int i = 0; i < b.size(); i++){
        std::cout << b[i] << std::endl;
    }
    return 0;
}