#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DH{
	int *ar;
	int size;
};

struct DH *createHash(){
	struct DH *d = malloc(sizeof(struct DH));
	d->ar = malloc(SIZE*(sizeof(int)));
	for(int i=0; i<SIZE; i++)
		d->ar[i]=-1;
	d->size = SIZE;

	return d;
}

int nearest_prime(){
	int num, flag;
	for(int i=2; i<SIZE; i++){
		flag = 0;
		for(int j=2; j<(i/2)+1; j++)
			if(i%j==0)
				flag = 1;
		if(!flag)
			num = i;
	}
	return num;
}	

void insert(struct DH *d, int key){
	int index1 = key%SIZE, index2, index;
	if(d->ar[index1]==-1)
		d->ar[index1] = key;
	else{
		int prime = nearest_prime();
		for(int i=1; ;i++){
			index2 = prime-(key%prime);
			index = (index1+i*index2)%SIZE;

			if(d->ar[index]==-1){
				d->ar[index] = key;
				break;
			}
		}
	}
}

void print(struct DH *d){
	for(int i=0; i<SIZE; i++){
		if(d->ar[i]==-1)
			printf("_, ");
		else
			printf("%d, ", d->ar[i]);
	}
}

int main(){
	struct DH *d = createHash();
	insert(d, 10);
	insert(d, 25);
	insert(d, 13);
	insert(d, 35);
	insert(d, 26);
	insert(d, 20);
	insert(d, 29);

	print(d);
	printf("\n");
	return 0;
}
