#include<stdio.h>
#define K 7
int main()
{
    int i,num = 0,s=0; //num加油次数；s加满油后已行驶的公里数
    int N;
    int a[N+2]={0,1,2,3,4,5,1,6,6};
    int b[N+1]={0}; //加油站加油最优解b1~bN
    for(i = 1;i <=N+1 ;i++)
        if(a[i] > K) { printf("no solution\n"); return 0; }
    for(i = 1,s = 0;i < N+1;i++) { s += a[i];
        if(s + a[i+1] > K) { num++; b[i]=1; s = 0; }
        }
return 0;
}