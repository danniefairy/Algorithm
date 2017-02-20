#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct node
{
	double height;
	double health;
	int date;
	struct node* link;
};
int main()
{
	double nutrient;
	double water;
	double sunshine;
	double stormdamage;
	
	double deltaheight;
	double deltahealth;
	
	node * root;
	root=(node*)malloc(sizeof(node));
	root->height=0;
	root->health=100;
	root->date=0;
	root->link=NULL;
	
	node *current;
	current=(node*)malloc(sizeof(node));
	root->link=current;
	current->health=root->health;
	current->height=root->height;
	for(int i=1;;i++)
	{
		printf("第%d天\n",i);
		for(int j=1;j<=4;j++)
		{
			_sleep(1000);
			if(kbhit())
			{
				printf("增加肥料(公斤):");
				scanf("%f公斤。",&nutrient);				
				printf("\n");
				printf("澆水(公升):");
				scanf("%f",&water);
			
			}
		}
		srand(time(NULL));
		sunshine=(rand()%100+1)/100;
		_sleep(1000);
		srand(time(NULL));
		stormdamage=(rand()%10+1);
		deltaheight=sqrt(nutrient+10*i-i*i)*(water*water+3-i)*sunshine/10;
		deltahealth=(nutrient-2*i)/10+(water-5)/5-stormdamage;
		current->height=current->height+deltaheight;
		current->health=current->health+deltahealth;
		if(current->height<=0 || current->health<=0)
		{
			printf("死掉了!\n");
			break;
		}
		printf("目前高度:%f\n",current->height);
		printf("目前健康:%f\n",current->health);
		node *next;
		next=(node*)malloc(sizeof(node));
		current->link=next;
		current=next;
		
	}
	system("pause");
	return 0;
}
