#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct employee
{
  int id;
  char name[20];
  char des[20];
};
typedef struct employee EMP;

int a[MAX];
EMP emp[MAX];
EMP hash[MAX];
void linear_prob(int key, int j);
void getemp(int key,int j);
void display();

FILE *fp=NULL;

void main()
{
  int key,i,j,count;
  int ID;
  char NAME[20],DES[20];
  fp=fopen("data.txt", "r");
  printf("\n\n----------HASHING TECHNIQUE WITH LINEAR PROBE----------\n");
  for (i=0;i<MAX;i++)
  {
    a[i] = -1;
  }
  i=0;
  while(!feof(fp))
  {
    fscanf(fp,"%d",&ID);
    fscanf(fp,"%s",NAME);
    fscanf(fp,"%s",DES);
    emp[i].id=ID;
    strcpy(emp[i].name,NAME);
    strcpy(emp[i].des,DES);
    i++;
  }
  count = i;
  for(j=0; j<count; j++)
  {
    key=emp[j].id % 100;
    linear_prob(key,j);
  }
  display();
}

void getemp(int key,int j)
{
  hash[key].id=emp[j].id;
  strcpy(hash[key].name, emp[j].name);
  strcpy(hash[key].des, emp[j].des);
}

void linear_prob(int key,int j)
{
 int flag, i, count=0;
 flag=0;
 if(a[key]== -1)
 {
   getemp(key,j);
   a[key] = key ;
 }
 else
 {
   printf("\n\nCollision Detected...!!!\n");
   i=0;
   while(i<MAX)
   {
     if(a[i]!=-1)count++;
     i++;
   }
   printf("\n\nCollision successfully handled using LINEAR PROBING\n");
   if(count == MAX)
   {
     printf("\n\nHash table is full\n");
     display();
     exit(1);
   }
   for(i=key+1; i<MAX; i++)
     if(a[i] == -1)
     {
       a[i] = key;
       getemp(key+1,j);
       flag =1;
       break;
     }

     i=0;
     while((i<key) && (flag==0))
     {
	if(a[i] == -1)
	{
	  a[i] = key;
	  getemp(key+1,j);
	  flag=1;
	  break;
	}
	i++;
     }
  }
}

void display()
{
  int i,ch;
  for(;;)
  {
  printf("\n\n1. DISPLAY ALL\n2. FILTERED DISPLAY\n3. EXIT\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1: printf("\n----------HASH TABLE----------\n");
	         printf("\nINDEX\tKEY\tEMPID\tNAME\t\tDESIGNATION\n");
           printf("---------------------------------------------");
	         for (i=0; i<MAX; i++)
	           printf("\n [%2d]\t%2d\t%4d\t%-10s\t%-10s", i, a[i], hash[i].id, hash[i].name, hash[i].des);
	         break;
   case 2: printf("\n----------HASH TABLE----------\n");
	         printf("\nINDEX\tKEY\tEMPID\tNAME\t\tDESIGNATION\n");
           printf("---------------------------------------------");
	         for(i=0; i<MAX; i++)
	           if(a[i]!=-1)
	           {
	             printf("\n [%2d]\t%2d\t%4d\t%-10s\t%-10s", i, a[i], hash[i].id, hash[i].name, hash[i].des);
	             continue;
	           }
	           break;
   default:exit(0);
  }
 }
}