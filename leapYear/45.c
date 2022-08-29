/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int y;y = input_year;;                         //declaring variable to store year
    //scanf("%d",&y);                /* taking input*/
    
    if (y%100==0){                 //condition for divisibility by 100
        if (y%400==0)              //cond. for div. by 400
            return 1;    // dividible by 100 & 400
        else
            return 0;     // by 100 but not 400
        }
        
    else{
            if (y%4==0)                   //cond. for div. by 4
                return 1;      /*by 4 but not 100 */
            else
                return 0;   /* neither 4 nor 100*/
        }
        
        
    
    //return 0;
}