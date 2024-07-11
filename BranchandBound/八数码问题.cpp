//还没彻底搞定

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    vector<vector<int>> state;
    int x, y; // 空格位置
    int g; // 当前路径长度
    int h; // 启发函数值
    int f; // f = g + h
    string path; // 路径

    bool operator<(const Node& other) const {
        return f > other.f; // 用于优先队列，f值小的优先
    }
};

// 用于计算曼哈顿距离的启发函数
int calculateHeuristic(const vector<vector<int>>& state, const vector<vector<int>>& goal) {
    int h = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (state[i][j] != 0) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (state[i][j] == goal[k][l]) {
                            h += abs(i - k) + abs(j - l);
                        }
                    }
                }
            }
        }
    }
    return h;
}

// 将状态转换为字符串用于存储在set中
string stateToString(const vector<vector<int>>& state) {
    string s;
    for (const auto& row : state) {
        for (int num : row) {
            s += to_string(num) + ",";
        }
    }
    return s;
}

vector<vector<int>> move(const vector<vector<int>>& state, int x1, int y1, int x2, int y2) {
    vector<vector<int>> newState = state;
    swap(newState[x1][y1], newState[x2][y2]);
    return newState;
}

int solve(vector<vector<int>> start, vector<vector<int>> goal) {
    int n = start.size();
    int m = start[0].size();

    // 找到空格位置
    int startX, startY, goalX, goalY;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (start[i][j] == 0) {
                startX = i;
                startY = j;
            }
            if (goal[i][j] == 0) {
                goalX = i;
                goalY = j;
            }
        }
    }

    priority_queue<Node> pq;
    unordered_set<string> visited;

    Node startNode = {start, startX, startY, 0, calculateHeuristic(start, goal), 0, ""};
    startNode.f = startNode.g + startNode.h;
    pq.push(startNode);
    visited.insert(stateToString(start));

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    string directions = "UDLR";

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        // 检查是否到达目标状态
        if (current.state == goal) {
            cout << "Path: " << current.path << endl;
            return current.g;
        }

        // 尝试移动空格到四个方向
        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                vector<vector<int>> newState = move(current.state, current.x, current.y, newX, newY);
                string newStateStr = stateToString(newState);

                if (visited.find(newStateStr) == visited.end()) {
                    Node newNode = {newState, newX, newY, current.g + 1, calculateHeuristic(newState, goal), 0, current.path + directions[i]};
                    newNode.f = newNode.g + newNode.h;
                    pq.push(newNode);
                    visited.insert(newStateStr);
                }
            }
        }
    }

    return -1; // 无解
}

int main() {
    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}
    };

    vector<vector<int>> goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    int steps = solve(start, goal);
    cout << "Minimum steps: " << steps << endl;

    return 0;
}
