/*
双链表
1.初始化链表
2.插入结点（头插法，尾插法）
3.删除结点
4.遍历链表
*/
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* pre;
}Node;
//初始化链表
Node* initlist(){
    Node* list = (Node*)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    list->pre = NULL;
}
//头插法
void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = list->data;
    node->next = list->next;
    node->pre = list;
    //链表为空
    if(list->data == 0){
        list->next = node;
    }
    else{
        list->next->pre = node;
        list->next = node;
    }
    list->data++;
}
//尾插法
void tailInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* pointer = list;//第一个结点
    while(pointer->next){
        pointer = pointer->next;
    }
    node->next = pointer->next;
    node->pre = pointer;
    pointer->next = node;
    list->data++;
}
//删除结点
int delete(Node* list, int data){
    Node* node = list->next;
    while(node){
        if(node->data == data){
            if(node->next){
                node->pre->next = node->next;
                node->next->pre = node->pre;
                free(node);
                list->data--;
            }
            else{
                node->pre->next == NULL;
                free(node);
                list->data--;
            }
            return TRUE;
        }
        node = node->next;
    }
    return FALSE;
}
//遍历节点
void print(Node* list){
    list = list->next;//第一个结点
    while(list){
        printf("%d->",list->data);
        list = list->next;
    }
    printf("NULL\n");
}
int main(){
    Node* list = initlist();
    headInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    tailInsert(list,5);
    tailInsert(list,6);
    print(list);
    return 0;
}