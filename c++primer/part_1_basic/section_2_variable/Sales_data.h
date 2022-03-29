#ifndef  SALES_DATA_H
#define SALES_DATA_H
#include<string>

struct Sales_data{
    std::string book_ISBN;
    double sum_sales = 0.0;
    int num = 0;
    double single_sales = 0.0;
};

#endif