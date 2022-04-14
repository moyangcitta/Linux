/*
栈
特殊的线性表：先进后出
可以解决的问题：1.表达式的值；2.解决一些递归问题；3.进制转换
1.初始化栈
2.出栈
3.入栈
4.判断栈空
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//初始化栈
Node* initStack(){
    Node* stack = (Node*)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
}
//判断栈空
int isEmpty(Node* stack){
    if(stack->data == 0 || stack->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//取栈顶
int getPop(Node* stack){
    if(isEmpty(stack)){
        return -1;
    }
    else{
        return stack->next->data;
    }
}
//出栈
int pop(Node* stack){
    if(!isEmpty(stack)){
        Node* node = stack->next;
        int num = node->data;
        stack->next = node->next;
        free(node);
        stack->data--;
        return num;
    }
    else{
        return -1;
    }
}
//入栈
void push(Node* stack, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
}
//遍历
void print(Node* stack){
    Node* pointer = stack->next;
    while(pointer){
        printf("%d->",pointer->data);
        pointer = pointer->next;
    }
    printf("NULL\n");
}
int main(){
    Node* stack = initStack();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    print(stack);
    pop(stack);
    print(stack);
    return 0;
}