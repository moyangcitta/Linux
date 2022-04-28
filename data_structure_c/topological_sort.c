/*
DAG：有向无环图
AOV：1.图的节点表示任务；2.图的弧表示先后依赖关系
拓扑排序
    概念：就是将AOV中的顶点排成一个线性序列，如果vi->vj有弧的话
        那么vi必然在vj前面
    流程：1.找出没有前驱的点，输出它，剪掉以它为出发点的所有边
        2.重复第一步，直到图中不存在没有前驱的点
*/
#include<stdio.h>
#include<stdlib.h>

//节点
typedef struct Graph{
    char* vexs;//顶点
    int** arcs;//边
    int vexNum;//顶点数量
    int arcNum;//边数量
}Graph;
//栈
typedef struct Node{
    int data;
    struct Node* next;
}Node;
//栈的初始化
Node* initStack(){
    Node* stack = (Node*)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}
//入栈
void push(Node* stack, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
}
//判断栈是否为空
int isEmpty(Node* stack){
    if(stack->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//出栈
int pop(Node* stack){
    if(!isEmpty(stack)){
        Node* node = stack->next;
        stack->next = node->next;
        return node->data;
    }
    else{
        return -1;
    }
}
//度
int* findInDegrees(Graph* G){
    int* inDegrees = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        inDegrees[i] = 0;
    }
    //计算节点的度
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            if(G->arcs[i][j]){
                inDegrees[j] = inDegrees[j] + 1;
            }
        }
    }
    return inDegrees;
}
//排序
void topologicalSort(Graph* G){
    int index = 0;
    int* top = (int*)malloc(sizeof(int) * G->vexNum);
    int* inDegrees = findInDegrees(G);
    Node* stack = initStack();
    //初始化，将没有前驱的节点入栈
    for(int i = 0; i < G->vexNum; i++){
        if(inDegrees[i] == 0){
            push(stack,i);
        }
    }
    while(!isEmpty(stack)){
        //取出一个没有前驱的节点
        int vex = pop(stack);
        top[index++] = vex;
        for(int i = 0; i < G->vexNum; i++){
            //该节点指向的下一节点，减小其度
            if(G->arcs[vex][i]){
                inDegrees[i] = inDegrees[i] - 1;
                //再次入栈
                if(inDegrees[i] == 0){
                    push(stack, i);
                }
            }
        }
    }
    for(int i = 0; i < index; i++){
        printf("%c\t",G->vexs[top[i]]);
    }
    printf("\n");
}
//初始化,vexNum是节点数量
Graph* initGraph(int vexNum){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexs = (char*)malloc(sizeof(char) * vexNum);
    G->arcs = (int**)malloc(sizeof(int*) * vexNum);
    for(int i = 0; i < vexNum; i++){
        G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
    }
    G->vexNum = vexNum;
    G->arcNum = 0;
    return G;
}
//创建//初始化边数量
void createGraph(Graph* G, char* vexs, int* arcs){
    for(int i = 0; i < G->vexNum; i++){
        G->vexs[i] = vexs[i];
        for(int j = 0; j < G->vexNum; j++){
            //确认位置
            G->arcs[i][j] = *(arcs + i * G->vexNum + j);
            if(G->arcs[i][j] != 0){
                G->arcNum++;
            }
        }
    }
    //因为是无向边
    G->arcNum /= 2;
}
//深度优先遍历
void DFS(Graph* G, int* visited, int index){
    //第一个节点
    printf("%c\t",G->vexs[index]);
    visited[index] = 1;
    //首先，visited是储存所有节点是否被访问
    //其次，递归和循环保证了程序的可用性
    for(int i = 0; i < G->vexNum; i++){
        if(G->arcs[index][i] == 1 && !visited[i]){
            DFS(G, visited, i);
        }
    }
}
int main(){
    Graph* G = initGraph(6);
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[6][6] = {
        0,1,1,1,0,0,
        0,0,0,0,0,0,
        0,1,0,0,1,0,
        0,0,0,0,1,0,
        0,0,0,0,0,0,
        0,0,0,1,1,0
    };
    createGraph(G, "123456", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    topologicalSort(G);
    return 0;
}