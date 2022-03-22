#include<iostream>

int main(){
    int currVal = 0, val = 0;
    //读取第一个数
    if(std::cin >> currVal){
        //设置次数
        int cnt = 1;
        //输入变量
        while(std::cin >> val){
            //如果和前一个变量相同，次数加一
            if(val == currVal){
                ++cnt;
            }
            //如果不同，输出变量及其次数，同时开始计算下一变量次数
            else{
                std::cout << currVal << " occurs "
                    << cnt << " times" << std::endl;
                    currVal = val;
                    cnt = 1;
            }
        }
        //循环结束，输出最后一个变量及其次数
        std::cout << currVal << " occurs "
            << cnt << " times" << std::endl;
        
    }

    return 0;
}