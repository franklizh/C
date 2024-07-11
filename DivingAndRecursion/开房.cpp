#include<stdio.h>
#include<math.h>
int main()
{
     int len;
    scanf("%d",&len);
    int n=len;
    int j=0;
    int a[len+1];
    while(n--)
    {
        scanf("%d",&a[j]);
        j++;
    }
    for(int i=0;i<len;i++)
    {
        int n=a[i];
        int a=pow(n,1/2);
        int b=pow(a,1/2);
        int c=pow(b,1/2);
    }
}