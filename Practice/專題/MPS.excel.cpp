#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

class object{
    public :
        int name;//����W�� 
        int num;//����s�� 
        int supnum[10];//�W�Ū���s�� 
        int lt;//�Ͳ����� 
        int m;//����multiple
        int b;//��qbatch 
        int level;//����
        int s[10];//�s�fstock
        int gr[10];//��ݨD gro requirements
        int nd[10];//�b�ݨD net demand 
        int r[10];//�q�汵���q receive
        int o[10];//�q��}�߶q order 
       
         
   
};

void constructor(object a[10][10])//��l�� 
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

int searchnum(object a[10][10],int name,int levelnum)//�N�s���ন��m 
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(a[i][j].name==name&&i==(levelnum-1))
            {
                cout << "�п�J�@��(" << name << ")�ݭn�h�֧���?";
                int m;
                cin >> m; 
                return (100*m+10*i+j);   
            }                         
        }
    }
    cout << "�䤣�즹�W�h�s��!" << endl;
    return 0; 
            
}


void findsupnum(object a[10][10],int name,int levelnum,int objnum)//��W�h��m 
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
                cout << "�п�J�W�h�s��:";
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

    cout << "�п�J�W�h�s��:";
    char csupname;
    cin >> csupname; 
    int supname;
    supname=csupname-'A'+1;
    a[levelnum][objnum].supnum[0]=searchnum(a,supname,levelnum);   
    a[levelnum][objnum].num=objnum;
    a[levelnum][objnum].level=levelnum;
}

void fillin(object a[10][10],int levelnum,int objnum)//�p�� 
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
    FILE *fp =fopen("MPS.csv", "w");
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
            cout << "�п�J�D����s��:";
            char name;
            cin >>  name;
            a[levelnum][0].name=name-'A'+1;
            cout << "�п�JLT:";
            cin >>  a[levelnum][0].lt;
            cout << "�п�J��q:";
            cin >> a[levelnum][0].b;
            cout << "�п�J�s�f�q:";
            cin >> a[levelnum][0].s[0];
            do
            {
                int w;
                cout << "�п�J�g��:";
                cin >> w;
                cout << "�п�J���q:";
                cin >> a[levelnum][0].gr[w-1];
                cout << "�O�_�A��J�g�����q?Y/N ";
                cin >> ch; 
            }while(toupper(ch)=='Y');
            fillin(a,levelnum,0);
        }
        else
        {
            cout << "��" << levelnum << "�h" << endl;
            cout << "�п�J���h�֪���" ;
            int objnum;
            cin >> objnum;
            for(int t=0;t<objnum;t++)
            {
                cout << "�п�J����s��:";
                char name;
                cin >>  name;
                a[levelnum][t].name=name-'A'+1;
                findsupnum(a,a[levelnum][t].name,levelnum,t);
                cout << "�п�JLT:";
                cin >>  a[levelnum][t].lt;
                cout << "�п�J��q:";
                cin >> a[levelnum][t].b;
                cout << "�п�J�s�f�q:";
                cin >> a[levelnum][t].s[0];
                cout << endl;
                
            }
        }
      
        
        
        levelnum++;
        cout << "�O�_���U�@�h?";
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
            fprintf(fp, "%c" , title);
            fputc('\n', fp);
            for(int i=0;i<10;i++)
            {
                fprintf(fp, "%d," , a[levelnum][g].gr[i]);
            }
            fputc('\n', fp);
            for(int i=0;i<10;i++)
            {
                fprintf(fp, "%d," , a[levelnum][g].s[i]);
            }
            fputc('\n', fp);
            for(int i=0;i<10;i++)
            {
                fprintf(fp, "%d," , a[levelnum][g].nd[i]);
            }
            fputc('\n', fp);
            for(int i=0;i<10;i++)
            {
                fprintf(fp, "%d," , a[levelnum][g].r[i]);
            }
            fputc('\n', fp);
            for(int i=0;i<10;i++)
            {
                fprintf(fp, "%d," , a[levelnum][g].o[i]);
            }        
            fputc('\n', fp);

        }
    }
    fclose(fp);
    system("pause");
    return 0;
}
