#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 99999
#define V 5

int G[V][V] = 
	{{0,8,10,15,0},
	 {8,0,25,9,5},
	 {10,25,0,11,2},
	 {15,9,11,0,4},
	 {0,5,2,4,0}};

int main(){
	int selected[V], edges=0, x, y, min, cost=0;
	memset(selected, false, sizeof(selected));
	selected[0] = true;
	
	printf("\nAdjacency Matrix: \n");
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++)
			printf("%d\t", G[i][j]);
		printf("\n");
	}

	printf("\nPrims Spanning Tree(starting from 0):\n");

	while(edges<V-1){
		min = INF;
		for(int i=0; i<V; i++){
			if(selected[i]==true){
				for(int j=0; j<V; j++){
					if(!selected[j] && G[i][j]<min && G[i][j]!=0){
						min = G[i][j];
						x = i;
						y = j;			
					}		
				}
			}
		}
		cost += G[x][y];
		printf("%d --> %d : (%d)\n", x, y, G[x][y]);
		selected[y] = true;
		edges++;
	}
	printf("\nTotal cost: %d\n\n", cost);
	return 0;
}
