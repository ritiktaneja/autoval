/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year)
{
    // Fill this area with your code.
    int yr;yr = input_year;int a,b,c;
    //scanf("%d",&yr);//input year
    a=yr%100;
    b=yr%400;
    c=yr%4;
    if (a==0){
    if (b==0)
    return 1; //100 year condition
    else 
    return 0;
    }
    else{
        if(a!=0 && c==0)//normal condition
        return 1;
        else
        return 0;
    }
    //return 0;
}
