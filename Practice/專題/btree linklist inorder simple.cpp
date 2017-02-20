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
					//printf("insert data %d\n",data[i]);
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
					//printf("insert data %d\n",data[i]);
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

}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);	
	} 
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
	//printf("%d",root->right->left->data);
	inorder(root);
	
	return 0;
}
