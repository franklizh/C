#include<stdio.h>
#include <math.h>
#define n 4
int x[n+1]={0};
int sum=0;
int place(int i)
{
    for(int j=1;j<i;j++)
        if( x[i]==x[j] || abs(i-j)==abs(x[i]-x[j]) )
            return 0;
    return 1; 
}
void queen(int i) //放第i个皇后
{
    if(i>n) sum++; //可行解个数加1 
    else
    for(int j=1; j<=n; j++)
    { 
        x[i] = j; //第t个皇后放在第j列
        if( place(i) ) 
            queen(i+1);
    }
}

int main()
{
    queen(1);
    printf("%d",sum);
}