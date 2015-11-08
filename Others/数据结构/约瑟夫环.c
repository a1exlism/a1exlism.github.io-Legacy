#include "stdio.h"
#include "stdlib.h"
typedef struct node{
	int cipher;
	int No;
	struct node *next;
}node,*List;
//-------创建链表-----
List createList(int num){		//返回头指针
	List headNode,newNode,tmpNode;
	if(!(headNode = (List)malloc(sizeof(node))))
		exit(0);
	headNode->cipher = 0;
	headNode->No = 1;
	headNode->next = NULL;		//初始化头结点
	if(num == 1)	//一个人
		return headNode;
	int i = 0;
	newNode = headNode;
	for(i = 0;i < num-1;i++){
		if(!(tmpNode = (List)malloc(sizeof(node))))
			exit(0);
		tmpNode->cipher = 0;
		tmpNode->No = i+2;
		tmpNode->next = NULL;
		newNode->next = tmpNode;		//这句话自己有过错误,顺序问题
		newNode = tmpNode;			//也就是newNode = newNode->next;递进
		tmpNode = NULL;
		free(tmpNode);
	}
    newNode->next = headNode;
	return headNode;
}			//创建空链表


//-------删除节点---------
int deleteNode(List node,int cipher){
	List tmpNode;
	if(!(tmpNode = (List)malloc(sizeof(node))))
		exit(0);
	cipher = node->next->cipher;    //存储,待会儿返回
	//好像没法释放原来的node->next节点
	tmpNode = node->next;	//tmpNode存储被删除的节点地址
	printf("输出编号:%d\n",tmpNode->No);
	node->next = tmpNode->next;	//更换指针域
	tmpNode->next = NULL;
	free(tmpNode);	//释放结构体
	printf("----看看有没有删除---:%d\n",node->next->cipher);
   return cipher;
}


int main(){
	int cipher,num,No,i = 0;
	List headNode,tmpNode;
	printf("请输入cipher初始值:\n");
	scanf("%d",&cipher);
	printf("请输入参加人数:\n");
	scanf("%d",&num);
	headNode = createList(num);
	printf("请输入他们各自的密码:\n");
	tmpNode = headNode;
	while( i < num){
		printf("第%d个的密码:\n", i+1);
		scanf("%d",&tmpNode->cipher);
		tmpNode = tmpNode->next;
		i++;
	}


	//----剔除----
	 while( num > 1 ){
	 	for( i = 1;i < cipher;i++){
	 		headNode = headNode->next;  //移动cipher-1次使headnode为被删除节点的前一个
	 	}
	 	cipher = deleteNode( headNode,cipher ); //返回删除之后新的cipher
	 	headNode = headNode->next;
	 	num --;
	 }
   printf("弹出编号:%d\n",headNode->No);
	return 0;
}
