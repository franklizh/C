/* ��֪��n��n��2�������������ɵļ���A={ak}��1��k��n������
�仮��Ϊ�������ཻ���Ӽ� A1��A2��Ԫ�ظ����ֱ���n1��n2�� A1 ��A2��Ԫ��֮�ͷֱ�ΪS1��S2�����һ�������ܸ�Ч�Ļ����㷨��
����|n1-n2|��С��|S1-S2|��� */
#include<stdio.h>
int findpos(int a[],int low,int high)
{
    int pos=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pos)//�ƶ�����a[hight]<pos
        {
            high--;
        }
        a[low]=a[high];
        while(low<high&&a[low]<=pos)//�ƶ�����a[low]>pos
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
   printf("%d",solution(a,len));
}