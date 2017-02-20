#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    int m,n;
    cin >> m;
    cin >> n;
    int a[m][n];
    for(int i=0;i<n;i++)
        a[0][i]=1;
    for(int i=0;i<m;i++)
        a[i][0]=1;
    for(int x=1;x<m;x++)
        for(int y=1;y<n;y++)
            a[x][y]=a[x-1][y]+a[x][y-1];

    
    for(int x=0;x<m;x++)
    {
        for(int y=0;y<n;y++)
        {
            cout << setw(8) << a[x][y];
            
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
