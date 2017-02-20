#include <cstdlib>
#include <iostream>
using namespace std;

void draw(int p)//10*10piture
{
     int tempy[2]={0};
     for(int x=0;x<10;x++)
     {
         for(int y=0;y<10;y++)
         {
             int i=0;
             if(p[x][y]==1)
             {
                 tempy[i]=y;
                 i++;
             }                 
         }
         for(int y=tempy[1],y<=tempy[2],y++)
             p[x][y]=1;
     }
}

int main()
{

    system("pause");
    return 0;
}
