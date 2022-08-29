/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
  int year;year = input_year; ;
     //scanf("%d",&year) ;//input year
  if (year%100 == 0){   //divisible by 100
  
  if (year%400 == 0){   //divisible by 400
     return 1;
  } else {              //not divisible by 400  
     return 0;
  }     
  } else {              //not divisible by  100
  if (year%4 == 0){     //divisible by 4
     return 1;
  } else {              //not divisible by 4   
     return 0;
  }
  }
    //return 0;
}