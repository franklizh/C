#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// 重载操作符实现小根堆
class ServicePoint {
public:
    int endTime;

    ServicePoint(int t = 0) : endTime(t) {}

    bool operator>(const ServicePoint& other) const {
        return endTime > other.endTime;
    }
};

void assignServicePoints(vector<int>& serviceTimes, int s) {
    // 优先队列（小根堆），存储每个服务点的结束时间
    priority_queue<ServicePoint, vector<ServicePoint>, greater<ServicePoint>> servicePoints;

    // 初始化服务点
    for (int i = 0; i < s; ++i) {
        servicePoints.push(ServicePoint(0));
    }

    int totalWaitTime = 0;

    for (int time : serviceTimes) {
        ServicePoint sp = servicePoints.top();
        servicePoints.pop();
        
        totalWaitTime += sp.endTime; // 累加等待时间
        sp.endTime += time;          // 更新服务点的结束时间

        servicePoints.push(sp);      // 将服务点重新加入队列
    }

    double averageWaitTime = static_cast<double>(totalWaitTime) / serviceTimes.size();
    cout << "Total wait time: " << totalWaitTime << endl;
    cout << "Average wait time: " << averageWaitTime << endl;
}

int main() {
    vector<int> serviceTimes = {56, 12, 1, 99, 1000, 234, 33 ,55 ,99 ,812}; // 每个顾客的服务时间
    int s = 2; // 服务点数量

    assignServicePoints(serviceTimes, s);

    return 0;
}
