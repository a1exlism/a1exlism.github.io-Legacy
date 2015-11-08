int Fibonacci( int k, int n )

{
	if ( k < 1 )
		exit( OVERFLOW );

	Queue q;                /* 定义队列 */

	InitQueue( q, k );      /* 初始化队列 */

	ElemType x, e;

	int i = 0;

	while ( i <= n )
	{
		if ( i < k - 1 )
		{
			if ( !EnQueue( q, 0 ) )
				exit( OVERFLOW );
		}

		if ( i == k - 1 )
		{
			if ( !EnQueue( q, 1 ) )
				exit( OVERFLOW );
		}

		if ( i >= k )
		{
/* 队列求和 */

			x = sum( q );

			DeQueue( q, e );

			EnQueue( q, x );
		}

		i++;
	}

	return(q.base[(q.rear + q.MaxSize - 1) % q.MaxSize]);
}