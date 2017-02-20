#include <stdio.h>
#include <stdlib.h>

struct node{
	int row;
	int col;
	int data;
	struct node* right;
	struct node* down;
};

node* constructor(int a[7][4],int col,int row)
{
	node* headcol[col];
	node* headrow[row];
	for(int i=0;i<col;i++){
		headcol[i]=(node*)malloc(sizeof(node));
		headcol[i]->data=-1;
		headcol[i]->right=NULL;
		headcol[i]->down=headcol[i];		
	}
	for(int j=0;j<row;j++){
		headrow[j]=(node*)malloc(sizeof(node));
		headrow[j]->data=-1;
		headrow[j]->down=NULL;
		headrow[j]->right=headrow[j];		
	}
	
	for(int i=0;i<col;i++)
	{
		node* ptrcol[i];
		ptrcol[i]=headcol[i];
		for(int j=0;j<row;j++)
		{
			if(a[i][j]!=0)
			{
				node* temp;
				temp=(node*)malloc(sizeof(node));
				temp->col=i;
				temp->row=j;
				temp->data=a[i][j];
				temp->down=headcol[i];
				ptrcol[i]->down=temp;
				ptrcol[i]=temp;
			}
		}
	}
	
	for(int j=0;j<row;j++)
	{
		node* ptrrow[j];
		ptrrow[j]=headrow[j];
		for(int i=0;i<col;i++)
		{
			node* ptrcol;
			ptrcol=headcol[i]->down;

			while(ptrcol->data!=-1)
			{
				if(ptrcol->col==i&&ptrcol->row==j)
					break;
				ptrcol=ptrcol->down;
			}
			if(ptrcol->data!=-1)
			{
				ptrrow[j]->right=ptrcol;
				ptrcol->right=headrow[j];
				ptrrow[j]=ptrcol;	
				}						
		}
	}
	//printf("data=%d,col=%d,row=%d\n",headcol[2]->down->data,headcol[2]->down->col,headcol[2]->down->row);
	//printf("%d",headrow[3]->right->right->data);
}

int main()
{
	int a[7][4]={{0,0,2,0},
				 {0,0,0,0},
				 {0,1,0,0},
				 {3,0,0,2},
				 {0,0,0,0},
				 {0,0,9,0},
				 {0,0,0,1}};
	int col=sizeof(a)/sizeof(a[0]);
	int row=sizeof(a[0])/4;
	constructor(a,col,row);
	
	
	return 0;
 } 
 
 
