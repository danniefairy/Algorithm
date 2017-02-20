#include <cstdlib>
#include <iostream>
using namespace std;

void sorting(string s)
{
    char a[100][2]={0};
    int i,c=0;
    for(i=0;s[i]!=0;i++)
    {
        a[s[i]-'a'][0]=s[i];
        a[s[i]-'a'][1]++;
    }
    do
    {
        for(int t=c;i<26;t++)
        {
            if(a[t][0]!=0)
            {
                a[c][0]=a[t][0];
                a[c][1]=a[t][1];
                if(t!=c)
                {
                    a[t][0]=0;
                    a[t][1]=0;
                }
                break;
            }  
        }
        c++;     
    }while(c<=26);
 
    for(int k=0;k+a[k][1]-1<i;k++)
        cout << a[k][0];    
}
int main()
{
    string s;
    int i;
    cin >> s;
    sorting(s);
    
    system("pause");
    return 0;
}
