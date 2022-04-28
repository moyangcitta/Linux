/*
最短路径
floyd算法（弗洛伊德算法）
    每一对顶点之间的最短距离
    d数组：保存了两点之间的最短路径长度
    p数组：保存了两点之间最短路径的前驱
核心：试探法，通过加入不同的点进行中转，选择出最优解
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 32767

//节点
typedef struct Graph{
    char* vexs;//顶点
    int** arcs;//边
    int vexNum;//顶点数量
    int arcNum;//边数量
}Graph;
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
//算法
void floyd(Graph* G){
    int d[G->vexNum][G->vexNum];
    int p[G->vexNum][G->vexNum];
    //初始化
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            //路径长度
            d[i][j] = G->arcs[i][j];
            //前驱
            if(G->arcs[i][j] > 0 && G->arcs[i][j] != MAX){
                p[i][j] = i;
            }
            else{
                p[i][j] = -1;
            }
        }
    }
    //算法实现
    //以i为中转
    for(int i = 0; i < G->vexNum; i++){
        //j起始节点
        for(int j = 0; j < G->vexNum; j++){
            //k目标节点
            for(int k = 0; k < G->vexNum; k++){
                if(d[j][i] + d[i][k] < d[j][k]){
                    d[j][k] = d[j][i] + d[i][k];
                    p[j][k] = p[i][k];
                }
            }
        }
    }
    //打印
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < G->vexNum; i++){
        for(int j = 0; j < G->vexNum; j++){
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}
int main(){
    Graph* G = initGraph(4);
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[4][4] = {
        0,1,MAX,3,
        1,0,2,2,
        MAX,2,0,8,
        3,2,8,0
    };
    createGraph(G, "1234", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    floyd(G);
    printf("\n");
    return 0;
}