/*  UTF-8 编码 */
/* 一个字占三个字符 */


#include<stdio.h>
int main()
{
    char a[4][100];
    for(int i=0;i<4;i++)
    {
        scanf("%s",a[i]);
    }
      for(int i=0;i<4;i++)
    {
        printf("%c%c%c",a[i][0],a[i][1],a[i][2]);
    }
    
    return 0;
    
}