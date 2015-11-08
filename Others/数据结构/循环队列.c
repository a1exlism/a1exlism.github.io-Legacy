/*
	K阶斐波那契数列,循环队列实现
*/
#include <stdio.h>
#include <stdlib.h>
#define K 100
//--------结构体定义-----------
typedef struct sQueue{
	int	*base;
	int	front;
	int	rear;
}sQueue;	
//--------初始化----------
int initQueue(sQueue &Q){
	Q.base = (int *)malloc(sizeof(int) * K );
	if( !Q.base)
		return 0;
	Q.front = Q.rear = 0;//位置初始化
	return 1;
}
//--------添加成员---------
int addQueue(sQueue &Q , int newNum ){
	// if( (Q.rear + 1 ) % K == Q.front )
	// 	return 0;	这道题目需要覆盖,不用判断队列是否已满
	Q.base[Q.rear] = newNum	;	//这里不清楚
	Q.rear = ( Q.rear + 1) % K ;
	return 1;
}
int bigger( int &f1 ,int &f2){	//需要改变f1 f2的值 添加&
	if( f1 < f2 ){
		f1 += f2;
		return f1;
	}else{
		f2 += f1;
		return f2;
	}
}	//计算每次新得出来的数字
int main(){
	int max;
	int i = sum = f1 = 0;
	int f2 =1;			//f1 f2 var
	printf("请输入最大值MAX:\n");
	scanf("%d", &max );
	sQueue Queue;	
	initQueue( &Queue );
	while( sum <= max ){
		bigger( f1 , f2);
		addQueue( &Queue , f1>f2?f1:f2);
		sum += Queue.base[front]; 
		//判断大小
		if( (sum + bigger( f1 , f2) > max){
			addQueue( &Queue , f1>f2?f1:f2);
			//添加队列 跳出循环
			break;
		}
	}
	return 0;
}