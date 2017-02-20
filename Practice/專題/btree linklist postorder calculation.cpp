#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* right;
	struct node* left;
};

node* createtree(int* data,int pos)
{
	if(pos>7)
		return NULL;
	else
	{
		node* ptr;
		ptr=(node*)malloc(sizeof(node));
		ptr->data=data[pos];
		ptr->right=createtree(data,2*pos+1);
		ptr->left=createtree(data,2*pos);
	}
}
void showinorder(node* ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		showinorder(ptr->left);
		printf("%c" "",ptr->data);		
		showinorder(ptr->right);
	}
}

void showpreorder(node* ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		printf("%c" "",ptr->data);
		showpreorder(ptr->left);				
		showpreorder(ptr->right);
	}
}

void showpostorder(node* ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		showpostorder(ptr->left);
		showpostorder(ptr->right);
		printf("%c" "",ptr->data);
	}
}

int cal(char op,int operand1,int operand2)
{
	switch(op)
	{
		case'+':return (operand1+operand2);
		case'-':return (operand1-operand2);
		case'*':return (operand1*operand2);
		case'/':return (operand1/operand2);
	}
}

int getvalue(node* ptr)
{
	if(ptr->left==NULL&ptr->right==NULL)
	{
		return ptr->data-48;
	}
	else
	{
		int operand1,operand2;
		operand1=getvalue(ptr->left);
		operand2=getvalue(ptr->right);
		return cal(ptr->data,operand1,operand2);
	}
}

int main()
{
	int data[8]={' ','+','*','*','5','6','4','3'};
	node* root;
	int pos=1;
	root=createtree(data,pos);
	showinorder(root);
	printf("=%d",getvalue(root));
	return 0;
}
