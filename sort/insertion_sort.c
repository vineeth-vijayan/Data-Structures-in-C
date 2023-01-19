#include <stdio.h>

int main(){
	int ar[] = {10, 1, 11, 9, 4, 2, 5, 3, 8, 6, 7, 12}, x, temp, i, j;
	
	printf("\nBefore Sorting: \n");
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	for(i=0; i<(sizeof(ar)/sizeof(int))-1; i++){
		x = ar[i+1];
		for(j=i; j>=0; j--){
			if(ar[j]>x)
				ar[j+1] = ar[j];
			else
				break;
		}
		ar[j+1] = x;
	}

	printf("\nAfter Sorting: \n");
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}
