/*
二叉树非递归后序遍历
    1.从根节点开始，寻找最左边的节点，并依次入栈
    2.出栈前，判断栈顶元素是否有右子树（还要判断右子树是否被访问过），如果有，则将右子树入栈
*/
#include<stdio.h>
#include<stdlib.h>

//节点
typedef struct TreeNode{
    char data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
    int flag;
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
        (*tree)->flag = 0;
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
//栈顶元素
StackNode* getTop(StackNode* stack){
    if(isEmpty(stack)){
        return NULL;
    }
    else{
        StackNode* node = stack->next;
        return node;
    }
}
//后序遍历
void postOrder(TreeNode* tree){
    TreeNode* node = tree;
    StackNode* stack = initStack();
    while(node || !isEmpty(stack)){
        if(node){
            push(stack, node);
            node = node->lchild;
        }
        else{
            TreeNode* top = getTop(stack)->data;
            //flag判断是否被遍历过
            if(top->rchild && (top->rchild->flag == 0)){
                //如果右子树没有被遍历过则从右子树开始遍历
                top = top->rchild;
                push(stack,top);
                node = top->lchild;
            }
            else{
                //若树已经被遍历过且子树均被遍历则出栈
                top = pop(stack)->data;
                printf("%c ",top->data);
                top->flag = 1;
            }
        }
    }
}
int main(int argc, char* argv[]){
    TreeNode* tree;
    int index = 0;
    createTree(&(tree),argv[1],&index);
    postOrder(tree);
    printf("\n");
    return 0;
}