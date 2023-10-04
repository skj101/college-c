#include <stdio.h>
 
void main()  
{  
    int limit, num, big = 0, small = 0;  
    printf("Enter the limit\n");  
    scanf("%d", &limit);  
    printf("Enter %d numbers\n", limit);  
    scanf("%d", &num);  
    big = small = num;  
    limit = limit - 1;  
    while(limit > 0)  
    {  
        scanf("%d", &num);  
        if(num > big)  
        {  
            big = num;  
        } 
        if(num < small)
        {  
            small = num;  
        } 
        limit--;  
    }  
    printf("Biggest is %d\n", big);  
    printf("Smallest is %d\n", small);  
}  
