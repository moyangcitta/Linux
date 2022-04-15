/*
循环队列
1.牺牲掉队列中一个空间来去标识队列为满或为空
2.判断逻辑如下:1)队空：front == rear；2）队满：（rear+1） % MAXSIZE == front

1.初始化队列
2.入队
3.出队
4.遍历循环队列
*/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
typedef struct Queur{
    int data[MAXSIZE];
    int front;
    int rear;
}Queue;
//初始化队列
Queue* initQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = 0;
    return queue;
}
//判断是否为空
int isEmpty(Queue* queue){
    if(queue->front == queue->rear){
        return 1;
    }
    else{
        return 0;
    }
}
//判断是否为满
int isFull(Queue* queue){
    if(queue->front == ((queue->rear + 1) % MAXSIZE)){
        return 1;
    }
    else{
        return 0;
    }
}
//入队
int enQueue(Queue* queue, int data){
    if(isFull(queue)){
        return 0;
    }
    else{
        //进位操作
        queue->data[queue->rear] = data;
        queue->rear = (queue->rear + 1) % MAXSIZE;
        return 1;
    }
}
//出队
int deQueue(Queue* queue){
    if(isEmpty(queue)){
        return 0;
    }
    else{
        int data = queue->data[queue->front];
        queue->front = (queue->front + 1) % MAXSIZE;
        return data;
    }
}
//遍历循环队列
void printQueue(Queue* queue){
    //要知道队列有多少个元素
    //首先计算长度
    int length = (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
    //起始数据
    int index = queue->front;
    //遍历
    for(int i = 0; i < length; i++){
        printf("%d->",queue->data[index]);
        index = (index + 1) % MAXSIZE;
    }
    printf("NULL\n");
}
int main(){
    Queue* queue = initQueue();
    enQueue(queue,1);
    enQueue(queue,2);
    enQueue(queue,3);
    enQueue(queue,4);
    printQueue(queue);
    deQueue(queue);
    deQueue(queue);
    printQueue(queue);
    return 0; 
}