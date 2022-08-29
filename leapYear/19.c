/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{   
    int y;y = input_year;;//variable to store year 
    //scanf("%d",&y);
    if(y%4==0&&!(y%100==0))/*checking no's divisibe by 4 but not by 100*/
    {
     return 1;
    }
    else if(y%400==0)/*checking no's divisible by 400*/
    {
     return 1;
    }
    else/*any leftout case is thus of a non leap year*/
    {
     return 0;
    }
    //return 0;
}