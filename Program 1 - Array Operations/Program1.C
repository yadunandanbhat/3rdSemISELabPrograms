#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[100], i, n, val, pos;

void create();
void insert();
void delet();
void display();

void main()
{
	int ch;
	while(1)
	{
	printf("\n\n----------ARRAY OPERATIONS----------\n\n");
	printf("1. CREATE\n2. INSERT\n3. DELETE\n4. DISPLAY\n5. EXIT\n");
	printf("\nEnter your choice\n");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:create();
			   break;
		case 2:insert();
			   break;
		case 3:delet();
			   break;
		case 4:display();
			   break;
		default:exit(0);
	}
	}
}

void create()
{
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for (i=0; i<n; i++)
		scanf("%d", &a[i]);
}

void display()
{
	printf("The Array elements are:\n");
	for (i=0; i<n; i++)
	{
		printf("%d\n", a[i]);
	}
}

void insert()
{
	printf("Enter the position of the element to be inserted\n");
	scanf("%d", &pos);
	printf("Enter the value of the element to be inserted\n");
	scanf("%d", &val);
	for (i=n-1; i>=pos; i--)
		a[i+1]=a[i];
		a[pos]=val;
	n=n+1;
}

void delet()
{
	printf("Enter the postion of the element to be deleted\n");
	scanf("%d", &pos);
	val=a[pos];
	for (i=pos; i<n-1; i++)
	{
	 a[i]=a[i+1];
	}
	n=n-1;
	printf("The deleted element is %d\n", val);
}