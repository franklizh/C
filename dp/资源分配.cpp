#include<iostream>
#include<algorithm>
#define M 3//商店数量
#define N 5//人数

using namespace std;

int v[M+1][N+1]={{0,0,0,0,0,0},
 {0,3,7,9,12,13},
 {0,5,10,11,11,11},
 {0,4,6,11,12,12}}; 
//求解结果表示
//dp[i][j]表示前i个商店，共分配到j个员工的最优盈利。则
//dp[m][n]为最优盈利。
int dp[M][N]={0};
int pnum[M][N]={0};
//中pnum[i][j]表示求出dp[i][j]时,对应商店i分配的人数

void D(int m,int n)
{
    for(int i=1;i<=M;i++)
        for(int j=i;j<=N;j++)
            {
                if(i==1)
                    dp[i][j]=v[1][j];
                else{
                    int k;
                    int ma=0;
                    int pnu;
                    for(k=0;k<=j;k++)
                    {
                        int t=v[i][k]+dp[i-1][j-k];
                        if(t>=ma)
                        {
                            ma=t;
                            pnu=k;
                        }
                    }
                    dp[i][j]=ma;
                    pnum[i][j]=dp[i][j];
                }
            }
}
int main()
{
    D(M,N);
    cout<<dp[M][N]<<endl;

}