/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
int student_solution(int input_year)
{
    int y;y = input_year;;//variable declaration of year
    //scanf("%d",&y);//read the value of y
    if(y%4==0)// first condition for leap year 
     {
      return 1;
     }
    else
     {
      return 0;
     }
    if(y%100==0)// second condition leap year or not
        {
         if(y%400==0)
         return 1;
         else
         return 0;
        }
    //return 0;
}