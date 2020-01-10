#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Q_SIZE 5

char item, q[Q_SIZE];
int f, r, count;

void enqueue();
void dequeue();
void display();

void main()
{
	int ch;
	f=0; r=-1; count=0;
	while (1)
	{
		printf("\n\n----------CIRCULAR QUEUE----------\n");
		printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: fflush(stdin);
					printf("Enter the element to be inserted\n");
					scanf("%c", &item);
					enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			default:exit(0);
		}
	}
}

void enqueue()
{
	if (count==Q_SIZE)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		r=(r+1)%Q_SIZE;
		q[r]=item;
		count++;
	}
}

void dequeue()
{
	if (count==0)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		f=(f+1)%Q_SIZE;
		count--;
	}
}

void display()
{
	int i, j;
	if (count==0)
	{
		printf("Queue Underflow\n");
	}
	else
	{
		printf("Queue elements are:\n");
		i=f;
		for (j=0; j<count;j++)
		{
			printf("%c\t", q[i]);
			i=(i+1)%Q_SIZE;
		}
	}
}