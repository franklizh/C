#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
#include <getopt.h>
#define MAX 100
struct Cow
{
    int no;//编号
    int b;
    int e;
    bool operator<(const Cow &s)const
    {
        if(e==s.e)
        {
            return b<=s.b;
        }
        else
            return e<=s.e;
    }
};
int n=5;
Cow A[]={{0},{1,1,10},{2,2,4},{3,3,6},{4,5,8},{5,4,7}};
//下标0不用
//求解结果表示
int ans[MAX]; //ans[i]表示第A[i].no头牛的蓄栏编号
void solve()
{
    std::sort(A+1,A+n+1);
    memset(ans,0,sizeof(ans));
    int num=1;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            ans[i]=num;
            int pre=A[i].e;
            for(int j=i+1;j<=n;j++)
            {
                if(A[j].b>pre&&ans[j]==0)
                {
                    ans[j]=num;
                    pre=A[j].e;
                }
            }
            num++;
        }
    }
    printf("num is %d",num);
}
int main()
{
    solve();
}