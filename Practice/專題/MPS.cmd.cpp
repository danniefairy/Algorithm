#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class object{
    public :
        int name;//物件名稱 
        int num;//物件編號 
        int supnum[10];//上級物件編號 
        int lt;//生產提早 
        int m;//倍數multiple
        int b;//批量batch 
        int level;//順位
        int s[10];//存貨stock
        int gr[10];//毛需求 gro requirements
        int nd[10];//淨需求 net demand 
        int r[10];//訂單接收量 receive
        int o[10];//訂單開立量 order 
       
         
   
};

void constructor(object a[10][10])//初始化 
{
     for(int i=0;i<10;i++)
     {
         for(int j=0;j<10;j++)
         {
             a[i][j].name=-1;
             a[i][j].num=-1;
             a[i][j].lt=-1;
             a[i][j].b=-1; 
             a[i][j].level=-1;
             for(int k=0;k<10;k++)
             {
                 a[i][j].supnum[k]=-1;//_multiple_levelnum _num
                 a[i][j].s[k]=0;
                 a[i][j].gr[k]=0;
                 a[i][j].nd[k]=0;
                 a[i][j].r[k]=0;
                 a[i][j].o[k]=0;
             }
         }
     }
    
}

int searchnum(object a[10][10],int name,int levelnum)//將編號轉成位置 
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(a[i][j].name==name&&i==(levelnum-1))
            {
                cout << "請輸入一個(" << name << ")需要多少材料?";
                int m;
                cin >> m; 
                return (100*m+10*i+j);   
            }                         
        }
    }
    cout << "找不到此上層編號!" << endl;
    return 0; 
            
}


void findsupnum(object a[10][10],int name,int levelnum,int objnum)//找上層位置 
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(a[i][j].name==name&&a[i][j].num!=-1&&i<levelnum)
            {
                int m;
                for( m=0;a[i][j].supnum[m]!=-1;m++)
                {
                    a[levelnum][objnum].supnum[m]=a[i][j].supnum[m];
                    a[i][j].supnum[m]=-1;
                }
                cout << "請輸入上層編號:";
                char csupname;
                cin >> csupname; 
                int supname;
                supname=csupname-'A'+1;                               
                a[levelnum][objnum].supnum[m]=searchnum(a,supname,levelnum);  
                a[levelnum][objnum].num=objnum;
                a[levelnum][objnum].level=levelnum;
                a[i][j].num=-1;  
                a[i][j].level=-1;  
                return ;                       
            }
        }
    }

    cout << "請輸入上層編號:";
    char csupname;
    cin >> csupname; 
    int supname;
    supname=csupname-'A'+1;
    a[levelnum][objnum].supnum[0]=searchnum(a,supname,levelnum);   
    a[levelnum][objnum].num=objnum;
    a[levelnum][objnum].level=levelnum;
}

void fillin(object a[10][10],int levelnum,int objnum)//計算 
{
    if(levelnum!=0)
    {
        for(int k=0;a[levelnum][objnum].supnum[k]!=-1;k++)
        {
            for(int t=0;t<10;t++)
            {
                a[levelnum][objnum].gr[t]=a[levelnum][objnum].gr[t]+a[a[levelnum][objnum].supnum[k]%100/10][a[levelnum][objnum].supnum[k]%10].o[t]*(a[levelnum][objnum].supnum[k]/100);
            }
        }
    }
     for(int i=1;i<=10;i++)
     {
         if(a[levelnum][objnum].gr[i-1]>0)
             a[levelnum][objnum].nd[i-1]=a[levelnum][objnum].gr[i-1]- a[levelnum][objnum].s[i-1];
         else
             a[levelnum][objnum].nd[i-1]=0;
         int tempbnum;
         if(a[levelnum][objnum].nd[i-1]!=0&&(a[levelnum][objnum].nd[i-1]!=a[levelnum][objnum].nd[i-1]/ a[levelnum][objnum].b*a[levelnum][objnum].b))
             tempbnum=a[levelnum][objnum].nd[i-1]/ a[levelnum][objnum].b+1;
         else if(a[levelnum][objnum].nd[i-1]!=0&&(a[levelnum][objnum].nd[i-1]==a[levelnum][objnum].nd[i-1]/ a[levelnum][objnum].b*a[levelnum][objnum].b))
             tempbnum=a[levelnum][objnum].nd[i-1]/ a[levelnum][objnum].b;
         else
             tempbnum=0;
         a[levelnum][objnum].r[i-1]=tempbnum*a[levelnum][objnum].b;
        
         a[levelnum][objnum].o[i-1-a[levelnum][objnum].lt]=a[levelnum][objnum].r[i-1];
         if(i!=10&&a[levelnum][objnum].nd[i-1]!=0)
             a[levelnum][objnum].s[i]=a[levelnum][objnum].r[i-1]-a[levelnum][objnum].nd[i-1];
         else if(i!=10&&a[levelnum][objnum].nd[i-1]==0)
             a[levelnum][objnum].s[i]=a[levelnum][objnum].s[i-1];
     }
}

