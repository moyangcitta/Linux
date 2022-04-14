//单链表
/*
1.有限的序列
2.序列中的每一个元素都有唯一的前驱和后继，除了开头和结尾两个节点

顺序表：分配一块连续的内存去存放这些元素，例如编程语言中的数组
链表：内存是不连续的，元素会各自被分配一块内存，内存和内存之间用指针进行相连

单链表操作：
1.增加：1.头插法
        2.尾插法
2.删除：只需要找到对应节点，将对应节点的前一个结点指向这个结点的后继，只操作一个指针

头节点：保存元素个数
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;
//头结点
Node* initList(){
    Node *list = (Node*)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}
//头插法
void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));//新建结点
    node->data = data;//将头结点的数据给插入结点
    node->next = list->next;//将头结点的指针给插入结点
    list->next = node;//更新头结点，将头结点指针指向新建结点
    list->data++;//列表长度加一
}
//尾插法
void tailInsert(Node* list, int data){
    Node* head = list;//保存头结点
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    list = list->next;//指向链表中第一个元素
    //找到列表末尾
    while(list->next){
        list = list->next;
    }
    list->next = node;//将新节点插入到列表末尾
    head->data++;//头结点储存的列表长度+1
}
//删除某个元素
void delete(Node* list, int data){
    Node* pre = list;
    Node* current = list->next;
    while(current){
        if(current->data == data){
            pre->data = current->data;
            free(current);
            break;
        }
        pre = current;
        current = current->next;
    }
    list->data--;
}
//遍历操作
void printList(Node* list){
    list = list->next;
    while(list){
        printf("%d", list->data);
        list = list->next;
    }
    printf("\n");
}
int main(){
    Node* list = initList();
    printf("%d\n",list->data);
    return 0;
}
