/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int year;year = input_year;;
    //scanf("%d",&year); //take input from user
    if(year%4==0)//check divisibility by 4
    {
        if(year%100==0)//check divisibility by 100
        {
          if(year%400==0) // check divisibility by 400
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