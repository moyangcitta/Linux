#include<iostream>
#include<vector>

int sum(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int mul(int a, int b){
    return a * b;
}
int divide(int a, int b){
    return a / b;
}
int (*pf)(int a, int b);//未初始化
int main(){
    using PF = int(*)(int, int);
    std::vector<PF>arr;
    pf = sum;
    arr.push_back(pf);
    pf = sub;
    arr.push_back(pf);
    pf = mul;
    arr.push_back(pf);
    pf = divide;
    arr.push_back(pf);
    int a, b;
    std::cin >> a >> b;
    std::cout << (*arr[0])(a,b)
        << (*arr[1])(a,b)
        << (*arr[2])(a,b)
        << (*arr[3])(a,b) << std::endl;
    return 0;
}