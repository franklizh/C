// 遍历所有字符对，如果 A[i - 1] 和 B[j - 1] 相等，则更新 dp[i][j] 为 dp[i - 1][j - 1] + 1。
// 同时，如果更新后的值大于 maxLength，则更新 maxLength 和 endIndex。
// 如果字符不相等，则将 dp[i][j] 置为0。


#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, string> longestCommonSubstring(const string& A, const string& B) {
    int m = A.size();
    int n = B.size();

    // 创建一个 (m+1) x (n+1) 的二维数组，初始化为0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0; // 记录最长公共子串的长度
    int endIndex = 0; // 记录最长公共子串的结束位置

    // 动态规划填表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1; // 更新最长公共子串的结束位置
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // 提取最长公共子串
    string lcs = A.substr(endIndex - maxLength + 1, maxLength);

    return {maxLength, lcs};
}

int main() {
    string A = "ABCBA";
    string B = "BABCA";

    auto result = longestCommonSubstring(A, B);
    int lcs_length = result.first;
    string lcs = result.second;

    cout << "最长公共子串的长度是: " << lcs_length << endl;
    cout << "最长公共子串是: " << lcs << endl;

    return 0;
}
