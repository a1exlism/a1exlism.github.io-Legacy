#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define Max_Size 20
//----------队列声明------
typedef struct Queue{
	int Tail,Head;
	char data[20];	//数据量为19的一个循环队列
}Queue;
void initQueue(Queue &queue){	//队列初始化
	queue.Tail = queue.Head = 0;
}
int EnQueue(Queue &queue,char ch){		//入队列
	queue.data[queue.Tail] = ch;
	queue.Tail = (queue.Tail + 1) % 20;
	return abs(queue.Tail - queue.Head) % 20;	//返回长度
}
int DeQueue(Queue &queue){		//出队列
	char ch;
	ch = queue.data[queue.Head];
	queue.Head = (queue.Head + 1) % 10;
	return ch;
}
//----------队列声明------

typedef struct CTNode{		//右边,孩子链表结构
	int childPos;
	struct CTNode *next;
}CTNode,*childPTr;
typedef struct CTBox{		//self 单元
	char data;
	childPTr firstChild;
}CTBox;
typedef struct CTree{
	int rootPos,num;
	CTBox nodes[Max_Size];
}CTree;
int isHere(CTree &tree,char ch){	//判断数组中的data是否已存在
	int i = 0;
	for(;i < tree.num; i++){
		if(tree.nodes[i].data == ch)
			return 1;
	}
	return 0;
}
int getPos(CTree &tree,char ch){	//获取数组位置
	int i = 0;
	while( i < tree.num){
		if( tree.nodes[i].data == ch)
			return i;
		else
			i++;
	}
}
childPTr insertNode(childPTr node,int pos){		//单链表添加
	childPTr newNode = (childPTr)malloc(sizeof(CTNode));
	newNode -> next = NULL;
	newNode -> childPos = pos;
	while( node -> next ){	//CTNode 类型,注意
		node = node -> next;
	}		//步入最底

	node -> next = newNode;
}
void createTree(CTree &tree){		//树的创建
	char tmpStr[4];
	tree.num = 1;
	tree.nodes[0].data = 'R';
	tree.nodes[0].firstChild->next = NULL;
	int position, i;
	tree.rootPos = position = i = 0;
	while(scanf("%s",tmpStr) && strlen(tmpStr) == 2){
		//printf("成功\n");
		while( i < 2){
			if(isHere(tree,tmpStr[i])){
				position = getPos(tree,tmpStr[i++]);
				printf("1111\n",i);
				continue;
			}
			else{		//第二个输入点进行链表插入动作
				printf("2222\n");
				//tree.nodes[position].firstChild =
				insertNode(tree.nodes[position].firstChild,tree.num);
				tree.nodes[tree.num].firstChild -> next = NULL;
				tree.nodes[tree.num++].data = tmpStr[i];
				i++;
			}
		}
		i = 0;
	}
}
void travelTree(CTree tree){		//树的遍历

}
int main(){
	CTree tree;
	Queue group;
	initQueue(group);
	createTree(tree);
	travelTree(tree);
	return 0;
}
