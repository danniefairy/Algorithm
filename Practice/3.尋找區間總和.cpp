#include <cstdlib>
#include <iostream>
using namespace std;
struct G{int a,b;};

int main()
{
     int a[5]={3,6,1,7,2},sum=0;
    for(int i=0,j=-1;;)
    {
        if(sum<=10)
        {
            j++;
            sum+=a[j];
            if(sum==10)
                cout << i << " " << j << " " << sum<<  endl;
            if(j==4)
                break;
        }
        else if(sum>10)
        {
             sum-=a[i];
             i++;
        }
       
    }
    system("pause");
    return 0;
}
