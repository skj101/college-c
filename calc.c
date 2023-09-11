#include <stdio.h>

void main(){
 char op; 
 int a, b;
 printf("Select an operation: ( +, -, *, / ) \n");
 scanf("%c",&op);
 printf("Enter first number:\n");
 scanf("%d",&a);
 printf("Enter Second number:\n");
 scanf("%d",&b);

switch(op){
	case '+':printf("%d + %d = %d \n", a,b, a+b );
	break;
	case '-':printf("%d - %d = %d \n", a,b, a-b );
	break;
	case '*':printf("%d * %d = %d \n", a,b, a*b );
	break;
	case '/':printf("%d / %d = %d \n", a,b, a/b );
	break;
	default: printf("Invalid Option");
}
}
