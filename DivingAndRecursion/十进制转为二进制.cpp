#include<stdio.h>
 //十进制转为二进制，每位求和
void dec(int n,int *sum)
{
   
    if(n==0)
        *sum=*sum+0;
    else if(n==1)
        *sum=*sum+1;
    else{
        dec(n/2,sum);
        *sum=*sum+(n%2);
    }
    
}
int trans(int n)
{
    int sum=0;
    while(n)
    {
        sum=sum+n%10;
        n=n/10;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    
  
    //  dec(n,&sum);
    // printf("%d",sum);
    // printf(" %d",trans(n));
    
for(int i=1;i<=n;i++)
{
    int sum=0;
    dec(i,&sum);
    int sum2=trans(i);
    if(sum==sum2)
        printf("%d %d %d\n",i,sum,sum2);
}
    return 0;

}