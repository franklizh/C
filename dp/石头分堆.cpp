//dp[i][j] 表示将第 i 堆石子合并到第 j 堆石子所需的最小力气
//辅助数组 prefixSum，其中 prefixSum[i] 表示前 i 堆石子的总和，以便快速计算任意子区间的石子总数。

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCostToMergeStones(vector<int>& stones) {
    int n = stones.size();
    if (n == 1) return 0;  // 如果只有一堆石子，直接返回0

    vector<vector<int>> dp(n, vector<int>(n, 0)); // 创建 dp 数组并初始化为 0
    vector<int> prefixSum(n + 1, 0); // 创建前缀和数组

    // 计算前缀和数组
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }

    // 填表格
    for (int length = 2; length <= n; ++length) {  // 子问题的长度从2到n
        for (int i = 0; i + length - 1 < n; ++i) { // 起点从0到n-length
            int j = i + length - 1;  // 终点位置
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + prefixSum[j + 1] - prefixSum[i];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1]; // 返回将所有石子合并成一堆的最小力气数
}

int main() {
    vector<int> stones = {1,3,5,2}; // 示例输入
    cout << "将石子合并成一堆的最省力气数是: " << minCostToMergeStones(stones) << endl;
    return 0;
}
