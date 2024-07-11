#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define MAXN 10
#define INF INT_MAX

int n; // 城市数量
int dist[MAXN][MAXN]; // 城市间的距离矩阵
int minCost = INF; // 最小费用
vector<int> bestPath; // 最优路径
vector<bool> visited; // 标记城市是否被访问

//path记录当前路径
void tsp(int currPos,int count,int cost, vector<int>& path){
    if(count==n && dist[currPos][0]>0)
    {
        int totalCost=cost+dist[currPos][0];
        if(totalCost<minCost){
            minCost=totalCost;
            
            //更新路径，最后回到源点
            bestPath=path;
            bestPath.push_back(0);
        }
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && dist[currPos][i]>0)
        {

            //减脂
            if(cost+dist[currPos][i]+dist[i][0]>=minCost)
            {
                continue;
            }

            visited[i]=true;
            path.push_back(i);
            tsp(i,count+1,cost+dist[currPos][i],path);
            path.pop_back();
            visited[i]=false;
        }
    }
}


int main() {
    cout << "请输入城市数量: ";
    cin >> n;

    cout << "请输入城市间的距离矩阵:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (i != j && dist[i][j] == 0) {
                dist[i][j] = INF; // 无法到达的城市距离设为INF
            }
        }
    }

    visited.resize(n, false);
    vector<int> path;
    path.push_back(0);
    visited[0] = true;

    tsp(0, 1, 0, path);

    cout << "最优路径总费用: " << minCost << endl;
    cout << "最优路径: ";
    for (int i : bestPath) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
