/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int Y;Y = input_year;;
    //scanf("%d",&Y); 
    if(Y%4==0) // % used for checking  divisiblity
    {
        if(Y%100==0) 
        {   
            if(Y%400==0) // /* checking for  Leap Year */
                return 1;
            else
                return 0; /* checking for Not Leap Year */
        }
        else
            return 1;
    }
    else
        return 0;
    // Fill this area with your code.
    //return 0;
}