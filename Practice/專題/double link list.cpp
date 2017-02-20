#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	struct node* flink;
	struct node* blink;
};

node* front =NULL;
node* rear =NULL;

node* constructor(node* a)
{
	a=(node*)malloc(sizeof(node));
	a->x=-100;
	a->flink=NULL;
	a->blink=NULL;
	return a;
}

node* fenqueue(node *a,int x)
{
	if(a->x==-100)
	{
		a->x=x;
		return a;
	}
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->flink=NULL;
	node* ptr;
	ptr=rear;
	temp->blink=ptr;
	rear->flink=temp;
	rear=rear->flink;
}

int fdequeue()
{
	node* ptr;
	ptr=front;
	int x=ptr->x;
	if(front->flink==NULL)
	{
		free(ptr);
		return x;
	}
	front->blink=NULL; 
	front=front->flink;
	front->blink=NULL;
	
	free(ptr);
	return x;
}

node* benqueue(node* a,int x)
{
	if(a->x==-100)
	{
		a->x=x;
		return a;
	}

	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->flink=front;
	temp->blink=NULL;
	front->blink=temp;
	front=temp;

}

int bdequeue()
{
	node* ptr;
	ptr=rear;
	int x=ptr->x;
	if(rear->blink==NULL)
	{
		free(ptr);
		return x;
	}
	rear=rear->blink;
	rear->flink=NULL;
	free(ptr);
	return x;
}

int main()
{
	node* a;
	a=constructor(a);
	front=a;
	rear=a;	
	while(true){//garbage input little problem
	
	printf("f for froward,b for backward!\n");
	char c1;
	char garbage;
	scanf("%c",&garbage);
	scanf("%c",&c1);
	if(c1=='f')
	{
		printf("e for enqueue,d for dequeue!\n");
				
		char c2;
		char garbage;
		scanf("%c",&garbage);
		scanf("%c",&c2);
		if(c2=='e')
		{
			printf("enter number for queue:\n");
			int x;
			scanf("%d",&x);
			fenqueue(a,x);
		}
		else 
		{
			printf("forward dequeue from queue :%d\n",fdequeue());
		}
	}
	else
	{
		printf("e for enqueue,d for dequeue!\n");
		char c3;
		char garbage;
		scanf("%c",&garbage);
		scanf("%c",&c3);
		if(c3=='e')
		{
			printf("enter number for queue:\n");
			int x;
			scanf("%d",&x);
			benqueue(a,x);
		}
		else
		{
			printf("backward dequeue from queue :%d\n",bdequeue());
		}
	}		


		
	}

	return 0;
}
