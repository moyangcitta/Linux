/*
先序线索二叉树
    如果节点没有左右孩子，则指针指向先序遍历的前驱和后继

1.创建先序线索二叉树
2.遍历先序线索二叉树

*/
//#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int ltag;//前驱
    int rtag;//后继
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
        (*T)->ltag = 0;
        (*T)->rtag = 0;
        //创建左子树和创建树的逻辑一致，进行递归
        //右子树同理
        createTree(&((*T)->lchild),data,index);
        createTree(&((*T)->rchild),data,index);
    }
}
//线索化//遍历时需要改变节点的值//pre前一个遍历的节点
void preThreadTree(TreeNode* T,TreeNode** pre){
    if(T){
        if(T->lchild == NULL){
            T->ltag = 1;
            T->lchild = *pre;
        }
        if((*pre != NULL) && ((*pre)->rchild == NULL)){
            (*pre)->rtag = 1;
            (*pre)->rchild = T;
        }
        *pre = T;
        //如果不加会导致无限调用，a从而导致栈溢出
        if(T->ltag == 0){
            preThreadTree(T->lchild, pre);
        }
        if(T->rtag == 0){
            preThreadTree(T->rchild, pre);
        }
    }
}
//得到后续节点
TreeNode* getNext(TreeNode* node){
    //有后继的情况
    if(node->rtag == 1){
        return node->rchild;
    }
    //无后继的情况
    else{
        if(node->ltag == 0){
            return node->lchild;
        }
        else{
            return node->rchild;
        }
    }
}

int main(int argc, char* argv[]){
    TreeNode* T;
    TreeNode* pre = NULL;
    int index = 0;
    createTree(&(T),argv[1],&index);
    preThreadTree(T, &pre);
    //对最后的节点进行处理
    pre->rtag = 1;
    pre->rchild = NULL;
    for(TreeNode* node = T; node != NULL; node = getNext(node)){
        printf("%c ",node->data);
    }
    printf("\n");
    return 0;
}
