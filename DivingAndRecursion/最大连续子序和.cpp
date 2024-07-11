//最大连续子序和
//递归和dp
#include<stdio.h>
#include<iostream>
using namespace std;
int max(int a,int b, int c)
{
    if(a>b)b=a;
    return c>b?c:b;
}
 int max_sub_sum(int a[], int str, int end) {
	if (str == end) {
		if (a[str] < 0) {
			return 0;
		}
		else {
			return a[str];
		}
	}
	else {
		int max_left_sum, max_right_sum;
		int mid = (str + end) / 2;
		max_left_sum = max_sub_sum(a, str, mid);//左半边的最大
		max_right_sum = max_sub_sum(a, mid + 1, end);//右半边的最大
		
		//求序列中间分别到两边的最大
		int max_left_boarder_sum = 0, max_right_boarder_sum = 0;
		int left_boarder_sum = 0, right_boarder_sum = 0;
		for (int i = mid; i >= str; i--) {
			left_boarder_sum += a[i];
			if (left_boarder_sum > max_left_boarder_sum) {
				max_left_boarder_sum = left_boarder_sum;
			}
		}
		for (int i = mid + 1; i <= end; i++) {
			right_boarder_sum += a[i];
			if (right_boarder_sum > max_right_boarder_sum) {
				max_right_boarder_sum = right_boarder_sum;
			}
		}

		//中间最大为两个加起来
		int max_mid_sum = max_left_boarder_sum + max_right_boarder_sum;

		//三个求最大
		return max(max_left_sum, max_mid_sum, max_right_sum);
	}
} 
int max2(int a,int b)
{
	if(a>b)return a;
	else return b;
}
//DP[i]为第i位结束的最大连续子序列
//dp[i]=max(dp[i-1]+num[i],num[i])
int maxsubDP(int a[],int len)
{
	int dp[len+1];
	dp[0]=a[0];
	int max=0;
	for(int i=1;i<len;i++)
	{
		dp[i]=max2(dp[i-1]+a[i],a[i]);
	}
	for(int i=0;i<len;i++)
	{
		if(dp[i]>max)max=dp[i];
	}
	return max;
}
int main() {
	int a[] = { -2, 11, -4, 13, -5 ,-2 };
	int len = sizeof(a) / sizeof(a[0]);
	int value =  max_sub_sum(a, 0, len - 1);
	int value2 =  maxsubDP(a,  len );
	cout << "最大连续子序列和为：" << value << endl;
	cout << "最大连续子序列和为：" << value2 << endl;
	return 0;
}
 














// int maxsub(int a[],int start,int end)
// {
     
// 	
//     if(start==end)
//     {
//         if(a[start]<0)return 0;
//         else return a[start];
//     }
//     else
//     {
//         int mid=(start+end)/2;
//         int rightpartmax=maxsub(a,start,mid);
//         int leftpartmax=maxsub(a,mid+1,end);
       
//         int letfmax,rightmax;
//         letfmax=rightmax=0;
//         for(int i=mid;i>=start;i--)
//         {
//             if(a[i]+letfmax>letfmax)letfmax=a[i]+letfmax;
//         }
//          for(int i=mid+1;i<=end;i++)
//         {
//             if(a[i]+rightmax>rightmax)rightmax=a[i]+rightmax;
//         }
//         int midpartmax=letfmax+rightmax;
//         return max(rightpartmax,leftpartmax,midpartmax);
        
//     }

// }