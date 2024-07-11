#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f // 表示∞
#define MAXN 51
//问题表示
int n; //图顶点个数
int a[MAXN][MAXN]; //图的邻接矩阵
int v; //源点
//求解结果表示
int dist[MAXN]; //dist[i]源点到顶点i的最短路径长度
int pre[MAXN]={0}; //prev[i]表示源点到i的最短路径中顶点i的前驱顶点

struct NodeType //队列结点类型
{   
    int vno; //顶点编号
    int length; //路径长度
    bool operator<(const NodeType &other) const{
        return length>other.length;//小跟堆
    }
};

//迪杰斯特拉算法
void dfs(int v)
{
    NodeType e,e1;
   // queue<NodeType> qu;
   priority_queue<NodeType>qu;
   //源点入队
    e.vno=v;
    e.length=0;
    qu.push(e);
    dist[v]=0;

    while(!qu.empty())
    {
       // e=qu.front();
       e=qu.top();
        qu.pop();//已经pop出了，不用重复考虑
        //对每一个出队的节点，找他的邻接节点
        for(int j=0;j<n;j++)//遍历每一个节点找
        {
            //如果相连且经过e到j比j直接到源点小，更新
            if(a[e.vno][j]<INF&& e.length+a[e.vno][j]<dist[j])
            {
                dist[j]=e.length+a[e.vno][j];
                pre[j]=e.vno;//记录前驱

                //更新这个点的length，入队
                e1.vno=j;
                e1.length=dist[j];
                qu.push(e1);
            }
        }
    }
}

void printp(int j)
{
    if(pre[j]!=-1)
    {
        printp(pre[j]);
    }
    cout<<j<<" ";
}


int main()
{
    n = 5;
    v = 0;

    // 初始化邻接矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INF;
        }
    }

    // 添加边 
    a[0][1] = 10;
    a[0][4] = 5;
    a[1][2] = 1;
    a[1][4] = 2;
    a[2][3] = 4;
    a[3][2] = 6;
    a[3][0] = 7;
    a[4][1] = 3;
    a[4][2] = 9;
    a[4][3] = 2;

    // 初始化距离和前驱数组
    fill(dist, dist + MAXN, INF);
    fill(pre, pre + MAXN, -1);

    dfs(v);

    cout << "Vertex\tDistance from Source\tPath" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << dist[i] << "\t\t";
        printp(i);
        cout << endl;
    }

}

