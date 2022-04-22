/*
二叉排序树
    一棵树，左子树上的节点的值，都比根节点小；
    右子树上的所有节点的值，都比根节点大；
    同时，这个性质也是递归的
    同时，树中的节点值不重复
如何构建
    1.建立一棵二叉排序树
    2.在二叉树中查找值
*/

#include<stdio.h>
#include<stdlib.h>
//节点
typedef struct TreeNode{
    int data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
//查找
TreeNode* bstSearch(TreeNode* T, int data){
    if(T){
        if(T->data == data){
            return T;
        }
        else if(data < T->data){
            return bstSearch(T->lchild, data);
        }
        else{
            return bstSearch(T->rchild, data);
        }
    }
    else{
        return NULL;
    }
}
//插入
void bstInsert(TreeNode** T, int data){
    //初始化
    if(*T == NULL){
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    //不能有重复值
    else if(data == (*T)->data){
        return ;
    }
    else if(data < (*T)->data){
        bstInsert(&((*T)->lchild), data);
    }
    else{
        bstInsert(&((*T)->rchild), data);
    }
}
//前序遍历
void preOrder(TreeNode* T){
    if(T){
        printf("%d ",T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}
int main(int argc, char* argv[]){
    TreeNode* T = NULL;
    int nums[6] = {4,5,19,23,2,8};
    for(int i = 0; i < 6; i++){
        bstInsert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
    return 0;
}