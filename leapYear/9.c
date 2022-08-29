/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int year;year = input_year;; 
    //scanf("%d", &year);         /*input year*/
    if (year%4!=0) {            /*not divisible by 4*/
        return 0;
    } else if (year%100!=0) {   /*not divisible by 100*/
        return 1;
    } else if (year%400!=0) {   /*not divisible by 400*/
        return 0;
    } else {                    /*divisible by 4,100,400*/
        return 1;
    }
    //return 0;
}