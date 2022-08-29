/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int year;year = input_year;;//declaration of variable
    //scanf("%d",&year);
    if(year%4 == 0){                                    
        if(year%100 ==0){
            if(year%400 == 0)//really a part of defination
                return 1;
            else
                return 0;}
        else
            return 1; 
    }
    else{
        return 0;
    }
    //return 0;
}