#define Q_SIZE 100
typedef int element;
element queue[Q_SIZE];

void enqueue(int *rear,element item);
int isEmpty(int *front,int rear);
element dequeue(int *front,int rear);
void deleteitem(int *front,int rear);
element peek(int front,int rear);

void  enqueue(int *rear,element item){
	if(*rear == Q_SIZE-1)
	{
		printf("Queue is full\n");
		return;
	}
	queue[++*rear] = item;
}

int isEmpty(int *front,int rear)
{
	if(*front == rear) return 1;
	else return 0;
}

element dequeue(int *front,int rear)
{
	if(*front == rear)
	{
		printf("Queue is empty\n");
		exit(1);
	}	
	else return queue[++*front];
}

void deleteitem(int *front,int rear){
	if(*front == rear){
		printf("Queue is empty\n");
		exit(1);
	}
	else ++*front;
}

element peek(int front,int rear){
	if(front == rear){
		printf("Queue is empty\n");
		exit(1);
	}
	else{
		return queue[front+1];
	}
}