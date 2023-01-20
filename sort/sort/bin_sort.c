#include <stdio.h>
#include <stdlib.h>

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

void BinSort(int ar[]){
	Node *temp;
	for(int i=0; i<size; i++){
		if(nd[ar[i]]!=NULL){
			temp = nd[ar[i]];
			while(temp->next!=NULL)
				temp = temp->next;
			Node *n = (Node *)malloc(sizeof(Node));
			n->val = ar[i];
			n->next = NULL;
			temp->next = n;
		}
		else{
			Node *n = (Node *)malloc(sizeof(Node));
			n->val = ar[i];
			n->next = NULL;
			nd[ar[i]] = n;
		}
	}
}

int main(){
	int ar[] = {6, 10, 12, 2, 9, 7, 1, 11, 8, 6, 4, 3, 5};
	size = sizeof(ar)/sizeof(ar[0]);

	printf("\nBefore sorting: \n");
	for(int i=0; i<size; i++)
		printf("%d ", ar[i]);

	int max = findMax(ar);
	nd = createNode(max+1);

	BinSort(ar);	
	
	printf("\n\nAfter sorting: \n");
	for(int i=0; i<=max; i++){
		if(nd[i]!=NULL){
			Node *temp = nd[i];
			while(temp!=NULL){
				printf("%d ", temp->val);
				temp = temp->next;
			}
		}
	}
	printf("\n");

	return 0;
}

