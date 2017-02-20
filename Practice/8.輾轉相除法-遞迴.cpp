#include <cstdlib>
#include <iostream>
using namespace std;
int GCD(int a,int b)
{
    
    if(b!=0)
        return GCD(b,a%b) ;
    else
        return a;
}
int main()
{
    int a,b;
    cin >> a;
    cin >> b;
    if(b>a)
        swap(a,b);
    cout << GCD(b,a%b);
    system("pause");
    return 0;
}
