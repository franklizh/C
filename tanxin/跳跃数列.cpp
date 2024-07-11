// 给定一个非负整数数组(长度<=100)，你最初位于数组的第一个位置。
// 数组中的每个元素(值在1-1000之间)代表你在该位置可以跳跃的最大长度。
// 假设总可以到达数组的最后一个位置，设计算法，
// 如何使用最少的跳跃次数到达数组的最后一个位置。输出跳跃点及跳跃次数。


#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void minJumps(const vector<int>&num)
{
    int n=num.size();
    if(n<=1)
    {
        printf("is at the last");
        return;
    }

    int jump=0,end=0,farest=0;
    vector<int> jumpmark;

    for(int i=0;i<n-1;i++)
    {
        farest=max(farest,i+num[i]);

        if(i==end)
        {
            jump++;
            end=farest;
            jumpmark.push_back(i);

            if(end>=n-1)break;
        }
    }
    printf("jump points:\n");
    for(int i:jumpmark)
    {
       cout << i << " ";
    }
    printf("num of jump is %d",jump);
}
int main()
{
    vector<int>num={2,3,1,1,1};
    minJumps(num);
    return 0;
}
