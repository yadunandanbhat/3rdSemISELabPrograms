#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int i, j, m, c, k, flag=0;
char STR[100], PAT[100], REP[100], ans[100];

void read();
void find();

void main()
{
	printf("\n\n----------STRING MATCHING AND REPLACING----------\n");
	read();
	find();
	if (flag==0)
	{
		printf("The pattern is not found\n");
	}
	else
	{
		ans[j]='\0';
		printf("The resultant string is %s\n", ans);
	}
	printf("Press any key to exit\n");
	getch();
}

void read()
{
	printf("Enter the main string\n");
	gets(STR);
	printf("Enter the pattern string\n");
	gets(PAT);
	printf("Enter the replace string\n");
	gets(REP);
}

void find()
{
	i=m=c=j=0;
	while (STR[c]!='\0')
	{
		if (STR[m]==PAT[i])
		{
			i++;
			m++;
			if (PAT[i]=='\0')
			{
				flag=1;
				for (k=0; REP[k]!='\0'; j++, k++)
				{
					ans[j]=REP[k];
				}
				i=0;
				c=m;
			}
		}
		else
		{
			ans[j]=STR[c];
			j++;
			c++;
			m=c;
			i=0;
		}
	}
}