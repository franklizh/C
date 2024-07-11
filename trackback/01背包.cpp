#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define MAXN 100

using namespace std;

int n=4; //4种物品
int C=6; //限制重量为6
int w[]={0,5,3,2,1}; //存放4个物品重量
int v[]={0,4,4,3,1}; //存放4个物品价值
//求解结果表示
int x[MAXN]; //存放最终解
int maxv=0; //存放最优解的总价值

/**
 * tw目前总重
 * tv目前总价值
 * i层
 * rv=v[i]+....+v[n]
 */
void dfs(int i,int tw,int tv,int rv,int op[])
{
    int j;
    if(i>n)//遍历到最后
    {
        if(tw<=C&&tv>maxv)//满足条件则更新maxvalue
        {
            maxv=tv;
            for( j=1;j<=n;j++)//注意是1到n，共n个
            {
                x[j]=op[j];
            }
        }
    }
    else
    {
        if(tw+w[i]<=C)//剪去超过限重的
        {
            op[i]=1;
            dfs(i+1,tw+w[i],tv+v[i],rv-v[i],op);
        }
        if(tv+rv-v[i]>maxv)//即使把剩下的都选都达不到当前最优值，也剪去
        {
            op[i]=0;
            dfs(i+1,tw,tv,rv-v[i],op);
        }
    }
}
int main()
{
    int a[MAXN]={0};
    int toatlvalue=0;
    int totalweight=0;

    for(int i=1;i<=n;i++)
    {
        toatlvalue+=v[i];
    }

    dfs(1,0,0,toatlvalue,a);

    printf("max value is %d\n",maxv);
    printf("selected items:\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d",x[i]);
    }
    return 0;
}