#include <stdio.h>
#include <stdlib.h>

struct node{
	int x,y;
	int th;
	struct node* link;
};

node* push(node* ptr,int x,int y,int th)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->y=y;
	temp->th=th;
	temp->link=ptr;
	ptr=temp;
	return ptr;
}

node* pop(node* ptr)
{
	node*temp;
	temp=ptr;
	ptr=ptr->link;
	free(temp);
	return ptr;
}

int main(){
	int a[7][12]={1,1,1,1,1,1,1,1,1,1,1,1,
				  1,0,0,0,1,0,0,0,0,0,0,1,
				  1,1,1,0,1,0,1,0,1,0,1,1,
				  1,0,0,0,1,0,1,0,1,0,1,1, 
				  1,0,1,1,1,0,1,0,1,1,1,1,
				  1,0,0,0,0,0,1,0,0,0,0,10,
				  1,1,1,1,1,1,1,1,1,1,1,1};
	node *start=NULL;
	int x=1;
	int y=1;
	int th=2;
	start=push(start,x,y,th);
	a[x][y]=2;
	while(true)
	{
		
		if(a[x][y+1]==0)
		{
			start=push(start,x,y+1,2);
			a[x][y+1]=2;
			x=x;
			y=y+1;
		}
		else if(a[x][y+1]==10)
		{
			start=push(start,x,y+1,10);
			break;
		}

		else if(a[x-1][y]==0)
		{
			start=push(start,x-1,y,2);
			a[x-1][y]=2;
			x=x-1;
			y=y;
		}
		else if(a[x-1][y]==10)
		{
			start=push(start,x-1,y,10);
			break;
		}
		
		else if(a[x][y-1]==0)
		{
			start=push(start,x,y-1,2);
			a[x][y-1]=2;
			x=x;
			y=y-1;
		}
		else if(a[x][y-1]==10)
		{
			start=push(start,x,y-1,10);
			break;
		}
		
		else if(a[x+1][y]==0)
		{
			start=push(start,x+1,y,2);
			a[x+1][y]=2;
			x=x+1;
			y=y;
		}
		else if(a[x+1][y]==10)
		{
			start=push(start,x+1,y,10);
			break;
		}
		
		else
		{
			start=pop(start);
			x=start->x;
			y=start->y;
		}
		
		//print trace
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<12;j++)
			{
				printf("%d,",a[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");	
				
	}
	while(start!=NULL)
	{
		printf("(%d,%d)\n",start->x,start->y);
		start=pop(start);
		
	}
	return 0;
} 
