#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Stack{
	int val;
	struct Stack *prev, *next;
}*top=NULL;

void push(struct Stack*);
void pop();
void peek();
bool isEmpty();
//bool isFull();


int main(){
	int choice, v;
	do{
		printf("\nEnter your choice: \n");
		printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Exit\n:: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: 
				struct Stack *newNode = (struct Stack*)malloc(sizeof(struct Stack)); 
				printf("\tEnter a value to push: ");
				scanf("%d", &v);
				newNode->val = v;
				newNode->prev = NULL;
				newNode->next = NULL;
				push(newNode);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				if(isEmpty())
					printf("\tStack is Empty!!\n");
				else
					printf("\tStack is not empty!!\n");
				break;
			case 5:
				printf("\tTerminating!!\n");
				break;
			default:
				printf("\tWrong Input!!\n");
				break;
		}
	}while(choice!=5);


}

void push(struct Stack *new){
	if(top == NULL)
		top = new;
	else{
		new->prev = top;
		top->next = new;
		top = new;
	}
}

void pop(){
	if(isEmpty())
		printf("\tStack is Empty!!\n");
	else{
		top = top->prev;
		printf("\tPopped successfully!!\n");
	}
}

void peek(){
	if(isEmpty())
		printf("\tStack is Empty!!\n");
	else
		printf("\tPeeked: %d", top->val);
}

bool isEmpty(){
	if(top == NULL)
		return 1;
	else
		return 0;
}
