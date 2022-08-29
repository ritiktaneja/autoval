/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    
    int Y;Y = input_year;;  
    //scanf("%d",&Y);  //Y stands for year.
    if(Y%4==0)
    {
        if(Y%100==0)   
        {
            if(Y%400==0)
            {
                return 1;
            }
        
            else if(Y%400!=0)
            {
                return 0;
            }
        }
        else
        return 1;
    }
    else    //Not divisible by 4 simply means not a leap year
    {
        return 0;
    }
    //return 0;
}