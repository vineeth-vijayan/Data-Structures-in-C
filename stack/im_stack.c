#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Stack{
	int size;
	int top;
	int *ar;
};

void push(struct Stack*, int);
void pop(struct Stack*);
void peek(struct Stack*);
bool isEmpty(struct Stack*);
bool isFull(struct Stack*);

int main(){
	struct Stack s;
	printf("Enter size of stack: ");
	scanf("%d", &s.size);

	printf("\nSetting top of stack as (-1)\n");
	s.top = -1;

	printf("\nCreating stack of size (%d)\n", s.size);
	s.ar = (int*) malloc(s.size*sizeof(int));
	
	push(&s,1);
	push(&s,2);
	peek(&s);
	push(&s,3);
	peek(&s);
	pop(&s);
	peek(&s);
	push(&s,4);
	peek(&s);
	pop(&s);
	
	return 0;
}

void push(struct Stack *s,int n){
	if(isFull(s))
		printf("Stack is Full!!\n");
	else{
		s->ar[++s->top] = n;
		printf("Pushed !!");
		printf("Top: %d\n", s->top);
	}
}

void peek(struct Stack *s){
	if(isEmpty(s))
		printf("Stack is Empty!!\n");
	elsewarning: passing argument 1 of ‘strcmp’ makes pointer from integer without a cast [-Wint-conversion]
		printf("Peek: %d\n", s->ar[s->top]);
}

void pop(struct Stack *s){
	if(isEmpty(s))
		printf("Stack is Empty!!\n");
	else
		printf("Pop: %d\n", s->ar[s->top--]);
}

bool isFull(struct Stack *s){
	return (s->top==(s->size-1));
}

bool isEmpty(struct Stack *s){
	return (s->top==-1);
}
