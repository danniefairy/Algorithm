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
node* insertnode(node *ptri,int num)
{
		
	if(num==0)
	{
		node* itemp;
		itemp=(node*)malloc(sizeof(node));
		printf("insert number:");
		scanf("%d",&itemp->x);
		itemp->link=ptri;
		ptri=itemp
		;
		return ptri;
	}
	else
	{
		node* ptr;
		ptr=ptri;
		
		while(ptri!=NULL)
		{
			//printf("+%d\n",num);
			num--;
			if(num==0)
			{

				node* itemp;
				itemp=(node*)malloc(sizeof(node));
				printf("insert number:");
				scanf("%d",&itemp->x);
				
			    itemp->link=ptr->link;
			    ptr->link=itemp;
				//printf("-%d\n",num);

				return ptri;
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
	int inum;
	scanf("%d",&inum);
	head=insertnode(head,inum);
	show(head);
	system("pause");
	return 0;
}
