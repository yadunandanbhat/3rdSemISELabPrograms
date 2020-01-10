#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int visited[10];

void BFS (int n, int a[10][10], int source)
{
	int i, q[10], u;
	int front=1, rear=1;
	visited[source]=1;
	q[rear]=source;
	while (front<=rear)
	{

		u=q[front];
		//printf("%d\t",u) incase of integer nodes
		printf("%c\t",u+64);
		front=front+1;
		for(i=1; i<=n; i++)
		if(a[u][i]==1 && visited[i]==0)
		{
			rear=rear+1;
			q[rear]=i;
			visited[i]=1;
		}
	}
}

void DFS (int n, int a[10][10], int source)
{
	int i, s[10], u;
	int top=-1;
	visited[source]=1;  // marking source vertex visited
	s[++top]=source;     // starting from source vertex
	while (top!=-1)
	{
		u=s[top--];
		//printf("%d\t",u) incase of integer nodes
		printf("%c\t", u+64);
		for(i=1; i<=n; i++)
		if(a[u][i]==1 && visited[i]==0)
		{
			top=top+1;
			s[top]=i;
			visited[i]=1;
		}
	}
}

void main()
{
	int n, a[10][10], i, j, source, ch;
	printf("\n\n----------GRAPHS----------\n");
	printf("\nEnter the number of nodes:\n");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix\n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	printf("\nEnter the source:\n");
	scanf("%d", &source);
	while(1)
	{
	printf("\n\n-----CHOOSE GRAPH TRAVERSAL METHOD-----\n");
	printf("\n1. Breadth First Search\n2. Depth First Search\n");
	printf("Enter your choice\n");
	scanf("%d", &ch);
	switch(ch)
	{
	  case 1:for(i=1; i<=n; i++)
		    visited[i]=0;
		  	BFS(n, a, source);
		  	break;
	  case 2:for(i=1; i<=n; i++)
		    visited[i]=0;
		  	DFS(n, a, source);
		  	break;
	  default:exit(0);
	}
	for(i=1;i<=n;i++)
	{
	   	if(visited[i]==0)
	     	printf("\nThe node %d is not reachable from %d",i,source);
	   	else
	     	printf("\nThe node %d is reachable from %d",i,source);
	}
    }
}