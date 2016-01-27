#include "stdio.h"
#include "stdlib.h"
typedef struct Node{
	char data;
	struct Node *next;
}Node,*pNode;

pNode InitList(pNode root){
	root = (pNode)malloc(sizeof(Node));
	if( !root )
		printf("Error\n");
	else{
		printf("Root->data:\n");
		scanf("%c",&root->data);
		while(getchar()!='\n');
		root->next = NULL;
	}
}

void AddNode(pNode root){
	pNode newNode,tmpPoint;
	//---Create a new Node---
	newNode = new Node;
	tmpPoint = new Node;
	newNode->next = NULL;
	printf("a new Node data:\n");
	scanf("%c",&newNode->data);
	//---tmpPoint遍历单链表---
	//tmpPoint = root->next;这么写导致tmpPoint成为一个空指针
	tmpPoint = root;
	if( tmpPoint->next == NULL ){
		root->next = newNode;
	}else{
		while( tmpPoint->next ){
			tmpPoint = tmpPoint->next;
		}
		tmpPoint->next = newNode;
	}
}

void DisplayList(pNode root){
	pNode tmpPoint;
	while( tmpPoint ){
		printf("---%c---\n", tmpPoint->data);
		tmpPoint = tmpPoint->next;
	}
}

int main(){
	pNode root;
	root = InitList(root);
	AddNode(root);
	DisplayList(root);
	return 0;
}
