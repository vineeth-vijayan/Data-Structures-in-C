#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct CirQueue{
	struct CirQueue *prev, *next;
	int val;
};

struct CirQueue *front = NULL;
struct CirQueue *rear = NULL;

bool isEmpty(){
	return front==NULL && rear==NULL;
}

void enqueue(int v){
	struct CirQueue *cq = (struct CirQueue*)malloc(sizeof(struct CirQueue));
	cq->val = v;
	if(!isEmpty()){
		cq->next = rear->next;
		rear->next = cq;
		cq->prev = rear;
		rear = cq;
	}
	else{
		cq->prev = NULL;
		cq->next = NULL;
		front = cq;
		rear = cq;
	}
}

void dequeue(){
	if(!isEmpty()){
		int v = front->val;
		if(front==rear){
			front = NULL;
			rear =NULL;
		}
		else{
			front->next->prev = rear;
			rear->next = front->next;
			front = front->next;
		}
		printf("\tDequeue: %d\n", v);
	}
	else{
		printf("\tQueue is Empty!!\n");
	}
}

void Front(){
	if(!isEmpty())
		printf("\tFront: %d\n", front->val);
	else
		printf("\tQueue is Empty!!\n");
}

void Rear(){
	if(!isEmpty())
		printf("\tRear: %d\n", rear->val);
	else
		printf("\tQueue is Empty!!\n");
}

int main(){
	int v, ch;
	do{
		printf("\nEnter your choice: \n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. isEmpty\n6. isFull\n7. Exit\n::");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter a value: ");
				scanf("%d", &v);
				enqueue(v);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				Front();
				break;
			case 4:
				Rear();
				break;
			case 5:
				if(isEmpty())
					printf("\tQueue is Empty!!\n");
				else
					printf("\tQueue is not Empty!!\n");
				break;
			case 6:
				//if(isFull())
				//	printf("\tQueue is Full!!\n");
				//else
				//	printf("\tQueue is not Full!!\n");
				break;
			case 7:
				printf("\tExit!!\n");
				break;
			default:
				printf("\tTry Again!!\n");
		}
	}while(ch!=7);

	return 0;
}
