#include <stdio.h>

void main(){
 int year;
 printf("Enter an year:\n");
 scanf("%d",&year);
if(year%4 == 0) 
   printf("%d is an leap year\n", year);
else
printf("%d is not a leap year\n",year);
 
}
