//Ѱ�������ȳ��������е���λ��
#include<stdio.h>
void postpart(int &a,int &b)
{
    int mid=(a+b)/2;
    if((a+b)%2==0)a=mid;//������Ԫ��
    else a=mid+1;//ż��
}
void prepart(int &a,int &b)
{
    int mid=(a+b)/2;
    b=mid;//��ǰ�沿����żһ��
}
int midnum(int a[],int m,int n,int b[],int p,int q)
{
    if (m==n&&p==q)
    {
         return a[m]<b[p]?a[m]:b[p]; 
    }
    else{
    int mid1=(m+n)/2;
    int mid2=(p+q)/2;
    if(a[mid1]==b[mid2])return a[mid1];
    else
    {
        if(a[mid1]>b[mid2])
        {
            prepart(m,n);
            postpart(p,q);
            return midnum(a,m,n,b,p,q);
        }
        
        if(a[mid1]<b[mid2])
        {
            prepart(p,q);
            postpart(m,n);
            return midnum(a,m,n,b,p,q);
        }
    }
    }
    return 0; 
}
int main()
{
    int n,m;
     
    printf("�����һ����Ԫ�ظ���");
    scanf("%d\n",&n);
    printf("����ڶ�����Ԫ�ظ���");
    scanf("%d\n",&m);
      int a[n+1],b[m+1];
    int i=0;
  for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        
    }
    
  for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        i++;
    }
    printf("��λ��Ϊ%d",midnum(a,0,n-1,b,0,m-1));
    return 0;
}