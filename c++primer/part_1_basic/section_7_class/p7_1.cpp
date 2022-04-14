#include<iostream>

struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(){
    Sales_data sum;
    double money;
    unsigned num;
    if(std::cin >> sum.bookNo){
        std::cin >> sum.units_sold >> sum.revenue;
        Sales_data data;
        while(std::cin >> data.bookNo){
            std::cin >> data.units_sold >> data.revenue;
            if(sum.bookNo == data.bookNo){
                money = sum.units_sold * sum.revenue + data.units_sold * data.revenue;
                num = sum.units_sold + data.units_sold;
            }
            else{
                std::cout << sum.bookNo << " " << num
                    << " " << money << std::endl;
                sum.bookNo = data.bookNo;
                sum.revenue = data.revenue;
                money = 0;
                num = 0;
            }
        }
        std::cout << sum.bookNo << " " << num
            << " " << money << std::endl;
    }
    return 0;
}