#include <cstdlib>
#include <iostream>
using namespace std;
void move(int n,char o,char r,char t)
{
    if(n==1)
        cout << "±q" << o << "²¾°Ê¨ì" << t << endl;
    
    else
    {
        move(n-1,o,t,r);
        move(1,o,r,t);
        move(n-1,r,o,t);
    } 
}

int main()
{
    int n;
    cin >> n;


    move(n,'A','B','C');
    
    system("pause");
    return 0;
}
