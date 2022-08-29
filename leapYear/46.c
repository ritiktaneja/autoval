/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int year;year = input_year;;
    //scanf("%d",&year); //reading the year from user
    if(year%4==0) //checking if the year is divisible by 4
    {
        if(year%100==0)//checking if the year is divisible by 100
           {
               if(year%400==0) //checking divisibility by 400
                  {
                      return 1;
                  }
               else
                  {
                      return 0;
                  }
           }
        else
          {
              return 1;
          }
    }
    else
      {
          return 0; 
      }
    //return 0;
}