#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define STACK_SIZE 5

int top, s[STACK_SIZE], item;

void push();
void pop();
void palindrome();
void display();

void main()
{
	int ch;
	top=-1;
	for ( ; ;)
	{
		printf("\n\n----------STACK OPERATIONS----------\n");
		printf("1. PUSH\n2. POP\n3. DISPLAY\n4. PALINDROME\n5. EXIT\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: printf("Enter the element to be inserted\n");
					scanf("%d", &item);
					push();
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: palindrome();
					break;
			default:exit(0);
		}
	}	
}

void push()
{
	if (top>=STACK_SIZE)
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	s[top]=item;
}

void pop()
{
	if (top==-1)
	{
		printf("Stack Underflow\n");
		return;
	}
	top=top-1;
}

void display()
{
	int i;
	if (top==-1)
	{
		printf("Stack Underflow\n");
		return;
	}
	printf("Stack elements are:\n");
	for (i=top; i>=0; i--)
	{
		printf("%d\n", s[i]);
	}
}

void palindrome()
{
	int rev[STACK_SIZE], len, num[STACK_SIZE], i, j, flag=0;
	i=0;
	for (j=top; j>=0; j--)
	{
		num[i]=s[j];
		i++;
	}
	len=i-1;
	j=0;
	for (i=len; i>=0; i--, j++)
	{
		rev[i]=num[j];
	}
	for (i=0; i<=len; i++)
	{
		if (rev[i]==num[i])
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
	if (flag==1)
	{
		printf("The given stack is a Palindrome\n");
	}
	else
	{
		printf("The given stack is not a Palindrome\n");
	}
}