/*
字符串暴力匹配
内容：1）数据域，字符串内容；2）字符串长度
功能：1）初始化字符串；2）暴力匹配
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct String{
    char* data;
    int len;
}String;
//初始化字符串
String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}
//字符串赋值
void stringAssign(String* s, char* data){
    //判断是否是野指针
    if(s->data){
        free(s->data);
    }
    int len = 0;
    char* temp = data;
    //记录data长度
    while(*temp){
        len++;
        temp++;
    }
    if(len == 0){
        s->data = NULL;
        s->len = 0;
    }
    else{
        s->len = len;
        temp = data;
        //设置字符串内部长度
        s->data = (char*)malloc(sizeof(char) * (len + 1));
        for(int i = 0; i < len; i++){
            s->data[i] = *temp;
            temp++;
        }
    }
}
//遍历字符串
void printString(String* s){
    for(int i = 0; i < s->len; i++){
        printf(i == 0 ? "%c " : "-> %c", s->data[i]);
    }
    printf("\n");
}
//暴力匹配
void forceMatch(String* master, String* sub){
    //首先找到是否匹配
    int i = 0;
    int j = 0;
    for(; i < master->len && j < sub->len;){
        if(master->data[i] == sub->data[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == sub->len){
        printf("success\n");
    }
    else{
        printf("fail\n");
    }
    //输出
}
int main(int argc, char* argv[]){
    String* s = initString();
    String* s1 = initString();
    stringAssign(s,argv[1]);
    stringAssign(s1,argv[2]);
    printString(s);
    printString(s1);
    forceMatch(s,s1);
    return 0;
}