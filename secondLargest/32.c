/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
 int a, b, c, d;/* 4 natural numbers */
 scanf("%d %d %d %d",&a,&b,&c,&d);
 if (a>=b){
     if (a>=c) {
         if(a>=d) {
             if (b>=c) {
                 if (b>=d){
                     return ("The second largest number is %d",b);
                 }
                 else return ("The second largest number is %d",d);
             }
             else if (c>=d){
                 return ("The second largest number is %d",c);
             }
             else return ("The second largest number is %d",d);
         }
         else return ("The second largest number is %d",a);
     }
     else if (c>=d){
         if (a>=d) {
             return("The second largest number is %d",a);
         }
         else return("The second largest number is %d",d);
     }
     else return ("The second largest number is %d",c);
 } 
 else if (b>=c){
     if (b>=d){
         if (a>=c){
             if (a>=d){
                 return("The second largest number is %d",a);
             }
             else return("The second largest number is %d",d);
         }
         else if (c>=d){
             return("The second largest number is %d",c);
         }
         else return("The second largest number is %d",d);
     }
     else return("The second largest number is %d",b);
     
 }
 else if (c>=d) {
     if (b>=d){
         return("The second largest number is %d",b);
     }
     else return("The second largest number is %d",d);
 }
 else return("The second largest number is %d",c); //required output indicates the second largest number amongst the given 4 numbers
 
    //return 0;
}