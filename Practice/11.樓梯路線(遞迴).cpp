#include <cstdlib>
#include <iostream>

using namespace std;

int stair(int i,int j)
{
    if(i==0&&j==0)
        return 1;
    else if(i==0&&j>0)
        return stair(i,j-1);
    else if(i>0&&j==0)
        return stair(i-1,j);
    else if(i>0&&j>0)
        return stair(i-1,j)+stair(i,j-1);  
}

int main()
{
    int i,j;
    cin >> i;
    cin >> j;
    cout << stair(i,j);
    
    system("pause");
    return 0;
}

