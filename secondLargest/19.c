/*execute-result:OK*/
/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);        //input 4 numbers.
    /*The program compares two consecutive variables and swaps them if       the first one is smaller. Thus we get the 4 numbers in decreasing       order and the second variable b is printed as the second largest       number. The code within the if body swaps the 2 numbers.*/
       if(a<b)
         {
             int s=a;
             a=b;
             b=s;
         }
       if(c<d)
         {
             int s=c;
             c=d;
             d=s;
         }
       if(b<c)
         {
             int s=b;
             b=c;
             c=s;
         }
       if(a<b)
         {
             int s=a;
             a=b;
             b=s;
         }
       if(b<c)
         {
             int s=b;
             b=c;
             c=s;
         }
       if(c<d)
         {
             int s=c;
             c=d;
             d=s;
         }
    return("The second largest number is %d",b);     
    //return 0;
}