/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int yr;yr = input_year;;   //yr is the variable to store the year entered by user
    
    //input by the user
    //scanf("%d",&yr);
    
    //conditions to check whether th year is a leap year
    
    if(yr%4==0){        //checking if the year is divisible by 4 
        if(yr%100!=0)   //if the year is not divisible by 100
        return 1;
        
        else{
            if(yr%400!=0)//if year is divisible by 100 but not by 400
            return 0;
            
            else        //if year is divisible by 100 and by 400
            return 1;
        }
    }
    
    else                //if year is not divisible by 4
    return 0;
    
    //return 0;
}