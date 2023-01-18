#include <stdio.h>
#include <stdlib.h>

#define SIZE 11 

struct QP{
	int *ar;
	int size;
};

struct QP *createQP(){
	struct QP *node = (struct QP*)malloc(sizeof(struct QP));
	node->ar = (int *)malloc(SIZE * sizeof(int));
	for(int i=0; i<SIZE; i++)
		node->ar[i] = -1;
	node->size = SIZE;
	return node;
}

void insert(struct QP *l, int key){
	int index = key%SIZE;
	if(l->ar[index]== -1)
		l->ar[index] = key;
	else{
		int j=1;
		while(j!=0){
			if(l->ar[((j*j)+index)%SIZE]!=-1)
				j = (j+1)%SIZE;
			else{
				l->ar[((j*j)+index)%SIZE] = key;		
				break;
			}
		}	
	}
}

void print(struct QP *l){
	for(int i=0;i<SIZE; i++){
		if(l->ar[i]!=-1)
			printf("%d, ", l->ar[i]);
		else
			printf("_, ");
	}
	printf("\n");
}


// Maintain a set of visited index and if length of visited index == SIZE; element not found
/*void search(struct QP *l, int num){
	int index = num%SIZE, flag=0, i=index;
	if(l->ar[index]==num)
		flag = 1;
	else{
		if(l->ar[index]!=-1){
			for(i=0; i!=index ; i=(i+1)%SIZE){
				if(l->ar[i]==num){
					flag = 1;
					break;
				}
				else if(l->ar[i]==-1)
					break;
			}
		}
	}
	if(!flag)
		printf("\tNumber not found\n");
	else
		printf("\tNumber found in index %d\n", i);
}*/

int main(){
	struct QP *l = createQP();
	insert(l, 10);
	insert(l, 15);
	insert(l, 29);
	insert(l, 11);
	insert(l, 20);
	insert(l, 25);
	printf("\tElements: ");
	print(l);
	printf("\n");

	//int num;
	//printf("Search: ");
	//scanf("%d", &num);
	//search(l,num);
	return 0;
}
