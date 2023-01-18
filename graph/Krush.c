#include <stdio.h>
#include <stdlib.h>

struct Link {
	int dist;
	int n1, n2;
	struct Link *next;
};

struct Link *createLink(int dist, int i, int j){
	struct Link *node = (struct Link*)malloc(sizeof(struct Link));
	node->dist = dist;
	node->n1 = i;
	node->n2 = j;
	node->next = NULL;

	return node;
}

struct Link *root = NULL;

void insert(struct Link *node){
	if(root==NULL)
		root = node;
	else{
		struct Link *temp = root;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = node;
	}
}

void sort(struct Link *node, int v){
	struct Link *temp = node;
	int l=0;
	while(temp!=NULL){
		temp=temp->next;
		l++;
	}
	temp = root;
	struct Link *dup;
	for(int i=0; i<l; i++)
		for(int j=0; j<l-1; j++){
			if(temp->dist > temp->next->dist){
				*dup = *temp;
				*temp = *temp->next;
				*temp->next = *dup;
			}
			temp = temp->next;
		}
}

int *selected;

void Krushkal(int **ar, int v){
	selected = (int *)malloc(v*sizeof(int));
	for(int i=0; i<v; i++)
		selected[i]=0;
	for(int i=0; i<v; i++){
		for(int j=0; j<i; j++){
			if(ar[i][j]>0){
				struct Link *node = createLink(ar[i][j], i, j);
				insert(node);
			}
		}
	}

	sort(root, v);
	
	struct Link *temp = root;
	while(temp!=NULL){
		printf("%d ", temp->dist);
		temp = temp->next;
	}

}

int main(){
	int v, **ar;
        printf("Enter number of nodes in graph: ");
        scanf("%d", &v);

        ar = (int**)malloc(v*sizeof(int*));
        for(int i=0;i<v; i++)
                ar[i] = (int*)malloc(v*sizeof(int));
        printf("Enter the adjacency matrix for all %d vertices:\n", v);


        char num[v];
        for(int i=0; i<v; i++){
                scanf("%s", num);
                for(int j=0; j<v; j++){
                        ar[i][j] = (int)(num[j])-48;
                }
        }


        printf("\nAdjacency matrix: \n");
        for(int i=0;i<v; i++){
                for(int j=0; j<v; j++)
                        printf("%d ", ar[i][j]);
                printf("\n");
        }

	Krushkal(ar, v);

	return 0;
}
