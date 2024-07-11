// 数字ASCII为48到57


#include <stdio.h>
#include <string.h>
void myscat(char str1[], char str2[]);
#define N 80
int main()
{char  s[N], t[N];
 gets(s);
 gets(t);
 
myscat(s,t);  //调用函数
 puts(s);
 return 0;
}
void myscat(char str1[], char str2[])
{int i = 0, j;
 while (str1[i] != '\0')
    i++;
 for(j=0;str2[j]!='\0';i++)
     {
        str1[i]=str2[j];  
        j++;
            }
     str1[i] = '\0';
}