/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
int student_solution(int input_year)
{
    int year;year = input_year;;
    //scanf("%d",&year);
    if(year%4==0 && year%100!=0)/*for years which are divisible by 4       but not by 100*/ 
    {
        return 1;
    }
    else if(year%4==0 && year%100==0)/*years which are both divisible      by 4 and 100*/
    {
        if(year%400==0)//to check if its divisible by 400
        {
            return 1;
            
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;//if not divisible by 4
    }
    //return 0;
}