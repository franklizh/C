#include<stdio.h>
void maxmin(int a[],int i,int j,int *max,int *min)
{
    int mid;
    int lmax,lmin,rmax,rmin;
    if(j==i){*max=a[i];*min=a[i];return;}
    else if(j-i==1)
    {
        if(a[i]>a[j]){*max=a[i];*min=a[j];return;}
        else {*max=a[j];*min=a[i];return;}
    }
    else
    {
        mid=(i+j)/2;
        maxmin(a,i,mid,&lmax,&lmin);
        maxmin(a,mid+1,j,&rmax,&rmin);
        if(lmax>rmax)*max=lmax;
        else *max=rmax;
        if(lmin<rmin)*min=lmin;
        else *min=rmin;
    }
}
int main()
{
    int a[6]={2,1,0,5,4,3};
    int min,max;
	 maxmin(a,0,5,&max,&min);
 
		printf("MAX=%d,MIN=%d ",max,min);
	return 0;
}