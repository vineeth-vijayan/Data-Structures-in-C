#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *count_ar;
void CountSort(int ar[], int size, int lar){
	count_ar = malloc(lar*sizeof(int));
	memset(count_ar, 0, (lar+1)*sizeof(count_ar[0]));

	for(int j=0; j<size; j++)
		count_ar[ar[j]]++;
}

int main(){
        int ar[] = {12,11,1,2,10,9,3,4,8,7,5,6,0,12,11,6,7,8,9,0,1,2,3,5,4,10}, lar=-1;

        printf("\nBefore sorting: \n");
        for(int i=0; i<(sizeof(ar)/sizeof(ar[0])); i++)
                printf("%d ", ar[i]);
        printf("\n");

	for(int i=0; i<sizeof(ar)/sizeof(ar[0]); i++)
                if(lar<ar[i])
                        lar = ar[i];


        CountSort(ar,sizeof(ar)/sizeof(int), lar);

        printf("\nAfter sorting: \n");
        for(int i=0; i<lar+1; i++)
                if(count_ar[i]>0)
			for(int j=0; j<count_ar[i]; j++)
				printf("%d ", i);
        
	printf("\n");
        return 0;
}

