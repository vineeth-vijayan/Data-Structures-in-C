#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Pr_Queue{
	int val;
	struct Pr_Queue *next;
};
struct Pr_Queue *front=NULL;
struct Pr_Queue *rear=NULL;

void enqueue(int);
int dequeue();
bool isEmpty();
//bool isFull();
//void Front();
//void Rear();

int main(){
	int ch, val;
	printf("\n***************************\n");
	printf("Elementary Priority Queue: ");
	printf("\n***************************\n\n");
	
	do{
		printf("\nEnter your choice: \n1.Enqueue\n2.Dequeue\n3.Check isEmpty\n4.Exit\n:: ");
		scanf("%d", &ch);

		switch(ch){
			case 1:
				printf("Enter a value to enqueue: ");
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2:
				if(!isEmpty()){
					printf("\tDequeue: %d\n", dequeue());
				}
				else
					printf("\tQueue is empty!!\n");
				break;
			case 3:
				if(!isEmpty())
					printf("\tQueue is not Empty!!\n");
				else
					printf("\tQueue is empty!!\n");
				break;
			case 4:
				printf("\tExit!!\n");
				break;
			default:
				printf("\tTry Again!!\n");
		}
	}while(ch!=4);

	return 0;
}

void enqueue(int v){
	struct Pr_Queue *deq = (struct Pr_Queue *)malloc(sizeof(struct Pr_Queue));
	deq->val = v;
	if(!isEmpty()){
		deq->next =front;
		rear->next = deq;
		rear = deq;
	}
	else{
		deq->next = deq;
		front = deq;
		rear = deq;
	}
}

int dequeue(){
	struct Pr_Queue *high_pr = front, *loop=front, *prev_high=front;
	if(front==rear){
		front = NULL;
		rear = NULL;
	}
	else{
		while(loop->next!=front){
			if(loop->next->val < high_pr->val){
				prev_high = loop;
				high_pr = loop->next;
			}
			loop = loop->next;
		}
		if(prev_high != high_pr)
			prev_high->next = high_pr->next;
		if(high_pr==front)
			front = high_pr->next;
		else if(high_pr==rear)
			rear = prev_high;
		printf("\tFront: %d\tRear: %d\n", front->val, rear->val);

	}
	return high_pr->val;
}

bool isEmpty(){
	return front==NULL && rear == NULL;
}

