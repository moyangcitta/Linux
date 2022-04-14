/*
双循环列表
1.初始化链表
2.增加结点（头插法，尾插法）
3.删除结点
4.遍历列表
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;
//初始化头结点
Node* initList(){
    Node* list = (Node*)malloc(sizeof(Node));
    list->data = 0;
    list->pre = list;
    list->next = list;
    return list;
}
//头插入
void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->pre = list;
    node->next = list->next;
    list->next->pre = node;
    list->next = node;
    list->data++;
}
//尾插入
void tailInsert(Node* list, int data){
    Node* prenode = list->pre;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->pre = prenode;
    node->next = list;
    prenode->next = node;
    list->pre = node;
    list->data++;
}
//删除
void delete(Node* list, int data){
    Node* pointer = list->next;
    while(pointer != list){
        if(pointer->data == data){
            pointer->pre->next = pointer->next;
            pointer->next->pre = pointer->pre;
            list->data--;
            free(pointer);
            break;
        }
        pointer = pointer->next;
    }
}
//遍历
void print(Node* list){
    Node* pointer = list->next;
    while(pointer != list){
        printf("%d->",pointer->data);
        pointer = pointer->next;
    }
    printf("NULL\n");
}
int main(){
    Node* list = initList();
    tailInsert(list,5);
    tailInsert(list,6);
    print(list);
    delete(list,3);
    delete(list,5);
    print(list);
    return 0;
}