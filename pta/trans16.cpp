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
//����һ����#�������ַ���������Ҫ����ȥ���еķ�ʮ�������ַ������ִ�Сд�������һ���µı�ʾʮ���������ֵ��ַ�����
//Ȼ����ת��Ϊʮ�����������������ڵ�һ��ʮ�������ַ�֮ǰ�����ַ���-�������������Ǹ�����
#include<stdio.h>

int main()
{

    char a;
    int flag=1,mark=0,sum=0; 
	//flag����ʾ��û�ж�����һ���ַ���mark����ʾ��һ���ַ��ǲ���'-'
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
