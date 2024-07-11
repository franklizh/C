/* #include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool ifs(char a)
{
    if(a>='0'&&a<='9'||a>='a'&&a<='f')return true;
    else return false;
}
int trans(char a)
{
    if(a>='0'&&a<='9')return a-'0';
    if(a>='a'&&a<='f')return a-'a'+10;
}
int main()
{
    char a;
    scanf("%c",&a);
    char s[100];
    s[0]=a;
    int i=1;
    while(a!='#')
    {
        scanf("%c",s[i]);
        i++;
    }
    int n=i;
    char stack[n+1];
    int temp=0;
    int mark=0;
    for(int j=0;j<=n;j++)
        {
            if(ifs(s[j]))
            {mark=j;
             break;
            }
        }
        for(int m=0;m<=n;m++)
        {
            if(ifs(s[m])){stack[temp]=s[m];temp++;}
        }
     if(temp==0)printf("0");
    else{
         
        int times=0;
        int sum=0;
        for(int k=temp-1;k>=0;k--)
        {
            sum=sum+trans(s[k])*pow(16,times);
            times++;
        }
        if(sum!=0&&mark==0)printf("%d",sum);
        if(sum!=0&&mark>0)printf("-%d",sum);
    }
    return 0;
} */
//输入一个以#结束的字符串，本题要求滤去所有的非十六进制字符（不分大小写），组成一个新的表示十六进制数字的字符串，
//然后将其转换为十进制数后输出。如果在第一个十六进制字符之前存在字符“-”，则代表该数是负数。
#include<stdio.h>

int main()
{

    char a;
    int flag=1,mark=0,sum=0; 
	//flag来表示有没有读到第一个字符，mark来表示第一个字符是不是'-'
    scanf("%c",&a);
    while(a!='#')
    {
        if(a>='0'&&a<='9'){
            flag=0;
            sum=sum*16+a-'0';

        }else if(a>='a'&&a<='f'){
            flag=0;
            sum=sum*16+a-'a'+10;

        }else if(a>='A'&&a<='F'){
            flag=0;
            sum=sum*16+a-'A'+10;

        }else if(a=='-'&&flag==1)
            mark=1;
        scanf("%c",&a);
	}

    if(sum==0) 
		printf("0");
    else
	{
        if(mark==1) 
			printf("-");
        printf("%d\n",sum);
    }

    return 0;

}
