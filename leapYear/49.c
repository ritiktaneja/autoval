/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
 int year;year = input_year;;
 //scanf("%d",&year);
 
  if ( year%400 == 0)
    return 1;  /*if divisible then leap year */
  else if ( year%100 == 0)  
    return 0;/*if divisible by 100 and not 400 then not leap year */
  else if ( year%4 == 0 )
    return 1; /*if divisible by 4 and not by 100 then leap year*/
  else
    return 0;  /*if not divisible by 4 then not leap year*/
 
    //return 0;
}
