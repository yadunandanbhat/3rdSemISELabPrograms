#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;

int key, item, flag=0;

void preorder_BST(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->info);
	preorder_BST(root->llink);
	preorder_BST(root->rlink);
}

void inorder_BST(NODE root)
{
	if(root==NULL)
		return;
	inorder_BST(root->llink);
	printf("%d\t",root->info);
	inorder_BST(root->rlink);
}

void postorder_BST(NODE root)
{
	if(root==NULL)
		return;
	postorder_BST(root->llink);
	postorder_BST(root->rlink);
	printf("%d\t",root->info);

}

void search_BST(NODE root)
{
  	NODE temp;
   	if(root==NULL)
   	{
    	printf("Tree is Empty!!\n");
    	return;
   	}
   	temp=root;
   	while(temp!=NULL)
   	{
     	if(key==temp->info)
     	{
       		flag=1;
       		break;
     	}
     	if(key<temp->info)
       		temp=temp->llink;
     	else
       		temp=temp->rlink;
   	}
}

NODE create_BST(NODE root)
{
	NODE temp, cur, prev;
	temp=(NODE)malloc(sizeof(struct node));
	temp->info=item;
	temp->llink=temp->rlink=NULL;
	if(root==NULL)return temp;
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}

void main()
{
	NODE root=NULL;
	int ch;
	for(;;)
	{
		printf("\n\n----------BINARY SEARCH TREE OPERATIONS----------\n");
		printf("\n1. CREATE BST\n2. INORDER\n3. PREORDER\n4. POSTORDER\n5. SEARCH\n6. EXIT\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the item to be inserted:\n");
					scanf("%d",&item);
					root = create_BST(root);
					break;
			case 2: if(root==NULL)
				   	printf("\nTree is Empty\n");
					else
					{
				  		printf("Inorder Traversal is:");
				  		inorder_BST(root);
				  		printf("\n");
					}
					break;
			case 3:	if(root==NULL)
				   	printf("\nTree is Empty\n");
					else
					{
				  		printf("Preorder Traversal is:");
				  		preorder_BST(root);
				  		printf("\n");
					}
					break;
			case 4:if(root==NULL)
				  	printf("\nTree is Empty\n");
					else
					{
				  		printf("Postorder Traversal is:");
				  		postorder_BST(root);
				  		printf("\n");
					}
					break;
			case 5:flag=0;
					printf("\nEnter key to search:\n");
					scanf("%d",&key);
					search_BST(root);
					if(flag==1)
				  		printf("\nSuccessfull Search\n");
					else
				  		printf("\nUnsuccessfull Search\n");
					break;
			default:exit(0);
		}
	}
}