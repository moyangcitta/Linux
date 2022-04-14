/*
队
先进先出：一种特殊的线性表，只允许在一端进行存取
1.初始化队
2.出队
3.入队
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//初始化队
Node* initQueue(){
    Node* queue = (Node*)malloc(sizeof(Node));
    queue->data = 0;
    queue->next = NULL;
    return queue;
}
//判断是否为空
int isEmpty(Node* queue){
    if(queue->data == 0 || queue->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//出队
int pop(Node* queue){
    if(isEmpty(queue)){
        return -1;
    }
    else{
        Node* node = queue->next;
        int data = node->data;
        queue->next = node->next;
        free(node);
        queue->data--;
        return data;
    }
}
//入队
int push(Node* queue, int data){
    Node* pointer = queue;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = pointer->next;
    pointer->next = node;
    queue->data++;
}
//遍历
void print(Node* queue){
    Node* pointer = queue->next;
    while(pointer != NULL){
        printf("%d->",pointer->data);
        pointer = pointer->next;
    }
    printf("NULL\n");
}
int main(){
    Node* queue = initQueue();
    push(queue,1);
    push(queue,2);
    push(queue,3);
    print(queue);
    pop(queue);
    print(queue);
    return 0;
}