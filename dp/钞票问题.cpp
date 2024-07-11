/**
 * f(n)表示，凑出n所需的最少钞票数量
 * dp(n)存的是解
 * 1,5,11面值
*/
#include<stdio.h>
#define INF 100000
int min(int a,int b,int c)
{
    int t;
    t=a>=b?b:a;
    t=t>=c?c:t;
    return t;
}
int f(int n)
{
    int dp[n+1];
    dp[0]=0;
    int c1,c2,c3;
    for(int i=1;i<=n;i++)
    {
        c1=c2=c3=INF;
        if(i-1>=0)c1=dp[i-1]+1;
        if(i-5>=0)c2=dp[i-5]+1;
        if(i-11>=0)c3=dp[i-11]+1;
        dp[i]=min(c1,c2,c3);
    }
    return dp[n];

}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
    // printf("%d",min(3,2,3));
}