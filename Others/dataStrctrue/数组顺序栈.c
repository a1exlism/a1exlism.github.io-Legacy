//==========数组构成的顺序栈============//
#include "stdio.h"
#include "stdlib.h"
typedef char elemType;
typedef struct stack{
	elemType	data[20];
	int top;
}stack,*pStack;

pStack initStack(){
	pStack S;
	S = (pStack)malloc(sizeof(stack));
	if( S ){
		S -> top = 0;	//初始指向0
	}else{
		printf("分配内存失败\n");
		exit( 0 );
	}
	return S;	//返回栈指针
}
//------压栈-------
void pushStack(pStack S,elemType data){
	S -> data[ S -> top ++] = data;
}
//------出栈-------
elemType popStack(pStack S){
	if( S -> top == 0 ){
		printf("栈空\n");
		exit( 0 );
	}else{
		elemType result;
       	S -> top --;
        	result = S -> data[ S -> top ];
		return result ;
	}
}
//------打印-------
void display(pStack S){
	int i = 0;
	if( S -> top == 0 ){
		printf("栈空\n");
		exit ( 0 );
	}
	while( i < S -> top ){
		printf("%c", S -> data[i++]);
	}
}
//------判断回文-------//
int isPalindrome(pStack S){
	elemType seqenceArr[];
	int i = 0;
	while( (seqenceArr[i] = getchar()) == '@' ){
		pushStack( S, seqenceArr[i] );
		i ++;
	}
	popStack( S );	//去掉@
	int length = --i;
	for(i = 0;i < length;i ++){
		if( popStack() != seqenceArr[i] )
			return 0;
	}
	return 1;
		//---main()--//
		if( isPalindrome(pStack S) )
			printf("回文\n");
		else
			printf("不是回文\n");
		//---------//
}
//--------------------------//
int main(){
	pStack Xstack;
	Xstack = initStack();
	int i,out;
	for( i = 0 ;i < 5 ; i++){
    		pushStack( Xstack,'a'+i );
    	}
    	for( i = 0; i < 5; i++ ){
		out =popStack(Xstack);
		printf("出栈的数据为:%c\n",out );
	}

	return 0;
}
