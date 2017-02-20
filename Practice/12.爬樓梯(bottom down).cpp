#include <cstdlib>
#include <iostream>

using namespace std;

int count(int n)
{
     if(n>=3)
     {
         return (count(n-1)+count(n-2));
     }
     else if(n==2||n==1)
     {
         return n;
     }
 }

int main()
{
    int n;
    cin >> n;
    cout << count(n);
    system("pause");
    return 0;
}

