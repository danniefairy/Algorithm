#include <cstdlib>
#include <iostream>
using namespace std;
struct G
{
    int in;
    int out;
};

void num(G g[],int i)
{
     int large=0,T[10000]={0};
     for(int t=0;t<=10000;t++)
     {
         int count =0;
         for(int j=0;j<i-1;j++)
         {
             
             if(g[j].in<=t&&g[j].out>=t)
                 count++;
         }
         T[t]=count;
         if(large<=count)
         {
             large=count;
         }
     }
    cout << "�H��̦h��: " << large << "�H" << endl; 
    cout << "�b";
    for(int t=0;t<10000;t++)
    {
            if(T[t]==large)
                cout << "��"<< t << "�� ,  ";
    }
     return;
 }
int main()
{
     G g[100];
     int i=0;
     do
     {
         cout << "�п�J��" << i+1 << "�Ӯȫȶi�J���ɶ�: ";
         cin >> g[i].in;
         cout << "�п�J��" << i+1 << "�ӮȫȥX�h���ɶ�: ";
         cin >> g[i].out;
         cout << endl;
         i++;
     }while((g[i-1].out-g[i-1].in)>0);
     num(g,i);
    system("pause");
    return 0;
}
