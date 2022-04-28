/*
最小生成树
kruskal算法
    假设（V,E）是一个连通图，U是顶点集V的一个非空子集，
    如果（U,V）是一条具有最小权值的边，u属于U，v属于（V-U），
    那么（U,V）必是最小生成树的边

    1.对边排序
    2.选边（不可以有回路）

    1.维护一个边的数组并排序
    2.判断图是否连通
        需要一个辅助数组，来去记录当前索引节点所属哪个连通分量
        
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
//边
typedef struct Edge{
    int start;//起点
    int end;//终点
    int weight;//权值
}Edge;
//边初始化
Edge* initEdge(Graph* G){
    int index = 0;
    Edge* edge = (Edge*)malloc(sizeof(Edge) * G->arcNum);
    //设计每一个边的起点、终点以及权值
    //因为此图为无向图，因此重复的边不需要考虑
    for(int i = 0; i < G->vexNum; i++){
        for(int j = i + 1; j < G->vexNum; j++){
            if(G->arcs[i][j] != MAX){
                edge[index].start = i;
                edge[index].end = j;
                edge[index].weight = G->arcs[i][j];
                index++;
            }
        }
    }
    return edge;
}
//排序
//根据权值排序，但是起点和终点仍然储存在数据结构中
void sortEdge(Edge* edge, Graph* G){
    Edge temp;
    for(int i = 0; i < G->arcNum - 1; i++){
        for(int j = 0; j < G->arcNum - i - 1; j++){
            if(edge[j].weight > edge[j + 1].weight){
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}
//算法
//连通分量
void kruska(Graph* G){
    int* connected = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        connected[i] = i;
    }
    Edge* edge = initEdge(G);//对每一个边初始化
    sortEdge(edge, G);//对边由小到大排序
    for(int i = 0; i < G->arcNum; i++){
        int start = connected[edge[i].start];
        int end = connected[edge[i].end];
        //如果没有首尾相连
        if(start != end){
            printf("v%c --> v%c weight = %d\n", G->vexs[edge[i].start],
                G->vexs[edge[i].end], edge[i].weight);
            for(int j = 0; j < G->vexNum; j++){
                if(connected[j] == end){
                    //使连通节点与初始节点相同 
                    connected[j] = start;
                }
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
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX 
            && !visited[i]){
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
    kruska(G);
    printf("\n");
    return 0;
}
