#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
void insert(int *btree,int *num)
{
	for(int i=0;i<MAX;i++)
	{
		if(i==0)
		{
			//printf("btree[0]=%d\n",btree[0]);
			btree[0]=num[0];
		}
		else if(num[i]!=-1)
		{
			int j=1;
			while(true)
			{
				if(btree[j-1]>num[i])//left
				{
					//printf("btree[%d]=%d>num[%d]=%d\n",j-1,btree[j-1],i,num[i]);
					//printf("btree[%d]=%d\n",2*j-1,btree[2*j-1]);
					if(btree[2*j-1]==-1)
					{
						btree[2*j-1]=num[i];
						//printf("btree[%d]=%d\n",2*j-1,btree[2*j-1]);
						break;
					}
					else
						j=2*j;
				}
				else//right
				{
					//printf("btree[%d]=%d<=num[%d]=%d\n",j-1,btree[j-1],i,num[i]);
					//printf("btree[%d]=%d\n",2*j,btree[2*j]);
					if(btree[2*j]==-1)
					{
						btree[2*j]=num[i];
						//printf("btree[%d]=%d\n",2*j,btree[2*j]);
						break;
					}
					else
						j=2*j+1;
				}
			}
		}
		else
			break;
	}
	
}

void show(int *btree)
{
	printf("\n\n");
	for(int i=0;i<MAX;i++)
	{
		printf("%d\n",btree[i]);
	}
}

int main()
{
	int num[MAX];
	memset(num,-1,MAX*sizeof(int));
	int input;
	int count=0;
	while(true)
	{
		scanf("%d",&input);
		if(input==-1||count>=MAX)
			break;
		num[count]=input;
		count++;
	}
	int btree[MAX];
	memset(btree,-1,MAX*sizeof(int));
	insert(btree,num);
	show(btree);
	
	
	return 0;
}
