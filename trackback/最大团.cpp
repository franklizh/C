#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20; // 假设最大顶点数为20
int graph[MAXN][MAXN]; // 图的邻接矩阵
int n; // 图的顶点数
int maxCliqueSize; // 最大团的大小
vector<int> currentClique; // 当前团
vector<int> bestClique; // 最大团
vector<int> candidates; // 候选顶点

// 检查给定的顶点集合是否是一个团
bool isClique(const vector<int>& clique) {
    for (size_t i = 0; i < clique.size(); ++i) {
        for (size_t j = i + 1; j < clique.size(); ++j) {
            if (!graph[clique[i]][clique[j]]) {
                return false;
            }
        }
    }
    return true;
}

// 回溯法寻找最大团
void findMaxClique(int start) {
    for (int i = start; i < n; ++i) {
        // 剪枝条件：如果当前团加上剩余候选顶点的数量不可能超过已知的最大团大小，则不继续搜索
        if (currentClique.size() + (n - i) <= maxCliqueSize) {
            return;
        }

        currentClique.push_back(i);
        if (isClique(currentClique)) {
            if (currentClique.size() > maxCliqueSize) {
                maxCliqueSize = currentClique.size();
                bestClique = currentClique;
            }
            findMaxClique(i + 1);
        }
        currentClique.pop_back();
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    maxCliqueSize = 0;
    findMaxClique(0);

    cout << "Maximum clique size: " << maxCliqueSize << endl;
    cout << "Vertices in the maximum clique: ";
    for (int v : bestClique) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
