#include <stdio.h>
int main()
{
     int f,i;
     float cm;
     scanf("%f",&cm);
     cm=cm/100.0;           //ע�ⵥλ���� 
     f = cm/0.3048;
     i = (cm-0.3048*f)/0.3048*12;
     printf("%d %d\n",f,i);
     
     return 0;
}

 /* 
 
�����֪Ӣ�Ƴ��ȵ�Ӣ��foot��Ӣ��inch��ֵ����ô��Ӧ������
(foot+inch/12)��0.3048�����ڣ�����û������������������ô��ӦӢ�Ƴ��ȵ�Ӣ�ߺ�Ӣ���Ƕ����أ�������1Ӣ�ߵ���12Ӣ�硣 */