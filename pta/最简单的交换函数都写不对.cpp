/**
 *  快学，别摆了
*/
#include<stdio.h>
void Swap(int *x,int *y)
{
    int t;
    t=*x;
    *x=*y;
    *y=t;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    Swap(&a,&b);
    printf("%d %d",a,b);
    return 0;
}