/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int n;n = input_year;;
    int a;
    int b;
    int c;
    //scanf("%d",&n);
    a=n%4;
    b=n%100;
    c=n%400;
    if (a==0)
    {
        if(b==0)
        {if(c==0)
    return 1;
    else
    return 0;
}   
else
return 1;
}
else
return 0;
//return 0;
}