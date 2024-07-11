#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
#include <getopt.h>
#include<queue>
#include<vector>
int n=7;
int m=3;
//优先队列
struct Node
{
    int no;//作业序号
    int t;//执行时间
    int m_no;//机器序号
    bool operator<(const Node &s) const{
        return t>s.t;//按t越小越优先出队
    }
};

struct Node
A[]={{1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3}};
void solve()
{
    Node e;
    if(n<=m)
    {
        printf("每一个作业分配一个机器\n");
        return ;
    }
    std::sort(A,A+n);//按t递减排序
    std::priority_queue<Node> qu;//小根堆

    for(int i=0;i<m;i++)
    {
        A[i].m_no=i+1;
        printf(" 给机器%d分配作业%d,执行时间为%2d,占用时间段:[%d,%d]\n",
                A[i].m_no,A[i].no,A[i].t,0,A[i].t);
        qu.push(A[i]);
    }

    for(int j=m;j<=n;j++)//处理剩下的作业
    {
        e=qu.top();
        qu.pop();//找到最先完成自己作业的机器
        printf("给机器%d分配作业%d,执行时间为%2d, 占用时间段：[%d,%d]\n",
                e.m_no,A[j].no,A[j].t,e.t,e.t+A[j].t);
        e.t+=A[j].t;
        qu.push(e);
    }

}
int main()
{
    solve();
}