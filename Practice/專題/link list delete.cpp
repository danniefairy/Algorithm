#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	struct node *link;	
};

void show(node *ptrs){
	while(ptrs!=NULL)
	{
		printf("No. %d node!\n",ptrs->x);
		ptrs=ptrs->link;
	}
}
node* deletenode(node *ptrd,int num)
{
		
	if(num==0)
	{
		ptrd=ptrd->link;
		return ptrd;
	}
	else
	{
		node* ptr;
		ptr=ptrd;
		
		while(ptrd!=NULL)
		{
			//printf("+%d\n",num);
			num--;
			if(num==0)
			{

				node* dtemp;
			    dtemp=ptr->link;
			    ptr->link=dtemp->link;
				//printf("-%d\n",num);
				free(dtemp);
				return ptrd;
			}
			else if(ptr->link!=NULL)
				ptr=ptr->link;
			else
				break;
			
		}
	}
}
int main()
{
	node *head;
	head=(node*)malloc(sizeof(node));
	head->x=0;
	head->link=NULL;
	node *ptr=head;
	for(int i=1;i<=10;i++)
	{
		node* temp=(node*)malloc(sizeof(node));
		temp->link=NULL;
		temp->x=i;
		ptr->link=temp;
		ptr=temp;
	}
	int dnum;
	scanf("%d",&dnum);
	head=deletenode(head,dnum);
	show(head);
	system("pause");
	return 0;
}
