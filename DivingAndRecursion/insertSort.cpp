//ֱ�Ӳ�������ݹ�ͷǵݹ�
#include<stdio.h>
//ֱ�Ӳ�������ǵݹ�
void insertSort(int a[],int len)
{
    for(int i=1;i<len;i++)
    {
        int temp=a[i];
        int j;
        for(j=i-1;j>=0&&a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}
void insertSortRe(int a[],int len)
{
    if(len<2)
        return;
    insertSortRe(a,len-1);
    int temp=a[len-1];
    int i;
    for(i=len-2;i>=0&&a[i]>temp;i--)
    {
        
        a[i+1]=a[i];
    }
    a[i+1]=temp;

}
int main()
{
    int len;
    printf("�������鳤��\n");
    scanf("%d",&len);
    int n=len;
    int j=0;
    int a[len+1];
    printf("��������");
    while(n--)
    {
        scanf("%d",&a[j]);
        j++;
    }
   // insertSort(a,len);
   insertSortRe(a,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
