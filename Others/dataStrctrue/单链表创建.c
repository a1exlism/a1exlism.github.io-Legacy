#include "stdio.h"
#include "stdlib.h"
typedef struct node 	//结构名为node
{
	char name[20];
	struct node *next;
}node,*Lnode;	//结构体变量
Lnode create(int num){		//返回指针
	Lnode newNode,head,tmpNode;
	int i;
	head = (Lnode)malloc(sizeof(node));
	if(!head)
		exit(0);
//-----定义头指针------
	head->name[0] = '\0';	//第一个head不输出
	head->next = NULL;
//-----地址1---------
	newNode = head;
	for( i = 0;i < num;i++){
//-----初始化---------
		if(!(tmpNode = (Lnode)malloc(sizeof(node))))
			exit(0);
		scanf("%s",tmpNode->name);
		tmpNode->next = NULL;

//-----tmpNode为地址2--------
		newNode->next = tmpNode ;

//-----地址复制使head指向newNode-------
		newNode = tmpNode;

//----不能忘了释放指针内存---------
		tmpNode = NULL;
		free(tmpNode);
//-------------------
	}
	return head;
}
int main(){
	int num;
	Lnode head;
	scanf("%d",&num);
	head = create(num);
	int i = 0;
	printf("OutPut:\n");
	for(i = 0;i < num+1;i++){
		printf("%s\n",head->name);
		head = head->next;
	}
	return 0;
}