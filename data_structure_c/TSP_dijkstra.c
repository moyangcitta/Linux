/*
最短路径 the shorted path
dijkstra算法（广义的贪心算法）
    目标顶点到其他顶点之间的的最短距离
    S数组：记录了目标顶点到其他顶点的最短路径是否求得
    P数组：记录了目标顶点到其他顶点的最短路径的前驱节点
    D数组：记录目标顶点到其他顶点的最短路径的长度
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 32767

//节点
typedef struct Graph{
    char* vexs;//顶点
    int** arcs;//边的权重
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
    //记录边的数量，因为是无向边
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
        if(G->arcs[index][i] > 1 && G->arcs[index][i] != MAX && !visited[i]){
            DFS(G, visited, i);
        }
    }
}
//找最短路径的节点
int getMin(Graph* G, int* d, int* s){
    int min = MAX;//最小值
    int index;
    for(int i = 0; i < G->vexNum; i++){
        //判断是否为已访问节点
        //判断是否小于之前的最短路径
        if(!s[i] && d[i] < min){
            min = d[i];
            index = i;
        }
    }
    return index;
}
//dijkstra算法
void dijkstra(Graph* G, int index){
    //准备辅助数组
    int* s = (int*)malloc(sizeof(int) * G->vexNum);
    int* p = (int*)malloc(sizeof(int) * G->vexNum);
    int* d = (int*)malloc(sizeof(int) * G->vexNum);
    //初始化
    for(int i = 0; i < G->vexNum; i++){
        if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX){
            p[i] = index;
            d[i] = G->arcs[index][i];
        }
        else{
            p[i] = -1;//没有前驱
            d[i] = MAX;
        }
        if(i == index){
            s[i] = 1;//节点
            d[i] = 0;//目标节点到目标节点最短路径长度
        }
        else{
            s[i] = 0;
        }
    }
    for(int i = 0; i < G->vexNum - 1; i++){
        //最短路径的坐标点
        int index = getMin(G, d, s);
        s[index] = 1;//将当前最短路径改成已访问
        //对最短路径进行调整
        for(int j = 0; j < G->vexNum; j++){
            //更改其他节点的最短路径
            if(!s[j] && d[index] + G->arcs[index][j] < d[j]){
                d[j] = d[index] + G->arcs[index][j];
                //前驱
                p[j] = index;
            }
        }
    }
    for(int i = 0; i < G->vexNum; i++){
        printf("%d %d %d\n", s[i], p[i], d[i]);
    }
    // //目标节点指向的最短节点
    // for(int i = 0; i < G->vexNum; i++){
    //     if(i == index){
    //         s[i] = 1;//节点
    //     }
    //     else{
    //         s[i] = 0;
    //     }
    // }
    // //前驱节点
    // for(int i = 0; i < G->vexNum; i++){
    //     if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX){
    //         p[i] = index;
    //     }
    //     else{
    //         p[i] = -1;//没有前驱
    //     }
    // }
    // //最短路径长度
    // for(int i = 0; i < G->vexNum; i++){
    //     if(G->arcs[index][i] > 0 && G->arcs[index][i] != MAX){
    //         d[i] = G->arcs[index][i];
    //     }
    //     else{
    //         d[i] = MAX;
    //     }
    //     if(i == index){
    //         d[i] = 0;//目标节点到目标节点最短路径长度
    //     }
    // }
    for(int i = 0; i < G->vexNum; i++){
        printf("%d %d %d\n",s[i],p[i],d[i]);
    }
}
int main(){
    Graph* G = initGraph(7);
    int* visited = (int*)malloc(sizeof(int) * G->vexNum);
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = 0;
    }
    int arcs[7][7] = {
        0,12,MAX,MAX,MAX,16,14,
        12,0,10,MAX,MAX,7,MAX,
        MAX,10,0,3,5,6,MAX,
        MAX,MAX,3,0,4,MAX,MAX,
        MAX,MAX,5,4,0,2,8,
        16,7,6,MAX,2,0,9,
        14,MAX,MAX,MAX,8,9,0
    };
    createGraph(G, "1234567", (int*)arcs);
    DFS(G, visited, 0);
    printf("\n");
    dijkstra(G, 0);
    return 0;
}