#include<istream>
#include<stdio.h>
using namespace std;
int maxlen(int num[],int length)
{
    // int length = sizeof(num) / sizeof(num[0]);
// printf("%d\n",length);
    if(length<2)
        return length;
    int preDiff=num[1]-num[0];
    int result=num[1]==num[0]?1:2;
    for(int i=2;i<length;i++)
    {
        int cur=num[i]-num[i-1];
        if((cur>0&&preDiff<=0)||(cur<0&&preDiff>=0))
        {
            result++;
            preDiff=cur;
        }

    }

    return result;
    
}
int main()
{
    int a[]={1,2,1,0};
    printf("maxlen is %d",maxlen(a,4));

}