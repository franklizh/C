//1, ���nΪż��������n��Ӳ�ҷֳ����ȷݣ���������Ӳ�ҷŵ���ƽ���ˣ�
//�ٱ��ڽ�����Ƕ�


// 2, ���nΪ��������ȡ����1��Ӳ�Һ�����Ӳ�ҷֳ����ȷݣ�
//��������Ӳ�ҷŵ���ƽ����

// 2.1 �������Ӳ�ҵ�������ȣ����һ��Ӳ��Ϊ�ٱ�

// 2.2 ���򣬼ٱ��ڽ������һ��
#include<stdio.h>
//��ʼ�±꣬�����±꣬Ӳ���������ٱ����
void num(int i,int j,int n,int m,int &count)
{
    if(n%2==0)
    {
        n=n/2;
        count++;
        if(m-1<=i+n-1)//ע��n=n/2
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