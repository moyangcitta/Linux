#include<iostream>
#include<string>

struct Student{
    std::string name;
    int score;
};

void output(Student *stu, int len){
    for(int i = 0; i < len; i++){
        std::cout << stu[i].name << " " << stu[i].score << std::endl;
    }
    return;
}

void insert_sort(int len, int opt){
    Student stu[len];
    for(int i = 0; i < len; i++){
        std::cin >> stu[i].name;
        std::cin >> stu[i].score;
    }
    //插入排序,默认升序
    for(int i = 1; i < len; i++){
        for(int j = i; j > 0; j--){
            if(opt){
                if(stu[j].score < stu[j - 1].score){
                    Student temp = stu[j];
                    stu[j] = stu[j - 1];
                    stu[j - 1] = temp;
                }
            }
            //降序
            else{
                if(stu[j].score > stu[j - 1].score){
                    Student temp = stu[j];
                    stu[j] = stu[j - 1];
                    stu[j - 1] = temp;
                }
            }
        }
    }
    //输出
    output(stu,len);
    return;
}

int main(){
    int num1 = 0, num2 = 0;
    while(std::cin >> num1){
        std::cin >> num2;
        insert_sort(num1,num2);
    }
    return 0;
}