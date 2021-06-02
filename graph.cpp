#include<stdio.h>

#define MAX 11

typedef enum vstate{UNDISCOVER,DISCOVER,VISITED} Vstatus;
typedef enum estate{UNDETERMINDER,TREE,CROSS,FORWORD,BACKWORD} Estatus;


typedef struct vertex //一个存储int的顶点
{
    int data;
    Vstatus vs;
    int degree,inDegree,outDegree;

}Vertex;

typedef struct edge//边
{
    int hasEdge;
    Estatus es;
    int preVertex,tailVertex;
    int weight; //权重
}Edge;

//用数组来表示顶点个数，有其局限性
typedef struct graph //图的邻接矩阵表示
{
   Vertex v[MAX];
   Edge e[MAX-1][MAX-1]; //二维数组判断是否有边
}Graph;

Graph g;

Graph initGraph(Graph g){ //初始化一个
    
    for (int i = 0; i < MAX-1; i++)
    {
        g.v[i].data=0;
        g.v[i].vs=UNDISCOVER;
    }
    
    g.v[0].data=1;  
    for (int k = 0; k < MAX-1; k++)
    {
        for (int j = 0; j < MAX-1; j++)
        {
            g.e[k][j].hasEdge=0;
            g.e[k][j].es=UNDETERMINDER;
            
        }
        
    }
    g.e[0][0].hasEdge=1;

    printf("the graph is created !\n");
   
    return g;
}

void showGraph(Graph g){//显示图

    printf("show by vertex of graph:\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("number %d:%d  ",i,g.v[i].data);
   
    }
    printf("\n\n");
    printf("display by edge of graph:\n");
    for (int k = 0; k < MAX-1; k++)
    {
        for (int j = 0; j < MAX-1; j++)
        {
            printf("%d  ",g.e[k][j].hasEdge);
        }
        printf("\n");
    }
}

Graph addVertex(Graph g,int n,int data){ 
    g.v[n].data=data;
    g.v[n].vs=UNDISCOVER;
    return g;
}

Graph addEdge(Graph g,int preV,int tailV,int weight){ 
    //先有点，后有线
    g.e[preV][tailV].hasEdge=1;
    g.e[tailV][preV].hasEdge=1;
    g.e[preV][tailV].preVertex=preV;
    g.e[preV][tailV].tailVertex=tailV;
    g.e[preV][tailV].weight=weight;
    g.v[preV].degree++;
    g.v[tailV].degree++;

    return g;
}

void delVertex(Graph g,int n){
    g.v[n].data=0;
    g.v[n].degree=0;
    for (int i = 0; i < MAX-1; i++)
    {
        //删除了点，该点的边也自然删除了
        g.e[i][n].hasEdge=0;
        g.e[i][n].weight=0;
        g.e[i][n].preVertex=0;
        g.e[i][n].tailVertex=0;
        g.e[n][i].hasEdge=0;
        g.e[n][i].weight=0;
        g.e[n][i].preVertex=0;
        g.e[n][i].tailVertex=0;
    }

}

void delEgde(Graph g,int preV,int tailV){
    g.e[preV][tailV].hasEdge=0;
    g.e[tailV][preV].hasEdge=0;
    g.e[preV][tailV].preVertex=0;
    g.e[tailV][preV].preVertex=0;
    g.e[tailV][preV].tailVertex=0;
    g.e[preV][tailV].tailVertex=0;

}


//既然用的是数组大小表示顶点个数
//那么就继续用一个数组表示队列，仍然有其局限性
int Vquene[MAX];
int k=0;

void BFS(Graph g,int n){// 广度优先遍历

    if(g.v[n].vs==UNDISCOVER||g.v[n].vs==DISCOVER){
        g.v[n].vs=VISITED;
    }
    for (int i = 0; i <MAX ; i++) //入栈相邻节点
    {
           if(g.e[i][n].hasEdge == 1 && g.v[i].vs==UNDISCOVER){
                g.v[i].vs=VISITED;
                Vquene[k++]=i;
           }
    }
    for (int j = k+1; j < MAX; j++)
    {
        Vquene[j]=-1;
    }
    
    if(Vquene[0]!=-1){
        printf("next node number:%d\n",Vquene[0]);
        int num=Vquene[0];
        for (int p = 0; p <MAX; p++)
        {
            Vquene[p]=Vquene[p+1];
        }
        
        BFS(g,num);
    }


}

int main(){
    Graph gr=initGraph(g);
    Graph gr1=addVertex(gr,3,7);
    Graph gr2=addVertex(gr1,1,6);
    Graph gr3=addEdge(gr2,0,1,1);
    showGraph(gr3);
    BFS(gr3,0);
    while (true)
    {
    }
    
    return 0;
}

