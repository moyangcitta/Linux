/*
最小生成树（Minimum Spanning Tree,MST）
prim算法
    (V,E)是一个连通图，那么假设 U 是 V 的非空子集
    (u,v)是一条最小权值的边，那么如果 u 是属于 U ，v 属于（V - U），
    那么必有（u,v）包含在最小生成树中
找点法
    从集合中根据边的大小找点
实现prim算法
    记录当前 U 集合的状态
    选择最小边以及顶点加入到 U 集合中

key：edge（U集合）可以保留每一个节点到下一个节点的最小权值
    u是已使用节点，v是未使用节点
*/
#include<stdio.h>
#include<stdlib.h>

/*
图顶点之前不通，那么邻接矩阵的值为MAX
如果顶点是自己本身，那么为0
*/
#define MAX 32767

//节点
typedef struct Graph{
    char* vexs;//顶点
    int** arcs;//边
    int vexNum;//顶点数量
    int arcNum;//边数量
}Graph;
//vex记录 U 集合到最小边的起始节点
//weight 记录最小边
typedef struct Edge{
    char vex;
    int weight;
}Edge;
//初始化,U集合
//当edge.weight = 0，代表顶点加入到 U 集合中
Edge* initEdge(Graph* G, int index){
    Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        edge[i].vex = G->vexs[index];
        edge[i].weight = G->arcs[index][i];
    }
    return edge;
}
//传入节点，找最小边
int getMinEdge(Edge* edge, Graph* G){
    int index;
    int min = MAX;
    for(int i = 0; i < G->vexNum; i++){
        //找权值最小边
        if(edge[i].weight != 0 && min > edge[i].weight){
            min = edge[i].weight;
            index = i;
        }
    }
    return index;
}
//prim算法
void prim(Graph* G, int index){
    int min;
    //初始化当前节点的边
    Edge* edge = initEdge(G, index);
    for(int i = 0; i < G->vexNum - 1; i++){
        //得到最小边
        min = getMinEdge(edge, G);
        printf("v%c --> v%c,weight = %d\n", edge[min].vex,
            G->vexs[min], edge[min].weight);
        //最小边权值为0
        edge[min].weight = 0;
        //改变其他边的路径，使该节点只连接权值最小的边
        for(int j = 0; j < G->vexNum; j++){
            //U 子集, 0为U子集中的内容
            //找下一节点或这一节点权值最小的边
            if(G->arcs[min][j] < edge[j].weight){
                edge[j].weight = G->arcs[min][j];
                //保留当前权值最小的节点
                edge[j].vex = G->vexs[min];
            }
        }
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
            //记录边的数量
            if(G->arcs[i][j] != 0 && G->arcs[i][j] != MAX){
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
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i]){
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
        0,6,1,5,MAX,MAX,
        6,0,5,MAX,3,MAX,
        1,5,0,5,6,4,
        5,MAX,5,0,MAX,2,
        MAX,3,6,MAX,0,6,
        MAX,MAX,4,2,6,0
    };
    createGraph(G, "123456", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    prim(G, 0);
    return 0;
}