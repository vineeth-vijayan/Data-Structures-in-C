#include <stdio.h>


void shell_sort(int ar[], int n){
	for(int gap=n/2; gap>0; gap/=2){
		
		for(int i=gap; i<n; i++){
			int temp = ar[i];
			 
			int j;
			for(j=i; j>=gap && ar[j-gap]>temp; j-=gap)
				ar[j] = ar[j-gap];

			ar[j] = temp;
		}
	}
}

int main(){
	int ar[] = {12,11,10,9,8,7,6,5,4,3,2,1}, size=sizeof(ar)/sizeof(ar[0]);

	printf("\nBefore Sorting: \n");
	for(int i=0; i<size; i++)
		printf("%d ", ar[i]);
	printf("\n");

	shell_sort(ar, size);

	printf("\nAfter Sorting: \n");
	for(int i=0; i<size; i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}
