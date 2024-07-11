#include<stdio.h>
int ternarySearch(int a[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid1=l+(l-r)/3;
        int mid2=mid1+(l-r)/3;
        if(a[mid1]==x)return mid1;
        if(a[mid2]==x)return mid2;
        if(a[mid1]>x)return ternarySearch(a,l,mid1-1,x);
        if(a[mid2]<x)return ternarySearch(a,mid2+1,r,x);
        return ternarySearch(a,mid1+1,mid2-1,x);
    }
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    
	return 0;
}