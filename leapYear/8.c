/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int year;year = input_year;;
    //scanf("%d",&year);       // Taking the year as input 
    if((year%100==0 && year%400==0) || (year%100!=0 && year%4==0)) 
                             // Checking if Leap Year or Not
    {
        return 1;     
    }
    else
    {
        return 0;
    }
    //return 0;
}