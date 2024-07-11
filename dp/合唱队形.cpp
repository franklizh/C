#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cout << "输入学生人数N：";
    cin >> N;
    vector<int> heights(N);
    cout << "输入每个学生的身高：";
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    // 求从左到右的LIS长度
    vector<int> leftLIS(N, 1);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[i] > heights[j]) {
                leftLIS[i] = max(leftLIS[i], leftLIS[j] + 1);
            }
        }
    }

    // 求从右到左的LIS长度
    vector<int> rightLIS(N, 1);
    for (int i = N - 2; i >= 0; --i) {
        for (int j = N - 1; j > i; --j) {
            if (heights[i] > heights[j]) {
                rightLIS[i] = max(rightLIS[i], rightLIS[j] + 1);
            }
        }
    }

    // 结合两个LIS，找到最长合唱队形的长度
    int maxLength = 0;
    for (int i = 0; i < N; ++i) {
        if (leftLIS[i] > 1 && rightLIS[i] > 1) {
            maxLength = max(maxLength, leftLIS[i] + rightLIS[i] - 1);
        }
    }

    // 计算需要出列的学生数
    int toRemove = N - maxLength;
    cout << "需要出列的学生数：" << toRemove << endl;

    return 0;
}
