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

void deletemethod(node* ,int,int);
int deletenode(node* root,int target)
{
	int method,direction;
	if(root==NULL)
	{
		printf("can't find target");
		return -1;
	}
	if(target>root->data)
	{
		printf("right\n");
		method=deletenode(root->right,target);
		printf("return right\n");
		direction=1;
		if(root->right->data==target)
			deletemethod(root,method,direction);
	}
	else if(target<root->data)
	{
		printf("left\n");
		method=deletenode(root->left,target);
		printf("return left\n");
		direction=0;
		if(root->left->data==target)
			deletemethod(root,method,direction);
	}
	else
	{
		printf("find target!\n");
		if(root->right==NULL&&root->left==NULL)//常礚 
			return 0;
		else if(root->right==NULL&&root->left!=NULL)//礚 
			return 1;
		else if(root->right!=NULL&&root->left==NULL)//オ礚 
			return 2;
		else //常Τ 
			return 3;
	}
}

void deletemethod(node* ptr,int method,int direction)
{
	if(method==0)//常礚 
	{
		if(direction==0)
		{
			printf("delete node %d complete!\n",ptr->left->data);
			free(ptr->left);
		}
			
		else
		{
			printf("delete node %d complete!\n",ptr->right->data);
			free(ptr->right);
		}
	}
	else if(method==1)//礚 
	{
		if(direction==0)
		{
			printf("delete node %d complete!\n",ptr->left->data);
			node* temp;
			temp=ptr->left;
			ptr->left=ptr->left->left;
			free(temp);
		}
			
		else
		{
			printf("delete node %d complete!\n",ptr->right->data);
			node* temp;
			temp=ptr->right;
			ptr->right=ptr->right->left;
			free(temp);
		}
	}
	else if(method==2)//オ礚 
	{
		if(direction==0)
		{
			printf("delete node %d complete!\n",ptr->left->data);
			node* temp;
			temp=ptr->left;
			ptr->left=ptr->left->right;
			free(temp);
		}
			
		else
		{
			printf("delete node %d complete!\n",ptr->right->data);
			node* temp;
			temp=ptr->right;
			ptr->right=ptr->right->right;
			free(temp);
		}
	}
	else//常Τ 
	{
		if(direction==0)
		{
			printf("delete node %d complete!\n",ptr->left->data);
			node* newptr=ptr->left;
			if(newptr->left->right==NULL)
			{
				ptr->left=newptr->left;
				free(newptr);
			}
			else
			{
				node* rightptr=newptr->left;
				while(rightptr->right!=NULL)
					rightptr=rightptr->right;
				newptr->data=rightptr->data;
				free(rightptr);
			}	
		}
			
		else
		{
			printf("delete node %d complete!\n",ptr->right->data);
			node* newptr=ptr->right;
			if(newptr->left->right==NULL)
			{
				ptr->right=newptr->left;
				free(newptr);
			}
			else
			{
				node* rightptr=newptr->left;
				while(rightptr->right!=NULL)
					rightptr=rightptr->right;
				newptr->data=rightptr->data;
				free(rightptr);
			}
		}
	}
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
	printf("Insert delete node:");
	scanf("%d",&target);
	deletenode(root,target);

	printf("Insert targt:");
	scanf("%d",&target);
	findnode(root,target);
	return 0;
}
