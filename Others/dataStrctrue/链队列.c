//队尾指向NULL
#include <stdio.h>
#include <stdlib.h>
typedef struct QNode
{
	Elemtype data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct 
{
	 QueuePtr *front;
	 QueuePtr *rear;	
}LinkQueue;
int InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QueuePtr)molloc(sizeof(QNode));	//分配了一个存储空间和两个指针空间
	if( !Q.front )
		return 0;
	Q.front->next = NULL;
	Q.rear->next = NULL;
	return 1;
}
int EnQueue(LinkQueue &Q, Elemtype e){
	//先分配一个空间
	QueuePtr tmp;	//tmp为指针类型
	tmp = (QueuePtr)molloc( sizeof(QNode) );
	if( !tmp )
		return 0;
//-------初始化
	tmp->data = e;
	tmp->next = NULL;
//--------
	Q.rear -> next = tmp;	//进行连接
	Q.rear = tmp;		//tmp为新的rear指针 原来的指针好像并没有释放
	return 1;
}
int DeQueue(LinkQueue &Q , Elemtype e){
	
}