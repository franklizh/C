#include <stdio.h>
int main()
{
     int f,i;
     float cm;
     scanf("%f",&cm);
     cm=cm/100.0;           //注意单位换算 
     f = cm/0.3048;
     i = (cm-0.3048*f)/0.3048*12;
     printf("%d %d\n",f,i);
     
     return 0;
}

 /* 
 
如果已知英制长度的英尺foot和英寸inch的值，那么对应的米是
(foot+inch/12)×0.3048。现在，如果用户输入的是厘米数，那么对应英制长度的英尺和英寸是多少呢？别忘了1英尺等于12英寸。 */