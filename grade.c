#include <stdio.h>

void main(){
 int mark1, mark2, mark3, total ;
 printf("Enter marks of any 3 subjects:\n First Subject :\n ");
 scanf("%d",&mark1);
 printf("Second Subject :\n ");
 scanf("%d",&mark2);
 printf("Third Subject :\n ");
 scanf("%d",&mark3);
 total = ( mark1 + mark2 + mark3 ) /3;
 if(total > 90 ){
  printf("Your grade is A+");
 } else if ( total > 80 && total < 90 ){
  printf("Your grade is B+");
 }
 else if ( total > 70 && total < 80 ){
  printf("Your grade is C+");
 }
 else if ( total > 60 && total < 70 ){
  printf("Your grade is D+");
 }
 else if ( total > 50 && total < 60 ){
  printf("Your grade is E+");
 }
  else {
  printf("You failed grade is F+ - your total avg is %d / 100", total);
 }

}
