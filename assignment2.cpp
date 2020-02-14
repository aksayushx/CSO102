#include<iostream>
#include<string.h>
using namespace std;

char infix[50],postfix[50],stack[50];
int top=-1;
int prec(char c) 
{ 
    if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
void push(char element)
{
    top++;
    stack[top]=element;
}
void pop()
{
    stack[top]='\0';
    top--;

}
int convert()
{
    int c=0;char ch;
    int i,l=strlen(infix);
    for(i=0;i<l;i++)
    {
        if(infix[i]>='1' && infix[i]<='9')
            postfix[c++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(top>=0 && stack[top]!='(')
            {
                ch=stack[top];
                pop();
                postfix[c++]=ch;
            }
            if(stack[top]=='(')
                pop();
        }
        else
        { 
            while(top>=0 && prec(infix[i]) <= prec(stack[top]) )
            { 
                ch = stack[top]; 
                pop(); 
                postfix[c++]=ch; 
            } 
            push(infix[i]); 
        } 
    }
    while(top>=0) 
    { 
        ch = stack[top]; 
        pop(); 
        postfix[c++]=ch; 
    } 
    postfix[c++]='\0';
    return c;
}
int main()
{
    int N;
    cin>>N;
    int i,l,j;
    char ans[100][50];
    for(i=0;i<N;i++)
    {
        cin>>infix;
        l=convert();
        for(j=0;j<l;j++)
            ans[i][j]=postfix[j];
    }
    for(i=0;i<N;i++)
        cout<<ans[i]<<"\n";
    
    return 0;
}