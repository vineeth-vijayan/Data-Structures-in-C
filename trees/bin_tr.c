#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

struct Queue{
	int size;
	int front;
	int rear;
	struct Node **Q;
};

void create(struct Queue *q,int size){
	q->size=size;
	q->front=q->rear=0;
	q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}

void enqueue(struct Queue *q,struct Node *x){
	if((q->rear+1)%q->size==q->front)
		printf("\tQueue is Full\n");
	else
	{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;	
	}
}

struct Node * dequeue(struct Queue *q){
	struct Node* x=NULL;
	if(q->front==q->rear)
		printf("\tQueue is Empty\n");
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(struct Queue q){
	//printf("%d %d ", q.front, q.rear);
	return q.front==q.rear;
}

/*void show_f_r(struct Queue q){
	printf("\n%d %d\n", q.front, q.rear);
}*/

struct Node *root=NULL;

void Treecreate(){
	struct Node *p,*t;
	int x;
	struct Queue q;
	create(&q,20);
	printf("Enter root value: ");
	scanf("%d",&x);
	root=(struct Node *)malloc(sizeof(struct Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter left child of %d(if not then -1): ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		printf("Enter right child of %d(if not then -1): ",p->data);
		scanf("%d",&x);
		if(x!=-1){
			t=(struct Node *)malloc(sizeof(struct Node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void Preorder(struct Node *p){
	if(p){
		printf("%d ",p->data);
		Preorder(p->lchild);
		Preorder(p->rchild);
	}
}

void Inorder(struct Node *p){
	if(p){
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}

void Postorder(struct Node *p){
	if(p){
		Postorder(p->lchild);
		Postorder(p->rchild);
		printf("%d ",p->data);
	}
}

void Levelorder(struct Queue *lq, struct Node *p){
	if(p==root && root!=NULL)
		enqueue(lq, p);
	if(!isEmpty(*lq)){
		p = dequeue(lq);
		if(p->lchild!=NULL)
			enqueue(lq,p->lchild);
		if(p->rchild!=NULL)
			enqueue(lq,p->rchild);
		printf("%d ", p->data);
		//p = dequeue(lq) ;
		//printf("\nempty: %d %d,%d", isEmpty(*lq), lq->front, lq->rear);
	}
}

int main(){
	Treecreate();
	printf("\nPre Order: ");
	Preorder(root);
	printf("\nPost Order: ");
	Postorder(root);
	printf("\nInorder: ");
	Inorder(root);
	struct Queue lq;
        create(&lq,20);
	printf("\nLevel Order: ");
	Levelorder(&lq, root);
	printf("\n");
	return 0;
}
