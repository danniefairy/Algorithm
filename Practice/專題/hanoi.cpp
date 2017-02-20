#include <stdio.h>
#include <stdlib.h>

static int times;

void hanoi(int n,int dish1,int dish2,int dish3)
{
	if(n==1)
	{
		printf("move from dish %d to dish %d\n",dish1,dish3);
		times++;
	}
		
	else
	{
		hanoi(n-1,dish1,dish3,dish2);
		printf("move from dish %d to dish %d\n",dish1,dish3);
		times++;
		hanoi(n-1,dish2,dish1,dish3);
	}
}

int main()
{
	times=0;
	hanoi(10,1,2,3);
	printf("times=%d\n",times);
	return 0;
 } 
