/*
后序线索二叉树

*/
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    struct TreeNode* parent;
    int ltag;//前驱
    int rtag;//后继
}TreeNode;
//创建二叉树
void createTree(TreeNode** T, char* data, int* index, TreeNode* parent){//指针的指针
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
        (*T)->parent = parent;
        //创建左子树和创建树的逻辑一致，进行递归
        //右子树同理
        createTree(&((*T)->lchild),data,index, *T);
        createTree(&((*T)->rchild),data,index, *T);
    }
}
//线索化//遍历时需要改变节点的值//pre前一个遍历的节点
void postThreadTree(TreeNode* T,TreeNode** pre){
    if(T){
        postThreadTree(T->lchild, pre);
        postThreadTree(T->rchild, pre);
        //设置前驱
        if(T->lchild == NULL){
            T->ltag = 1;
            T->lchild = *pre;
        }
        //设置后继，pre是inThreadTree（t->lchild,pre）中的元素
        //关键点是无法直接获得后继节点，只有将左子节点作为指针变量，通过全局
        //添加该节点的后继
        //e.x.ABD##EF###C##
        if(*pre != NULL && (*pre)->rchild == NULL){
            (*pre)->rtag = 1;
            (*pre)->rchild = T;
        }
        //设置下一个底层变量的前驱
        //最后一个节点的后继因为无法设置而默认为NULL
        *pre = T;
    }
}
//第一个节点：1.找到最左边的节点；2.判断这个节点是否有右子树
//如果有右子树，继续寻找以右子树为根树的最左节点
//如果没有，那么第一个节点就是最左边的节点
TreeNode* getFirst(TreeNode* T){
    while(T->ltag == 0){
        T = T->lchild;
    }
    if(T->rtag == 0){
        return getFirst(T->rchild);
    }
    return T;
}
//next节点
//1.是根节点，next = NULL
//2.是左孩子，那么判断父亲右子树是否为空
//如果为空，next = parent
//右子树不为空，next = getFirst（parent->rchild）
//3.是右孩子，next = parent
TreeNode* getNext(TreeNode* node){
    if(node->rtag == 1){
        return node->rchild;
    }
    else{
        //如果是根节点
        if(node->parent == NULL){
            return NULL;
        }
        //如果是右节点
        else if(node->parent->rchild == node){
            return node->parent;
        }
        //如果是左节点
        else{
            //找右子树的左孩子
            if(node->parent->ltag == 0){
                return getFirst(node->parent->rchild);
            }
            else{
                node->parent;
            }
        }
    }
}
int main(int argc, char* argv[]){
    TreeNode* T;
    TreeNode* pre = NULL;
    int index = 0;
    createTree(&(T),argv[1],&index,NULL);
    postThreadTree(T, &pre);
    //对最后的节点进行处理，最后一个节点是A
    //pre->rtag = 1;
    //pre->rchild = NULL;
    for(TreeNode* node = getFirst(T); node != NULL; node = getNext(node)){
        printf("%c ",node->data);
    }
    printf("\n");
    return 0;
}