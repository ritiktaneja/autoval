/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
int student_solution(int input_year){
   int year;year = input_year;;
   //scanf("%d",&year);     //input from the user and put & before                                   variable name
 if((year%100)==0){
     if((year%400)==0){
         return 1;
     }
     else{
         return 0;
     }
 }                       //close the brackets(used for if)
  if((year%100)!=0){
     if((year%4)==0){
         return 1;
     }
     else{
         return 0;
     }
 }                      //close the brackets(used for if)
   //return 0;
}