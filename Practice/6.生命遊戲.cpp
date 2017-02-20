#include <cstdlib>
#include <iostream>

using namespace std;
int decision(int x,int y,int a[5][5]);

int main()
{

    
    int a[5][5]={0},temp[5][5]={0},x,y;

    do
    {
        cout << "輸入行座標:";
        cin >> x;
        cout << "輸入列座標:";
        cin >> y;
        cout << endl;
        a[x][y]=1;
    }while(x<5||y<5);
    system("cls");
    int count=0;
    int t=0;
    cout << "第"<<t<<"張圖:"<<endl; 
    for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout << a[i][j];
            } 
            cout << endl;
        }
    system("pause");
    system("cls");
    do
    {
        t++;
        count=0;
        cout << "第"<<t<<"張圖:"<<endl; 
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                int d=decision(i,j,a);
                if(a[i][j]==0&&d==3)
                    temp[i][j]=1;
                else if(a[i][j]==1&&(d==2||d==3))
                     temp[i][j]=1;
                else if(a[i][j]==1&&(d==0||d==1))
                     temp[i][j]=0;   
                else if(a[i][j]==1&&(d>=4))
                     temp[i][j]=0;
               
                     
            }
        }
      
        
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                cout << temp[i][j];
                a[i][j]=temp[i][j];
            } 
            cout << endl;
        }
        
        
        system("pause");
        system("cls");
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                count=count+a[i][j];

    }while(count>0);
    system("pause");
    return 0;
}
int decision(int x,int y,int a[5][5])
{
    int count=0;
    if(x==0&&y==0)
    {
        count=count+a[x+1][y];
        count=count+a[x+1][y+1];
        count=count+a[x][y+1];
    }
    else if(x==5-1&&y==0)
    {
        count=count+a[x-1][y];
        count=count+a[x-1][y+1];
        count=count+a[x][y+1];
    }
    else if(x==0&&y==5-1)
    {
        count=count+a[x][y-1];
        count=count+a[x+1][y-1];
        count=count+a[x+1][y];
    }
    else if(x==5-1&&y==5-1)
    {
        count=count+a[x-1][y];
        count=count+a[x-1][y-1];
        count=count+a[x][y-1];
    }
    else if(x>0&&x<5-1&&y==0)
    {
        count=count+a[x+1][y];
        count=count+a[x+1][y+1];
        count=count+a[x][y+1];
        count=count+a[x-1][y+1];
        count=count+a[x-1][y];
    }
     else if(x>0&&x<5-1&&y==5-1)
    {
        count=count+a[x+1][y];
        count=count+a[x+1][y-1];
        count=count+a[x][y-1];
        count=count+a[x-1][y-1];
        count=count+a[x-1][y];
    }
      else if(x==0&&y>0&&y<5-1)
    {
        count=count+a[x][y-1];
        count=count+a[x+1][y-1];
        count=count+a[x+1][y];
        count=count+a[x+1][y+1];
        count=count+a[x][y+1];
    }
     else if(x==5-1&&y>0&&y<5-1)
    {
        count=count+a[x][y-1];
        count=count+a[x-1][y-1];
        count=count+a[x-1][y];
        count=count+a[x-1][y+1];
        count=count+a[x][y+1];
    }
    else if(x>0&&x<5-1&&y>0&&y<5-1)
    {
         for(int i=0;i<=2;i++)
             for(int j=0;j<=2;j++)
             {
                 count=count+a[x-1+i][y-1+j];
             }
         count=count-a[x][y];
    }
    return count;
}
