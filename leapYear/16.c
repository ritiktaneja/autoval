/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{   
    int y;y = input_year;;
    //scanf("%d",&y); //Taking input of year.
    if(y%100==0)
    {   if(y%400==0) //Checking divisiblity by 400.
            return 1;
        else
            return 0;
    }
    else
    {   if(y%4==0)
            return 1;
        else
            return 0;
    }
    //return 0;
}