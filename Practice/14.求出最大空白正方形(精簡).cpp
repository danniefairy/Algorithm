#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int a[10][10]={
    {1,1,1,1,0,0,0,1,0,1},
    {1,1,1,0,0,0,1,0,1,0},
    {1,1,1,1,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,0,0,0},
    {1,1,1,1,0,1,1,1,1,0},
    {1,1,1,1,0,0,1,1,1,0},
    {1,1,1,1,0,1,1,1,1,0},
    {1,1,1,1,0,1,1,0,0,0},
    {0,1,1,0,0,0,0,0,0,0}};
    int arealength[10][10]={0};
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(i==0&&a[i][j]==1)
                arealength[i][j]=1;
            else if(j==0&&a[i][j]==1)
                arealength[i][j]=1;
            else if(a[i][j]==1)
                arealength[i][j]=min(min(arealength[i-1][j],arealength[i][j-1]),arealength[i-1][j-1])+1;
        }
    } 
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout << setw(3) << arealength[i][j]*arealength[i][j] ;
        }
        cout << endl;
    }    
    system("pause");
    return 0;
}
