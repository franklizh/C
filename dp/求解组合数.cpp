/**
 * 递归
 */
#include<iostream>
using namespace std;
int ComB(int n,int m)
{
    if(m==0||n==m)
        return 1;
    else
        return ComB(n-1,m-1)+ComB(n-1,m);
}

/**
 * dp
 * dp[i][j]表示c(j上，i下)
 */
int comB(int n,int m)
{
    int dp[n+1][m+1]={0};
    int i,j;
    for(i=1;i<=n;i++)dp[i][0]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(i==j)dp[i][j]=1;
            else if(i>j)dp[i][j]=dp[i-1][j-1]+dp[i-1][j];

    return dp[n][m];
}
int main()
{
    int n;
    int m;
    cin>>n>>m;
    cout<<"用dp"<<comB(n,m)<<endl;
    cout<<"用递归"<<ComB(n,m)<<endl;
}