#include <stdio.h>

void main(){   
int a,b;

 printf("Enter first number to compare:\n");
 scanf("%d",&a);
 printf("Enter second number  to compare:\n");
 scanf("%d",&b);
 if(a > b)
      printf("%d is greater than %d",a,b);
 else
      printf("%d is greater than %d",b,a);
}
