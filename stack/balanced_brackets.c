#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Brackets{
	int top;
	int size;
	char *ch;
};

void push(struct Brackets *b, char c){
	//printf("push");
	b->ch[++b->top]=c;
	//printf("%d\n", b->top);
	for(int i=0;i<=b->top; i++)
		printf("%c ", b->ch[i]);
	printf("\n");
}

char* pop(struct Brackets *b){
	//printf("pop");	
	//printf("%d\n", b->top);
	char t;
	if(b->top>-1){
		//printf("%c", b->ch[b->top]);
		return &b->ch[b->top--];
	}
	else{
		printf("1.No, brackets are not balanced!!");
		exit(0);
	}
}

bool isEmpty(struct Brackets *b){
	//printf("isEmpty");
	if(b->top==-1)
		return 1;
	else
		return 0;
}

bool bracket_balanced(char *c){
	char* t;
	struct Brackets b;
	b.top = -1;
	b.size = 20;
	b.ch = (char*)malloc(20);
	for(int i=0; i<strlen(c); i++){
		//printf("\n%c\n", c[i]);
		switch(c[i]){
			case '{':
				push(&b, c[i]);
				break;
			case '[':
				push(&b, c[i]);
				break;
			case '(':
				push(&b, c[i]);
				break;
			case ')':
				t = pop(&b);
				printf("%d ", strcmp(t,"("));
				if(strcmp(t,"(")!=0)
					return 0;
				break;
			case '}':
				t = pop(&b);
				printf("%d " , strcmp(t,"{"));
				if(strcmp(t,"{")!=0)
					return 0;
				break;
			case ']':
				t = pop(&b);
				printf("%d ", strcmp(t,"["));	
				if(strcmp(t, "[")!=0)
					return 0;
				break;
			default:
				continue;
		}
	}
	if(isEmpty(&b))
		return 1;
	else
		return 0;
}


int main(){
	char *chr;
	chr = (char*) malloc(20);	
	
	printf("Read brackets: ");
	scanf("%s", chr);
	if(bracket_balanced(chr))
		printf("Yes");
	else
		printf("No");

	return 0;
}
