#include <stdio.h>

void main()
{
    int a, b, c;
    printf("Enter three numbers: \nFirst number: ");
    scanf("%d", &a);
    printf("Second number: ");
    scanf("%d", &b);
    printf("Third Number: ");
    scanf("%d", &c);
    if (a > b && a > c)
        printf("Biggest number is %d", a);
    if (b > a && b > c)
        printf("Biggest number is %d", b);
    if (c > a && c > b)
        printf("Biggest number is %d", c);
}
