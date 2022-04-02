#include<iostream>
#include<vector>

int main(){
    int num;
    std::vector<int>nums;
    while(std::cin >> num){
        nums.push_back(num);
    }
    int len = nums.size();
    std::vector<int>::iterator it = nums.begin();
    int record = 0;
    int sum = 0;
    for(; it != nums.end(); it++){
        sum += *it;
        record++;
        if(record == 2){
            std::cout << sum << std::endl;
            sum = 0;
            record = 0;
        }
    }
    std::cout << *it << std::endl;
    return 0;
}