#include<stdio.h>
void main()
{
	int G[10][10],i,j,nov;
	printf("Enter how many vertices =:");
	scanf("%d",&nov);
	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
		{
			printf("Enter edge between %d and %d ",i+1,j+1);
			scanf("%d",&G[i][j]);
		}
	}
	printf("Entered adjancency matrix is \n");
	for(i=0;i<nov;i++)
	{
		for(j=0;j<nov;j++)
		{
			
			printf("%d",G[i][j]);
		}
		printf("\n");
	}
}
