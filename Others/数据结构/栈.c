#include <stdio.h>
#include <stdlib.h>
#define initSize 100
#define addSize 10
#define OVERFLOW 0
typdef int elemType;

//-----顺序栈声明-------
typdef	struct{
	elemType *base;
	elemType *top;
	int stackSize;
}stack;	//栈顶/栈基指针
//------创建新栈-----
int initStack (stack &S){
	S->base = (elemType *)malloc(initStack * sizeof(elemType));
	if(!S->base)
		exit(OVERFLOW);
	S->top = S->base;	//指针初始化
	S->stackSize = initSize;	//基本容量
	return 1;
}
//-------获取栈顶指针----
int getTop(stack S,elemType &e){//stack S 不需要改变数值
	if(S.top == S.base)
		return 0;
	e = S.top -1;
		return 1;
} 

//-------插入栈顶元素push----
int push(stack &S,elemType e){
	if(S->top-S->base >=stackSize){	//栈满情况
		S->base = (elemType*)realloc(S->base,(S->stackSize+addSize * sizeof(elemType));
		if(!S->base)
			return OVERFLOW;
		S->top = S->base + S->stackSize;
		S->stackSize += addSize;
	}
	*S->top++ = e;	//存储数据
	return 1;
}
/*
*	-- ++优先于*
*/
//------删除栈顶元素pop-----
int pop(stack &S){
	if(S->top == S->base)
		return 0;
	e = *S->top--;
		return 1;
}













int main(){

	return 0;
}