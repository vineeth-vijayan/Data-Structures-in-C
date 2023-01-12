#include<stdio.h>

struct Tree{
	int val;
	struct Tree *left, *right;
};

struct Queue{
	int size;
	int front;
	int rear;
	struct Tree *Q;
};

struct Queue *createQueue(int size){
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (struct Tree*)malloc(sizeof(struct Tree));

	return q;
}

void enqueue(){}


void add_nodes(){


}
	
int main(){
	int ch, value;
	struct Tree *node = (struct Tree*)malloc(sizeof(struct Tree));
	node->left = node->right = NULL;
	struct Queue *q = createQueue(20);
	do{
		printf("\nEnter your choice: \n1.Preorder Traverse\n2.Postorder Traverse\n3.Inorder Traverse\n4.Level Traverse\n5.Exit\n:: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				pre_traverse();
				break;
			case 2:
				post_traverse();
				break;
			case 3:
				in_traverse();
				break;
			case 4:
				lvl_traverse();
				break;
			case 5:
				printf("\tExit!!");
				break;
			default:
				printf("\tTry Again!!\n");
		}
	}while(ch!=6);	

	return 0;
}
