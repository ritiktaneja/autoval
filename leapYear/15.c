/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
int a;a = input_year;; //assigning for the input//
//scanf ("%d", &a); //taking input//
if (a%4==0) //Applying conditions for Leap Year.//
 {if (a%100==0 && a%400==0)
{return  1;}
else if(a%4==0 && a%100!=0)
{return  1;}
else if (a%100==0 && a%400!=0)
{return  0;}
 }
else {return  0; }
//return 0;
}