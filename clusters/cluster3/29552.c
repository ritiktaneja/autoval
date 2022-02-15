#include <stdio.h>
int digitSum(int n)
{
	int sum=0;
    //int m=n;
    for(int i=0;n>0;i++)
    {
        sum+=n%10;n=n/10;
    }
    //printf("%d %d\n",m,sum);
    if(sum>=10)
    {return digitSum(sum);}
    else
    {return sum;}
}