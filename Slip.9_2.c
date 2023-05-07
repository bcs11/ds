#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left,*right;
}TREE;

TREE* create(TREE *temp, int no)
{
	if(temp==NULL)
	{
		temp = (TREE *) malloc(sizeof(TREE));
		temp->data = no;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}
	if(no < temp->data)
	{
		temp->left = create(temp->left,no);
	}
	else if(no > temp->data)
	{
		temp->right = create(temp->right,no);
	}

	return temp;
}

TREE* insert(TREE *temp,int no)
{
	if(temp==NULL)
	{
		temp = (TREE *) malloc(sizeof(TREE));
		temp->data = no;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}
	if(no < temp->data)
	{
		temp->left = insert(temp->left,no);
	}
	else if(no > temp->data)
	{
		temp->right = insert(temp->right,no);
	}

	return temp;
}

void postorder(TREE *temp)
{
	if(temp != NULL)
	{
		printf(" %d ",temp->data);
		postorder(temp->left);
		postorder(temp->right);
	}
}

int main()
{
	TREE *root = NULL;

	int ch,n,no;

	do
	{
		printf("\n 1: CREATE");
		printf("\n 2: INSERT");
		printf("\n 3: POSTORDER");
		printf("\n 4: EXIT");

		printf("\n Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: 	printf("\n Enter No. of Nodes : ");
						scanf("%d",&n);
						while(n>0)
						{
							printf("\n Enter Data : ");
							scanf("%d",&no);
							root = create(root,no);
							n--;
						}
						break;
				
			case 2: 	printf("\n Enter Data : ");
						scanf("%d",&n);
						root = insert(root,n);
						break;

			case 3: 	postorder(root);
						break;

			case 4: 	exit(0);
		}
	}while(1);
	
	return 0;
}
