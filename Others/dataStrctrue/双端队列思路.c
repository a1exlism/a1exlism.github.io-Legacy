typedef struct qnode 
{ 
DataType data; 
struct qnode *next; 
}LQNode; 

typedef struct {  
LQNode  *front; 
LQNode  *rear; 
}LQueue; 