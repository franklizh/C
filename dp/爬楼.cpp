#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits.h>
#include <unordered_map>

using namespace std;

std::unordered_map<int, int> myMap;

//自顶向下
int numways(int n)
{
    if(n==0)
        return 1;
    if(n<=2)
        return n;
    if(myMap.find(n)!=myMap.end())//在备忘录中
    {
        return myMap[n];
    }else{
        myMap[n]=numways(n-1)+numways(n-2);
        return myMap[n];
    }
}

//自低向上
int numways2(int n)
{
    if(n<=1)
        return 1;
    if(n==2)
        return 2;
    int a=1;
    int b=2;
    int temp=0;
    for(int i=3;i<=n;i++)
    {
        temp=a+b;
        a=b;
        b=temp;
    }
    return temp;
}

int main()
{
    int n;
    cin>>n;
    cout<<numways(n)<<endl;
    cout<<numways2(n)<<endl;
    cout<<"我真聪明";
}