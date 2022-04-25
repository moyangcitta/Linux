/*
图（无向图）
    节点+边
邻接矩阵法

图的遍历
BFS
    
DFS
    深度优先遍历
    1.找一个节点访问
    2.找这个节点可以可以访问的节点
    3.重复第一步直到所有节点访问完毕
*/

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

//节点
typedef struct Graph{
    char* vexs;//顶点
    int** arcs;//边
    int vexNum;//顶点数量
    int arcNum;//边数量
}Graph;
//队列
typedef struct Queue{
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;
//队列初始化
Queue* initQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = 0;
    return Q;
}
//判断是否满
int isFull(Queue* Q){
    if((Q->rear + 1) % MAXSIZE == Q->front){
        return 1;
    }
    else{
        return 0;
    }
}
//判断是否为空
int isEmpty(Queue* Q){
    if(Q->front == Q->rear){
        return 1;
    }
    else{
        return 0;
    }
}
//插入节点
int enQueue(Queue* Q, int data){
    if(isFull(Q)){
        return 0;
    }
    else{
        Q->data[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}
//弹出节点
int deQueue(Queue* Q){
    if(isEmpty(Q)){
        return -1;
    }
    else{
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return data;
    }
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
//广度优先搜索
void BFS(Graph* G, int* visited, int index){
    Queue* Q = initQueue();
    //访问第一个节点
    printf("%c\t",G->vexs[index]);
    visited[index] = 1;
    enQueue(Q,index);
    while(!isEmpty(Q)){
        int i = deQueue(Q);
        for(int j = 0; j < G->vexNum; j++){
            if(G->arcs[i][j] == 1 && ! visited[j]){
                printf("%c\t",G->vexs[j]);
                visited[j] = 1;
                enQueue(Q, j);
            }
        }
    }
}
int main(){
    Graph* G = initGraph(5);
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[5][5] = {
        0,1,1,1,0,
        1,0,1,1,1,
        1,1,0,0,0,
        1,1,0,0,1,
        0,1,0,1,0
    };
    createGraph(G, "ABCDE", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    BFS(G, visited, 0);
    printf("\n");
    return 0;
}