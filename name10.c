#include <stdio.h>

//print name 5 times

//void main() {
//  for(int i = 0; i <= 5; i++)
//  printf("sanu\n");
//}

//print 1 to 50 using for loop

//void main(){
//for(int i = 1; i <= 50; i++)
//printf("%d\n",i);
//}

//first n natural numbers

// void main(){
// int num;
// printf("ENter a limit: ");
// scanf("%d",&num);
// for(int i = 1; i <= num; i++)
// printf("%d\n",i);
// }


//Reverse the natural numbers
//#include <stdio.h>
//void main(){

//    int num;
//    printf("Enter the limit: ");
//    scanf("%d", &num);
//    for(int i=num; i>=1; i--)
//    printf("%d\n", i);
// }


//first n even natural numbers

 //void main(){
 //int num;
 //printf("Enter a limit: ");
 //scanf("%d",&num);
 //for(int i = 1; i <= num; i++)
 //if(i%2==0){
 //printf("%d\n",i);
 //}
 //}

//first n odd natural numbers

 //void main(){
 //int num;
 //printf("Enter a limit: ");
 //scanf("%d",&num);
 //for(int i = 1; i <= num; i++)
 //if(i%2!=0){
 //printf("%d\n",i);
 //}
 //}

//#include <stdio.h>
//void main() {
//    int n, sum = 0;
//    printf("Enter a integer: ");
//    scanf("%d", &n);
//    for (int i = 1; i <= n; ++i) {
//        sum += i;
//    }
//    printf("Sum = %d\n", sum);
//}


//#include <stdio.h>
//void main() {
//    int n, fact = 1;
//    printf("Enter a integer: ");
//    scanf("%d", &n);
//    for (int i = 1; i <= n; ++i) {
//        fact *= i;
//    }
//    printf("Factorial of %d = %d\n",n, fact);
//}


//read n numbers and find greatest
#include <stdio.h>

void main(){
  int limit,larg=0;
  printf("Enter the limit: ");
  scanf("%d", &limit);
  int arr[limit],
  for(int i= 0; i< limit; i++){
     printf("Enter the %d number\n ",i+1);
     scanf("%d",&arr[i]);
  }
  for(int i=0; i<limit;i++){
  if(larg<arr[i])
  	larg = arr[i];
  }
  printf("Largest is %d \n",larg);
}









