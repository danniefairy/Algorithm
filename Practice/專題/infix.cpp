#include <stdio.h>
#include <stdlib.h>

struct node{
	char x;
	struct node * link;
};

node* push(node* oppush,char cpush){
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->link=oppush;
	temp->x=cpush;
	oppush=temp;
	return oppush;
}

node* pop(node* oppop,char* cpop)
{
	node* temp;
	temp=oppop;
	*cpop=oppop->x;
	oppop=oppop->link;
	free(temp);
	return oppop;
}

bool empty(node* opemp)
{
	if(opemp==NULL)
		return true;
	else
		return false;
}

bool isoperator(char isop)
{
	if(isop=='+'||isop=='-'||isop=='*'||isop=='/')
		return true;
	else 
		return false;
}

int priority(char pri)
{
	switch (pri)
	{
		case '+':
		case '-': return 0; break;
		case '*':
		case '/': return 1; break;
		default: return -1;
	}
		
}

int calculator(int operand1,int operand2,char operators)
{
	switch(operators)
	{
		case '+': return (operand1+operand2);
		case '-': return (operand1-operand2);
		case '*': return (operand1*operand2);
		case '/': return (operand1/operand2);
	}
}

int main(){
	node* operators=NULL;
	node* operands=NULL;
	
	char a[20];
	gets(a);
	int i=0;
	while(a[i]!='\0')
	{	
		if(!isoperator(a[i]))
		{

			if(empty(operators))
			{
				operands=push(operands,a[i]);
			}
				
			else
			{
				char temptor;
				operators=pop(operators,&temptor);
				if(priority(temptor)==1)
				{
					char ctempand;
					int  itempand1;
					int  itempand2;
					operands=pop(operands,&ctempand);
					
					itempand1=ctempand-'0';
					itempand2=a[i]-'0';
					itempand1=calculator(itempand1,itempand2,temptor);
					
					ctempand=itempand1+'0';
					operands=push(operands,ctempand);
				}
				else
				{			
					operands=push(operands,a[i]);
					operators=push(operators,temptor);
				}
					
			}
		}
		else
		{
			operators=push(operators,a[i]);
		}
			
		i++;
	}

	while(true)
	{
		char optemp,optemp1,optemp2,opcheckminus;
		int temp1,temp2;
		if(!empty(operators))
		{
			if(!empty(operators->link))
			{
				operators=pop(operators,&optemp);
				operators=pop(operators,&opcheckminus);
				if(opcheckminus=='-'&&optemp=='-')
				{
					operators=push(operators,'-');
					optemp='+';
					operands=pop(operands,&optemp2);
					operands=pop(operands,&optemp1);
				}
				else if(opcheckminus=='-'&&optemp=='+')
				{
					operators=push(operators,'+');
					optemp='-';
					operands=pop(operands,&optemp1);
					operands=pop(operands,&optemp2);
				}
				else
				{
					operators=push(operators,opcheckminus);
					operands=pop(operands,&optemp2);
					operands=pop(operands,&optemp1);
				}
					
			}
			else
			{
				operators=pop(operators,&optemp);
				operands=pop(operands,&optemp2);
				operands=pop(operands,&optemp1);
			}
			
			temp1=optemp1-'0';
			temp2=optemp2-'0';
			temp1=calculator(temp1,temp2,optemp);
			optemp1=temp1+'0';
			operands=push(operands,optemp1);
			

		}
		else
			break;
	}
	char solution;
	operands=pop(operands,&solution);
	printf("solutioni:%c",solution);
	
	

	
	return 0;
} 
