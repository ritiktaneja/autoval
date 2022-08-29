/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
int y;y = input_year;; //box for year
//scanf("%d",&y);

    if ((y%4==0)&&(y%100!=0)) //year divisible by 4 but not by 100
{    return 1;
} 
   else 
    if ((y%100==0)&&(y%400==0))
    {return 1; //divisible by 100 and 400
    }
    else {
    return 0;
}

    //return 0;
}
