/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int a;a = input_year;;
    //scanf("%d",&a);
    if (a%4==0){                //if divisible by 4 it is a leap year except if divisible by 100 also
        if (a%100==0){          //if divisible by 100 check if divisible by 100
            if (a%400==0){      //if divisible by 400 it is a leap year
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
        
    }else{
        return 0;
    }    
    //return 0;
}