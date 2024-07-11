#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxsub(vector<int>& nums)
{
    int n=nums.size();
    if(n==0)return 0;
    vector<int> dp(n);
    dp[0]=nums[0];
    int maxsum=dp[0];

    for(int i=1;i<n;i++)
    {
        dp[i]=max(nums[i],dp[i-1]+nums[i]);
        maxsum=max(maxsum,dp[i]);
    }
    return maxsum;
}

int main()
{
    vector<int>nums={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "最大连续子序列和: " << maxsub(nums) << endl;
    return 0;
}