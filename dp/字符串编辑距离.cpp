#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算字符串A转换为字符串B的最少操作次数
int editDistance(const string &A, const string &B) {
    int m = A.size();
    int n = B.size();
    
    // 创建一个二维数组来存储子问题的解
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    // 初始化边界情况
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // 将A的前i个字符转换为空字符串所需的删除操作次数
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // 将空字符串转换为B的前j个字符所需的插入操作次数
    }
    
    // 填充dp数组
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // 如果字符相同，不需要额外操作
            } else {
                dp[i][j] = min({ dp[i - 1][j] + 1, // 删除操作
                                 dp[i][j - 1] + 1, // 插入操作
                                 dp[i - 1][j - 1] + 1 }); // 替换操作
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string A = "sfdqxbw";
    string B = "gfdgw";
    cout << "Minimum number of operations required to convert A to B: " << editDistance(A, B) << endl;
    return 0;
}
