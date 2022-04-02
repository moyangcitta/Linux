#include<iostream>

int main(){
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    for(int (&i)[4] : ia){
        for(int &j : i){
            std::cout << j << " ";
        }
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            std::cout << ia[i][j] << " ";
        }
    }
    std::cout << std::endl;
    for(int (*p)[4] = ia; p != ia + 3; p++){
        for(int *q = std::begin(*p); q != std::end(*p); q++){
            std::cout << *q << " ";
        }
    }
    std::cout << std::endl;
    using int_array = int[4];
    typedef int int_array[4];
    for(int_array *q = ia; q != ia + 3; q++){
        for(int *p = *q; p != *q + 4; ++p){
            std::cout << *p << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}