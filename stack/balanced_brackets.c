#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Brackets{
	int top;
	unsigned size;
	char *ch;
};


struct Brackets* createStack(unsigned s){
	struct Brackets* b_stack = (struct Brackets*) malloc(sizeof(struct Brackets));

	if(!b_stack)
		return NULL;
	b_stack->top=-1;
	b_stack->size = s;
	b_stack->ch = (char*)malloc(s*sizeof(char));

	return b_stack;
}

void push(struct Brackets *b, char c){
	b->ch[++b->top]=c;
}



char pop(struct Brackets *b){
	if(b->top>-1){
		//printf("pop: %c\n", b->ch[b->top]);
		return b->ch[b->top--];
	}
	else{
		printf("No\n");
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

bool compare(char a, char b){
	//printf("compare: (%c:%c)\n", a, b);
	char *beta = &b, *alpha =  &a;
	return strcmp(beta,")") && strcmp(alpha,"(") || strcmp(alpha,"{") && strcmp(beta,"}") || strcmp(alpha,"[") && strcmp(beta,"]");
}

bool bracket_balanced(char *c){
	char t;
	struct Brackets *b = createStack(20);
	
	for(int i=0; i<strlen(c); i++){
		switch(c[i]){
			case '{':
			case '[':
			case '(':
				push(b, c[i]);
				break;
			case ')':
			case '}':
			case ']':
				t = pop(b);
				if(!compare(t, c[i]))
					return 0;
				break;
		}
	}
	if(isEmpty(b))
		return 1;
	else
		return 0;
}


int main(){
	char *c;
	printf("Enter string of brackets: ");
	c = (char*)malloc(20*sizeof(char));
	scanf("%s", c);
	if(bracket_balanced(c))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
