#include<stdio.h>
int main()
{
    int i,j,n,a[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)//±éÀúÊäÈë
        scanf("%d",&a[i]);
    if(n>=1)printf("%d",a[0]);
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i;j++)
            if(a[i]==a[j])
            break;
        if(j==i)
            printf(" %d",a[i]);
    }
    return 0;
}