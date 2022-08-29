/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>

int student_solution(int input_year){
    int y;y = input_year;;//defining year variable 
    //scanf("%d",&y);
    if (y%4==0) {
        if (y%100==0){
            if (y%400==0) return 1;//checking it's divisiblity
            else return 0;
        }
         else return 1;// negative output of 400 dividing
    }
    
    
    else return 0;
    //return 0;
}