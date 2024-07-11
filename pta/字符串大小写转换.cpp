#include <stdio.h>

void convert(char *p)
{
     while(*p != '\0') 
     {    
         if (*p >= 'A' && *p <= 'Z')
             *p=*p+32;    
         else if (*p >= 'a' && *p <= 'z')
             *p=*p-32;   
         p++;  
     }
}

int main()  
{
    int i;
    char str[50];
    gets(str);
    convert(str);
    puts(str);
    return 0;
} 