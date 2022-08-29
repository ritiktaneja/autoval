/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
  int x;x = input_year;; //variable for input
  //scanf("%d",&x); //take input from the user
  if (x%4==0)  //calculation for leap year
  {
      if (x%100==0) //condition for leap year
      {
          if (x%400==0) //condition for leap year
          {
              return 1; //display the output on the console
          }
          else 
          { 
              return 0; //display the output on the console
          }
          
      }
      else 
      {
          return 1; //display the output on the console
      }
  }
  else
      { 
          return 0; //display the output on the console
      }
      
      
    //return 0;
}