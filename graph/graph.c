#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int front, rear;
	int size;
	int *ar;
};

struct Queue* createQueue(int size){
	struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
	if(!q)
		return NULL;
	q->size = size;
	q->front = -1;
	q->rear = -1;
	q->ar = (int*) malloc(size*sizeof(int));

	return q;
}

int isEmpty(struct Queue* q){
	return q->front==-1 && q->rear==-1;
}

int isFull(struct Queue* q){
	return (q->rear+1)%q->size == q->front;
}

void enqueue(struct Queue *q, int num){
	if(!isFull(q)){
		q->ar[(++q->rear)%q->size] = num;
		if(q->front==-1)
			q->front++;
		//printf("\tEnqueued!!\n");
	}
	else
		printf("\tQueue is Full!!\n");
}

int dequeue(struct Queue *q){
	if(!isEmpty(q)){
		int num =  q->ar[q->front];
		if(q->front==q->rear){
			q->front = -1;
			q->rear = -1;
		}
		else
			q->front = (q->front+1)%q->size;
		return num;
	}
	else
		printf("\tQueue is Empty!!\n");
}

int *createVisit(int v){
	int *visited = (int *)malloc(v*sizeof(int));
	return visited;
}

void BFS(int **ar, int ver, int v, int *visited){
	struct Queue *q=createQueue(v);
	for(int i=0; i<v; i++)
		visited[i] = 0;
	int i=0, u;
	if(visited[ver]!=1){
		enqueue(q,i);
		visited[i]=1;
		while(!isEmpty(q)){
			u = dequeue(q);
			printf("%d ", u);
			for(int j=0; j<v; j++){
				if(ar[u][j]==1 && visited[j]!=1){
					enqueue(q, j);
					visited[j]=1;
				}
			}
		}
	}
}

void DFS(int **ar, int ver, int v, int *visited){
	if(visited[ver]!=1){
		printf("%d ", ver);
		visited[ver]=1;
		for(int j=0; j<v; j++)
			if(ar[ver][j]==1 && visited[j]!=1)
				DFS(ar, j, v, visited);
	}
}

int *selected;

/*void Prims(int **ar, int ver, int v){
	
}*/

void Krushkal(int **ar, int v){
	selected = (int *)malloc(v*sizeof(int));
	for(int i=0; i<v; i++)
		selected[i] = 0;
	int dist, node[2];
	for(int i=0; i<v; i++){
		dist = -1;
		for(int j=0; j<i; j++){
			if(ar[i][j]>0 && dist==-1 &&(selected[i]==0 || selected[j]==0)){
				dist=ar[i][j];
				node[0] = i;
				node[1] = j;
			}
			else if(ar[i][j]<dist && (selected[i]!=0 || selected[j]!=0)){
				dist = ar[i][j];
				node[0]=i;
				node[1]=j;
			}
		}
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

	int ver;
	printf("Enter a vertex to begin the traversal: ");
	scanf("%d",&ver);

	printf("\nBFS traversal: \n");
	BFS(ar, ver, v, createVisit(v));

	printf("\nDFS traversal: \n");
	DFS(ar, ver, v, createVisit(v));

	printf("\nKrushkal's Spanning Tree: \n");
	Krushkal(ar,v);

	printf("\n");
	return 0;
}
