#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSprinklers(vector<int>& ranges) {
    int n = ranges.size() - 1;  // 花盆的数量
    vector<pair<int, int>> intervals;

    for (int i = 0; i <= n; ++i) {
        int left = max(0, i - ranges[i]);
        int right = min(n, i + ranges[i]);
        intervals.push_back({left, right});
    }

    // 按照起始位置进行排序
    sort(intervals.begin(), intervals.end());

    int count = 0;
    int end = 0;
    int i = 0;

    while (end < n) {
        int farthest = end;
        while (i <= n && intervals[i].first <= end) {
            farthest = max(farthest, intervals[i].second);
            ++i;
        }

        if (farthest == end) {
            return -1;  // 无法覆盖所有花盆
        }

        ++count;
        end = farthest + 1;
    }

    return count;
}

int main() {
    vector<int> ranges = {2, 3, 0, 0, 1};
    int result = minSprinklers(ranges);

    if (result == -1) {
        cout << "无法覆盖所有花盆" << endl;
    } else {
        cout << "最少需要的喷头数量: " << result << endl;
    }

    return 0;
}
