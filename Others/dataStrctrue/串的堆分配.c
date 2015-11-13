#include "stdio.h"
#include "stdlib.h"
#define MaxSize 255
typedef struct{
	char *ch;		//定义一个首地址
	int length;
}HString,*pHString;
void InitString( pHString ch){
	char str[MaxSize];
	gets( str );
	int i ;
	while( str[i] != '\0'){
		i ++;	//i为length
	}
	ch -> ch = (char *)malloc(sizeof(char) * i);
	if ( ch->ch == NULL)
		exit( 0 );
	int j = 0;
	while( j < i){
		ch -> ch[j] = str[j];
		j++;
	}
}
int Concat( pHString T , HString a, HString b){
	if( T -> ch)
		free( T->ch);	//空字符串
	if( !( T = (pHString)molloc(sizeof(Hstring) * (a.length + b.length))))
		exit( 0 );
	T-> length = a.length + b.length ;
	int i = 0;
	while( i < a.length ){
		T -> ch[i] = a.ch[i];
		i ++ ;
	} 
	int j = 0;
	while( j < b.length ){
		T -> ch[i] = b -> ch[j];
		i ++ ;
		j ++ ;
	}
	return 1;
}
int main(){
	pHString s1,s2,sn;	
	printf("请输入第一个字符串\n");
	InitString( &s1 );
	printf("请输入第二个字符串\n");
	InitString( &s2);
	Concat( &sn , s1, s2);
	printf("合并之后的字符串:\n%s\n", sn->ch );
	return 0 ;
}