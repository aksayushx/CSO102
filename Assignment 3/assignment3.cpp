#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    char country[50];
    char penny[5];
    node* next;
};
node* head=NULL;
node* rear=NULL;
node* create_new_node(char cn[],char pn[])
{
    node* ptr;
    ptr=new node;
    strcpy(ptr->country,cn);
    strcpy(ptr->penny,pn);
    ptr->next=NULL;
    return ptr;
}
void display()
{
    node*temp;
    temp=head;
    if(head==NULL)
    {
        cout<<'\n';
        return;
    }
    while(temp!=NULL)
    {
        cout<<temp->country<<" ";
        temp=temp->next;
    }
    cout<<'\n';
}
void del()
{
    node* temp;
    if(head!=NULL)
    {
        while(strcmp(head->penny,"P")==0)
            head=head->next;
        temp=head;
        while(temp->next!=NULL)
        {
            if(strcmp(temp->next->penny,"P")==0)
            {
                temp->next=temp->next->next;
            }
            else
            {
                temp=temp->next;
            }
            
        }
        rear=temp;
    }
}
void add(node* new_cn)
{
    if(head==NULL)
    {
        head=new_cn;
        rear=new_cn;
    }
    else
    {
        rear->next=new_cn;
        rear=rear->next;
    }
    

}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int i;
    node* new_cn;
    char country[50],penny[5],op[15];
    for(i=0;i<m;i++)
    {
        cin>>op;
        if(strcmp(op,"ADD")==0)
        {
            cin>>country>>penny;
            //cout<<op<<'\n'<<country<<'\n'<<penny<<'\n';
            new_cn=create_new_node(country,penny);
            add(new_cn);
        }
        else if(strcmp(op,"DEL")==0)
            del();
        else
            display();    

    }
    return 0;

}