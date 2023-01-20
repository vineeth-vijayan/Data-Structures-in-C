#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node{
	int val;
	struct Node *next;
}Node;

Node **nd;
int size;

int findMax(int ar[]){
	int lar = -1;
	for(int i=0; i<size; i++)
		if(lar<ar[i])
			lar = ar[i];
	return lar;
}

Node **createNode(int m){
	Node **n = (Node **)malloc(m*sizeof(Node *));
	for(int i=0; i<m; i++)
		n[i] = NULL;

	return n;
}

void RadixSort(int ar[], int i){
	int ind;
	Node *temp;
	for(int j=0; j<size; j++){
		ind = (int)(ar[j]/pow(10,i-1));
		ind = ind%10;
		if(nd[ind]!=NULL){
			temp = nd[ind];
			while(temp->next!=NULL)
				temp = temp->next;
			Node *n = (Node *)malloc(sizeof(Node));
			n->val = ar[j];
			n->next = NULL;
			temp->next = n;
		}
		else{
			Node *n = (Node *)malloc(sizeof(Node));
			n->val = ar[j];
			n->next = NULL;
			nd[ind] = n;
		}
	}

	for(int i=0,j=0; i<10; i++){
                if(nd[i]!=NULL){
                        Node *temp = nd[i];
                        while(temp!=NULL){
                                ar[j++] = temp->val;
                                temp = temp->next;
                        }
                }
        }
}

int main(){
	int ar[] = {6, 10, 12, 2, 9, 7, 1, 11, 8, 6, 4, 3, 5};
	size = sizeof(ar)/sizeof(ar[0]);

	printf("\nBefore sorting: \n");
	for(int i=0; i<size; i++)
		printf("%d ", ar[i]);

	int max = findMax(ar), i;
	nd = createNode(10);
	
	for(i=1; (int)(max/pow(10,i))!=0; i++)
		RadixSort(ar,i);	
	RadixSort(ar,i);
	
	printf("\n\nAfter sorting: \n");
	for(int i=0; i<size; i++){
		printf("%d ", ar[i]);
	}
	printf("\n");

	return 0;
}
