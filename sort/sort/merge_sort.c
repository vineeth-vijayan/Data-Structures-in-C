#include <stdio.h>

void Merge(int[], int, int, int);
void MergeSort(int[], int, int);

int main(){
	int ar[] = {12,11,1,2,10,9,3,4,8,7,5,6,0}; 

	printf("\nBefore sorting: \n");
	for(int i=0; i<(sizeof(ar)/sizeof(int)); i++)
		printf("%d ", ar[i]);
	printf("\n");

	MergeSort(ar, 0, sizeof(ar)/sizeof(int)-1);

	printf("\nAfter sorting: \n");
	for(int i=0; i<(sizeof(ar)/sizeof(int)); i++)
		printf("%d ", ar[i]);
	printf("\n");
	return 0;
}


void Merge(int ar[], int l, int mid, int h){
	int i, j, k, temp_ar[h];
	i = l;	
	j = mid+1; 
	k = 0;

	while(i<=mid && j<=h){
		if(ar[i]<ar[j])
			temp_ar[k++] = ar[i++];
		else
			temp_ar[k++] = ar[j++];
	}
	for(; i<=mid; i++)
		temp_ar[k++] = ar[i];
	for(; j<=h; j++)
		temp_ar[k++] = ar[j];

	for(i=0,j=l; i<=h-l; i++,j++)
		ar[j] = temp_ar[i];
}

void MergeSort(int ar[], int l, int h){
	int mid = l+(h-l)/2;
	if(l<h){
		MergeSort(ar, l, mid);
		MergeSort(ar, mid+1, h);
		Merge(ar, l, mid, h);
	}
}
