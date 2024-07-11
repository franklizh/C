#include <stdio.h>
#define MAX 0x7fffffff
//（1）只能买卖一次，且无手续费
void situa1(){ 
    int prices[]={0,3,9,2,5,4,7,1}; 
    int minPrices = MAX ,n=sizeof(prices)/sizeof(int)-1;
    int buy=1,sell=1,k=1,profit=0; 
 
    for(int i = 2; i <= n;i++){ 
    if(prices[i]-prices[k]>profit){ //今天是否拟卖出
        profit = prices[i]-prices[k];
        buy=k; sell=i;
    }
    if(prices[i] < prices[k]) k=i; //今天的价格是否更低
    }
    printf("buy=%d,sell=%d,profit=%d\n",buy,sell,profit); 
  
}
 
int main(){
    situa1();
}