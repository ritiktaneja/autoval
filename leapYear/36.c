/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int a;a = input_year;;
    //scanf("%d",&a);
    if (a%4==0) 
             {   if (a%100==0) 
                  {if (a%400==0)
                      {return 1;}
                   else {
                       return 0;}
                   }
                 else {return 1;}
             }
    else {return 0;}
       //return 0;
}