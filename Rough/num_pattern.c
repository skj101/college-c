#include <stdio.h>
void main() {
	int a, j = 1, x = 0, l = 0;
	printf("Input number of lines: ");
	scanf("%d", &a);
 	printf("Input number of items lines: ");
	scanf("%d", &l);
	for(int i = 1; i <= a; i++) {
		while(x < l) {
			printf("%d ", j++);
			x++;
		}
		x = 0;
		printf("\n");
	}
}

