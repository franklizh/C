#include<stdio.h>
#include <climits>
int mina(int a[],int num)
{
    int m=a[0];
    for(int i=0;i<num;i++)
    {
        if(m>a[i])
        {
            m=a[i];
        }
    }
    return m;
}
int opt(int p[],int num)
{
    int dp[num+1][num+1];

    // for(int i=1;i<=num;i++)
    //     for(int j=1;j<=num;j++)
    //     {
    //         if(i==j)dp[i][j]=0;
    //         else if(i<j)
    //         {
    //             int a[j-i+1];
    //             int len=0;
    //             for(int k=i;k<j;k++)
    //             {
    //                 a[k]=dp[i][k]+dp[k+1][i]+p[i]*p[k+1]*p[j+1];
    //                 len++;
    //             }
    //             dp[i][j]=mina(a,len);
    //         }
    //     }
    //     return dp[1][num];
for (int i = 1; i <= num; i++) {
        for (int j = 1; j <= num; j++) {
            dp[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    for (int length = 2; length <= num; length++) {
        for (int i = 1; i <= num - length + 1; i++) {
            int j = i + length - 1;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][num];

}
int main()
{
    int n;
    printf("input nums");
    scanf("%d",&n);
    int p[n+1];
    int t=0;
    printf("input dimensions: ");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Minimum number of multiplications is %d\n", opt(p, n));
    return 0;
}