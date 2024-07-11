#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits.h>

using namespace std;

struct Activity
{
    int start;
    int end;
};

bool compare(Activity s1,Activity s2)
{
    return s1.end<s2.end;
}

void backtrack(int index,int n,const vector<Activity>& activities,
vector<Activity>& currentActivities,vector<Activity>& selectedActivities,
int& maxCount,int &last_end_time)
{
    if(index==n)
    {

        if(currentActivities.size()>maxCount)
        {
            maxCount=currentActivities.size();
            selectedActivities=currentActivities;
        }
        return ; //没加return没有输出
    }

    //包含当前活动
    if(activities[index].start>=last_end_time){
        int pre_end_time=last_end_time;//记录lastendtime用来回su
        last_end_time=activities[index].end;
        currentActivities.push_back(activities[index]);
        backtrack(index+1,n,activities,currentActivities,selectedActivities,maxCount,last_end_time);
        currentActivities.pop_back();
        last_end_time=pre_end_time;
    }

    //不包含当前活动
    backtrack(index+1,n,activities,currentActivities,selectedActivities,maxCount,last_end_time);
}

void activitySelection(vector<Activity>&activities,vector<Activity>&selectedActivities,int &maxCount)
{
    //按结束时间排序
    std::sort(activities.begin(),activities.end(),compare);
    int n=activities.size();
    int last_end_time=-1;

    vector<Activity>currentActivities;
    backtrack(0,n,activities,currentActivities,selectedActivities,maxCount,last_end_time);
}


int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {4, 7}, {1, 8}, {5, 9}, {8, 10}};
    vector<Activity> selectedActivities;
    int maxCount = 0;

    activitySelection(activities, selectedActivities, maxCount);

    cout << "Maximum number of activities: " << maxCount << endl;
    cout << "Selected activities are: " << endl;
    
    //auto 关键字使编译器能够自动推断变量的类型
    for (auto& activity : selectedActivities) {
        cout << "[" << activity.start << ", " << activity.end << "]" << endl;
    }

    return 0;
}