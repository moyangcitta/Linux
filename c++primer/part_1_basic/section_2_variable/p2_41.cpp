#include<iostream>
#include<string.h>
#include"Sales_data.h"
//编写程序，读取多条销售记录，并统计每个ISBN有几条销售记录
int main(){
    Sales_data books;
    Sales_data sum;
    
    if(std::cin >> sum.book_ISBN){
        std::cin >> sum.num;
        std::cin >> sum.single_sales;
        sum.sum_sales = sum.num * sum.single_sales;
        while(std::cin >> books.book_ISBN){
            if(sum.book_ISBN == books.book_ISBN){
                std::cin >> books.num;
                std::cin >> books.single_sales;
                sum.sum_sales += books.num * books.single_sales;
                sum.num += books.num;
            }
            else{
                std::cout << sum.book_ISBN << " " << sum.num <<
                    " " << sum.sum_sales << std::endl;
                std::cin >> books.num;
                std::cin >> books.single_sales;
                sum.book_ISBN = books.book_ISBN;
                sum.num = books.num;
                sum.sum_sales = books.single_sales * books.num;
            }
        }
        std::cout << sum.book_ISBN << " " << sum.num <<
            " " << sum.sum_sales << std::endl;
    }
    return 0;
}