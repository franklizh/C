#include<stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100
int a[MAX][MAX];//无向图，存储地图节点
int x[MAX];//记录颜色
//x[1]=1：第一个节点颜色为1
int n,m;//顶点数和颜色数
int count=0;

bool islegal(int i)
{
    //如果两个节点有联系，且颜色一样
    for(int j=1;j<i;j++)
    {
        if(a[i][j]==1&& x[i]==x[j])return false;
    }
    return true;    
}

void dfs(int i)
{
    if(i>n)
    {
        count++;
    }
    else{
        for(int k=1;k<=m;k++)
        {
            x[i]=k;//选择合适颜色涂上
            if(islegal(i))//合适则继续遍历
                dfs(i+1);
        }
    }
}

int main()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    int e;
    cout<<"输入顶点数和可用颜色数："<<endl;
    cin>>n>>m;
    cout<<"请输入边数:"<<endl;
    cin>>e;
    cout<<"请输入相连接的顶点："<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }
    dfs(1);
    cout<<count<<endl;
    // if(count>0)
    // {
    //     for(int i=1;i<=n;i++)
    //     {
    //         printf("第%d顶点，颜色为%d\n",i,x[i]);
    //     }

    // }
    // else 
    //     printf("no solution");
}