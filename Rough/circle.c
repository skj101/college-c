#include <stdio.h>

void main(){
   int radius;
   float perimeter, area,  pie = 3.14;
   printf("Enter the radius of the circle:\n");
   scanf("%d",&radius);
   perimeter = 2*pie*radius;
   area = pie * (radius * radius );
   printf("area of circle with radius %d is:\n %f \n",radius,area);
   printf("perimeter of circle with radius %d is:\n %f \n",radius,perimeter);
}
