#include <cstdlib>
#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int s[n];
    s[n]=0;
    s[0]=1;
    s[1]=1;
    for(int i=2;i<=n;i++)
        s[i]=s[i-1]+s[i-2];
    cout << s[n];
    system("pause");
    return 0;
}

