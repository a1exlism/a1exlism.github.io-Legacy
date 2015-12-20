#include "stdio.h"
#include "stdlib.h"
#define END 0
typedef struct binNode{
	struct binNode *lChild,*rChild;
	char data;
}binNode,*binTree;
//-----先序创建创建二叉树------
binTree createNode( binTree tree){
	char tmp;
	tmp = getchar();
	if( tmp == '#' )
		tree = NULL;	//如果遇到标记,则创建的节点指向NULL
	else{	//申请并赋值
		tree = (binTree)malloc(sizeof(binNode));
		tree -> data = tmp;
		tree -> lChild = createNode( tree -> lChild );
		tree -> rChild = createNode( tree -> rChild );
	}
	return tree;
}
//--------二叉树输出Start--------
int preOrder( binTree tree ){
	if( tree ){
		printf("%c", tree->data );
		preOrder( tree -> lChild );
		preOrder( tree -> rChild );
	}
	return END;	//成为子叶,退出栈
}
int inOrder( binTree tree ){
	if( tree ){
		inOrder( tree -> lChild );
		printf("%c",tree -> data );
		inOrder( tree -> rChild );
	}else
	return END;
}
int postOrder( binTree tree ){
	if( tree ){
		postOrder( tree -> lChild );	//左节点跑完弹出栈就会往右
		postOrder( tree -> rChild );
		printf("%c",tree -> data );
	}else
	return END;
}
//----------END--------------
int main(){
	//a#bc##de###
	binTree tree;
	tree = createNode( tree );
	//先序 preOrder( tree );
	printf("中序\n");
	inOrder( tree );
	printf("\n后序\n");
	postOrder( tree );
	return 0;
}
