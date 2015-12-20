#include "stdio.h"
#include "stdlib.h"
typedef char elemType;
//----基本节点
typedef struct node{
	elemType data;
	struct node *next;
}node,*pNode;
//------基本栈
typedef struct  stack{
	int size;
	pNode	top;		//读到后面了解了top就是root节点
	//链接节点,top结构体指针可以指向结构体内容
}stack,*pStack;
//------创建空栈
pStack createStack(){
	pStack S;
	S = (pStack)malloc(sizeof(stack));
	if( S != NULL ){
		S -> top = NULL;
		S -> size = 0;
	}
	return S;
}
//------入栈
pStack pushStack(pStack S , elemType data){
	pNode tmpNode;
	tmpNode = (pNode)malloc(sizeof(node));
	if( tmpNode == NULL ){
		printf("内存分配失败\n");
		exit( 0 );
	}else{
		tmpNode -> data = data;
		tmpNode -> next = NULL;
		S -> top = tmpNode;
		S -> size ++;		//不清楚所说的size
		//tmpNode = NULL??清空试试看?
	}
	return S;
}
//------出栈
elemType popStack(pStack S){
	elemType data;
	data = S -> top -> data;
	S -> top = S -> top -> next;
	S -> size -- ;
	return data;
}
//-----遍历栈,并存储数据
void traverseStack(pStack S){
	pStack tmpStack = S;
	int length = S -> size;
	elemType storeArr[length];
	int i = 0;
	while( i ++ < length){
		storeArr[i] = tmpStack -> top -> data;
		printf("第%d个数据为:%c\n",i,storeArr[i-1] );
		tmpStack -> top = tmpStack -> top -> next;
	}

	free( tmpStack );
	tmpStack = NULL;
}
//-----清空链栈
void clearStack( pStack S ){
	if( !S -> top)
		printf("Already empty!\n");
	else{
		//创建一个遍历指针
		pNode tmpNode;
		tmpNode = (pNode)malloc(sizeof(node));
		tmpNode = S -> top;
		while( S -> size -- > 0 ){
			S -> top = tmpNode -> next;
			S -> size --;
			free( tmpNode );
			tmpNode = S -> top;
		}
	}
}
int main(){
	pStack Xstack;
	Xstack = createStack();
	int i,out;
	for( i = 0 ;i < 5 ; i++){
    		pushStack( Xstack,'a'+i );
    	}
    	for( i = 0; i < 5; i++ ){
		out =popStack(Xstack);
		printf("出栈的数据为:%c\n",out );
	}
}
