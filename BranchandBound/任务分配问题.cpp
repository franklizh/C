//任务分配问题：有n（n≥1）个任务需要分配给n个人执行，每个任务只能分配给一个人，每个人只能执行一个任务。第i个人执行第j个任务的成本是c[i][j]（1≤i，j≤n）。求出总成本最小的分配方案。

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <string.h>
#define n 4
#define Maxn n+1

using namespace std;

int c[Maxn][Maxn]={{0},{0,9,2,7,8},{0,6,4,3,7},{0,5,8,1,8},{0,7,6,9,4}};
int best[Maxn];
int mincost=INT_MAX;
int total=0;

struct NodeType//队列节点
{
    int no;//节点编号
    int i;//人员编号
    int x[Maxn];//为人员i分配的任务编号
    bool worker[Maxn];//worker[i]=true表示任务i已经被分配
    int cost;//已经分配任务所需的成本
    int lb;//下界

    bool operator<(const NodeType &node)const
    {
        return lb>node.lb;
    }
};

void bound(NodeType &e)//求e的下界
{
    int minsum=0;
    for(int i1=e.i+1;i1<=n;i1++)//从没分配的开始
    {
        int mins=INT_MAX;
        int j=1;
        while(!e.worker[j])//寻找没分配的任务
        {
            if(c[i1][j]<=mins)//找最小
            {
                mins=c[i1][j];
            }
            j++;
        }
        minsum+=mins;//相加为剩下最优
    }
    e.lb=e.cost+minsum;//和当前点的成本加起来为当前点的下界
}

void bfs()
{
    int j;
    priority_queue<NodeType>qu;
    NodeType e;
    memset(e.x,0,sizeof(e.x));
    memset(e.worker,0,sizeof(e.worker));

    //处理源点
    e.i=0;
    e.cost=0;
    bound(e);
    e.no=total;
    qu.push(e);

    while(!qu.empty())
    {
        e=qu.top();
        qu.pop();
        if(e.i==n)
        {
            if(e.cost<mincost)//更新结果
            {
                mincost=e.cost;
                for(j=1;j<=n;j++)//更新结果分配数组
                {
                    best[j]=e.x[j];
                }
            }
        }

        // NodeType enext;
        // enext.no=e.no+1;
        // for(int m=1;m<=n;m++)//对任务m
        // {
        //     if(e.worker[m])
        //         continue;//已经被分配
        //     for(int p=1;p<=n;p++)
        //     {
        //         enext.x[p]=e.x[p];
        //     }
        //     enext.x[enext.i]=m;//给enext分配任务m

        //     for(int p=1;p<=n;p++)
        //     {
        //         enext.worker[p]=e.worker[p];
        //     }
        //     enext.worker[enext.i]=true;

        //     bound(enext);
        //     if(enext.lb<=mincost)
        //     {
        //         qu.push(enext);
        //     }
        // }

//处理下一个节点
        for(int m=1;m<=n;m++)
        {
            if(e.worker[m])continue;//曾经被访问过，就不要访问了

            NodeType enext=e;
            enext.i=e.i+1;
            enext.x[enext.i]=m;//分配任务m
            enext.worker[m]=true;//标记
            enext.cost=e.cost+c[enext.i][m];//记录成本

            bound(enext);//求下界减脂
            if(enext.lb<mincost)
            {
                qu.push(enext);
            }
        }

    
    }  
      

}

int main()
{
    bfs();
    cout<<mincost<<endl;
    for(int j=1;j<=n;j++)
    {
        cout<<best[j]<<" ";
    }
}