#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int p[1000]={0};
    p[0]=2;
    for(int i=3;i<1000;i++)
    {
            int j=0;
            while(p[j]!=0)
            {
                if((i%p[j]!=0)&&i>p[j])
                {
                    if(p[j+1]==0)
                        p[j+1]=i;
                }
                else
                    break;
                j++;
            }
    }
    for(int k=0;p[k]!=0;k++)
        cout << p[k] << endl;
    system("pause");
    return 0;
}
