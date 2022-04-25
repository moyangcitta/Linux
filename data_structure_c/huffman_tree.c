/*
哈夫曼树
    带权路径长度，权值越大的节点，路径越短
哈夫曼树，所有叶子节点的带权路径长度最小
如何通过权值，节点列表，生成哈夫曼树
    1.从节点列表中选出第一小和第二小的节点，并组成一棵树，
        父节点的权值=两节点权值之和
    2.将生成的新树再次放入节点列表中，重复第一步，直到
        列表中只剩下一个节点
哈夫曼编码
顺序存储
*/
#include<stdio.h>
#include<stdlib.h>
//节点
typedef struct TreeNode{
    int weight;//权值
    int parent;
    int lchild;
    int rchild;
}TreeNode;
//哈夫曼树
typedef struct HFTree{
    TreeNode* data;
    int length;
}HFTree;
//初始化哈夫曼树
HFTree* initTree(int* weight, int length){
    HFTree* T = (HFTree*)malloc(sizeof(HFTree));
    //data相当于是一个列表，列表内的数据是树
    T->data = (TreeNode*)malloc(sizeof(HFTree) * (2 * length - 1));
    T->length = length;
    for(int i = 0; i < length; i++){
        T->data[i].weight = weight[i];
        T->data[i].parent = 0;
        T->data[i].lchild = -1;
        T->data[i].rchild = -1;
    }
    return T;
}
//选择最小
int* selectMin(HFTree* T){
    int min = __INT_MAX__;//最小值
    int secondMin = __INT_MAX__;
    int minIndex;//最小值脚标
    int secondIndex;
    for(int i = 0; i < T->length; i++){
        if(T->data[i].parent == 0){
            if(T->data[i].weight < min){
                min = T->data[i].weight;
                minIndex = i;
            }
        }
    }
    //第二个最小值
    for(int i = 0; i < T->length; i++){
        if(T->data[i].parent == 0 && i != minIndex){
            if(T->data[i].weight < secondMin){
                secondMin = T->data[i].weight;
                secondIndex = i;
            }
        }
    }
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = minIndex;
    res[1] = secondIndex;
    return res;//以指针方式返回
}
//创建哈夫曼树
void createHFTree(HFTree* T){
    int* res;
    int min;
    int secondMin;
    int length = T->length * 2 - 1;
    for(int i = T->length; i < length; i++){
        res = selectMin(T);
        min = res[0];
        secondMin = res[1];
        T->data[i].weight = T->data[min].weight + T->data[secondMin].weight;
        T->data[i].lchild = min;
        T->data[i].rchild = secondMin;
        T->data[i].parent = 0;
        T->data[min].parent = i;
        T->data[secondMin].parent = i;
        T->length++;
    }
}
//前序遍历
void preOrder(HFTree* T, int index){
    if(index != -1){
        printf("%d ",T->data[index].weight);
        preOrder(T, T->data[index].lchild);
        preOrder(T, T->data[index].rchild);
    }
}
int main(){
    int weight[7] = {5,1,3,6,11,2,4};
    HFTree* T = initTree(weight, 7);
    createHFTree(T);
    preOrder(T, T->length - 1);
    printf("\n");
    // int *res = selectMin(T);
    // printf("%d %d\n",res[0],res[1]);
    return 0;
}