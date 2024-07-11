// dp[i][j] 表示序列 A 的前 i 个字符与序列 B 的前 j 个字符的最长公共子序列的长度。
// 1.当前字符匹配，则最长公共子序列长度增加1:
// A[i-1] == B[j-1]，则 dp[i][j] = dp[i-1][j-1] + 1
// 2.当前字符不匹配，则取去掉一个字符后的最长公共子序列长度的较大值
// A[i-1] != B[j-1]，则 dp[i][j] = max(dp[i-1][j], dp[i][j-1])

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>

using namespace std;

pair<int, string> longestCommonSubsequence(const string& A, const string& B) {
    int m = A.size();
    int n = B.size();
    
    // 创建一个 (m+1) x (n+1) 的二维数组，初始化为0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // 动态规划填表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // 回溯找到最长公共子序列
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs.push_back(A[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    
    // 由于我们是从后往前构建的子序列，所以需要反转
    reverse(lcs.begin(), lcs.end());
    
    return {dp[m][n], lcs};
}

int main() {
    string A = "ABCBDAB";
    string B = "BDCAB";
    
    auto result = longestCommonSubsequence(A, B);
    int lcs_length = result.first;
    string lcs = result.second;
    
    cout << "最长公共子序列的长度是: " << lcs_length << endl;
    cout << "最长公共子序列是: " << lcs << endl;
    
    return 0;
}
