/*
单循环链表
1.初始化链表
2.增加结点（头插法，尾插法）
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
}Node;
//初始化链表
Node* initlist(){
    Node* list = (Node*)malloc(sizeof(Node));
    list->data = 0;
    list->next = list;//循环链表，末尾指向头结点
    return list;
}
//头插法
void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = list->data;
    node->next = list->next;
    list->next = node;
    list->data++;
}
//尾插法
void tailInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list;//循环链表
    Node* pointer = list->next;//记录第一个结点
    //将最后一个结点的下一个指针指向插入结点，同时插入节点的下一个指针为头结点
    while(pointer->next != list){
        pointer = pointer->next;
    }
    pointer->next = node;
    list->data--;
}
//删除结点
int delete(Node* list, int data){
    Node* prenode = list;//定义前一个结点
    Node* node = list->next;//定义第一个结点
    while(node != list){
        if(node->data == data){
            prenode->next = node->next;
            free(node);
            list->data--;
            return TRUE;
        }
        prenode = node;
        node = node->next;
    }
    return FALSE;
}
//遍历节点
void printList(Node* list){
    Node* node = list->next;//指向头结点
    while(node != list){//循环链表，末尾不是NULL，当指针指向头结点时结束循环
        printf("%d->",node->data);
        node = node->next;
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
    tailInsert(list,7);
    delete(list,3);
    printList(list);
    return 0;
}