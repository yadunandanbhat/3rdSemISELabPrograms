#include<stdio.h>
#include<conio.h>
void toh (int n, char a, char b, char c);
int n, i=0;
char a, b, c;

void toh(int n, char a, char b, char c) {
	if (n>0) {
		toh(n-1, a, c, b);
		printf("Move disc from %c to %c\n", a, c);
		toh(n-1, b, a, c);
		i++;
	}
}

void main() {
	printf("\n\n----------TOWER OF HANOI----------\n");
	printf("\nEnter the no. of disc\n");
	scanf("%d", &n);
	toh(n, 'A', 'B', 'C');
	printf("\nNo. of moves are %d\n", i);
}