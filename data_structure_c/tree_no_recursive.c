/*
二叉树非递归遍历
    1.入栈根节点
    2.循环，直到左孩子为空
    3.出栈，访问节点，入栈，右孩子
*/

#include<stdio.h>
#include<stdlib.h>

//节点
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
//栈
typedef struct StackNode{
    TreeNode* data;
    struct StackNode* next;
}StackNode;
//创建二叉树
void createTree(TreeNode** tree, char* data, int* index){
    char ch;
    ch = data[*index];
    *index += 1;
    if(ch == '#'){
        *tree = NULL;
    }
    else{
        *tree = (TreeNode*)malloc(sizeof(TreeNode));
        (*tree)->data = ch;
        createTree(&((*tree)->lchild),data,index);
        createTree(&((*tree)->rchild),data,index);
    }
}
//栈初始化
StackNode* initStack(){
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = NULL;
    node->next = NULL;
    return node;
}
//入栈
void push(StackNode* stack, TreeNode* tree){
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = tree;
    node->next = stack->next;
    stack->next = node;
}
//判断栈是否为空
int isEmpty(StackNode* stack){
    if(stack->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//出栈
StackNode* pop(StackNode* stack){
    if(isEmpty(stack)){
        return NULL;
    }
    else{
        StackNode* node = stack->next;
        stack->next = node->next;
        return node;
    }
}
//前序遍历
void preOrder(TreeNode* tree){
    TreeNode* node = tree;
    StackNode* stack = initStack();//栈初始化
    while(node || !isEmpty(stack)){
        if(node){
            //先遍历左孩子，打印头结点
            //打印头结点
            printf("%c ",node->data);
            //入栈
            push(stack,node);
            //遍历左节点
            node = node->lchild;
        }
        else{
            //头结点打印完成，打印右节点
            //出栈，防止重复打印
            node = pop(stack)->data;
            //遍历右节点
            node = node->rchild;
            //得到右孩子节点，再从左孩子开始遍历
        }
    }
}
//中序遍历
void inOrder(TreeNode* tree){
    TreeNode* node = tree;
    StackNode* stack = initStack();//栈初始化
    while(node || !isEmpty(stack)){
        if(node){
            //先遍历左孩子，打印头结点
            //入栈
            push(stack,node);
            //遍历左节点
            node = node->lchild;
        }
        else{
            //头结点打印完成，打印右节点
            //出栈，防止重复打印
            node = pop(stack)->data;
            //打印左结点
            printf("%c ",node->data);
            //遍历右节点
            node = node->rchild;
            //得到右孩子节点，再从左孩子开始遍历
        }
    }
}
int main(int argc, char* argv[]){
    TreeNode* tree;
    int index = 0;
    createTree(&(tree),argv[1],&index);
    preOrder(tree);
    printf("\n");
    inOrder(tree);
    printf("\n");
    return 0;
}