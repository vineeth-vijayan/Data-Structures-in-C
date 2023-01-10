#include<stdio.h>
#include<stdlib.h>

int main(){
	int *ar;
	int num;
	printf("Enter the size of array: ");
	scanf("%d", &num);
	
	ar = (int *) malloc(num*sizeof(int));
	printf("Created array size: %lu", sizeof(ar));

	return 0;
}
