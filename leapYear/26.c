/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
int year;year = input_year;;           
    
int l;                    //defined integer l.
    
//scanf("%d",&year);        //input.  
    
l=(year%4);               //expression.
    
if (l==0) {     
    return 1;  //if r=0.
}
else {
    return 0;//if r = 1,2,3.
}     

    //return 0;
}
