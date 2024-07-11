#include<iostream>
#include<algorithm>
#define N 4//数量
#define C 10//限重

using namespace std;

//使用0占位：将物品的重量和价值的数组索引与动态规划表的索引对齐
int w[N+1]={0,2,3,5,5};
int v[N+1]={0,2,4,3,7};
int dp[N+1][C+1]={0};

int x[N+1]={0};//记录结构

//设dp[i][j]表示将前i件物品装进限重为j的背包可以获得的最大价值
int DP(int n,int c)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(j<w[i])//放不下第i个
            {
                dp[i][j]=dp[i-1][j];
            }
            if(j>=w[i])
            {//放得下第i个，dp为放和不放中最大的
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                //放：前i-1放在j-w[i]中，加上放了第i个（增加了v[i]）
            }
        }
    }
    return dp[n][c];
}

void build()
{
    int i=N;
    int j=C;

    while(i>=0)
    {
        if(dp[i][j]==dp[i-1][j])//没选这个商品
        {
            x[i]=0;
        }
        else{
            x[i]=1;//选了
            j=j-w[i];//往回，
        }
        i--;
    }
}

int main()
{
    printf("%d\n",DP(N,C));
    build();
    for(int i=1;i<=N;i++)
    {
        cout<<x[i]<<" ";
    }
}