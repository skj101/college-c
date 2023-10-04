
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main()
{
	int sec = 0;
	printf("Enter the seconds : ");
	scanf("%d",&sec);
	for (int i = 0; i < sec; i++) {
		system("clear"); 
		printf("%d seconds passed\n", i + 1);
		sleep(1);
	}
}

