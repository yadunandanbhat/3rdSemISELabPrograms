#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	struct node *prev;
	int sem, phno;
	char name[20], usn[20], branch[20];
	struct node *next;
}*first=NULL, *last=NULL, *temp=NULL, *temp1;

void create();
void display();
void insertfront();
void insertback();
int deletefront();
int deleteback();

void main()
{
	int ch, i, n;
	while (1)
	{
	printf("\n\n----------DOUBLY LINKED LIST----------\n");
	printf("\n1. CREATE\n2. DISPLAY\n3. INSERT AT FRONT\n4. INSERT AT BACK\n5. DELETE AT FRONT\n6. DELETE AT BACK\n7. EXIT\n");
	printf("\nEnter your choice\n");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1: printf("Enter the number of students\n");
				scanf("%d", &n);
				for (i=0; i<n; i++)
				{
					insertback();
				}
				break;
		case 2: display();
				break;
		case 3: insertfront();
				break;
		case 4: insertback();
				break;
		case 5: deletefront();
				break;
		case 6: deleteback();
				break;
		default:exit(0);
	}
	}
}

void create()
{
	int phno, sem;
	char name[20], usn[20], branch[20];
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the values for Name, USN, Sem, Branch and Phone Number\n");
	scanf("%s%s%d%s%d", name, usn, &sem, branch, &phno);
	strcpy(temp->name, name);
	strcpy(temp->usn,usn);
	strcpy(temp->branch, branch);
	temp->sem=sem;
	temp->phno=phno;
	temp->next=NULL;
	temp->prev=NULL;
}

void insertfront()
{
	if (first==NULL)
	{
		create();
		first=temp;
		last=first;
	}
	else
	{
		create();
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
}

void insertback()
{
	if (first==NULL)
	{
		create();
		first=temp;
		last=first;
	}
	else
	{
	create();
	last->next=temp;
	temp->prev=last;
	last=temp;
	}
}

void display()
{
	temp1=first;
	if (temp1==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("Linked List elements are:\n");
	while (temp!=NULL)
	{
		printf("%s%s%d%s%d\n", temp1->name, temp1->usn, temp1->sem, temp1->branch, temp1->phno);
		temp1=temp1->next;
	}
}

int deletefront()
{
	temp=first;
	if (temp->next==NULL)
	{
		printf("%s%s%d%s%d\n", temp->name, temp->usn, temp->sem, temp->branch, temp->phno);
		free(temp);
		first=NULL;
	}
	else
	{
		first=temp->next;
		printf("%s%s%d%s%d\n", temp->name, temp->usn, temp->sem, temp->branch, temp->phno);
		free(temp);
	}
	return 0;
}

int deleteback()
{
	temp=first;
	if (temp->next==NULL)
	{
		printf("%s%s%d%s%d\n", temp->name, temp->usn, temp->sem, temp->branch, temp->phno);
		free(temp);
		first=NULL;
		return 0;
	}
	else
	{
		temp=last->prev;
		temp->next=NULL;
		printf("%s%s%d%s%d\n", last->name, last->usn, last->sem, last->branch, last->phno);
		free(last);
	}
	return 0;
}