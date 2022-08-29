/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
int student_solution(int input_year)
{int y;y = input_year;;
//scanf("%d",&y);
  if (y%4==0)//if divisible by 4 then it may be leap year or may not be
{
   if (y%100==0)// if divisible by 100 then there is chances to be not a leap year
     {if (y%400==0)//if divisible by 400,100 then it is leap year
        return 1;
      else//if divisible by 4,100 and not by 400 then it is not leap year
          return 0;
           }
   else//if divisible by 4 but not by 100 then it is also leap year
      return 1;
           }
     else//if not divisible by 4 then it is not leap year 
       return 0;
//return 0;
}