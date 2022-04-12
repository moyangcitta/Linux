#include<iostream>
#include<vector>

int abc(int a, int b){

}
int (*pf)(int a, int b);//未初始化
int main(){
    using PF = int(*)(int, int);
    std::vector<PF>arr;
    for(int i = 0; i < 10; i++){
        pf = abc;
        arr.push_back(pf);
    }
    return 0;
}