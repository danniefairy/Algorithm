#include <cstdlib>
#include <iostream>
#include <iomanip>
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
    

    int i,j,w=100,wt=0,h=0,area=0,H=0,W=0;
    for(int x=0;x<10;x++)
    {
        for(int y=0;y<10;y++)
        {

            j=y;
            for(i=x;i<10&&a[i][j]!=0;i++)
            {
                for(j=y;j<10&&a[i][j]!=0;j++)
                {
                    wt++;
                    
                }        
                if(wt<=w)
                w=wt;
                wt=0;
                h++;
                j=y;
    
                if(h*w>area)
                {
                    area=h*w;
                    H=h;
                    W=w;
                }
                

            }
            if(w==100)
                w=0;
            cout <<"x="<< setw(2)<< x <<" y="<< setw(2)<<y <<" h=" << setw(2)<< (H) << " w=" << setw(2)<<(W) << " area="<< setw(2)<<area<< endl;
            h=0;
            w=100;
            wt=0;
            H=0;
            W=0;
            area=0;
        }
        cout << endl;
        w=100;
        wt=0;
       
    }
    
  
    system("pause");
    return 0;
}
