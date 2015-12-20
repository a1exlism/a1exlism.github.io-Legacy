#include "stdio.h"
#include "stdlib.h"
typedef Queue{
	int Tail,Head;
	char data[20];	//数据量为19的一个循环队列
}Queue;
void initQueue(Queue &queue){	//队列初始化
	queue.Tail = queue.Head = 0;
	queue.data = 0;
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