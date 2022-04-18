/*
二叉树层次遍历
    队的数据结构
1.队相关的功能
2.新建树的功能
*/

#include<stdio.h>
#include<stdlib.h>
//二叉树结点
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
//队的数据结构
typedef struct QueueNode{
    TreeNode* data;
    struct QueueNode* pre;
    struct QueueNode* next;
}QueueNode;
//二叉树创建
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
//前序遍历
void preOrder(TreeNode* tree){
    if(tree == NULL){
        return ;
    }
    else{
        printf("%c ", tree->data);
        preOrder(tree->lchild);
        preOrder(tree->rchild);
    }
}
//队的初始化
QueueNode* initQueue(){
    QueueNode* Q = (QueueNode*)malloc(sizeof(QueueNode));
    Q->data = NULL;
    Q->next = Q;
    Q->pre = Q;
}
//入队
void enQueue(TreeNode* data, QueueNode* Q){
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = Q;
    node->pre = Q->pre;
    Q->pre->next = node;
    Q->pre = node;
}
//判断是否为空
int isEmpty(QueueNode* Q){
    if(Q->next == Q){
        return 1;
    }
    else{
        return 0;
    }
}
//出队
QueueNode* deQueue(QueueNode* Q){
    if(isEmpty(Q)){
        return NULL;
    }
    else{
        QueueNode* node = Q->next;
        Q->next->next->pre = Q;
        Q->next = Q->next->next;
        return node;
    }
}
//二叉树层次遍历
void levelTraverse(QueueNode* Q, TreeNode* T){
    enQueue(T,Q);//把树中的数据插入到队列中
    while(!isEmpty(Q)){
        QueueNode* node = deQueue(Q);//出队，将第一列的数据输出
        printf("%c ",node->data->data);
        if(node->data->lchild){
            enQueue(node->data->lchild,Q);
        }
        if(node->data->rchild){
            enQueue(node->data->rchild,Q);
        }
    }
}
int main(int argc, char* argv[]){
    TreeNode* tree;
    int index = 0;
    createTree(&(tree), argv[1], &index);
    preOrder(tree);
    printf("\n");
    QueueNode* Q;
    Q = initQueue();
    levelTraverse(Q, tree);
    printf("\n");
    return 0;
}