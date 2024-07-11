// //初始化最优解的上界为正无穷。
// 从根节点（起始城市）开始，进行深度优先搜索。
// 对于每个城市，计算当前路径的成本并更新下界。
//求下界是因为旅行商是求最短
// 如果当前路径的下界小于最优解的上界，则继续扩展。
// 如果找到一个完整的回路且其成本小于当前最优解，则更新最优解

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

struct Node{
    int level;          // 当前节点的层次（访问到第几个城市）
    int path_cost;      // 到达当前节点的路径花费
    int bound;          // 当前节点的下界
    vector<int> path;   // 当前路径

    bool operator<(const Node &other)const{
        return bound>other.bound;
    }
};

int calbound(const Node &node,const vector<vector<int>>&cost,int n){
    int bound=node.path_cost;
    vector<bool>visited(n,false);

    for(int i:node.path) // 标记当前路径中的城市为已访问
    {
        visited[i]=true;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])//没被访问
        {
            int min_cost=INF;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&!visited[j])
                {
                    min_cost=min(min_cost,cost[i][j]);
                }
            }
            bound+=min_cost;
        }
    }
    return bound;
}

void TSP(const vector<vector<int>> &cost)
{
    int n=cost.size();
    priority_queue<Node>qu;

    //入源点
    Node root;
    root.level=0;
    root.path_cost=0;
    root.path={0};
    root.bound=calbound(root,cost,n);
    qu.push(root);

    int min_cost=INF;
    vector<int>best_path;

    while(!qu.empty())
    {
        Node current=qu.top();
        qu.pop();

//下界小于最优解
        if(current.bound<min_cost)
        {
            for(int i=1;i<n;i++)//除去源点，从一开始
            {

                // 在旅行商问题（TSP）中，每个城市只能访问一次。
                // 因此，在扩展路径时，需要检查即将访问的城市是否已经在当前路径中出现过
                // 如果已经访问过，则不应再访问；如果未访问过，则可以继续访问
                
                // 在 current.path 中搜索元素 i，
                // 如果找到，返回一个指向该元素的迭代器；
                // 如果找不到，则返回一个指向容器末尾的迭代器。
                if(std::find(current.path.begin(),current.path.end(),i)==current.path.end())
                {
                    //未被访问
                    Node child;
                    child.level=current.level+1;
                    child.path=current.path;
                    child.path.push_back(i);
                    child.path_cost=current.path_cost+cost[current.path.back()][i];

                    if(child.level==n-1)//结果
                    {
                        child.path.push_back(0);//回路
                        int total_cost=child.path_cost+cost[i][0];
                        if(total_cost<min_cost)
                        {
                            min_cost=total_cost;
                            best_path=child.path;
                        }
                    }else
                        {
                            child.bound=calbound(child,cost,n);
                            if(child.bound<min_cost)//节点的下界已经大于当前已知的最优解，那么该节点就可以被剪枝，
                            {
                                qu.push(child);
                            }
                        }
            }
        }
    }

}
cout<<min_cost<<endl;
for(int i:best_path)
{
    cout<<i<<" ";
}

}

int main()
{
    vector<vector<int>> cost = {
        {INF, 10, 15, 20},
        {10, INF, 35, 25},
        {15, 35, INF, 30},
        {20, 25, 30, INF}
    };

    TSP(cost);
    return 0;
}