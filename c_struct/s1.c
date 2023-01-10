#include<stdio.h>

struct Student{
	int age;
	char fname[50];
	char lname[50];
	int std;
};

int main(){
	struct Student s;

	scanf("%d", &s.age);
	scanf("%s", s.fname);
	scanf("%s", s.lname);
	scanf("%d", &s.std);

	printf("%d %s %s %d", s.age, s.fname, s.lname, s.std);
}
