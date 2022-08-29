/*execute-result:OK*/
/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year){
    
int year;year = input_year;;
//scanf("%d",&year);//to take the value of year from user

if(year%4==0)//condition for leap year
{
    if((year%100==0)&&(year%400==0))
    {
        return 1;
    }
    
    else if((year%100==0)&&(year%400!=0))
    {
        return 0;
    }
    
    else
    return 1;
}

else
{
return 0;
}

    //return 0;
}