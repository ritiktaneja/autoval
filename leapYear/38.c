/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int year;year = input_year;int rem;
    //scanf("%d",&year);   
    rem=year%4;         
    if(rem==0)   // check divisibility of year by 4
    {
        if((year%100==0)&&(year%400!=0))  /*condition to check whether given year is divisible by 100 AND not divisible by 400*/  
            return 0;
        else                       
            return 1;
    }
    else 
        return 0;
    //return 0;       
}
