#include <cstdlib>
#include <iostream>
using namespace std;
int GCD(int a,int b)
{
    if(b>a)
        swap(a,b);
    
    while(a%b!=0)
    {
        int temp;
        temp=b;
        b=a%b;
        a=temp;    
    }
    return b ;
}
int main()
{
    int a,b;
    cin >> a;
    cin >> b;
    cout << GCD(a,b);
    system("pause");
    return 0;
}
