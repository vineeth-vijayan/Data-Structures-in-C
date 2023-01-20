#include <stdio.h>

int main(){
	int ar[] = {10,12,11,2,1,3,8,9,7,4,6,5}, flag, temp;

	printf("\nBefore sort: \n");
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	for(int i=0; i<sizeof(ar)/sizeof(int); i++){
		flag = 0;
		for(int j=0; j<(sizeof(ar)/sizeof(int))-1-i; j++){
			if(ar[j] > ar[j+1]){
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
				flag = 1;
			}
		}
		if(!flag)
			break;
	}

	printf("\nAfter Swapping: \n");
	for(int i=0; i<sizeof(ar)/sizeof(int); i++)
		printf("%d ", ar[i]);
	printf("\n");

	return 0;
}
