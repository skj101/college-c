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
 
 switch(total /10){
     
     case 10: case 9: 
     		printf("Your Grade is A");
      	        break;
     case 8: printf("Your Grade is B");
     		break;
     case 7: printf("Your grade is C");
     		break;
     case 6: printf("Your grade is D");
     		break;
     case 5: printf("Your grade is E");
     		break;
     default: printf("Your grade is F");
     }
     		
 }
 
