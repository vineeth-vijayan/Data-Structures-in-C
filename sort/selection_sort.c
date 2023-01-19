#include <stdio.h>

int main(){
	int ar[] = {12, 1, 5, 3, 11, 8, 2, 4, 7, 9, 6, 10}, i, j, k, temp, min;
	printf("\nBefore Sorting: \n");
	for(i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	for(i=0; i<(sizeof(ar)/sizeof(int))-1; i++){
		min = ar[i];
		for(j=i, k=i; j<(sizeof(ar)/sizeof(int)); j++){
			if(ar[j]<min){
				min = ar[j];
				k = j;
			}
		}
		if(k!=i){
			temp = ar[k];
			ar[k] = ar[i];
			ar[i] = temp;
		}
	}

	printf("\nAfter Sorting: \n");
	for(i=0; i<(sizeof(ar)/sizeof(int)); i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}
