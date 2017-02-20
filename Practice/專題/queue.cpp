#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node* link;
};

node *constructor(node* a,int *front,int *rear)
{
	a=(node*)malloc(sizeof(node));
	a->x=-100;
	a->link=NULL;
	*front=-1;
	*rear=-1;
	return a;
}

node *enqueue(node* a,int x,int *front,int *rear)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->link=NULL;
	
	*rear=*rear+1;

	if(*rear==0)
	{
		a=temp;
		return a;
	}
	
	int count=*rear;
	node* ptrrear=a;
	while((count-1)!=0)
	{
		ptrrear=ptrrear->link;
		count--;
	}
	ptrrear->link=temp;
	return a;
}

node *dequeue(node* a,int *x,int *front,int *rear)
{
	node* ptrfront;
	*front=*front+1;
	if(*front>*rear)
	{
		printf("no data in queue!\n");
		*front=-1;
		*rear=-1;
		return 0;
	}
	ptrfront=a;
	*x=a->x;
	a=a->link;
	free(ptrfront);
	return a;
}

int main()
{
	node* a;
	int front;
	int rear;
	a=constructor(a,&front,&rear);
	
	while(true)
	{
		int x;
		scanf("%d",&x);
		if(x==-100)
			break;
		a=enqueue(a,x,&front,&rear);
	}
	
	
	while(true)
	{
		int xout;
		a=dequeue(a,&xout,&front,&rear);
		if(front==-1)
			break;
		printf("No.%d in queue is %d\n",front,xout);
		
	}
	

	
	
	return 0;
 } 