int main()
{
    object a[10][10];
    constructor(a);
    int levelnum=0;
    char choose,ch;
    do
    {
        if(levelnum==0)
        {
            a[levelnum][0].level=levelnum;
            a[levelnum][0].num=0;
            cout << "請輸入主物件編號:";
            char name;
            cin >>  name;
            a[levelnum][0].name=name-'A'+1;
            cout << "請輸入LT:";
            cin >>  a[levelnum][0].lt;
            cout << "請輸入批量:";
            cin >> a[levelnum][0].b;
            cout << "請輸入存貨量:";
            cin >> a[levelnum][0].s[0];
            do
            {
                int w;
                cout << "請輸入週次:";
                cin >> w;
                cout << "請輸入分量:";
                cin >> a[levelnum][0].gr[w-1];
                cout << "是否再輸入週次份量?Y/N ";
                cin >> ch; 
            }while(toupper(ch)=='Y');
            fillin(a,levelnum,0);
        }
        else
        {
            cout << "第" << levelnum << "層" << endl;
            cout << "請輸入有多少物件" ;
            int objnum;
            cin >> objnum;
            for(int t=0;t<objnum;t++)
            {
                cout << "請輸入物件編號:";
                char name;
                cin >>  name;
                a[levelnum][t].name=name-'A'+1;
                findsupnum(a,a[levelnum][t].name,levelnum,t);
                cout << "請輸入LT:";
                cin >>  a[levelnum][t].lt;
                cout << "請輸入批量:";
                cin >> a[levelnum][t].b;
                cout << "請輸入存貨量:";
                cin >> a[levelnum][t].s[0];
                cout << endl;
                
            }
        }
      
        
        
        levelnum++;
        cout << "是否有下一層?";
        cin >> choose;
        cout << endl << endl;
        choose=toupper(choose);
    }while(choose=='Y');
    for(int i=1;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(a[i][j].name!=-1&&a[i][j].num!=-1)
                     fillin(a,i,j);
            }
        }  
    for(int levelnum=0;levelnum<10;levelnum++)
    {
        for(int g=0;g<10;g++)
        {
            if(a[levelnum][g].num==-1)
                continue;
            char title='A'+a[levelnum][g].name-1 ;
            cout << title << endl;
            for(int i=0;i<10;i++)
            {
                cout << setw(4) << a[levelnum][g].gr[i];
            }
            cout << endl;
            for(int i=0;i<10;i++)
            {
                cout << setw(4) << a[levelnum][g].s[i];
            }
            cout << endl;
            for(int i=0;i<10;i++)
            {
                cout << setw(4) << a[levelnum][g].nd[i];
            }
            cout << endl;
            for(int i=0;i<10;i++)
            {
                cout << setw(4) << a[levelnum][g].r[i];
            }
            cout << endl;
            for(int i=0;i<10;i++)
            {
                cout << setw(4) << a[levelnum][g].o[i];
            }        
            cout << endl;
            cout << "---------------------------------------"<<endl;
        }
    }
 
    system("pause");
    return 0;
}
