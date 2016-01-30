#include "stdio.h"
#include "stdlib.h"
typedef char elemType;

typedef struct node{
	struct node *next;
	elemType data[20];
}node,*Lnode;

//-----单链表创建---------
Lnode createNode( int num ){	//num个节点	返回根节点
	int i = 1;
	Lnode root;
	root = (Lnode)malloc(sizeof(node));
	root -> next = NULL;
	printf("请输入第1个String:\n" );
	scanf("%s",root -> data);
	if( num == 1)
		return root;
	else{
		Lnode tmpNode,newNode;
		newNode = (Lnode)malloc(sizeof(node));

		newNode = root;	//复制root节点

		for( ;i < num ; i++){
			tmpNode = (Lnode)malloc(sizeof(node));
			printf("请输入第%d个String:\n",i+1);
			scanf("%s", tmpNode -> data );
			tmpNode -> next = NULL;
			//----------
		 	newNode -> next = tmpNode ;
		 	newNode = tmpNode;
			//----------newNode一直进入next
			tmpNode = NULL;
		}
		return root;
	}
}
void putNode( Lnode root ){
	while( root ){
		printf("%s\n",root -> data );
		root = root -> next;
	}
}
int main(){
	Lnode root;
	int number;
	printf("请输入创建节点数:\n");
	scanf("%d",&number);
	root = createNode( number );	//创建两个节点
	int i = 0;

	printf("OutPut:\n");
	putNode( root );
	return 0;
}