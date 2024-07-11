#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits.h>
#include <unordered_map>

using namespace std;


int find(const vector<int>&ve)
{
    if(ve.size()==0)
    {
        return 0;
    }
    int dp[ve.size()];
    dp[0]=1;
    int maxans=1;

    for(int i=1;i<ve.size();i++)
    {
        dp[i]=1;

        for(int j=0;j<i;j++)
        {
            //找到前面比nums[i]小的数nums[j],即有dp[i]= dp[j]+1
            if(ve[j]<ve[i])
            {
                //因为会有多个小于nums[i]的数，也就是会存在多种组合了嘛，我们就取最大放到dp[i]
                dp[i]=max(dp[i],dp[j]+1);
            }
        }

        maxans=max(maxans,dp[i]);//找整段序列最大的
    }
    return maxans;
}

int main()
{
    vector<int> ve;
    ve.push_back(0);
    ve.push_back(1);
    ve.push_back(0);
    ve.push_back(3);
    ve.push_back(2);
    ve.push_back(3);
    cout<<find(ve);
}