#include <cstdlib>
#include <iostream>
#include <ctype.h>

using namespace std;

class object
{
      public:
             int a;
             int count;
};

struct node
{
       object x;
       struct node* link;
};

struct node2
{
       object x;
       struct node2*  forward;
       struct node2*  backward;
};

void constructor (node* a)
{
     if(a==NULL)
     {
         cout << "out of memory" << endl;
         return ;
     }
     a->x.a=0;
     a->x.count=0;
     a->link=NULL;
     return ;
}

void constructor2 (node2* a)
{
     if(a==NULL)
     {
         cout << "out of memory" << endl;
         return ;
     }
     a->x.a=0;
     a->x.count=0;
     a->forward=NULL;
     a->backward=NULL;
     return ;
}

void showstack(node *pt)
{
     while(pt->x.count>0)
    {
        cout << "No."<< pt->x.count <<"=" <<pt->x.a << endl;
        pt=pt->link;
    }
    return ;
}

void showqueue(node *pt)
{
    while(pt!=NULL)
    {
        cout << "No."<< pt->x.count <<"=" <<pt->x.a << endl;
        pt=pt->link;
    }
    return ;
}

void showdoubleforward(node2* pt)
{
    while(pt!=NULL)
    {
        cout <<"No."<< pt->x.count << "=" << pt->x.a << endl;
        pt=pt->forward;
    }
    return ;
}

void showdoublebackward(node2* pt)
{
    while(pt->backward!=NULL)
    {
        cout <<"No."<< pt->x.count << "=" << pt->x.a << endl;
        pt=pt->backward;
    }
    return ;
}

int main()
{
    system("cls");
    restart:
    cout << "Please enter your choice for data storing:" << endl;
    cout << "S for STACK, Q for QUEUE, D for DOUBLELINKLIST" << endl;
    char choice;
    cin >> choice;
    choice=toupper(choice);
    if(choice=='S')
    {
        node* target;//stack
        target=(node*)malloc(sizeof(node));
        constructor(target);    
        while(1)
        {
            node* temp;//stack
            temp=(node*)malloc(sizeof(node));
            constructor(temp);
            temp->x.count=target->x.count+1;
            cout << "Please enter No" << temp->x.count << "'s data:" ; 
            cin >> temp->x.a;
            if(temp->x.a==-1)
                  break;            
            temp->link=target;
            target=temp;  
        }
        showstack(target);
    }
    else if(choice=='Q')
    {
         node* head;//queue
         node* tail;
         head=(node*)malloc(sizeof(node));
         tail=(node*)malloc(sizeof(node));
         node* target;
         target=(node*)malloc(sizeof(node));
         constructor(target);
         head->link=target;
         tail->link=target;
         while(1)
         {
             node* temp;
             temp=(node*)malloc(sizeof(node));
             constructor(temp);
             temp->x.count=tail->link->x.count+1;
             cout << "Please enter No" << temp->x.count << "'s data:" ; 
             cin >> temp->x.a;             
             if(temp->x.a==-1)
                 break;
             tail->link->link=temp;
             tail->link=temp;    
         }        
         showqueue(head->link->link);//queue
    }
    else if(choice=='D')
    {
         node2* head;//doublelinklist
         head=(node2*)malloc(sizeof(node2));
         constructor2(head);
         node2* tail;
         tail=(node2*)malloc(sizeof(node2));
         constructor2(tail);
         node2* pt;
         pt=head;
         while(1)
         {
             node2* temp;
             temp=(node2*)malloc(sizeof(node2));
             constructor2(temp);
             temp->x.count=pt->x.count+1;
             cout << "Please enter No" << temp->x.count << "'s data:" ; 
             cin >> temp->x.a;             
             if(temp->x.a==-1)
                break;
             if(pt->x.count==0)
             {
                pt->forward=temp;
                pt->backward=NULL;
                temp->forward=NULL;
                temp->backward=pt;
             }
             else
             {
                 pt->forward=temp;
                 temp->forward=NULL;
                 temp->backward=pt;
             }
             pt=pt->forward;
             tail=pt;
         }
         reshow:
         cout << "Please enter your choice for data showing:" << endl;
         cout << "F for FORWARD, B for BACKWARD" << endl;
         char direction;
         cin >> direction;
         direction=toupper(direction);
         if(direction=='F')
             showdoubleforward(head->forward);
         else if(direction=='B')
             showdoublebackward(tail);
         else
         {
             cout << "Wrong!" << endl;
         }
         cout << "Want to reshow:Y/N" << endl;
         char reshow;
         cin >> reshow;
         reshow=toupper(reshow);
         if(reshow=='Y')
             goto reshow;//doublelinklist
    }
    else
        cout << "Wrong!" << endl;
    
    cout << "Want to restart:Y/N" << endl;
    char again;
    cin >> again;
    again=toupper(again);
    if(again=='Y')
        goto restart;
  
    
    system("pause");
    return 0;
}
