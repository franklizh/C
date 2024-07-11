// //≤‚ ‘getchar()
// #include <cstdio>
// using namespace std;

// int main()
// {
// 	int n,a,b;
// 	scanf("%d",&n);
// 	while(n--)
// 	{
// 		scanf("%d",&a);
//         char ch=getchar();
//         scanf("%d",&b);
 
//     }
//     printf("%d%d",a,b);
// }

#include<stdio.h>
int main()
{
    
    int bl ;
    int di ;
    int other ;
	bl=di=other=0;
    char s= getchar();
    while(s!='\n')
    {
        if(s==' ')
            bl++;
        else if(s>='0'&&s<='9')
            di++;
        else other++;
       s= getchar();
    }
    printf("blank = %d, digit = %d, other = %d",bl,di,other);
    return 0;
}