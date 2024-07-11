#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
#include <getopt.h>
#define MAX 11
struct Action
{
    int s;
    int e;
    bool operator<(const Action &s)const
    {
        return e<=s.e;//活动时间递增排序
    }
};
int n=11;
Action
A[]={{0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},
 {8,12},{2,13},{12,15}};

bool ans[MAX];
int Count=0;

void solve()
{
    memset(ans,0,sizeof(ans));
    std::sort(A+1,A+n+1);
    int pre=0;
    for(int i=1;i<=n;i++)
    {
        if(A[i].s>=pre)
        {
            ans[i]=true;
            pre=A[i].e;
        }
    }
    
}
int main()
{
    solve();
    for(int i=0;i<=MAX;i++)
    {
        if(ans[i]==true)
        {
            printf("%d\n",i);
            printf("start:%d end:%d\n",A[i].s,A[i].e);
        }
    }
}