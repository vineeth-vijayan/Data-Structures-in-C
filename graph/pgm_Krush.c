#include <stdio.h>

#define V 6

int G[V][V] = 
	{{0,4,4,0,0,0},
	 {4,0,2,0,0,0},
	 {4,2,0,3,4,2},
	 {0,0,3,0,3,0},
	 {0,0,4,3,0,3},
         {0,0,2,0,3,0}};

typedef struct edge{
	int u,v,w;
}edge;

typedef struct edge_list{
	edge data[V*V];
	int n;
}edge_list;

edge_list ed, spanning;
int cost=0;

void sort(){
        edge temp;

        for(int i=1; i<ed.n; i++){
                for(int j=0; j<(ed.n-1); j++){
                        if(ed.data[j].w > ed.data[j+1].w){
                        	temp = ed.data[j];
                                ed.data[j] = ed.data[j+1];
                                ed.data[j+1] = temp;
                        }
                }
        }
}

int find(int belongs[], int v){
        return belongs[v];
}

void Union(int belongs[], int c1, int c2){
	for(int i=0; i<V; i++)
                if(belongs[i]==c2)
                        belongs[i]=c1;        
}

void print(){
	for(int i=0; i<spanning.n; i++){
		printf("%d --> %d: (%d)\n", spanning.data[i].u, spanning.data[i].v, spanning.data[i].w);
		cost += spanning.data[i].w;
	}
	printf("\n Total cost: %d\n", cost);
}

void krushkal(){
	int belongs[V], c1, c2;
	
	for(int i=0; i<V; i++)
		belongs[i] = i;
	ed.n=0;
	for(int i=1; i<V; i++){
		for(int j=0; j<i; j++){
			if(G[i][j]>0){
				ed.data[ed.n].u = i;
				ed.data[ed.n].v = j;
				ed.data[ed.n].w = G[i][j];
				ed.n++;
			}
		}
	}

	sort();

	spanning.n=0;

	for(int i=0; i<ed.n; i++){
		c1 = find(belongs, ed.data[i].u);
		c2 = find(belongs, ed.data[i].v);
		if(c1 != c2){
			spanning.data[spanning.n++] = ed.data[i];
			Union(belongs, c1, c2);
		}
	}

	print();
	printf("\n");
}


int main(){
	krushkal();

	return 0;
}
