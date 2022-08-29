/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int y;y = input_year;;
    //scanf("%d",&y);//TAKING INPUT FROM USER
    if(y%4==0){
      if((y%100==0 && y%400==0) ||y%100!=0)//DIVISIBILITY BY 100 & 400 OR                                              NOT DIVISIBLE BY 100
      return 1;
      else 
      return 0;
      }
    else
    return 0;
    //return 0;
}