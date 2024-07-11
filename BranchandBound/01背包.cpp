#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 物品的数量和背包的容量
int n = 4;
int C = 6;

// 物品的重量和价值
int w[] = {0, 5, 3, 2, 1};
int va[] = {0, 4, 4, 3, 1};

// 节点结构体
struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

//计算节点的上界
float bound(Node u)
{
    if(u.weight>=C)
        return 0;
    else 
    {
        float result=u.profit;
        int j=u.level+1;
        int totalweight=u.weight;

        //逐步增加商品，直到达到上限
        while(j<=n&& totalweight+w[j]<=C)
        {
            totalweight+=w[j];
            result+=va[j];
            j++;
        }

        //如果还有容量，部分选择
        if(j<=n)
        {
            result+=(C-totalweight)*(va[j]/(float)w[j]);
        }
    }
}


int knap()
{
    queue<Node> Q;
    Node u,v;
    u.level=0;
    u.profit=0;
    u.weight=0;
    Q.push(u);

    int maxprofit=0;
    while(!Q.empty())//队列模拟广度
    {
        u=Q.front();
        Q.pop();

        if(u.level==n)
            continue;

//v用来遍历节点的
        //选择该物品，
        v.level=u.level+1;
        v.weight=u.weight+w[v.level];
        v.profit=u.profit+va[v.level];

        // 更新最大价值
        if(v.weight<=C&& v.profit>maxprofit)
        {
            maxprofit=v.profit;
        }

        v.bound=bound(v);
        //如果上界大于当前最大价值，入队
        if(v.bound>maxprofit)
            Q.push(v);

        // 生成不选择当前物品的节点
        v.weight=u.weight;
        v.profit=u.profit;
        v.bound=bound(v);

        if(v.bound>maxprofit)
            Q.push(v);

    }
    return maxprofit;
}

int main() {
    int maxProfit = knap();
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}