#include<iostream>

void print(const int ia[],size_t size){
    for(size_t i = 0; i != size; ++i){
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;
}
void print1(const int a[10]){
    for(size_t i = 0; i!= 10; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
int &get(int *arry, int index){
    return arry[index];
}
void manip(int a, int b){
    std::cout << a << " " << b << std::endl;
}
int main(){
    int a[10];
    for(int i = 0; i != 10; ++i){
        get(a, i) = i;
    }
    double dobj;
    manip(55.4, dobj);
    //int a[10] = {0,1,2,3,4,5,6,7,8,9};
    //print(a,10);
    //print1(a);
    //int ia[3][4] = {0};
    //for(int (*p)[4] = ia;p != ia + 3; ++p){
    //    for(auto q = *p; q != *p + 4; ++q){
    //        std::cout << *q << " ";
    //    }
    //    std::cout << std::endl;
    //}
    return 0;
}