/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int t;t = input_year;;
    //scanf("%d", &t);
    if(((!(t%4))&&(t%100))||(!(t%400)))
        {return 1;}
    else
        {return 0;}
    //return 0;
}