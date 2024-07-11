#include<stdio.h>
void SelectSortRe(int a[],int i,int n)
{
    int j,k;
    if(i==n)return;
    k=i;
    for(j=i+1;j<=n;j++)
    {
        if(a[j]<a[k])k=j;

    }
    if(k!=i)
        { int tem=a[i];
         a[i]=a[k];
        a[k]=tem;
        }
    SelectSortRe(a,i+1,n);
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
  SelectSortRe(a,1,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
