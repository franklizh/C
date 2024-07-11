//遍历数组，找到最大的三个数，
//或最大的一个数乘最小的两个数,
//两者求最大
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution{
    public:
        long long maxp(std::vector<int>& nums){
            int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
            int min1=INT_MAX,min2=INT_MAX;

            for(int num:nums)
            {
                if(num>max1){
                    max3=max2;
                    max2=max1;
                    max1=num;
                }else if(num>max2){
                    max3=max2;
                    max2=num;
                }else if(num>max3){
                    max3=num;

                }
                if(num<min1){
                    min2=min1;
                    min1=num;
                }else if(num<min2){
                    min2=num;
                }
            }
            // 使用 static_cast 转换为 long long 以避免溢出
    long long product1 = static_cast<long long>(max1) * max2 * max3;
    long long product2 = static_cast<long long>(max1) * min1 * min2;

    // 使用 std::max 比较两个 long long 类型的值
    long long maxProduct = std::max(product1, product2);
    return maxProduct;
        }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    long long result = solution.maxp(nums);
    
    std::cout << "Max: " << result << std::endl;
    
    return 0;
}