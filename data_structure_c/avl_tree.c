/*
平衡二叉树
    是一棵合理的二叉排序树
如何保证合理性
    特点：左右子树高度差不超过1
如何构建
    1.本质上和构建二叉排序树一致
    2.在构建二叉排序树的过程中，如果发现树不符合特性，需要进行调整
        ，调整需要用到树的高度，所以我们节点的结构体当中需要加一个
        字段来记录树的高度，如果遇到多棵树不平衡，选择最小树
        LL RR RL LR
如何判断调整类型
    1.找到失衡树的根节点 root
    2.找到导致树失衡的节点 node
    3.判断 node 在 root 孩子的哪一侧
RR：取中间的节点，使它的父亲成为它的左孩子，如果他有左孩子的话
    ，那么这个左孩子连接到父亲的右孩子上面，父亲的右孩子不变
LL：取中间节点，使他的父亲作为自己的右孩子，如果自己有右孩子的话
    ，那么将自己的右孩子连接到父亲的左孩子上面
LR：取最后一个节点作为父节点，同时将它的父亲作为自己的左孩子，
    将他的父亲的父亲作为自己的右孩子，如果他有左孩子或者右孩子
    他原先的左孩子连接到父亲的右孩子上，他现在的右孩子，连接到
    父亲的父亲的左孩子上
RL：取最后一个节点，作为父亲节点，将他原先的父亲作为自己的右孩子
    ，将父亲的父亲作为自己的左孩子，如果自己有左孩子，将它连接到
    父亲的父亲的右孩子上，右孩子连接到父亲的左孩子上
*/
//节点
#include<stdio.h>
#include<stdlib.h>
//节点
typedef struct TreeNode{
    int data;
    int height;//树的高度
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;
//得到树的高度
int getHeight(TreeNode* node){
    return node ? node->height : 0;
}
//最大值
int max(int a, int b){
    return a > b ? a : b;
}
//RR,temp是中间节点，node是当前节点
void rrRotation(TreeNode* node, TreeNode** root){
    TreeNode* temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node->height = max(getHeight(node->lchild),
        getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(temp->lchild),
        getHeight(temp->rchild)) + 1;
    *root = temp;
}
//LL
void llRotation(TreeNode* node, TreeNode** root){
    TreeNode* temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node->height = max(getHeight(node->lchild),
        getHeight(node->rchild)) + 1;
    temp->height = max(getHeight(temp->lchild),
        getHeight(temp->rchild)) + 1;
    *root = temp;
}
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
void avlInsert(TreeNode** T, int data){
    //初始化
    if(*T == NULL){
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    //不能有重复值
    else if(data == (*T)->data){
        return ;
    }
    else if(data < (*T)->data){
        avlInsert(&((*T)->lchild), data);
        //拿到当前节点左右子树的高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        //判断高度差
        if(lHeight - rHeight == 2){
            if(data < (*T)->lchild->data){
                //LL调整
                llRotation(*T, T);
            }
            else{
                //LR调整->RR->LL
                rrRotation((*T)->lchild, &((*T)->lchild));
                llRotation(*T,T);
            }
        }
    }
    else if(data > (*T)->data){
        avlInsert(&((*T)->rchild), data);
        //拿到当前节点左右子树的高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        //判断高度差
        if(rHeight - lHeight == 2){
            if(data > (*T)->rchild->data){
                //RR调整
                rrRotation(*T, T);
            }
            else{
                //RL调整->LL->RR
                rrRotation((*T)->rchild, &((*T)->rchild));
                llRotation(*T,T);
            }
        }
    }
    (*T)->height = max(getHeight((*T)->lchild)
        , getHeight((*T)->rchild)) + 1;
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
    int nums[5] = {8,7,9,5,6};
    for(int i = 0; i < 5; i++){
        avlInsert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
    return 0;
}