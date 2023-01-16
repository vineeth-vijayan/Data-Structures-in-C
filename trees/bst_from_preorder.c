#include <stdio.h>
#include <stdlib.h>

struct Stack{
	struct Tree **t;
	int size;
	int top;
};

struct Tree{
	int data;
	struct Tree *left,*right;
};

struct Stack *st = NULL;

struct Stack *createStack(int size){
	struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
	st->size = size;
	st->t = (struct Tree **)malloc(size*sizeof(struct Tree*));
	st->top = -1;
	return st;
}


struct Tree *root = NULL, *p = NULL;

struct Tree *createNode(int data){
	struct Tree *t = malloc(sizeof(struct Tree));
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int isEmpty(){
	if(st->top == -1)
		return 1;
	else 
		return 0;
}

int isFull(){
	if(st->top!=(st->size-1))
		return 0;
	else
		return 1;
}

	
void push(struct Tree *t){
	if(!isFull())
		st->t[++st->top] = t;

}

struct Tree *pop(){
	if(!isEmpty())
		return st->t[st->top--];
}

int peek(){
	return st->t[st->top]->data;
}

void add_node(int data){
	struct Tree *node = createNode(data);
	if(root == NULL){
		root = node;
		p = root;
	}
	else if(p->data > data){
		p->left = node;
		push(p);
		p = node;
	}
	else{
		while(!isEmpty()){
			if(p->data<data && data < peek())
				break;
			p = pop();
		}
		p->right = node;
		p = node;
	}
}

void Preorder(struct Tree *root){
	if(root!=NULL){
		printf("%d ", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}


int main(){
	//int ar[]= {30,20,10,15,25,40,50,45};
	int ar[] = {5,3,1,0,4};
	st = createStack(sizeof(ar)/sizeof(int));

	for(int i=0; i<(sizeof(ar)/sizeof(int)); i++)
		add_node(ar[i]);
	Preorder(root);
	return 0;
}
