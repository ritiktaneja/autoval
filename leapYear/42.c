/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
  int year;year = input_year;;
  //scanf("%d",&year);//Taking the input
  if(year%4==0)//Checking for the leap year condition
  {
      if(year%100==0)
      {
        if(year%400==0)//extra check for the leap year
        return 1;
        else
        return 0;
      }
      else
      return 1;
  }
  else
      return 0;
  //return 0;
}