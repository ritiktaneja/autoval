/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
        int year;year = input_year;;
        //scanf ("%d",&year);
        if (year%4==0 && year%100!=0)//initialising if condition for a                                        leap year not divisible by 100
        {
            return  1;

        }
        else

        if (year%100==0 && year%400==0)//initialising if condition for                                         leap year divisible by 100
        {
            return  1;
        }
        else
        {
            return  0;
        }

    //return 0;
}
