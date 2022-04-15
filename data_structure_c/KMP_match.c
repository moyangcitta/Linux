/*
KMP匹配算法
KMP算法是什么？对于暴力匹配到底有哪些改进？
答：暴力匹配在刚才匹配的过程中，主串指针回溯了2次，才达到匹配的状态
    KMP算法，主串指针没有回溯，并且快速达到了匹配状态
    KMP算法是一种高效的模式匹配算法，牺牲了一定的空间去保存next数组，提高了我们的匹配效率
    KMP算法还能更加智能地移动字符串，让字符串达到匹配状态
next数组
    是当字符与主串发生不匹配之后，值对应索引的字符要移动到跟主串不匹配的字符对应
算法
    公共前后缀
    next = 公共前后缀 + 1
公共前后缀
    为了能找到能够匹配的状态
核心
    减少主串指针的移动，并且能快速找到能够前后端匹配的状态，从而加快匹配的进程

1.初始化串
2.求next数组
3.KMP匹配
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct String{
    char* data;
    int len;
}String;

//字符串初始化
String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}
//字符串赋值
void stringAssign(String* s, char* data){
    //清空数据，防止出现野指针
    if(s->data){
        free(s->data);
    }
    int len = 0;
    //temp指向data的第一个数据
    char* temp = data;
    while(*temp){
        len++;
        temp++;
    }
    if(len == 0){
        s->len = 0;
        s->data = NULL;
    }
    else{
        s->len = len;
        temp = data;
        s->data = (char*)malloc(sizeof(char) * (len + 1));
        for(int i = 0; i < len; i++){
            s->data[i] = *temp;
            temp++;
        }
    }
}
//字符串遍历
void printString(String* s){
    for(int i = 0; i < s->len; i++){
        printf(i == 0 ? "%c " : "-> %c ", s->data[i]);
    }
    printf("\n");
}
//KMP匹配算法
int main(int argc, char* argv[]){
    String* s1 = initString();
    String* s2 = initString();
    stringAssign(s1,argv[1]);
    stringAssign(s2,argv[2]);
    printString(s1);
    printString(s2);
    return 0;
}