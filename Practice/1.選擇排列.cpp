#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int a[100],i=0;
    cout << "輸入123456789時跳出" << endl; 
    do
    {
        cout << "請輸入第" << i+1 << "的數 ";
        cin >> a[i];
        cout << endl;
        i++;
    }while(a[i-1]!=123456789);
   
    int num;

    for(int j=0;j<i-1;j++)
    {
            int small=100000000;
            for(int k=j;k<i-1;k++)
            {
                if(a[k]<small)
                {
                    small=a[k]; 
                    num=k;       
                }
                    
            }
            swap(a[j],a[num]);
    }
    cout << "重新排列後為:" << endl; 
    for(int k=0;k<i-1;k++)
        cout << a[k] << "  ";
    cout << endl;
    system("pause");
    return 0;
}
