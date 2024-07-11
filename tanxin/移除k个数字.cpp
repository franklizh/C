// 给定一个以字符串表示的非负整数 num，移除这个
// 数中的 k 位数字，使得剩下的数字最小

#include <iostream>
#include <vector>
#include <limits.h>
#include<stack>
#include <math.h>
using namespace std;

string delk(const vector<int>&num,int k)
{
    stack<int> s;
    int n=num.size();
    for(int i=0;i<n;i++)
    {
        while(!s.empty()&&s.top()>num[i]&&k>0)
        {
            s.pop();
            k--;
        }
        if(!s.empty()||num[i]!=0)
        {
            s.push(num[i]);
        }
    }

    while(!s.empty()&&k>0)
    {
        s.pop();
        k--;
    }

    string res="";
    while(!s.empty())
    {
        res=to_string(s.top())+res;
        s.pop();
    }
    
    return res.empty()?"0":res;
}
int main()
{
    vector<int>num={1,4,3,2,2,1,9};
    cout<<delk(num,3);

}