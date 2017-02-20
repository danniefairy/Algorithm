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
	show(head);
	system("pause");
	return 0;
}
