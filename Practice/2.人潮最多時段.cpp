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
    cout << "人潮最多有: " << large << "人" << endl; 
    cout << "在";
    for(int t=0;t<10000;t++)
    {
            if(T[t]==large)
                cout << "第"<< t << "分 ,  ";
    }
     return;
 }
int main()
{
     G g[100];
     int i=0;
     do
     {
         cout << "請輸入第" << i+1 << "個旅客進入的時間: ";
         cin >> g[i].in;
         cout << "請輸入第" << i+1 << "個旅客出去的時間: ";
         cin >> g[i].out;
         cout << endl;
         i++;
     }while((g[i-1].out-g[i-1].in)>0);
     num(g,i);
    system("pause");
    return 0;
}
