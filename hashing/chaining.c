#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct chain{
	int key;
	struct chain *next;
};

struct chain *ch[SIZE];

void init(){
	for(int i=0; i<SIZE; i++)
		ch[i] = NULL;
}

void insert(int key){
	int index = key % SIZE;
	struct chain *node = (struct chain*)malloc(sizeof(struct chain));
	node->key = key;
	node->next = NULL;
	if(ch[index]==NULL)
		ch[index] = node;
	else
    	{
        	struct chain *temp = ch[index];
	        while(temp->next)
	        {
	            temp = temp->next;
	        }
	        temp->next = node;
    	}
}

void print()
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        struct chain *temp = ch[i];
        printf("chain[%d]--> ",i);
        while(temp)
        {
            printf("%d -->",temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
	init();

	insert(7);
	insert(0);
	insert(3);
	insert(11);
	insert(21);
	insert(31);
	insert(4);
	insert(5);
	
	print();	

	return 0;
}
