/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
int student_solution(int input_year)
{
    int y;y = input_year;;
    //scanf("%d",&y);
    if(y%4==0 || y%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //return 0;
}
