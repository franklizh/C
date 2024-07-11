// 从键盘输入n(n≤10)个同学的三门功课成绩，
//调用排序函数按成绩总分由高到低进行排序
//并输出排序后的结果。


#include <stdio.h>
typedef struct student
{
    char name[20];
    float score[3];
}STUDENT;

void swap (STUDENT*p,STUDENT*q)
{
    STUDENT  t;
    t = *p;
    *p=*q;
    *q = t;
}

void sortStu(STUDENT *s, int n)
{
    int i, j, k, ind;
    float sum, sum1;
    
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        sum = 0;
        for (j = 0; j < 3; j++)
            sum+=s[i].score[j];
        for (j = i + 1; j < n; j++)
        {
            sum1 = 0;
            for (k = 0; k < 3; k++)
                sum1 += s[j].score[k];
            if (sum1>sum)
            {
                ind = j;
                sum = sum1;
            }
        }
        if (ind != i)
            swap (s+i,s+ind);
    }
}
int main()
{
    STUDENT stu[10];
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s %f %f %f", stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
    
    sortStu(stu, n);
    
    for (i = 0; i < n; i++)
        printf("%s %.2f %.2f %.2f\n", stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2]);
    
    return 0;
}


// 3
// Liming 83 92 77
// Zhaolin 98 75 88
// Hanxu 76 82 63


// Zhaolin 98.00 75.00 88.00
// Liming 83.00 92.00 77.00
// Hanxu 76.00 82.00 63.00