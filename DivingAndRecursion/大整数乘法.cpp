#include<math.h>
#include<cmath>
int divideConquer(int X,int Y,int n)
{
    int x=abs(X);
    int y=abs(Y);
    if(x==0||y==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return x*y;
    }
    else{
        int A=x/pow(10,n/2);
        int B=x-A*pow(10,n/2);
        int C=y/pow(10,n/2);
        int D=y-C*pow(10,n/2);
        int AC=divideConquer(A,C,n/2);
        int BD=divideConquer(B,D,n/2);
        int ABCD=divideConquer((A-B),(D-C),n/2)+AC+BD;
        return AC*pow(10,n)+ABCD+pow(10,n/2)+BD;
    }
}