#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  
  char *names[5], a[5];
  int l, i;
  char *x;
  printf("Enter 5 strings:\n");

  for (i = 0; i < 5; i++) {
    scanf("%s", a); // taking values in char array
    l = strlen(a);

    x = (char *)malloc(l + 1);
    strcpy(x, a);
    names[i] = x;
  }
  printf("The strings are:\n");
  
  for (i = 0; i < 5; i++)
    printf("%s\n", names[i]);
  
  return 0;
}
