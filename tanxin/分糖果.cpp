// 老师想给孩子们分发糖果，有 N 个孩子站成了一
// 条直线，老师会根据每个孩子的表现，预先给他们评分并分
// 发糖果。规则为：每个孩子至少分配到 1 个糖果，评分更高
// 的孩子必须比他两侧的邻位孩子获得更多的糖果。请帮忙算
// 算，老师至少需要准备多少颗糖果？
// 输入：[1，0，2]
// 输出：5（分别发2、1、2 颗糖果）

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCandies(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1); // 每个孩子至少得到一个糖果

    // 从左到右遍历
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // 从右到左遍历
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // 计算总糖果数
    int totalCandies = 0;
    for (int candy : candies) {
        totalCandies += candy;
    }

    return totalCandies;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    cout << "Minimum candies needed: " << minCandies(ratings) << endl;
    return 0;
}
