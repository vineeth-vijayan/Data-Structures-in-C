#include <stdio.h>

void quick_sort(int num[], int first, int last){
	int pivot, i, j, temp;

	if(first<last){
		pivot = first;
		i = first;
		j = last;
		while(i<j){
			while(num[i]<=num[pivot] && i<last)
				i++;
			while(num[j]>num[pivot])
				j--;
			if(i<j){
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
		temp = num[pivot];
		num[pivot] = num[j];
		num[j] = temp;
		quick_sort(num, first, j-1);
		quick_sort(num, j+1, last);
	}
}

int main(){
	int ar[] = {12, 1, 11, 2, 10, 3, 9, 4, 8, 5, 7, 6};

	printf("\nBefore Sorting: \n");
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	quick_sort(ar, 0, (sizeof(ar)/sizeof(int))-1);

	printf("\nAfter Sorting: \n");
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}
