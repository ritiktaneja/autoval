/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
  int year;year = input_year;;
    //scanf("%d",&year);
   if(year%4==0)//year has to be divisible by 4 for it to be leap year
    { if(year%100!=0)//there is ambiguity only when year is also divisible by 100,otherwise it will be a leap year
        return 1;
      else
        {if(year%400==0)
          return 1;
         else
          return 0;
        }
    }
   else
      return 0;//here curly braces are not needed since there is only 1 statement inside 'if'
    //return 0;
}