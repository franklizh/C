#include<stdio.h>
#include<malloc.h>

//合并成有序，借助数组b
 void merge(int a[],int b[],int low,int mid,int high)
 {
    int i=low,j=mid+1,k=low;//k用来给数组b中放元素
    
    while(i!=mid+1&&j!=high+1)
    {
        if(a[i]>a[j])
            b[k++]=a[j++];
        else
            b[k++]=a[i++];
    }

    while(i!=mid+1)
        b[k++]=a[i++];
    while(j!=high+1)
        b[k++]=a[j++];

    //复制给数组a  
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
 }

 //分开
void mergesort(int a[],int b[], int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergesort(a,b,low,mid);
        mergesort(a,b,mid+1,high);
        merge(a,b,low,mid,high);
    }
}

int main()
{
    int a[6]={2,1,0,5,4,3};
    int b[6];
	mergesort(a,b,0,5);
 
  
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	return 0;
}