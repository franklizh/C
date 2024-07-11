/*
    f(n,k)=1  n=1||k=1
    f(n,k)=f(n,n) n<k
    f(n,k)=f(n,n-1)+1  n=k
    f(n,k)=f(n,k-1)+f(n-k,k)  n>k
*/


#include<stdio.h>
#define max 100
int splitnum(int n,int k)
{
    int dp[max][max]={0};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
        {
            if(i==1||j==1)dp[i][j]=1;
            else if(i<j)
                dp[i][j]=dp[i][i];
            else if(i==j) 
                dp[i][j]=dp[i][i-1]+1;
            else dp[i][j]=dp[i][j-1]+dp[i-j][j];
        }
        return dp[n][k];
}

int main()
{
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    printf("%d",splitnum(n,k));
}