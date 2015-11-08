#include "stdio.h"
#include "stdlib.h"
typedef struct node
{
	int data;
	struct node *next;
}node;
void create( node *Lnode){
	Lnode = (node *)malloc(sizeof(node));
	Lnode->data = 1;
	Lnode->next = NULL;
}
int main(){
	node *head;
	//创建一个链表节点好了	
	create(head);
	return 0;
}