#include<stdio.h>
int find(int a[],int len)
{
    int num=a[0];
    int count=1;
    for(int i=1;i<len;i++)
    {
        if(a[i]==num)
            count++;
        else 
            count--;
        if(count==0)
        {
            num=a[i];
            count=1;
        }
    }
    count=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]=num)
        count++;
    }
    if(count*2>len)
        return num;
    return 0;
}
int find2(int a[])
{
    
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
    int f=find(a,len);
    printf("%d",f);
    return 0;
}