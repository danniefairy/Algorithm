#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    double l,w=1,p=0,sum=0;
    cin >> l;
    do
    {
       p=(w*p+l/2)/(w+1);
       w++;
       cout << p << endl;
    }while(w!=10);
    
    system("pause");
    return 0;
}
