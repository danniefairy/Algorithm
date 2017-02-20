#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int a[100]={-1},n=0;
    do
    {
        int t;
        cin >> t;
        if(t==0||t==1)
            a[n]=t;
        else
            break;
        n++;
    }while(1);  
    int c1=0,c2=0,num1=-1,num2=-1;
    for(int i=0;a[i]!=-1;i++)
    {
       if(a[i]==1&&c1==0)
       {
           num1=i;
           c1++;
       }
       else if(a[i]==1&&c1!=0)
           c1++;
       else if(a[i]==0&&c1>c2)
       {
           num2=num1;
           num1=-1;
           c2=c1;
           c1=0;           
       }
        else if(a[i]==0&&c1<=c2)
        {
            c1=0;
            num1=-1; 
        }
    }
    
    cout << endl << num2+1 << endl << c2 << endl;
    system("pause");
    return 0;
}

