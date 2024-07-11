#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int main()
{
    vector<int>prices={23, 18, 22, 35, 16, 8, 4, 30, 35};
    vector<pair<int,int>>tran;
    int profit=0;
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]>prices[i-1])
        {
            tran.push_back({i-1,i});
            profit+=prices[i]-prices[i-1];
        }
    }

    for(const auto& tran:tran)
    {
        printf("buy on %d,price= %d   sell on %d,price=%d \n",tran.first,prices[tran.first],tran.second,prices[tran.second]);
    }
    cout << "Total Profit: " <<profit << endl;

    return 0;

}