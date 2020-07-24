#include <iostream>
#include <math.h>
using namespace std;

struct flags
{
    int top1,top2;
    int *ptr;
};
flags f;
void push1(int flagIndex)
{
    f.top1++;
    f.ptr[f.top1]=flagIndex;
    
}
void pop1()
{
    f.ptr[f.top1]=0;
    f.top1--;
}
void push2(int flagIndex)
{
    f.top2--;
    f.ptr[f.top2]=flagIndex;
    
}
void pop2()
{
    f.ptr[f.top2]=0;
    f.top2++;
}
int main()
{
    int M,N,i,operation,stackNo,no;
    cin>>N;
    cin>>M;
    f.top1=-1;
    f.top2=N;
    f.ptr=new int[N];
    int *arr=new int[M];
    for(i=0;i<N;i++)
        f.ptr[i]=0;
    for(i=0;i<M;i++)
        arr[i]=0;
    int c=0;
    for(i=0;i<M;i++)
    {

        cin>>operation>>stackNo>>no;
        if(no!=-1)
            arr[c++]=no;
        if(operation==1 && stackNo==1)
            push1(no);
        else if(operation==1 && stackNo==2)
           push2(no);
        else if(operation==2 && stackNo==1)
            pop1();
        else
            pop2(); 
           
            
    }
    float mean,median,mode,sum=0,stdDev=0.0;
    for(i=0;i<c;i++)
    {
        sum+=arr[i];
    }
    mean=sum/c;
    int temp,j;
    for (i = 0; i < c - 1; i++)
    {
        for (j = i + 1; j < c; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    if(c%2==0)
        median=(arr[c/2]+arr[(c+1)/2])/2;
    else
        median=arr[c/2];
    for(i=0;i<c;i++)
        stdDev+=pow(arr[i]-mean,2);
    stdDev=sqrt(stdDev/c);
    mode=arr[0];
    int num,count,maxCount=1;
    for(i=0;i<c;)
    {
        count=1;
        num=arr[i];
        for(j=i+1;j<c;j++)
        {
            if(arr[j]==num)
                count++;
            else
                break;    
        }
        i=j;
        if(count>maxCount)
        {
            maxCount=count;
            mode=num;
        }
    }

    cout<<mean<<" "<<median<<" "<<mode<<" "<<stdDev<<"\n";
    for(i=f.top1;i>=0;i--)
    {
        cout<<f.ptr[i]<<" ";
        pop1();
    }
    cout<<"\n";
    for(i=f.top2;i<N;i++)
    {
        cout<<f.ptr[i];
        pop2();
    } 
    cout<<"\n";

    return 0;
}
