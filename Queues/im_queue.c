#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Queue{
	int front, rear;
	int size;
	int *ar;
};

struct Queue* createQueue(int size){
	struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
	if(!q)
		return NULL;
	q->size = size;
	q->front = -1;
	q->rear = -1;
	q->ar = (int*) malloc(size*sizeof(int));

	return q;
}

bool isempty(struct Queue* q){
	return q->front==-1 && q->rear==-1;
}

bool isfull(struct Queue* q){
	return (q->rear+1)%q->size == q->front;
}


void enqueue(struct Queue *q){
	if(!isfull(q)){
		int num;
		printf("Enter num to enter into the queue: ");
		scanf("%d", &num);
		q->ar[(++q->rear)%q->size] = num;
		if(q->front==-1)
			q->front++;
		printf("\tEnqueued!!\n");
	}
	else
		printf("\tQueue is Full!!\n");
}

void dequeue(struct Queue *q){
	if(!isempty(q)){
		printf("\tDequeue: %d", q->ar[q->front]);
		if(q->front==q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else
			q->front = (q->front+1)%q->size;
	}
	else
		printf("\tQueue is Empty!!\n");
}

void show_front(struct Queue *q){
	if(isempty(q))
		printf("\tQueue is Empty!!\n");
	else
		printf("\tFront: %d\n", q->ar[q->front]);
}

void show_rear(struct Queue *q){
	if(isempty(q))
		printf("\tQueue is Empty!!\n");
	else
		printf("\tRear: %d\n", q->ar[q->rear]);
}

int main(){
	int *ar;
	int size, ch;
	printf("Enter size of Queue: ");
	scanf("%d", &size);
	struct Queue* a = createQueue(size);

	do{
		printf("\nEnter your choice: \n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. isEmpty\n6. isFull\n7. Exit\n::");
		scanf("%d", &ch);

		switch(ch){
			case 1:
				enqueue(a);
				break;
			case 2:
				dequeue(a);
				break;
			case 3:
				show_front(a);
				break;
			case 4:
				show_rear(a);
				break;
			case 5:
				if(isempty(a))
					printf("\tQueue is Empty!!\n");
				else
					printf("\tQueue is not Empty!!\n");
				break;
			case 6:
				if(isfull(a))
					printf("\tQueue is Full!!\n");
				else
					printf("\tQueue is not Full!!\n");
				break;
			case 7:
				printf("\tExit!!\n");
				break;
			default:
				printf("\tTry again!!\n");
		}
	}while(ch!=7);

	return 0;
}
