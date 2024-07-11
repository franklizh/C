//1, 如果n为偶数，则将这n个硬币分成两等份，并将两份硬币放到天平两端，
//假币在较轻的那端


// 2, 如果n为奇数，则取出第1个硬币后将其余硬币分成两等份，
//并将两份硬币放到天平两端

// 2.1 如果两份硬币的重量相等，则第一个硬币为假币

// 2.2 否则，假币在较轻的那一端
#include<stdio.h>
//开始下标，结束下标，硬币数量，假币序号
void num(int i,int j,int n,int m,int &count)
{
    if(n%2==0)
    {
        n=n/2;
        count++;
        if(m-1<=i+n-1)//注意n=n/2
        {
            num(i,i+n-1,n,m,count);
        }
        else {
            num(i+n,j,n,m,count);
        }
    }
    else 
    {
        int q = i + 1;
		n = (n - 1) / 2;
		count++;
		if (m-1 == i)
		{

		}
		else if ((m - 1) <= (q + n -1)){
			if (n == 2){
				count++;
			}
			else{
				num( q, q + n - 1, n, m, count);
			}
			
		}
		else {
			if (n == 2){
				count++;
			}
			else{
				num( q + n, j, n, m, count);
			}
		}
 
    }
}