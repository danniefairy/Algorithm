#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
struct node{
	int data;
	struct node* right;
	struct node* left;
};

void insert(node* root,int* data)
{
	root->data=data[0];
	root->right=NULL;
	root->left=NULL;
	for(int i=1;i<MAX;i++)
	{
		if(data[i]==-1)
			break;
		node* ptr;
		ptr=root;
		while(true)
		{
			if(data[i]>=ptr->data)
			{
				//printf("right\n");
				if(ptr->right==NULL)
				{
					node* temp;
					temp=(node*)malloc(sizeof(node));
					ptr->right=temp;
					temp->data=data[i];
					temp->right=NULL;
					temp->left=NULL;
					break;
				}
				else
					ptr=ptr->right;
			}
			else
			{
				//printf("left\n");
				if(ptr->left==NULL)
				{
					node* temp;
					temp=(node*)malloc(sizeof(node));
					ptr->left=temp;
					temp->data=data[i];
					temp->right=NULL;
					temp->left=NULL;
					break;
				}
				else
					ptr=ptr->left;
			}
			
		}
	}
	//printf("%d",root->left->right->data);
}

void findnode(node* root,int target)
{
	node* ptr =root;
	while(ptr!=NULL)
	{
		if(target>ptr->data)
		{
			ptr=ptr->right;
			printf("Go right\n");
		}			
		else if(target <ptr->data)
		{
			ptr=ptr->left;
			printf("Go left\n");	
		}			
		else if(target==ptr->data)
		{
			printf("Find the target\n");
			return ;
		}	
	}
	printf("Can't find the target!\n");
}

int main()
{
	node* root;
	root=(node*)malloc(sizeof(node));
	int data[MAX];
	int count=0;
	int input;
	memset(data,-1,MAX*sizeof(int));
	while(true)
	{
		scanf("%d",&input);
		if(count==MAX||input==-1)
			break;
		data[count]=input;
		count++;
	}
	insert(root,data);
	int target;
	printf("Insert target:");
	scanf("%d",&target);
	findnode(root,target);
	return 0;
}
