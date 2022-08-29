/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{ 
//declaration and obtaining value
int yr;yr = input_year;;                             //yr=input year by user
//scanf("%d",&yr);

if(yr%4==0)                         //Leap year is divisible by 4
{   if(yr%100==0){
        if(yr%400==0)               //If year is divisible by 100 then 
            return 1;    //it should be divisible by 400 
        else                        //else year is NOT a leap year.
            return 0;
                 }
    else
        return 1;
}
else                        //Year not divisible by 4 is not leap year.
    return 0;
    //return 0;
}