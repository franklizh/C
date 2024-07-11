//全排列问题
#include<stdio.h>
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void perm(int a[],int k,int n)
{
    if(k==n)
    {
        for(int i=0;i<=n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else
    {
        for(int j=k;j<=n;j++)
        {
            swap(a[k],a[j]);
            perm(a,k+1,n);
             swap(a[k],a[j]);
        }
    }
}
int main()
{
    int a[]={1,2,3,4};
    perm(a,0,3);
     
}