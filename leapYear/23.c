/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    int a;a = input_year;int b; 
    //scanf ("%d",&a);    /*input of year by user*/
    
    b=(a%4) ;
    
    if (b==0) { /*condition statement if leap year*/
    return  1;
    }
    else { /* for not a LP*/
        return  0;
    
    }
    //return 0;
}
