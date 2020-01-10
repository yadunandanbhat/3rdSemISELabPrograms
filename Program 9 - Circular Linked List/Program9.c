#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int cf, x, y, z;
	struct node *link;
};

typedef struct node *NODE;
NODE head, h1, h2;

NODE readpoly (NODE head)
{
	int cf, x, y, z, n, i;
	printf("Enter the number of terms\n");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		printf("Enter the value for coefficients, x, y and z\n");
		scanf("%d%d%d%d", &cf, &x, &y, &z);
		insert(head, cf, x, y, z);
	}
	return(head);
}

int insert (NODE head, int cf, int x, int y, int z)
{
	NODE temp, cur;
	temp=(NODE)malloc(sizeof(struct node));
	temp->cf=cf;
	temp->x=x;
	temp->y=y;
	temp->z=z;
	cur=head->link;
	while(cur->link!=head)
	{
		cur=cur->link;
	}
	cur->link=temp;
	temp->link=head;
	return 0;
}

void display()
{
	NODE temp;
	if(head->link==head)
	{
		printf("Polynomial doesn't exist\n");
		return;
	}
	temp=head->link;
	while(temp!=head)
	{
		printf("%dx^%dy^%dz^%d\n",temp->cf,temp->x,temp->y,temp->z);
		temp=temp->link;
	}
}

void eval(NODE head)
{
	NODE poly;
	int xv,yv,zv,sum=0;
	printf("\nEnter the value of x,y,z\n");
	scanf("%d%d%d",&xv,&yv,&zv);
	poly=head->link;
	while(poly!=head)
	{
		sum+=poly->cf*pow(xv,poly->x)*pow(yv,poly->y)*pow(zv,poly->z);
		poly=poly->link;
	}
	printf("Result after Evaluation is %d\n",sum);
}

void add_poly(NODE h1,NODE h2)
{
	int cf1;
	NODE p1,p2;
	p1=h1->link;
	p2=h2->link;
	printf("\nAddition is:\n");
	while(p1!=h1 || p2!=h2)
	{
	if(p1->x==p2->x && p1->y==p2->y && p1->z==p2->z)
		{
			cf1=p1->cf+p2->cf  ;
			printf(" %dx^%dy^%dz^%d +",cf1,p1->x,p1->y,p1->z);
			p1=p1->link;
			p2=p2->link;
		}
	else if(p1->x>p2->x && p1->y>p2->y && p1->z>p2->z)
		{
			cf1=p1->cf;
			printf(" %dx^%dy^%dz^%d +",cf1,p1->x,p1->y,p1->z);
			p1=p1->link;
		}
	else
		{
			cf1=p2->cf;
			printf(" %dx^%dy^%dz^%d +",cf1,p2->x,p2->y,p2->z);
			p2=p2->link;
		}
	}
}

void main()
{
	int ch;
	head=(NODE)malloc(sizeof(struct node));
	h1=(NODE)malloc(sizeof(struct node));
	h2=(NODE)malloc(sizeof(struct node));
	head->link=head;
	h1->link=h1;
	h2->link=h2;
	while(1)
	{
	printf("\n\n----------CIRCULAR LINKED LIST----------\n");
	printf("\n1. READ\n2. DISPLAY\n3. EVALUATION\n4. POLYNOMIAL ADDITION\n5. EXIT\n");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: head=readpoly(head);
			break;
	case 2:	printf("The Polynomial is\n");
			display();
			break;
	case 3: eval(head);
			break;
	case 4: h1=readpoly(h1);
			h2=readpoly(h2);
			add_poly(h1,h2);
			break;
	default: exit(0);
	}
	}
}