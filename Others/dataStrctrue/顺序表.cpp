/*
顺序表是在计算机内存中以数组的形式保存的线性表,
是指用一组地址连续的存储单元依次存储数据元素的线性结构
*/
#include "stdio.h"
#include "stdlib.h"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef char ElemType;

typedef struct {
	ElemType *elem;
	int length;	//当前容量
	int listsize;	//总容量
}SqList;

void InitList_Sq( SqList &L ){
	L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);//基地址
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

void DestroyList(SqList &L){
	//---------------
	free(L.elem);	//指向的内存块被标记可用
	L.elem = NULL;
	//---------------
	L.length = 0;
	L.listsize = 0;
}

void ClearList( SqList &L ){
	L.length = 0;//置空
}

int LocateElem(SqList &L,ElemType e){
	ElemType *p;
	p = L.elem;
	int i = 1;
	while( *(p++) != e && i <= L.length ){
		i++;
	}
	if( i <= L.length){
		return i;
	}else{
		printf("404 Not Found!\n");
		return 0;
	}
}

void InsertList( SqList &L,int pos,ElemType e ){
	if( pos > L.length+1 || pos < 1 ){	//第一个判断表示内存的连续性
		printf("Param ilegal\n");
		exit( 0 );
	}
	ElemType *movingP,*insertP;
	if( L.length >= L.listsize ){
		ElemType *newbase;
		newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		L.elem = newbase;
		L.listsize+=LISTINCREMENT;
	}

	insertP = L.elem + pos -1;
	movingP = L.elem+L.length;
	while( movingP >= insertP ){	//为insertP腾出空位
		*(movingP+1) = *movingP;
		movingP --;
	}

	*insertP = e;
	L.length++;
}

void TraverseList( SqList &L ){
	ElemType *position;
	for(position = L.elem;position<L.elem+L.length;position++){
		printf("%c\n", *position );
	}
}

int main(){
	SqList list;
	int location = 0;
	InitList_Sq( list );
	InsertList( list,1,'a');
	location = LocateElem( list, 'a');
	printf("Location 'a' is :\n",Location);
	TraverseList( list );
	return 0;
}
