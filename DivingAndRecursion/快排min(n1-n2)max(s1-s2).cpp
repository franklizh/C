/* 已知由n（n≥2）个正整数构成的集合A={ak}（1≤k≤n），将
其划分为两个不相交的子集 A1和A2，元素个数分别是n1和n2， A1 和A2中元素之和分别为S1和S2。设计一个尽可能高效的划分算法，
满足|n1-n2|最小且|S1-S2|最大。 */
#include<stdio.h>
int findpos(int a[],int low,int high)
{
    int pos=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pos)//移动条件a[hight]<pos
        {
            high--;
        }
        a[low]=a[high];
        while(low<high&&a[low]<=pos)//移动条件a[low]>pos
        {
            low++;
        }
        a[high]=a[low];

    }
    a[low]=pos;
    return low;
}
int solution(int a[],int n)
{
    int low=1,high=n;
    while(1)
    {
        int i=findpos(a,low,high);
        if(i==n/2)break;
        else if(i<n/2)
            low=i+1;
        else
        high=i-1;
    }
    int s1=0,s2=0;
    for(int i=1;i<=n/2;i++)
        s1+=a[i];
    for(int j=n/2+1;j<=n;j++)
        s2+=a[j];
    return s2-s1;
}
int main()
{
    int len; 
    printf("输入数组长度\n");
    scanf("%d",&len);
    int n=len;
    int j=0;
    int a[len+1];
    printf("输入数组");
    while(n--)
    {
        scanf("%d",&a[j]);
        j++;
    }
   printf("%d",solution(a,len));
}