1.使用数组实现队列
queue.h
typedef int ElementType;
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
struct QueueRecord;
typedef struct QueueRecord *Queue;
int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
#endif // QUEUE_H_INCLUDED
fatal.h#ifndef FATAL_H_INCLUDED
#define FATAL_H_INCLUDED
#include 
#include 
#define Error(Str)　　　　　　　　FatalError(Str)
#define FatalError(Str)　　 fprintf(stderr, "%sn", Str), exit(1)
#endif // FATAL_H_INCLUDED
queue.c
#include "queue.h"
#include "fatal.h"
#define MinQueueSize 5
struct QueueRecord
{
　　　　int Capacity;
　　　　int Front;//指向队头元素
　　　　int Rear;//指向队尾元素
　　　　int Size;
　　　　ElementType *Array;
};
int IsEmpty(Queue Q)
{
　　　　return Q->Size == 0;
}
int IsFull(Queue Q)
{
　　　　return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
　　　　Queue Q;
　　　　if(MaxElements < MinQueueSize)
　　　　　　　　Error("Queue size is too small");
　　　　Q = malloc(sizeof(struct QueueRecord));
　　　　if(Q == NULL)
　　　　　　　　FatalError("Out of space!!!");
　　　　Q->Array = malloc(sizeof(ElementType) * MaxElements);
　　　　if(Q->Array == NULL)
　　　　　　　　FatalError( "Out of space!!!" );
　　　　Q->Capacity = MaxElements;
　　　　MakeEmpty(Q);
　　　　return Q;
}
void MakeEmpty(Queue Q)
{
　　　　Q->Size = 0;
　　　　Q->Front = 1;
　　　　Q->Rear = 0;
}
void DisposeQueue(Queue Q)
{
　　　　if(Q != NULL)
　　　　{
　　　　　　　　free(Q->Array);
　　　　　　　　free(Q);
　　　　}
}
static int Succ(int Value, Queue Q)
{
　　　　if(++Value == Q->Capacity)
　　　　　　　　Value = 0;
　　　　return Value;
}
void Enqueue(ElementType X, Queue Q)
{
　　　　if(IsFull(Q))
　　　　　　　　Error("Full queue");
　　　　else
　　　　{
　　　　　　　　Q->Size++;
　　　　　　　　Q->Rear = Succ(Q->Rear, Q);
　　　　　　　　Q->Array[Q->Rear] = X;
　　　　}
}
ElementType Front(Queue Q)
{
　　　　if(!IsEmpty(Q))
　　　　　　　　return Q->Array[Q->Front];
　　　　Error("Empty queue");
　　　　return 0;　　/* Return value used to avoid warning */
}
void Dequeue(Queue Q)
{
　　　　if(IsEmpty(Q))
　　　　　　　　Error( "Empty queue" );
　　　　else
　　　　{
　　　　　　　　Q->Size--;
　　　　　　　　Q->Front = Succ(Q->Front, Q);
　　　　}
}
ElementType FrontAndDequeue(Queue Q)
{
　　　　ElementType X = 0;
　　　　if(IsEmpty(Q))
　　　　　　　　Error("Empty queue");
　　　　else
　　　　{
　　　　　　　　Q->Size--;
　　　　　　　　X = Q->Array[Q->Front];
　　　　　　　　Q->Front = Succ(Q->Front, Q);
　　　　}
　　　　return X;
}
2.使用数组实现双端队列
deque.h
#define DEQUE_H_INCLUDED
struct QueueRecord;
typedef struct QueueRecord *Queue;
int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
ElementType Front(Queue Q);//取队头元素
void Push(ElementType X, Queue Q);//在队头执行入队操作
void Pop(Queue Q);//在队头执行出队操作
ElementType FrontAndPop(Queue Q);//出队并取队头元素
ElementType Rear(Queue Q);//取队尾元素
void Inject(ElementType X, Queue Q);//在对尾执行入队操作
void Eject(Queue Q);//在队尾执行出队操作
ElementType RearAndEject(Queue Q);//出队并取队尾元素
#endif // DEQUE_H_INCLUDED
deque.c
#include "deque.h"
#include "../lib/fatal.h"
#define MinQueueSize 5
struct QueueRecord
{
　　　　int Capacity;
　　　　int Front;//指向队头元素
　　　　int Rear;//指向队尾元素
　　　　int Size;
　　　　ElementType *Array;
};
int IsEmpty(Queue Q)
{
　　　　return Q->Size == 0;
}
int IsFull(Queue Q)
{
　　　　return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
　　　　Queue Q;
　　　　if(MaxElements < MinQueueSize)
　　　　　　　　Error("Queue size is too small");
　　　　Q = malloc(sizeof(struct QueueRecord));
　　　　if(Q == NULL)
　　　　　　　　FatalError("Out of space!!!");
　　　　Q->Array = malloc(sizeof(ElementType) * MaxElements);
　　　　if(Q->Array == NULL)
　　　　　　　　FatalError( "Out of space!!!" );
　　　　Q->Capacity = MaxElements;
　　　　MakeEmpty(Q);
　　　　return Q;
}
void MakeEmpty(Queue Q)
{
　　　　Q->Size = 0;
　　　　Q->Front = 1;
　　　　Q->Rear = 0;
}
void DisposeQueue(Queue Q)
{
　　　　if(Q != NULL)
　　　　{
　　　　　　　　free(Q->Array);
　　　　　　　　free(Q);
　　　　}
}
static int Succ(int Value, Queue Q)
{
　　　　if(++Value == Q->Capacity)
　　　　　　　　Value = 0;
　　　　return Value;
}
static int Prev(int Value, Queue Q)
{
　　　　if(--Value == -1)
　　　　　　　　Value = Q->Capacity - 1;
　　　　return Value;
}
/* 取队头元素 */
ElementType Front(Queue Q)
{
　　　　if(!IsEmpty(Q))
　　　　　　　　return Q->Array[Q->Front];
　　　　Error("Empty queue");
　　　　return 0;　　/* Return value used to avoid warning */
}
/* 在队头执行入队操作 */
void Push(ElementType X, Queue Q)
{
　　　　if(IsFull(Q))
　　　　　　　　Error("Full queue");
　　　　else
　　　　{
　　　　　　　　Q->Size++;
　　　　　　　　Q->Front = Prev(Q->Front, Q);
　　　　　　　　Q->Array[Q->Front] = X;
　　　　}
}
/* 在队头执行出队操作 */
void Pop(Queue Q)
{
　　　　if(IsEmpty(Q))
　　　　　　　　Error( "Empty queue" );
　　　　else
　　　　{
　　　　　　　　Q->Size--;
　　　　　　　　Q->Front = Succ(Q->Front, Q);
　　　　}
}
/* 出队并取队头元素 */
ElementType FrontAndPop(Queue Q)
{
　　　　ElementType X = 0;
　　　　if(IsEmpty(Q))
　　　　　　　　Error("Empty queue");
　　　　else
　　　　{
　　　　　　　　Q->Size--;
　　　　　　　　X = Q->Array[Q->Front];
　　　　　　　　Q->Front = Succ(Q->Front, Q);
　　　　}
　　　　return X;
}
/* 取队尾元素 */
ElementType Rear(Queue Q)
{
　　　　if(!IsEmpty(Q))
　　　　　　　　return Q->Array[Q->Rear];
　　　　Error("Empty queue");
　　　　return 0;　　/* Return value used to avoid warning */
}
/* 在队尾执行入队操作 */
void Inject(ElementType X, Queue Q)
{
　　　　if(IsFull(Q))
　　　　　　　　Error("Full queue");
　　　　else
　　　　{
　　　　　　　　Q->Size++;
　　　　　　　　Q->Rear = Succ(Q->Rear, Q);
　　　　　　　　Q->Array[Q->Rear] = X;
　　　　}
}
/* 在队尾执行出队操作 */
void Eject(Queue Q)
{
　　　　if(IsEmpty(Q))
　　　　　　　　Error( "Empty queue" );
　　　　else
　　　　{
　　　　　　　　Q->Size--;
　　　　　　　　Q->Rear = Prev(Q->Rear, Q);
　　　　}
}
/* 出队并取队尾元素 */
ElementType RearAndEject(Queue Q)
{
　　　　ElementType X = 0;
　　　　if(IsEmpty(Q))
　　　　　　　　Error("Empty queue");
　　　　else
　　　　{
　　　　　　　　Q->Size--;
　　　　　　　　X = Q->Array[Q->Rear];
　　　　　　　　Q->Rear = Prev(Q->Rear, Q);
　　　　}
　　　　return X;
}