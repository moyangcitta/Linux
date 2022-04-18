/*
树
是一个n个结点的有限集，如果n=0时，称之为空树
    1.树的定义是递归的，树的定义中又用到了自身
    2.树的根节点没有前驱，除根节点外，其他所有节点有且只有一个前驱
    3.树中的所有节点可以有多个或0个后驱
二叉树
    1.一种特殊的数据结构
    2.每个结点至多只有两个子树
遍历方式
    1.前序  根-》左-》右
    2.中序  左-》根-》右
    3.后序  左-》右-》根
1.二叉树的创建
2.二叉树的遍历
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
//创建二叉树
void createTree(TreeNode** T, char* data, int* index){//指针的指针
    //data输入数组
    //index遍历数组
    char ch;
    ch = data[*index];
    *index += 1;//指针类型不能直接++，否则只是地址+1
    if(ch == '#'){
        //此时为空节点
        *T = NULL;
    }
    else{
        //此时不为空
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        //创建左子树和创建树的逻辑一致，进行递归
        //右子树同理
        createTree(&((*T)->lchild),data,index);
        createTree(&((*T)->rchild),data,index);
    }
}
//遍历二叉树
void preOrder(TreeNode* T){
    if(T == NULL){
        return ;
    }
    else{
        //先办事，
        printf("%c ",T->data);
        //处理左孩子
        preOrder(T->lchild);
        //处理右孩子
        preOrder(T->rchild);
    }
}
//中序遍历
void inOrder(TreeNode* T){
    if(T == NULL){
        return ;
    }
    else{
        inOrder(T->lchild);
        printf("%c ",T->data);
        inOrder(T->rchild);
    }
}
//后序遍历
void postOrder(TreeNode* T){
    if(T == NULL){
        return ;
    }
    else{
        postOrder(T->lchild);
        postOrder(T->rchild);
        printf("%c ",T->data);
    }
}
int main(int argc, char* argv[]){
    TreeNode* T;
    int index = 0;
    createTree(&(T),argv[1],&index);
    preOrder(T);
    printf("\n");
    inOrder(T);
    printf("\n");
    postOrder(T);
    printf("\n");
    return 0;
}

