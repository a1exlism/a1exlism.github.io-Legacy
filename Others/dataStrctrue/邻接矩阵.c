#include "stdio.h"
#include "stdlib.h"
#define INFINITY INT_MAX
#define MAX_VErteX_NUM 5
typedef struct ArcCell{
	int adj;
}ArcCell,AdjMatrix[MAX_VErteX_NUM][MAX_VErteX_NUM];

typedef struct {
	int vexs[MAX_VErteX_NUM];	//用来引导行和列
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;

int LocateVex(MGraph &graph,int v);
void InsertVex(MGraph &graph,int v);
void DeleteVex(MGraph &graph,int v);
void InsertArc(MGraph &graph,int v,int w);
void DeleteArc(MGraph &graph,int v,int w);
void CreateGraph(MGraph &graph);
void displayGraph(MGraph &graph);


void CreateGraph(MGraph &graph){
	int i,j;
	printf("Please input vexnum,arcnum:\n");
	scanf("%d %d",&graph.vexnum,&graph.arcnum);
	for(i=0;i<graph.vexnum;i++){
		graph.vexs[i] = 0;
		for(j=0;j<graph.vexnum;j++){
			graph.arcs[i][j] = {0};
		}
	}
	for(i=0;i< graph.arcnum;i++){
		//添加两点之间的关系
		printf("请输入第%d个关系边(v->w格式):\n",i);
		int v,w;
		scanf("%d->%d",&v,&w);
		InsertArc(graph,v,w);
	}
}
void displayGraph(MGraph &graph){
	for(int i = 0;i < graph.vexnum;i++){
		for(int j = 0;i < graph.vexnum;j++){
			printf("%2d",graph.arcs[i][j] );
		}
		printf("\n");
	}
}
int LocateVex(MGraph &graph,int v){
	int i = 0;
	while( i < graph.vexnum ){
		if( graph.i == v ){
			return i;
		}else{
			i++;
		}
	}
	printf("Error\n");
	return 0;
}
void InsertVex(MGraph &graph,int v){	//插入顶点 v > graph.vexnum即多出一行
	graph.vexnum++;
	graph.vexs[vexnum] = v;
}
void DeleteVex(MGraph &graph,int v){	//删除顶点
	int endPos = graph.vexnum-1;
	int currentPos = LocateVex(graph,v);
	int i,j;
	for( i=currentPos;i < graph.vexnum;i++){	//更改列
		for( j=currentPos;j <graph.vexnum;j++){
			graph.arcs[i][j-1] = graph.arcs[i][j];
		}
	}
	for( i=currentPos;i < graph.vexnum;i++){	//更改行
		for( j=currentPos;j <graph.vexnum;j++){
			graph.arcs[i-1][j] = graph.arcs[i][j];
		}
	}
}
void InsertArc(MGraph &graph,int v,int w){	//插入有向边v->w	即增加两个点之间的关系
	graph.arcnum ++;
	int vPos = LocateVex(graph,v);
	int wPos = LocateVex(graph,w);
	graph.arcs[i][j] = 1;
}
void DeleteArc(MGraph &graph,int v,int w){	//删除边
	int vPos = LocateVex(graph,v);
	int wPos = LocateVex(graph,w);
	graph.arcs[i][j] = 1;
	graph.arcnum --;
}
int main(){
	MGraph graph;
	CreateGraph(graph);
	displayGraph(graph);
	InsertVex(graph,3);
	printf("插入点v,vexnum:%d\n",graph.vexnum);
	DeleteVex(graph,2);
	displayGraph(graph);
	DeleteArc(graph,1,2);		//前面设置了1->2的边
	displayGraph(graph);
}
