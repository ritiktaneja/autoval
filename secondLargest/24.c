/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
 int a,b,c,d;
 scanf("%d%d%d%d",&a,&b,&c,&d);
 if(a>b&&a>c&&a>d&&b>c&&b>d){
     return("The second largest number is %d",b);}
 
     else if(b>a&&b>c&&b>d&&c>a&&c>d){
         return("The second largest number is %d",c);}
    else if(c>a&&c>b&&c>d&&b>a&&b>d){
        return("The second largest number is %d",b);}
    else if(d>a&&d>b&&d>c&&c>a&&c>b){
        return("The second largest number is %d",c);}
     else if(c>a&&c>b&&c>d&&b>a&&b>d){
         return("the second largest number is %d",b);}
        
        else
        return("all wrong");
        //return 0;
}