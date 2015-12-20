/*
			邻接表结构
		--------------------------
		|vex1|arc1-arc2-NULL
		|vex2|NULL
		|vex3|arc1-arc2-NULL
		--------------------------
*/
//依次输入 顶vex点数,弧arc数目,顶点信息和弧的信息建立图
#include "stdio.h"
#include "stdlib.h"
#define MAX_VERTEX_NUM 20
typedef char VertexType;

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

int LocateVex(ALGraph graph,VertexType vex){
	for(int i = 0;i < graph.vexnum;i++){
		if(graph.vertices[i].data == vex){
			return i;
		}
	}
	printf("Error,Not Found the Vex\n");
	return 0;
}
void CreateGraph( ALGraph &graph ){
	printf("Print vexnum&arcnum:\n");
	scanf("%d,%d",&graph.vexnum,&graph.arcnum);
	while(getchar()!='\n');//覆盖回车
	int i;
	for(i = 0;i < graph.vexnum;i++){	//添加顶点信息
	    printf("The %d Vex:\n",i+1);
		scanf("%c",&graph.vertices[i].data);
		while(getchar()!='\n');//覆盖回车
		graph.vertices[i].firstarc = NULL;
	}
	//邻接表利用数组遍历LocateVex()获取地址(数组下标)
	printf("In order print the relationship between two vex(format: v1,v2):\n");

	//-------单链表节点添加-----重点----------
	for(i = 0;i < graph.arcnum;i ++){
        VertexType v1,v2;
        printf("The %d arc:\n",i+1);
        scanf("%c %c",&v1,&v2);
		while(getchar()!='\n');
    	int startPos,endPos;
        startPos = LocateVex(graph,v1);
        endPos = LocateVex(graph,v2);

		ArcNode *p,*q;	//p为添加的节点,q作为节点指针进行跳跃
		//-----创建新的单链表节点-----
		p = new ArcNode;
		p->nextarc = NULL;
		p->adjvex = endPos;
		//-----节点插入-----
		q = new ArcNode;
		q = graph.vertices[startPos].firstarc;
		if( q == NULL ){
			graph.vertices[startPos].firstarc = p;
		}else{
			while( q->nextarc != NULL){
			//q != NULL之所以是错的原因是因为q本身是一个地址,肯定会存在值,尝试使用*q可能可以成功
				q = q->nextarc;
			}
			//此时q->nextarc指向NULL,即已经在链尾
			q->nextarc = p;
		}
	}
}
void displayGraph(ALGraph &graph){
	//创建一个遍历链表的指针
	ArcNode *traverseNode;
    traverseNode = new ArcNode;
    traverseNode -> nextarc = NULL;
    printf("\n遍历状态:\n");
	for(int i = 0;i < graph.vexnum;i++){

		printf("%c ",graph.vertices[i].data );	//Vex
		traverseNode = graph.vertices[i].firstarc;
		while( traverseNode ){	//Vex->arc
			printf("%c ",graph.vertices[traverseNode->adjvex].data);
			traverseNode = traverseNode->nextarc;
		}
		printf("\n");
	}
}
int main(){
	ALGraph graph;
	CreateGraph( graph );
	displayGraph(graph);
	return 0;
}
/* 总结:死在判断链尾的状态上:Line92 Line74 && 单链表连接*/
/*
测试数据
4,4
a
b
c
d
a b
a c
c d
d a
