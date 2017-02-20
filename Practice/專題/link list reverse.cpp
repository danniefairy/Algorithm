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
node* reversenode(node *ptrr)
{
	//initialize
	node* left;
	node* mid;
	node* right;
	//head
	left=NULL;
	mid=ptrr;
	right=ptrr->link;
	//middle
	while(right->link!=NULL)
	{
		mid->link=left;
		left=mid;
		mid=right;
		right=right->link;
	}
	//tail
	mid->link=left;
	right->link=mid;

	return right;
			
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
	head=reversenode(head);
	show(head);
	system("pause");
	return 0;
}
