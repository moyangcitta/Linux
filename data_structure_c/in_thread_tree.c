/*
中序线索二叉树
    利用线索将二叉树转换成一个类似的线性结构
    线索：将节点连在一起的指针；如果一个二叉树有n个节点
    那么有多少个指针指向这些节点？n-1个指针，一共有2n个指针
    2n-（n-1）=n+1个指针没有用，利用这n+1个指针，来指向
    二叉树遍历序列当中的前驱和后继

1.建立一颗线索二叉树
2.遍历线索二叉树

ltag = 0 child
rtag = 0 child
*/
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
void inThreadTree(TreeNode* T,TreeNode** pre){
    if(T){
        inThreadTree(T->lchild, pre);
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
        inThreadTree(T->rchild, pre);
    }
}
//第一个节点：最左边的节点
TreeNode* getFirst(TreeNode* T){
    while(T->ltag == 0){
        T = T->lchild;
    }
    return T;
}
//next节点
TreeNode* getNext(TreeNode* node){
    if(node->rtag == 1){
        return node->rchild;
    }
    else{
        getFirst(node->rchild);
    }
}
int main(int argc, char* argv[]){
    TreeNode* T;
    TreeNode* pre = NULL;
    int index = 0;
    createTree(&(T),argv[1],&index);
    inThreadTree(T, &pre);
    //对最后的节点进行处理
    pre->rtag = 1;
    pre->rchild = NULL;
    for(TreeNode* node = getFirst(T); node != NULL; node = getNext(node)){
        printf("%c ",node->data);
    }
    printf("\n");
    return 0;
}