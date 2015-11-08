/* Filename:Queue.h */

typedef struct {
	ElemType *base;

	int front;

	int rear;

	Status tag;

	int MaxSize;
}DQueue;

Status InitDQueue( DQueue & q, int size )

{
	q.MaxSize = size;

	q.base = new ElemType[q.MaxSize];

	if ( !q.base )
		return(FALSE);

	q.front = 0;

	q.rear = 0;

	q.tag = 0;

	return(OK);
}


Status EnDQueue( DQueue & q, ElemType e )

{
	if ( q.front == q.rear && q.tag )
		return(FALSE);

	if ( q.front == q.rear && !q.tag ) /* 空队列 */

	{
		q.base[q.rear] = e;

		q.rear = (q.rear + 1) % q.MaxSize;

		if ( q.rear == q.front )
			q.tag = 1;
	}else  { /* 非空非满 */
		if ( e < (q.base[q.front] + q.base[(q.rear + q.MaxSize - 1) % q.MaxSize]) / 2 )
		{
/* 从队头入队 */

			q.front = (q.front + q.MaxSize - 1) % q.MaxSize;

			q.base[q.front] = e;

			if ( q.rear == q.front )
				q.tag = 1;
		}else  { /* 从队尾入队 */
			q.base[q.rear] = e;

			q.rear = (q.rear + 1) % q.MaxSize;

			if ( q.rear == q.front )
				q.tag = 1;
		}
	}

	return(OK);
}


Status DeDQueue( DQueue & q, ElemType & e )

{
	if ( q.front == q.rear && !q.tag )
		return(FALSE);

	else{   /* 非空队列 */
		e = q.base[q.front];

		q.front = (q.front + 1) % q.MaxSize;

		q.tag = 0;
	}

	return(OK);
}


/* Filename:XT333.cpp 主程序文件 */

#include <iostream.h>

#include <stdlib.h>

typedef int ElemType;

#include "D:\VC99\Queue.h"

int main()

{
	int t1, t2, t3, t4;

	ElemType e;

	cout << "请输入作业a1、a2、a3、a4的执行时间: ";

	cin >> t1 >> t2 >> t3 >> t4;

	DQueue dq;

	InitDQueue( dq, 5 );

	EnDQueue( dq, t1 );

	EnDQueue( dq, t2 );

	EnDQueue( dq, t3 );

	EnDQueue( dq, t4 );

	while ( dq.front != dq.rear || dq.tag )
	{
		DeDQueue( dq, e );

		cout << e << endl;
	}

	return(0);
}