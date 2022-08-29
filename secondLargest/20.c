/*execute-result:OK*/
/*compile-errors:*/
/*compile-result:1*/
/*save-event:compile*/
#include<stdio.h>
#define scanf(str, x, y, z, w); *x=input_a;*y=input_b;*z=input_c;*w=input_d;

int student_solution(int input_a, int input_b, int input_c, int input_d)
{
    int a,b,c,p;
    scanf("%d,%d,%d,%d",&a,&b,&c,&p);
    if(a>b)
    {if(a>b && b>c && b>p)
    return("second largest number=%d",a);
    }
    else{
    return("second largest number=%d",b);
    }
    if(a>c){
  return("second largest number=%d",a);
    }
   else{
   return("second largest number=%d",c );
   }
   if(a<p){
    return("second largest number=%d",a);
    }
    else{
    return("second largest number=%d",p);
    }
   //return 0;
}