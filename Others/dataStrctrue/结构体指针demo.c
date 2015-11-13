#include "stdio.h"
#include "stdlib.h"
typedef struct
{
	char name[20];
}node,*Lnode;
int main(){
	Lnode a;
	a = (Lnode)malloc(sizeof(node));
	scanf("%s",a->name);    //首地址
	printf("%s\n",a->name );
}
