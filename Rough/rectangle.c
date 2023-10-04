#include <stdio.h>

void main(){
   int length, breadth, perimeter, area;
   printf("Enter the length of the rectangle:\n");
   scanf("%d",&length);
   printf("Enter the breadth of the rectangle:\n");
   scanf("%d",&breadth);
   perimeter = (length + breadth) * 2;
   area = length * breadth;
   printf("area of rectangle with length %d , and breadth %d is:\n %d \n",length,breadth,area);
   printf("perimeter of rectangle with length %d , and breadth %d is:\n %d \n",length,breadth,perimeter);
}
