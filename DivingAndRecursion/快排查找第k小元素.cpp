int quicksort(int a[],int s,int l,int k)
{
    int i,j,tmp;
    if(s==l&&s==k)
    {
        return a[s];
    }
    if(s>l)return 0;
    tmp=a[s];
    i=s;
    j=l;
    while(i<j)
    {
        while(i<j&&a[j]>=tmp)
        j--;
        a[i]=a[j];
        while(i<j&&a[i]<=tmp)
        i++;
        a[j]=a[i];
    }
a[i]=tmp;
if(i==k)return a[i];
else if(i>k)return quicksort(a,s,i-1,k);
else return quicksort(a,i+1,l,k);
}